// Generated by gencpp from file agile_v_core/electric.msg
// DO NOT EDIT!


#ifndef AGILE_V_CORE_MESSAGE_ELECTRIC_H
#define AGILE_V_CORE_MESSAGE_ELECTRIC_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace agile_v_core
{
template <class ContainerAllocator>
struct electric_
{
  typedef electric_<ContainerAllocator> Type;

  electric_()
    : voltage()
    , pwrDriving()
    , pwrSteering()
    , pwrTotal()
    , AmpDriving()
    , AmpSteering()
    , UnitAmp()  {
      voltage.assign(0.0);

      pwrDriving.assign(0.0);

      pwrSteering.assign(0.0);

      pwrTotal.assign(0.0);

      AmpDriving.assign(0.0);

      AmpSteering.assign(0.0);

      UnitAmp.assign(0.0);
  }
  electric_(const ContainerAllocator& _alloc)
    : voltage()
    , pwrDriving()
    , pwrSteering()
    , pwrTotal()
    , AmpDriving()
    , AmpSteering()
    , UnitAmp()  {
  (void)_alloc;
      voltage.assign(0.0);

      pwrDriving.assign(0.0);

      pwrSteering.assign(0.0);

      pwrTotal.assign(0.0);

      AmpDriving.assign(0.0);

      AmpSteering.assign(0.0);

      UnitAmp.assign(0.0);
  }



   typedef boost::array<float, 4>  _voltage_type;
  _voltage_type voltage;

   typedef boost::array<float, 4>  _pwrDriving_type;
  _pwrDriving_type pwrDriving;

   typedef boost::array<float, 4>  _pwrSteering_type;
  _pwrSteering_type pwrSteering;

   typedef boost::array<float, 4>  _pwrTotal_type;
  _pwrTotal_type pwrTotal;

   typedef boost::array<float, 4>  _AmpDriving_type;
  _AmpDriving_type AmpDriving;

   typedef boost::array<float, 4>  _AmpSteering_type;
  _AmpSteering_type AmpSteering;

   typedef boost::array<float, 4>  _UnitAmp_type;
  _UnitAmp_type UnitAmp;




  typedef boost::shared_ptr< ::agile_v_core::electric_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::agile_v_core::electric_<ContainerAllocator> const> ConstPtr;

}; // struct electric_

typedef ::agile_v_core::electric_<std::allocator<void> > electric;

typedef boost::shared_ptr< ::agile_v_core::electric > electricPtr;
typedef boost::shared_ptr< ::agile_v_core::electric const> electricConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::agile_v_core::electric_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::agile_v_core::electric_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace agile_v_core

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'agile_v_core': ['/mnt/Data/AgileV_dev/ROS/src/agile_v_core/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::agile_v_core::electric_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::agile_v_core::electric_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::agile_v_core::electric_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::agile_v_core::electric_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::agile_v_core::electric_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::agile_v_core::electric_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::agile_v_core::electric_<ContainerAllocator> >
{
  static const char* value()
  {
    return "c6bc6c3c8d1a9c04520cae2eed8a6f9d";
  }

  static const char* value(const ::agile_v_core::electric_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xc6bc6c3c8d1a9c04ULL;
  static const uint64_t static_value2 = 0x520cae2eed8a6f9dULL;
};

template<class ContainerAllocator>
struct DataType< ::agile_v_core::electric_<ContainerAllocator> >
{
  static const char* value()
  {
    return "agile_v_core/electric";
  }

  static const char* value(const ::agile_v_core::electric_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::agile_v_core::electric_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32[4] voltage\n\
float32[4] pwrDriving\n\
float32[4] pwrSteering\n\
float32[4] pwrTotal\n\
float32[4] AmpDriving\n\
float32[4] AmpSteering\n\
float32[4] UnitAmp\n\
\n\
";
  }

  static const char* value(const ::agile_v_core::electric_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::agile_v_core::electric_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.voltage);
      stream.next(m.pwrDriving);
      stream.next(m.pwrSteering);
      stream.next(m.pwrTotal);
      stream.next(m.AmpDriving);
      stream.next(m.AmpSteering);
      stream.next(m.UnitAmp);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct electric_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::agile_v_core::electric_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::agile_v_core::electric_<ContainerAllocator>& v)
  {
    s << indent << "voltage[]" << std::endl;
    for (size_t i = 0; i < v.voltage.size(); ++i)
    {
      s << indent << "  voltage[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.voltage[i]);
    }
    s << indent << "pwrDriving[]" << std::endl;
    for (size_t i = 0; i < v.pwrDriving.size(); ++i)
    {
      s << indent << "  pwrDriving[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.pwrDriving[i]);
    }
    s << indent << "pwrSteering[]" << std::endl;
    for (size_t i = 0; i < v.pwrSteering.size(); ++i)
    {
      s << indent << "  pwrSteering[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.pwrSteering[i]);
    }
    s << indent << "pwrTotal[]" << std::endl;
    for (size_t i = 0; i < v.pwrTotal.size(); ++i)
    {
      s << indent << "  pwrTotal[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.pwrTotal[i]);
    }
    s << indent << "AmpDriving[]" << std::endl;
    for (size_t i = 0; i < v.AmpDriving.size(); ++i)
    {
      s << indent << "  AmpDriving[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.AmpDriving[i]);
    }
    s << indent << "AmpSteering[]" << std::endl;
    for (size_t i = 0; i < v.AmpSteering.size(); ++i)
    {
      s << indent << "  AmpSteering[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.AmpSteering[i]);
    }
    s << indent << "UnitAmp[]" << std::endl;
    for (size_t i = 0; i < v.UnitAmp.size(); ++i)
    {
      s << indent << "  UnitAmp[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.UnitAmp[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // AGILE_V_CORE_MESSAGE_ELECTRIC_H