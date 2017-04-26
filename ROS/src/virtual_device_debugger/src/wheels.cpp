#include <ros.h>
//#include <FlexiTimer2.h>
#include <std_msgs/UInt16MultiArray.h>
#include <std_msgs/Float32MultiArray.h>
#include <std_msgs/Int32MultiArray.h>

/*
#define CONTRL      3
#define BACK        4
#define BREAK       5 //connecting to driving motor controller.
#define csn        13 //yellow
#define datS        2 //green
#define datD        8 //green
#define clk         9 //blue
#define PUL         6
#define DIR         7 // direction for the angle motor
#define VOLT        A3
#define AMPD        A7
#define AMPS        A6
*/

ros::NodeHandle handle;
const uint16_t encoder_resolution = 4096;
const unsigned int updateTime = 40000;	//Time in us
int pulseTime = 100;                	//Time in us
uint16_t Angle[4] = {0,0,0,0};
int16_t Speed[4] = {0,0,0,0};
uint16_t steeringTarget[4] = {0,0,0,0};
uint16_t _zero[4] = {231,2646,1895,2297};
uint16_t _last[4] = {0,0,0,0};
uint16_t drive_input[4];
uint16_t drive_val[4];

std_msgs::UInt16MultiArray ActuatorStatus0;
std_msgs::UInt16MultiArray ActuatorStatus1;
std_msgs::UInt16MultiArray ActuatorStatus2;
std_msgs::UInt16MultiArray ActuatorStatus3;
/************
    unsigned short StrActual;
    unsigned short DrvActual;
************/
std_msgs::Float32MultiArray PowerStatus0;
std_msgs::Float32MultiArray PowerStatus1;
std_msgs::Float32MultiArray PowerStatus2;
std_msgs::Float32MultiArray PowerStatus3;
/************
    float Voltage;
    float CurrentS;
    float CurrentD;
************/
/************
std_msgs::UInt16MultiArray ctrl_var;
    int inputSteer;
    int inputDrive;
    int inputBreak;
    int reverse;
************/

//***MODIFY UNIT-SPECIFIC TOPICS AS NECESSARY!!!***//
ros::Publisher assessActual("WheelActual00", &ActuatorStatus0);
ros::Publisher assessPower("UnitPower00", &PowerStatus0);

ros::Publisher assessActual("WheelActual01", &ActuatorStatus1);
ros::Publisher assessPower("UnitPower01", &PowerStatus1);

ros::Publisher assessActual("WheelActual02", &ActuatorStatus2);
ros::Publisher assessPower("UnitPower02", &PowerStatus2);

ros::Publisher assessActual("WheelActual03", &ActuatorStatus3);
ros::Publisher assessPower("UnitPower03", &PowerStatus3);

unsigned long time_last;                 //for Buffer flushing
unsigned long time_last_query;           //for Query


void Actuate0( const std_msgs::UInt16MultiArray& ctrl_var){
    //Send Signals to stepper motor and BLDC according to messages subscribed
    drive_input = ctrl_var.data[1];
	if(ctrl_var.data[3]>0){ // 倒车
        vel = vel - drive_input;
	}//adjust for the switch
    else{
		vel = vel + drive_input;
	}
	if (ctrl_var.data[2]==0){
	    vel = vel*0.98;
	}
	else{											//Breaking
		vel = vel*(0.98-ctrl_var.data[2]*0.7/255);
	}
    // As the first version has only one encoder (for the angle), only the angle part has the close loop control.
   steeringTarget = ctrl_var.data[0];
}

//***MODIFY UNIT-SPECIFIC TOPICS AS NECESSARY!!!***//
ros::Subscriber<std_msgs::UInt16MultiArray> sub("WheelControl00", &Actuate);

void Driving(){
    int error = drive_input - Speed;
    drive_val = error/255*180 + 75;
    drive_val = max(min(drive_val * min(1000.0 / (PowerStatus.data[0]*PowerStatus.data[2]),1.0),255),0);
}

void Steering(){
	//-------------------start angle control------------------------------------
	if(steeringTarget < 0 || steeringTarget >encoder_resolution-1) { // will be modified as -90 degree to 90 degree
        //Serial.println("bad DesiredAngle input.");
    }
    else {
		int err = (steeringTarget-Angle+encoder_resolution)%(encoder_resolution)-(encoder_resolution*0.5);
		//min(min(abs(steeringTarget-Angle),abs(steeringTarget-Angle+encoder_resolution)),abs(steeringTarget-Angle-encoder_resolution));
        if(!(abs(err)<40)) {
			pulseTime = 7000/(1.1*abs(err)+5);	//Need Modification
            if (err<0) {
                Flip(0);
            }
            else {
                Flip(1);
            }  
        }
        //end while loop 
    }
	//----------------end angle control---------------------------------------------  
}

void setup() {
/*
	// set driving control
	pinMode(DIR, OUTPUT);
	pinMode(PUL, OUTPUT);
	// set angle encoder
	pinMode(csn, OUTPUT);
	pinMode(datS, INPUT);
	pinMode(datD, INPUT);
	pinMode(clk, OUTPUT);
*/
	
	handle.initNode();
	handle.subscribe(sub);
	
    //PowerStatus.layout.dim_length = 1;
    malloc(sizeof(std_msgs::MultiArrayDimension) * 3);
    PowerStatus.layout.dim[0].label = "UnitPower";
    PowerStatus.layout.dim[0].size = 3;
    PowerStatus.layout.dim[0].stride = 1*3;
    //PowerStatus.layout.data_offset = 0;
    PowerStatus.data = (float *)malloc(sizeof(float)*3);
    PowerStatus.data_length = 3;
    handle.advertise(assessPower);
    
    //ActuatorStatus.layout.dim_length = 1;
    malloc(sizeof(std_msgs::MultiArrayDimension) * 2);
    ActuatorStatus.layout.dim[0].label = "WheelActual";
    ActuatorStatus.layout.dim[0].size = 2;
    ActuatorStatus.layout.dim[0].stride = 1*2;
    //ActuatorStatus.layout.data_offset = 0;
    ActuatorStatus.data = (uint16_t *)malloc(sizeof(uint16_t)*2);
    ActuatorStatus.data_length = 2;
    handle.advertise(assessActual);
	
	steeringTarget = ActuatorStatus.data[0];	//Stop Init Steering of the wheel
	
	//Initiate Steering Actuator and run via FlexiTimer
	//Query();
	//FlexiTimer2::set(updateTime,Query);  //time in the unit of ms
    //FlexiTimer2::start();
}

void loop() {
   unsigned long time_now = micros();
   if ((unsigned long)(time_now - time_last) > pulseTime){
       Steering();
       time_last = micros();
   }
   if ((unsigned long)(time_now - time_last_query) > updateTime){
       Query();
       Driving();
       time_last_query = micros();
   }
   handle.spinOnce();
}

// the function to determine the wave pattern to servo
bool V_last = false;

void Flip(bool direc) {
  if (direc == 0){
    angle += 360/3000;
  }
  else if (direc == 1) {
    angle -= 360/3000;
  }
}

void Query()
{
  uint16_t dataActuator[2] = {0};
  float dataPower[3];
  
  /*
  digitalWrite(csn,LOW);
  delayMicroseconds(1);
  for (int k=0;k<12;k++)
  {
    digitalWrite(clk,LOW);
    delayMicroseconds(1);
    digitalWrite(clk,HIGH);
    delayMicroseconds(1);
    dataActuator[0]=(dataActuator[0]<<1)+digitalRead(datS);		//Steering
    dataActuator[1]=(dataActuator[1]<<1)+digitalRead(datD);		//Driving
    //delayMicroseconds(1);
  }
  for (int k=0;k<6;k++)
  {
    digitalWrite(clk,LOW);
    delayMicroseconds(1);
    digitalWrite(clk,HIGH);
    delayMicroseconds(1);
  }
  digitalWrite(csn,HIGH);
  */

  dataActuator[0] = angle/360*4096+_zero;
  dataActuator[1] = dataActuator[1]+vel/4096;
  Angle=(dataActuator[0]-_zero+encoder_resolution)%encoder_resolution;
  Speed=(-dataActuator[1]+_last+encoder_resolution)%encoder_resolution;
  _last = dataActuator[1];
  //Angle=dataActuator[0];
  
  dataPower[0] = 50*(0.02892+0.00002576*50)+2.99;
  dataPower[1] = 5.0;
  dataPower[2] = drive_input[0]*vel[0]/62500;
  
  ActuatorStatus.data = dataActuator;
  PowerStatus.data = dataPower;
  
  ActuatorStatus.data[0] = drive_input;
  ActuatorStatus.data[1] = drive_val;
  
  assessActual.publish (&ActuatorStatus);
  assessPower.publish (&PowerStatus);
  //Serial.write((const uint8_t*)&to_send,sizeof(serial_format));
}

