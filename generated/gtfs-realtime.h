/*
 *  This file is generated with Embedded Proto, PLEASE DO NOT EDIT!
 *  source: gtfs-realtime.proto
 */

// This file is generated. Please do not edit!
#ifndef GTFS-REALTIME_H
#define GTFS-REALTIME_H

#include <cstdint>
#include <MessageInterface.h>
#include <WireFormatter.h>
#include <Fields.h>
#include <MessageSizeCalculator.h>
#include <ReadBufferSection.h>
#include <RepeatedFieldFixedSize.h>
#include <FieldStringBytes.h>
#include <Errors.h>
#include <Defines.h>
#include <limits>

// Include external proto definitions

namespace transit_realtime {

template<
    uint32_t FeedHeader_gtfs_realtime_version_LENGTH
>
class FeedHeader final: public ::EmbeddedProto::MessageInterface
{
  public:
    FeedHeader() = default;
    FeedHeader(const FeedHeader& rhs )
    {
      set_gtfs_realtime_version(rhs.get_gtfs_realtime_version());
      set_incrementality(rhs.get_incrementality());
      set_timestamp(rhs.get_timestamp());
    }

    FeedHeader(const FeedHeader&& rhs ) noexcept
    {
      set_gtfs_realtime_version(rhs.get_gtfs_realtime_version());
      set_incrementality(rhs.get_incrementality());
      set_timestamp(rhs.get_timestamp());
    }

    ~FeedHeader() override = default;

    enum class Incrementality : uint32_t
    {
      FULL_DATASET = 0,
      DIFFERENTIAL = 1
    };

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      GTFS_REALTIME_VERSION = 1,
      INCREMENTALITY = 2,
      TIMESTAMP = 3
    };

    FeedHeader& operator=(const FeedHeader& rhs)
    {
      set_gtfs_realtime_version(rhs.get_gtfs_realtime_version());
      set_incrementality(rhs.get_incrementality());
      set_timestamp(rhs.get_timestamp());
      return *this;
    }

    FeedHeader& operator=(const FeedHeader&& rhs) noexcept
    {
      set_gtfs_realtime_version(rhs.get_gtfs_realtime_version());
      set_incrementality(rhs.get_incrementality());
      set_timestamp(rhs.get_timestamp());
      return *this;
    }

    static constexpr char const* GTFS_REALTIME_VERSION_NAME = "gtfs_realtime_version";
    inline void clear_gtfs_realtime_version() { gtfs_realtime_version_.clear(); }
    inline ::EmbeddedProto::FieldString<FeedHeader_gtfs_realtime_version_LENGTH>& mutable_gtfs_realtime_version() { return gtfs_realtime_version_; }
    inline void set_gtfs_realtime_version(const ::EmbeddedProto::FieldString<FeedHeader_gtfs_realtime_version_LENGTH>& rhs) { gtfs_realtime_version_.set(rhs); }
    inline const ::EmbeddedProto::FieldString<FeedHeader_gtfs_realtime_version_LENGTH>& get_gtfs_realtime_version() const { return gtfs_realtime_version_; }
    inline const char* gtfs_realtime_version() const { return gtfs_realtime_version_.get_const(); }

    static constexpr char const* INCREMENTALITY_NAME = "incrementality";
    inline void clear_incrementality() { incrementality_.clear(); }
    inline void set_incrementality(const Incrementality& value) { incrementality_ = value; }
    inline void set_incrementality(const Incrementality&& value) { incrementality_ = value; }
    inline const Incrementality& get_incrementality() const { return incrementality_.get(); }
    inline Incrementality incrementality() const { return incrementality_.get(); }

    static constexpr char const* TIMESTAMP_NAME = "timestamp";
    inline void clear_timestamp() { timestamp_.clear(); }
    inline void set_timestamp(const uint64_t& value) { timestamp_ = value; }
    inline void set_timestamp(const uint64_t&& value) { timestamp_ = value; }
    inline uint64_t& mutable_timestamp() { return timestamp_.get(); }
    inline const uint64_t& get_timestamp() const { return timestamp_.get(); }
    inline uint64_t timestamp() const { return timestamp_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = gtfs_realtime_version_.serialize_with_id(static_cast<uint32_t>(FieldNumber::GTFS_REALTIME_VERSION), buffer, false);
      }

      if((static_cast<Incrementality>(0) != incrementality_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = incrementality_.serialize_with_id(static_cast<uint32_t>(FieldNumber::INCREMENTALITY), buffer, false);
      }

      if((0U != timestamp_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = timestamp_.serialize_with_id(static_cast<uint32_t>(FieldNumber::TIMESTAMP), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::GTFS_REALTIME_VERSION:
            return_value = gtfs_realtime_version_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::INCREMENTALITY:
            return_value = incrementality_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::TIMESTAMP:
            return_value = timestamp_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_gtfs_realtime_version();
      clear_incrementality();
      clear_timestamp();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::GTFS_REALTIME_VERSION:
          name = GTFS_REALTIME_VERSION_NAME;
          break;
        case FieldNumber::INCREMENTALITY:
          name = INCREMENTALITY_NAME;
          break;
        case FieldNumber::TIMESTAMP:
          name = TIMESTAMP_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#endif

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = gtfs_realtime_version_.to_string(left_chars, indent_level + 2, GTFS_REALTIME_VERSION_NAME, true);
      left_chars = incrementality_.to_string(left_chars, indent_level + 2, INCREMENTALITY_NAME, false);
      left_chars = timestamp_.to_string(left_chars, indent_level + 2, TIMESTAMP_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      ::EmbeddedProto::FieldString<FeedHeader_gtfs_realtime_version_LENGTH> gtfs_realtime_version_;
      EmbeddedProto::enumeration<Incrementality> incrementality_ = static_cast<Incrementality>(0);
      EmbeddedProto::uint64 timestamp_ = 0U;

};

class Position final: public ::EmbeddedProto::MessageInterface
{
  public:
    Position() = default;
    Position(const Position& rhs )
    {
      set_latitude(rhs.get_latitude());
      set_longitude(rhs.get_longitude());
      set_bearing(rhs.get_bearing());
      set_odometer(rhs.get_odometer());
      set_speed(rhs.get_speed());
    }

    Position(const Position&& rhs ) noexcept
    {
      set_latitude(rhs.get_latitude());
      set_longitude(rhs.get_longitude());
      set_bearing(rhs.get_bearing());
      set_odometer(rhs.get_odometer());
      set_speed(rhs.get_speed());
    }

    ~Position() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      LATITUDE = 1,
      LONGITUDE = 2,
      BEARING = 3,
      ODOMETER = 4,
      SPEED = 5
    };

    Position& operator=(const Position& rhs)
    {
      set_latitude(rhs.get_latitude());
      set_longitude(rhs.get_longitude());
      set_bearing(rhs.get_bearing());
      set_odometer(rhs.get_odometer());
      set_speed(rhs.get_speed());
      return *this;
    }

    Position& operator=(const Position&& rhs) noexcept
    {
      set_latitude(rhs.get_latitude());
      set_longitude(rhs.get_longitude());
      set_bearing(rhs.get_bearing());
      set_odometer(rhs.get_odometer());
      set_speed(rhs.get_speed());
      return *this;
    }

    static constexpr char const* LATITUDE_NAME = "latitude";
    inline void clear_latitude() { latitude_.clear(); }
    inline void set_latitude(const float& value) { latitude_ = value; }
    inline void set_latitude(const float&& value) { latitude_ = value; }
    inline float& mutable_latitude() { return latitude_.get(); }
    inline const float& get_latitude() const { return latitude_.get(); }
    inline float latitude() const { return latitude_.get(); }

    static constexpr char const* LONGITUDE_NAME = "longitude";
    inline void clear_longitude() { longitude_.clear(); }
    inline void set_longitude(const float& value) { longitude_ = value; }
    inline void set_longitude(const float&& value) { longitude_ = value; }
    inline float& mutable_longitude() { return longitude_.get(); }
    inline const float& get_longitude() const { return longitude_.get(); }
    inline float longitude() const { return longitude_.get(); }

    static constexpr char const* BEARING_NAME = "bearing";
    inline void clear_bearing() { bearing_.clear(); }
    inline void set_bearing(const float& value) { bearing_ = value; }
    inline void set_bearing(const float&& value) { bearing_ = value; }
    inline float& mutable_bearing() { return bearing_.get(); }
    inline const float& get_bearing() const { return bearing_.get(); }
    inline float bearing() const { return bearing_.get(); }

    static constexpr char const* ODOMETER_NAME = "odometer";
    inline void clear_odometer() { odometer_.clear(); }
    inline void set_odometer(const double& value) { odometer_ = value; }
    inline void set_odometer(const double&& value) { odometer_ = value; }
    inline double& mutable_odometer() { return odometer_.get(); }
    inline const double& get_odometer() const { return odometer_.get(); }
    inline double odometer() const { return odometer_.get(); }

    static constexpr char const* SPEED_NAME = "speed";
    inline void clear_speed() { speed_.clear(); }
    inline void set_speed(const float& value) { speed_ = value; }
    inline void set_speed(const float&& value) { speed_ = value; }
    inline float& mutable_speed() { return speed_.get(); }
    inline const float& get_speed() const { return speed_.get(); }
    inline float speed() const { return speed_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0.0 != latitude_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = latitude_.serialize_with_id(static_cast<uint32_t>(FieldNumber::LATITUDE), buffer, false);
      }

      if((0.0 != longitude_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = longitude_.serialize_with_id(static_cast<uint32_t>(FieldNumber::LONGITUDE), buffer, false);
      }

      if((0.0 != bearing_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = bearing_.serialize_with_id(static_cast<uint32_t>(FieldNumber::BEARING), buffer, false);
      }

      if((0.0 != odometer_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = odometer_.serialize_with_id(static_cast<uint32_t>(FieldNumber::ODOMETER), buffer, false);
      }

      if((0.0 != speed_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = speed_.serialize_with_id(static_cast<uint32_t>(FieldNumber::SPEED), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::LATITUDE:
            return_value = latitude_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::LONGITUDE:
            return_value = longitude_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::BEARING:
            return_value = bearing_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::ODOMETER:
            return_value = odometer_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::SPEED:
            return_value = speed_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_latitude();
      clear_longitude();
      clear_bearing();
      clear_odometer();
      clear_speed();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::LATITUDE:
          name = LATITUDE_NAME;
          break;
        case FieldNumber::LONGITUDE:
          name = LONGITUDE_NAME;
          break;
        case FieldNumber::BEARING:
          name = BEARING_NAME;
          break;
        case FieldNumber::ODOMETER:
          name = ODOMETER_NAME;
          break;
        case FieldNumber::SPEED:
          name = SPEED_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#endif

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = latitude_.to_string(left_chars, indent_level + 2, LATITUDE_NAME, true);
      left_chars = longitude_.to_string(left_chars, indent_level + 2, LONGITUDE_NAME, false);
      left_chars = bearing_.to_string(left_chars, indent_level + 2, BEARING_NAME, false);
      left_chars = odometer_.to_string(left_chars, indent_level + 2, ODOMETER_NAME, false);
      left_chars = speed_.to_string(left_chars, indent_level + 2, SPEED_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      EmbeddedProto::floatfixed latitude_ = 0.0;
      EmbeddedProto::floatfixed longitude_ = 0.0;
      EmbeddedProto::floatfixed bearing_ = 0.0;
      EmbeddedProto::doublefixed odometer_ = 0.0;
      EmbeddedProto::floatfixed speed_ = 0.0;

};

class TimeRange final: public ::EmbeddedProto::MessageInterface
{
  public:
    TimeRange() = default;
    TimeRange(const TimeRange& rhs )
    {
      set_start(rhs.get_start());
      set_end(rhs.get_end());
    }

    TimeRange(const TimeRange&& rhs ) noexcept
    {
      set_start(rhs.get_start());
      set_end(rhs.get_end());
    }

    ~TimeRange() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      START = 1,
      END = 2
    };

    TimeRange& operator=(const TimeRange& rhs)
    {
      set_start(rhs.get_start());
      set_end(rhs.get_end());
      return *this;
    }

    TimeRange& operator=(const TimeRange&& rhs) noexcept
    {
      set_start(rhs.get_start());
      set_end(rhs.get_end());
      return *this;
    }

    static constexpr char const* START_NAME = "start";
    inline void clear_start() { start_.clear(); }
    inline void set_start(const uint64_t& value) { start_ = value; }
    inline void set_start(const uint64_t&& value) { start_ = value; }
    inline uint64_t& mutable_start() { return start_.get(); }
    inline const uint64_t& get_start() const { return start_.get(); }
    inline uint64_t start() const { return start_.get(); }

    static constexpr char const* END_NAME = "end";
    inline void clear_end() { end_.clear(); }
    inline void set_end(const uint64_t& value) { end_ = value; }
    inline void set_end(const uint64_t&& value) { end_ = value; }
    inline uint64_t& mutable_end() { return end_.get(); }
    inline const uint64_t& get_end() const { return end_.get(); }
    inline uint64_t end() const { return end_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0U != start_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = start_.serialize_with_id(static_cast<uint32_t>(FieldNumber::START), buffer, false);
      }

      if((0U != end_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = end_.serialize_with_id(static_cast<uint32_t>(FieldNumber::END), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::START:
            return_value = start_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::END:
            return_value = end_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_start();
      clear_end();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::START:
          name = START_NAME;
          break;
        case FieldNumber::END:
          name = END_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#endif

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = start_.to_string(left_chars, indent_level + 2, START_NAME, true);
      left_chars = end_.to_string(left_chars, indent_level + 2, END_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      EmbeddedProto::uint64 start_ = 0U;
      EmbeddedProto::uint64 end_ = 0U;

};

template<
    uint32_t TranslatedString_translation_REP_LENGTH, 
    uint32_t TranslatedString_translation_Translation_text_LENGTH, 
    uint32_t TranslatedString_translation_Translation_language_LENGTH
>
class TranslatedString final: public ::EmbeddedProto::MessageInterface
{
  public:
    TranslatedString() = default;
    TranslatedString(const TranslatedString& rhs )
    {
      set_translation(rhs.get_translation());
    }

    TranslatedString(const TranslatedString&& rhs ) noexcept
    {
      set_translation(rhs.get_translation());
    }

    ~TranslatedString() override = default;

    template<
        uint32_t Translation_text_LENGTH, 
        uint32_t Translation_language_LENGTH
    >
    class Translation final: public ::EmbeddedProto::MessageInterface
    {
      public:
        Translation() = default;
        Translation(const Translation& rhs )
        {
          set_text(rhs.get_text());
          set_language(rhs.get_language());
        }

        Translation(const Translation&& rhs ) noexcept
        {
          set_text(rhs.get_text());
          set_language(rhs.get_language());
        }

        ~Translation() override = default;

        enum class FieldNumber : uint32_t
        {
          NOT_SET = 0,
          TEXT = 1,
          LANGUAGE = 2
        };

        Translation& operator=(const Translation& rhs)
        {
          set_text(rhs.get_text());
          set_language(rhs.get_language());
          return *this;
        }

        Translation& operator=(const Translation&& rhs) noexcept
        {
          set_text(rhs.get_text());
          set_language(rhs.get_language());
          return *this;
        }

        static constexpr char const* TEXT_NAME = "text";
        inline void clear_text() { text_.clear(); }
        inline ::EmbeddedProto::FieldString<Translation_text_LENGTH>& mutable_text() { return text_; }
        inline void set_text(const ::EmbeddedProto::FieldString<Translation_text_LENGTH>& rhs) { text_.set(rhs); }
        inline const ::EmbeddedProto::FieldString<Translation_text_LENGTH>& get_text() const { return text_; }
        inline const char* text() const { return text_.get_const(); }

        static constexpr char const* LANGUAGE_NAME = "language";
        inline void clear_language() { language_.clear(); }
        inline ::EmbeddedProto::FieldString<Translation_language_LENGTH>& mutable_language() { return language_; }
        inline void set_language(const ::EmbeddedProto::FieldString<Translation_language_LENGTH>& rhs) { language_.set(rhs); }
        inline const ::EmbeddedProto::FieldString<Translation_language_LENGTH>& get_language() const { return language_; }
        inline const char* language() const { return language_.get_const(); }


        ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
        {
          ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

          if(::EmbeddedProto::Error::NO_ERRORS == return_value)
          {
            return_value = text_.serialize_with_id(static_cast<uint32_t>(FieldNumber::TEXT), buffer, false);
          }

          if(::EmbeddedProto::Error::NO_ERRORS == return_value)
          {
            return_value = language_.serialize_with_id(static_cast<uint32_t>(FieldNumber::LANGUAGE), buffer, false);
          }

          return return_value;
        };

        ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
        {
          ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
          ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
          uint32_t id_number = 0;
          FieldNumber id_tag = FieldNumber::NOT_SET;

          ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
          while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
          {
            id_tag = static_cast<FieldNumber>(id_number);
            switch(id_tag)
            {
              case FieldNumber::TEXT:
                return_value = text_.deserialize_check_type(buffer, wire_type);
                break;

              case FieldNumber::LANGUAGE:
                return_value = language_.deserialize_check_type(buffer, wire_type);
                break;

              case FieldNumber::NOT_SET:
                return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
                break;

              default:
                return_value = skip_unknown_field(buffer, wire_type);
                break;
            }

            if(::EmbeddedProto::Error::NO_ERRORS == return_value)
            {
              // Read the next tag.
              tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
            }
          }

          // When an error was detect while reading the tag but no other errors where found, set it in the return value.
          if((::EmbeddedProto::Error::NO_ERRORS == return_value)
             && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
             && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
          {
            return_value = tag_value;
          }

          return return_value;
        };

        void clear() override
        {
          clear_text();
          clear_language();

        }

    #ifndef DISABLE_FIELD_NUMBER_TO_NAME 

        static char const* field_number_to_name(const FieldNumber fieldNumber)
        {
          char const* name = nullptr;
          switch(fieldNumber)
          {
            case FieldNumber::TEXT:
              name = TEXT_NAME;
              break;
            case FieldNumber::LANGUAGE:
              name = LANGUAGE_NAME;
              break;
            default:
              name = "Invalid FieldNumber";
              break;
          }
          return name;
        }

    #endif

    #ifdef MSG_TO_STRING

        ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
        {
          return this->to_string(str, 0, nullptr, true);
        }

        ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
        {
          ::EmbeddedProto::string_view left_chars = str;
          int32_t n_chars_used = 0;

          if(!first_field)
          {
            // Add a comma behind the previous field.
            n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
            if(0 < n_chars_used)
            {
              // Update the character pointer and characters left in the array.
              left_chars.data += n_chars_used;
              left_chars.size -= n_chars_used;
            }
          }

          if(nullptr != name)
          {
            if( 0 == indent_level)
            {
              n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
            }
            else
            {
              n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
            }
          }
          else
          {
            if( 0 == indent_level)
            {
              n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
            }
            else
            {
              n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
            }
          }
          
          if(0 < n_chars_used)
          {
            left_chars.data += n_chars_used;
            left_chars.size -= n_chars_used;
          }

          left_chars = text_.to_string(left_chars, indent_level + 2, TEXT_NAME, true);
          left_chars = language_.to_string(left_chars, indent_level + 2, LANGUAGE_NAME, false);
      
          if( 0 == indent_level) 
          {
            n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
          }
          else 
          {
            n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
          }

          if(0 < n_chars_used)
          {
            left_chars.data += n_chars_used;
            left_chars.size -= n_chars_used;
          }

          return left_chars;
        }

    #endif // End of MSG_TO_STRING

      private:


          ::EmbeddedProto::FieldString<Translation_text_LENGTH> text_;
          ::EmbeddedProto::FieldString<Translation_language_LENGTH> language_;

    };

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      TRANSLATION = 1
    };

    TranslatedString& operator=(const TranslatedString& rhs)
    {
      set_translation(rhs.get_translation());
      return *this;
    }

    TranslatedString& operator=(const TranslatedString&& rhs) noexcept
    {
      set_translation(rhs.get_translation());
      return *this;
    }

    static constexpr char const* TRANSLATION_NAME = "translation";
    inline const Translation<TranslatedString_translation_Translation_text_LENGTH, TranslatedString_translation_Translation_language_LENGTH>& translation(uint32_t index) const { return translation_[index]; }
    inline void clear_translation() { translation_.clear(); }
    inline void set_translation(uint32_t index, const Translation<TranslatedString_translation_Translation_text_LENGTH, TranslatedString_translation_Translation_language_LENGTH>& value) { translation_.set(index, value); }
    inline void set_translation(uint32_t index, const Translation<TranslatedString_translation_Translation_text_LENGTH, TranslatedString_translation_Translation_language_LENGTH>&& value) { translation_.set(index, value); }
    inline void set_translation(const ::EmbeddedProto::RepeatedFieldFixedSize<Translation<TranslatedString_translation_Translation_text_LENGTH, TranslatedString_translation_Translation_language_LENGTH>, TranslatedString_translation_REP_LENGTH>& values) { translation_ = values; }
    inline void add_translation(const Translation<TranslatedString_translation_Translation_text_LENGTH, TranslatedString_translation_Translation_language_LENGTH>& value) { translation_.add(value); }
    inline ::EmbeddedProto::RepeatedFieldFixedSize<Translation<TranslatedString_translation_Translation_text_LENGTH, TranslatedString_translation_Translation_language_LENGTH>, TranslatedString_translation_REP_LENGTH>& mutable_translation() { return translation_; }
    inline Translation<TranslatedString_translation_Translation_text_LENGTH, TranslatedString_translation_Translation_language_LENGTH>& mutable_translation(uint32_t index) { return translation_[index]; }
    inline const ::EmbeddedProto::RepeatedFieldFixedSize<Translation<TranslatedString_translation_Translation_text_LENGTH, TranslatedString_translation_Translation_language_LENGTH>, TranslatedString_translation_REP_LENGTH>& get_translation() const { return translation_; }
    inline const ::EmbeddedProto::RepeatedFieldFixedSize<Translation<TranslatedString_translation_Translation_text_LENGTH, TranslatedString_translation_Translation_language_LENGTH>, TranslatedString_translation_REP_LENGTH>& translation() const { return translation_; }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = translation_.serialize_with_id(static_cast<uint32_t>(FieldNumber::TRANSLATION), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::TRANSLATION:
            return_value = translation_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_translation();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::TRANSLATION:
          name = TRANSLATION_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#endif

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = translation_.to_string(left_chars, indent_level + 2, TRANSLATION_NAME, true);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      ::EmbeddedProto::RepeatedFieldFixedSize<Translation<TranslatedString_translation_Translation_text_LENGTH, TranslatedString_translation_Translation_language_LENGTH>, TranslatedString_translation_REP_LENGTH> translation_;

};

template<
    uint32_t TripDescriptor_trip_id_LENGTH, 
    uint32_t TripDescriptor_route_id_LENGTH, 
    uint32_t TripDescriptor_start_time_LENGTH, 
    uint32_t TripDescriptor_start_date_LENGTH
>
class TripDescriptor final: public ::EmbeddedProto::MessageInterface
{
  public:
    TripDescriptor() = default;
    TripDescriptor(const TripDescriptor& rhs )
    {
      set_trip_id(rhs.get_trip_id());
      set_route_id(rhs.get_route_id());
      set_direction_id(rhs.get_direction_id());
      set_start_time(rhs.get_start_time());
      set_start_date(rhs.get_start_date());
      set_schedule_relationship(rhs.get_schedule_relationship());
    }

    TripDescriptor(const TripDescriptor&& rhs ) noexcept
    {
      set_trip_id(rhs.get_trip_id());
      set_route_id(rhs.get_route_id());
      set_direction_id(rhs.get_direction_id());
      set_start_time(rhs.get_start_time());
      set_start_date(rhs.get_start_date());
      set_schedule_relationship(rhs.get_schedule_relationship());
    }

    ~TripDescriptor() override = default;

    enum class ScheduleRelationship : uint32_t
    {
      SCHEDULED = 0,
      ADDED = 1,
      UNSCHEDULED = 2,
      CANCELED = 3
    };

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      TRIP_ID = 1,
      START_TIME = 2,
      START_DATE = 3,
      SCHEDULE_RELATIONSHIP = 4,
      ROUTE_ID = 5,
      DIRECTION_ID = 6
    };

    TripDescriptor& operator=(const TripDescriptor& rhs)
    {
      set_trip_id(rhs.get_trip_id());
      set_route_id(rhs.get_route_id());
      set_direction_id(rhs.get_direction_id());
      set_start_time(rhs.get_start_time());
      set_start_date(rhs.get_start_date());
      set_schedule_relationship(rhs.get_schedule_relationship());
      return *this;
    }

    TripDescriptor& operator=(const TripDescriptor&& rhs) noexcept
    {
      set_trip_id(rhs.get_trip_id());
      set_route_id(rhs.get_route_id());
      set_direction_id(rhs.get_direction_id());
      set_start_time(rhs.get_start_time());
      set_start_date(rhs.get_start_date());
      set_schedule_relationship(rhs.get_schedule_relationship());
      return *this;
    }

    static constexpr char const* TRIP_ID_NAME = "trip_id";
    inline void clear_trip_id() { trip_id_.clear(); }
    inline ::EmbeddedProto::FieldString<TripDescriptor_trip_id_LENGTH>& mutable_trip_id() { return trip_id_; }
    inline void set_trip_id(const ::EmbeddedProto::FieldString<TripDescriptor_trip_id_LENGTH>& rhs) { trip_id_.set(rhs); }
    inline const ::EmbeddedProto::FieldString<TripDescriptor_trip_id_LENGTH>& get_trip_id() const { return trip_id_; }
    inline const char* trip_id() const { return trip_id_.get_const(); }

    static constexpr char const* ROUTE_ID_NAME = "route_id";
    inline void clear_route_id() { route_id_.clear(); }
    inline ::EmbeddedProto::FieldString<TripDescriptor_route_id_LENGTH>& mutable_route_id() { return route_id_; }
    inline void set_route_id(const ::EmbeddedProto::FieldString<TripDescriptor_route_id_LENGTH>& rhs) { route_id_.set(rhs); }
    inline const ::EmbeddedProto::FieldString<TripDescriptor_route_id_LENGTH>& get_route_id() const { return route_id_; }
    inline const char* route_id() const { return route_id_.get_const(); }

    static constexpr char const* DIRECTION_ID_NAME = "direction_id";
    inline void clear_direction_id() { direction_id_.clear(); }
    inline void set_direction_id(const uint32_t& value) { direction_id_ = value; }
    inline void set_direction_id(const uint32_t&& value) { direction_id_ = value; }
    inline uint32_t& mutable_direction_id() { return direction_id_.get(); }
    inline const uint32_t& get_direction_id() const { return direction_id_.get(); }
    inline uint32_t direction_id() const { return direction_id_.get(); }

    static constexpr char const* START_TIME_NAME = "start_time";
    inline void clear_start_time() { start_time_.clear(); }
    inline ::EmbeddedProto::FieldString<TripDescriptor_start_time_LENGTH>& mutable_start_time() { return start_time_; }
    inline void set_start_time(const ::EmbeddedProto::FieldString<TripDescriptor_start_time_LENGTH>& rhs) { start_time_.set(rhs); }
    inline const ::EmbeddedProto::FieldString<TripDescriptor_start_time_LENGTH>& get_start_time() const { return start_time_; }
    inline const char* start_time() const { return start_time_.get_const(); }

    static constexpr char const* START_DATE_NAME = "start_date";
    inline void clear_start_date() { start_date_.clear(); }
    inline ::EmbeddedProto::FieldString<TripDescriptor_start_date_LENGTH>& mutable_start_date() { return start_date_; }
    inline void set_start_date(const ::EmbeddedProto::FieldString<TripDescriptor_start_date_LENGTH>& rhs) { start_date_.set(rhs); }
    inline const ::EmbeddedProto::FieldString<TripDescriptor_start_date_LENGTH>& get_start_date() const { return start_date_; }
    inline const char* start_date() const { return start_date_.get_const(); }

    static constexpr char const* SCHEDULE_RELATIONSHIP_NAME = "schedule_relationship";
    inline void clear_schedule_relationship() { schedule_relationship_.clear(); }
    inline void set_schedule_relationship(const ScheduleRelationship& value) { schedule_relationship_ = value; }
    inline void set_schedule_relationship(const ScheduleRelationship&& value) { schedule_relationship_ = value; }
    inline const ScheduleRelationship& get_schedule_relationship() const { return schedule_relationship_.get(); }
    inline ScheduleRelationship schedule_relationship() const { return schedule_relationship_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = trip_id_.serialize_with_id(static_cast<uint32_t>(FieldNumber::TRIP_ID), buffer, false);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = route_id_.serialize_with_id(static_cast<uint32_t>(FieldNumber::ROUTE_ID), buffer, false);
      }

      if((0U != direction_id_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = direction_id_.serialize_with_id(static_cast<uint32_t>(FieldNumber::DIRECTION_ID), buffer, false);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = start_time_.serialize_with_id(static_cast<uint32_t>(FieldNumber::START_TIME), buffer, false);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = start_date_.serialize_with_id(static_cast<uint32_t>(FieldNumber::START_DATE), buffer, false);
      }

      if((static_cast<ScheduleRelationship>(0) != schedule_relationship_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = schedule_relationship_.serialize_with_id(static_cast<uint32_t>(FieldNumber::SCHEDULE_RELATIONSHIP), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::TRIP_ID:
            return_value = trip_id_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::ROUTE_ID:
            return_value = route_id_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::DIRECTION_ID:
            return_value = direction_id_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::START_TIME:
            return_value = start_time_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::START_DATE:
            return_value = start_date_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::SCHEDULE_RELATIONSHIP:
            return_value = schedule_relationship_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_trip_id();
      clear_route_id();
      clear_direction_id();
      clear_start_time();
      clear_start_date();
      clear_schedule_relationship();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::TRIP_ID:
          name = TRIP_ID_NAME;
          break;
        case FieldNumber::ROUTE_ID:
          name = ROUTE_ID_NAME;
          break;
        case FieldNumber::DIRECTION_ID:
          name = DIRECTION_ID_NAME;
          break;
        case FieldNumber::START_TIME:
          name = START_TIME_NAME;
          break;
        case FieldNumber::START_DATE:
          name = START_DATE_NAME;
          break;
        case FieldNumber::SCHEDULE_RELATIONSHIP:
          name = SCHEDULE_RELATIONSHIP_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#endif

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = trip_id_.to_string(left_chars, indent_level + 2, TRIP_ID_NAME, true);
      left_chars = route_id_.to_string(left_chars, indent_level + 2, ROUTE_ID_NAME, false);
      left_chars = direction_id_.to_string(left_chars, indent_level + 2, DIRECTION_ID_NAME, false);
      left_chars = start_time_.to_string(left_chars, indent_level + 2, START_TIME_NAME, false);
      left_chars = start_date_.to_string(left_chars, indent_level + 2, START_DATE_NAME, false);
      left_chars = schedule_relationship_.to_string(left_chars, indent_level + 2, SCHEDULE_RELATIONSHIP_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      ::EmbeddedProto::FieldString<TripDescriptor_trip_id_LENGTH> trip_id_;
      ::EmbeddedProto::FieldString<TripDescriptor_route_id_LENGTH> route_id_;
      EmbeddedProto::uint32 direction_id_ = 0U;
      ::EmbeddedProto::FieldString<TripDescriptor_start_time_LENGTH> start_time_;
      ::EmbeddedProto::FieldString<TripDescriptor_start_date_LENGTH> start_date_;
      EmbeddedProto::enumeration<ScheduleRelationship> schedule_relationship_ = static_cast<ScheduleRelationship>(0);

};

template<
    uint32_t VehicleDescriptor_id_LENGTH, 
    uint32_t VehicleDescriptor_label_LENGTH, 
    uint32_t VehicleDescriptor_license_plate_LENGTH
>
class VehicleDescriptor final: public ::EmbeddedProto::MessageInterface
{
  public:
    VehicleDescriptor() = default;
    VehicleDescriptor(const VehicleDescriptor& rhs )
    {
      set_id(rhs.get_id());
      set_label(rhs.get_label());
      set_license_plate(rhs.get_license_plate());
    }

    VehicleDescriptor(const VehicleDescriptor&& rhs ) noexcept
    {
      set_id(rhs.get_id());
      set_label(rhs.get_label());
      set_license_plate(rhs.get_license_plate());
    }

    ~VehicleDescriptor() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      ID = 1,
      LABEL = 2,
      LICENSE_PLATE = 3
    };

    VehicleDescriptor& operator=(const VehicleDescriptor& rhs)
    {
      set_id(rhs.get_id());
      set_label(rhs.get_label());
      set_license_plate(rhs.get_license_plate());
      return *this;
    }

    VehicleDescriptor& operator=(const VehicleDescriptor&& rhs) noexcept
    {
      set_id(rhs.get_id());
      set_label(rhs.get_label());
      set_license_plate(rhs.get_license_plate());
      return *this;
    }

    static constexpr char const* ID_NAME = "id";
    inline void clear_id() { id_.clear(); }
    inline ::EmbeddedProto::FieldString<VehicleDescriptor_id_LENGTH>& mutable_id() { return id_; }
    inline void set_id(const ::EmbeddedProto::FieldString<VehicleDescriptor_id_LENGTH>& rhs) { id_.set(rhs); }
    inline const ::EmbeddedProto::FieldString<VehicleDescriptor_id_LENGTH>& get_id() const { return id_; }
    inline const char* id() const { return id_.get_const(); }

    static constexpr char const* LABEL_NAME = "label";
    inline void clear_label() { label_.clear(); }
    inline ::EmbeddedProto::FieldString<VehicleDescriptor_label_LENGTH>& mutable_label() { return label_; }
    inline void set_label(const ::EmbeddedProto::FieldString<VehicleDescriptor_label_LENGTH>& rhs) { label_.set(rhs); }
    inline const ::EmbeddedProto::FieldString<VehicleDescriptor_label_LENGTH>& get_label() const { return label_; }
    inline const char* label() const { return label_.get_const(); }

    static constexpr char const* LICENSE_PLATE_NAME = "license_plate";
    inline void clear_license_plate() { license_plate_.clear(); }
    inline ::EmbeddedProto::FieldString<VehicleDescriptor_license_plate_LENGTH>& mutable_license_plate() { return license_plate_; }
    inline void set_license_plate(const ::EmbeddedProto::FieldString<VehicleDescriptor_license_plate_LENGTH>& rhs) { license_plate_.set(rhs); }
    inline const ::EmbeddedProto::FieldString<VehicleDescriptor_license_plate_LENGTH>& get_license_plate() const { return license_plate_; }
    inline const char* license_plate() const { return license_plate_.get_const(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = id_.serialize_with_id(static_cast<uint32_t>(FieldNumber::ID), buffer, false);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = label_.serialize_with_id(static_cast<uint32_t>(FieldNumber::LABEL), buffer, false);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = license_plate_.serialize_with_id(static_cast<uint32_t>(FieldNumber::LICENSE_PLATE), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::ID:
            return_value = id_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::LABEL:
            return_value = label_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::LICENSE_PLATE:
            return_value = license_plate_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_id();
      clear_label();
      clear_license_plate();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::ID:
          name = ID_NAME;
          break;
        case FieldNumber::LABEL:
          name = LABEL_NAME;
          break;
        case FieldNumber::LICENSE_PLATE:
          name = LICENSE_PLATE_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#endif

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = id_.to_string(left_chars, indent_level + 2, ID_NAME, true);
      left_chars = label_.to_string(left_chars, indent_level + 2, LABEL_NAME, false);
      left_chars = license_plate_.to_string(left_chars, indent_level + 2, LICENSE_PLATE_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      ::EmbeddedProto::FieldString<VehicleDescriptor_id_LENGTH> id_;
      ::EmbeddedProto::FieldString<VehicleDescriptor_label_LENGTH> label_;
      ::EmbeddedProto::FieldString<VehicleDescriptor_license_plate_LENGTH> license_plate_;

};

template<
    uint32_t EntitySelector_agency_id_LENGTH, 
    uint32_t EntitySelector_route_id_LENGTH, 
    uint32_t EntitySelector_trip_TripDescriptor_trip_id_LENGTH, 
    uint32_t EntitySelector_trip_TripDescriptor_route_id_LENGTH, 
    uint32_t EntitySelector_trip_TripDescriptor_start_time_LENGTH, 
    uint32_t EntitySelector_trip_TripDescriptor_start_date_LENGTH, 
    uint32_t EntitySelector_stop_id_LENGTH
>
class EntitySelector final: public ::EmbeddedProto::MessageInterface
{
  public:
    EntitySelector() = default;
    EntitySelector(const EntitySelector& rhs )
    {
      set_agency_id(rhs.get_agency_id());
      set_route_id(rhs.get_route_id());
      set_route_type(rhs.get_route_type());
      set_trip(rhs.get_trip());
      set_stop_id(rhs.get_stop_id());
    }

    EntitySelector(const EntitySelector&& rhs ) noexcept
    {
      set_agency_id(rhs.get_agency_id());
      set_route_id(rhs.get_route_id());
      set_route_type(rhs.get_route_type());
      set_trip(rhs.get_trip());
      set_stop_id(rhs.get_stop_id());
    }

    ~EntitySelector() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      AGENCY_ID = 1,
      ROUTE_ID = 2,
      ROUTE_TYPE = 3,
      TRIP = 4,
      STOP_ID = 5
    };

    EntitySelector& operator=(const EntitySelector& rhs)
    {
      set_agency_id(rhs.get_agency_id());
      set_route_id(rhs.get_route_id());
      set_route_type(rhs.get_route_type());
      set_trip(rhs.get_trip());
      set_stop_id(rhs.get_stop_id());
      return *this;
    }

    EntitySelector& operator=(const EntitySelector&& rhs) noexcept
    {
      set_agency_id(rhs.get_agency_id());
      set_route_id(rhs.get_route_id());
      set_route_type(rhs.get_route_type());
      set_trip(rhs.get_trip());
      set_stop_id(rhs.get_stop_id());
      return *this;
    }

    static constexpr char const* AGENCY_ID_NAME = "agency_id";
    inline void clear_agency_id() { agency_id_.clear(); }
    inline ::EmbeddedProto::FieldString<EntitySelector_agency_id_LENGTH>& mutable_agency_id() { return agency_id_; }
    inline void set_agency_id(const ::EmbeddedProto::FieldString<EntitySelector_agency_id_LENGTH>& rhs) { agency_id_.set(rhs); }
    inline const ::EmbeddedProto::FieldString<EntitySelector_agency_id_LENGTH>& get_agency_id() const { return agency_id_; }
    inline const char* agency_id() const { return agency_id_.get_const(); }

    static constexpr char const* ROUTE_ID_NAME = "route_id";
    inline void clear_route_id() { route_id_.clear(); }
    inline ::EmbeddedProto::FieldString<EntitySelector_route_id_LENGTH>& mutable_route_id() { return route_id_; }
    inline void set_route_id(const ::EmbeddedProto::FieldString<EntitySelector_route_id_LENGTH>& rhs) { route_id_.set(rhs); }
    inline const ::EmbeddedProto::FieldString<EntitySelector_route_id_LENGTH>& get_route_id() const { return route_id_; }
    inline const char* route_id() const { return route_id_.get_const(); }

    static constexpr char const* ROUTE_TYPE_NAME = "route_type";
    inline void clear_route_type() { route_type_.clear(); }
    inline void set_route_type(const int32_t& value) { route_type_ = value; }
    inline void set_route_type(const int32_t&& value) { route_type_ = value; }
    inline int32_t& mutable_route_type() { return route_type_.get(); }
    inline const int32_t& get_route_type() const { return route_type_.get(); }
    inline int32_t route_type() const { return route_type_.get(); }

    static constexpr char const* TRIP_NAME = "trip";
    inline void clear_trip() { trip_.clear(); }
    inline void set_trip(const TripDescriptor<EntitySelector_trip_TripDescriptor_trip_id_LENGTH, EntitySelector_trip_TripDescriptor_route_id_LENGTH, EntitySelector_trip_TripDescriptor_start_time_LENGTH, EntitySelector_trip_TripDescriptor_start_date_LENGTH>& value) { trip_ = value; }
    inline void set_trip(const TripDescriptor<EntitySelector_trip_TripDescriptor_trip_id_LENGTH, EntitySelector_trip_TripDescriptor_route_id_LENGTH, EntitySelector_trip_TripDescriptor_start_time_LENGTH, EntitySelector_trip_TripDescriptor_start_date_LENGTH>&& value) { trip_ = value; }
    inline TripDescriptor<EntitySelector_trip_TripDescriptor_trip_id_LENGTH, EntitySelector_trip_TripDescriptor_route_id_LENGTH, EntitySelector_trip_TripDescriptor_start_time_LENGTH, EntitySelector_trip_TripDescriptor_start_date_LENGTH>& mutable_trip() { return trip_; }
    inline const TripDescriptor<EntitySelector_trip_TripDescriptor_trip_id_LENGTH, EntitySelector_trip_TripDescriptor_route_id_LENGTH, EntitySelector_trip_TripDescriptor_start_time_LENGTH, EntitySelector_trip_TripDescriptor_start_date_LENGTH>& get_trip() const { return trip_; }
    inline const TripDescriptor<EntitySelector_trip_TripDescriptor_trip_id_LENGTH, EntitySelector_trip_TripDescriptor_route_id_LENGTH, EntitySelector_trip_TripDescriptor_start_time_LENGTH, EntitySelector_trip_TripDescriptor_start_date_LENGTH>& trip() const { return trip_; }

    static constexpr char const* STOP_ID_NAME = "stop_id";
    inline void clear_stop_id() { stop_id_.clear(); }
    inline ::EmbeddedProto::FieldString<EntitySelector_stop_id_LENGTH>& mutable_stop_id() { return stop_id_; }
    inline void set_stop_id(const ::EmbeddedProto::FieldString<EntitySelector_stop_id_LENGTH>& rhs) { stop_id_.set(rhs); }
    inline const ::EmbeddedProto::FieldString<EntitySelector_stop_id_LENGTH>& get_stop_id() const { return stop_id_; }
    inline const char* stop_id() const { return stop_id_.get_const(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = agency_id_.serialize_with_id(static_cast<uint32_t>(FieldNumber::AGENCY_ID), buffer, false);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = route_id_.serialize_with_id(static_cast<uint32_t>(FieldNumber::ROUTE_ID), buffer, false);
      }

      if((0 != route_type_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = route_type_.serialize_with_id(static_cast<uint32_t>(FieldNumber::ROUTE_TYPE), buffer, false);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = trip_.serialize_with_id(static_cast<uint32_t>(FieldNumber::TRIP), buffer, false);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = stop_id_.serialize_with_id(static_cast<uint32_t>(FieldNumber::STOP_ID), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::AGENCY_ID:
            return_value = agency_id_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::ROUTE_ID:
            return_value = route_id_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::ROUTE_TYPE:
            return_value = route_type_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::TRIP:
            return_value = trip_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::STOP_ID:
            return_value = stop_id_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_agency_id();
      clear_route_id();
      clear_route_type();
      clear_trip();
      clear_stop_id();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::AGENCY_ID:
          name = AGENCY_ID_NAME;
          break;
        case FieldNumber::ROUTE_ID:
          name = ROUTE_ID_NAME;
          break;
        case FieldNumber::ROUTE_TYPE:
          name = ROUTE_TYPE_NAME;
          break;
        case FieldNumber::TRIP:
          name = TRIP_NAME;
          break;
        case FieldNumber::STOP_ID:
          name = STOP_ID_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#endif

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = agency_id_.to_string(left_chars, indent_level + 2, AGENCY_ID_NAME, true);
      left_chars = route_id_.to_string(left_chars, indent_level + 2, ROUTE_ID_NAME, false);
      left_chars = route_type_.to_string(left_chars, indent_level + 2, ROUTE_TYPE_NAME, false);
      left_chars = trip_.to_string(left_chars, indent_level + 2, TRIP_NAME, false);
      left_chars = stop_id_.to_string(left_chars, indent_level + 2, STOP_ID_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      ::EmbeddedProto::FieldString<EntitySelector_agency_id_LENGTH> agency_id_;
      ::EmbeddedProto::FieldString<EntitySelector_route_id_LENGTH> route_id_;
      EmbeddedProto::int32 route_type_ = 0;
      TripDescriptor<EntitySelector_trip_TripDescriptor_trip_id_LENGTH, EntitySelector_trip_TripDescriptor_route_id_LENGTH, EntitySelector_trip_TripDescriptor_start_time_LENGTH, EntitySelector_trip_TripDescriptor_start_date_LENGTH> trip_;
      ::EmbeddedProto::FieldString<EntitySelector_stop_id_LENGTH> stop_id_;

};

template<
    uint32_t TripUpdate_trip_TripDescriptor_trip_id_LENGTH, 
    uint32_t TripUpdate_trip_TripDescriptor_route_id_LENGTH, 
    uint32_t TripUpdate_trip_TripDescriptor_start_time_LENGTH, 
    uint32_t TripUpdate_trip_TripDescriptor_start_date_LENGTH, 
    uint32_t TripUpdate_vehicle_VehicleDescriptor_id_LENGTH, 
    uint32_t TripUpdate_vehicle_VehicleDescriptor_label_LENGTH, 
    uint32_t TripUpdate_vehicle_VehicleDescriptor_license_plate_LENGTH, 
    uint32_t TripUpdate_stop_time_update_REP_LENGTH, 
    uint32_t TripUpdate_stop_time_update_StopTimeUpdate_stop_id_LENGTH
>
class TripUpdate final: public ::EmbeddedProto::MessageInterface
{
  public:
    TripUpdate() = default;
    TripUpdate(const TripUpdate& rhs )
    {
      set_trip(rhs.get_trip());
      set_vehicle(rhs.get_vehicle());
      set_stop_time_update(rhs.get_stop_time_update());
      set_timestamp(rhs.get_timestamp());
      set_delay(rhs.get_delay());
    }

    TripUpdate(const TripUpdate&& rhs ) noexcept
    {
      set_trip(rhs.get_trip());
      set_vehicle(rhs.get_vehicle());
      set_stop_time_update(rhs.get_stop_time_update());
      set_timestamp(rhs.get_timestamp());
      set_delay(rhs.get_delay());
    }

    ~TripUpdate() override = default;

    class StopTimeEvent final: public ::EmbeddedProto::MessageInterface
    {
      public:
        StopTimeEvent() = default;
        StopTimeEvent(const StopTimeEvent& rhs )
        {
          set_delay(rhs.get_delay());
          set_time(rhs.get_time());
          set_uncertainty(rhs.get_uncertainty());
        }

        StopTimeEvent(const StopTimeEvent&& rhs ) noexcept
        {
          set_delay(rhs.get_delay());
          set_time(rhs.get_time());
          set_uncertainty(rhs.get_uncertainty());
        }

        ~StopTimeEvent() override = default;

        enum class FieldNumber : uint32_t
        {
          NOT_SET = 0,
          DELAY = 1,
          TIME = 2,
          UNCERTAINTY = 3
        };

        StopTimeEvent& operator=(const StopTimeEvent& rhs)
        {
          set_delay(rhs.get_delay());
          set_time(rhs.get_time());
          set_uncertainty(rhs.get_uncertainty());
          return *this;
        }

        StopTimeEvent& operator=(const StopTimeEvent&& rhs) noexcept
        {
          set_delay(rhs.get_delay());
          set_time(rhs.get_time());
          set_uncertainty(rhs.get_uncertainty());
          return *this;
        }

        static constexpr char const* DELAY_NAME = "delay";
        inline void clear_delay() { delay_.clear(); }
        inline void set_delay(const int32_t& value) { delay_ = value; }
        inline void set_delay(const int32_t&& value) { delay_ = value; }
        inline int32_t& mutable_delay() { return delay_.get(); }
        inline const int32_t& get_delay() const { return delay_.get(); }
        inline int32_t delay() const { return delay_.get(); }

        static constexpr char const* TIME_NAME = "time";
        inline void clear_time() { time_.clear(); }
        inline void set_time(const int64_t& value) { time_ = value; }
        inline void set_time(const int64_t&& value) { time_ = value; }
        inline int64_t& mutable_time() { return time_.get(); }
        inline const int64_t& get_time() const { return time_.get(); }
        inline int64_t time() const { return time_.get(); }

        static constexpr char const* UNCERTAINTY_NAME = "uncertainty";
        inline void clear_uncertainty() { uncertainty_.clear(); }
        inline void set_uncertainty(const int32_t& value) { uncertainty_ = value; }
        inline void set_uncertainty(const int32_t&& value) { uncertainty_ = value; }
        inline int32_t& mutable_uncertainty() { return uncertainty_.get(); }
        inline const int32_t& get_uncertainty() const { return uncertainty_.get(); }
        inline int32_t uncertainty() const { return uncertainty_.get(); }


        ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
        {
          ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

          if((0 != delay_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = delay_.serialize_with_id(static_cast<uint32_t>(FieldNumber::DELAY), buffer, false);
          }

          if((0 != time_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = time_.serialize_with_id(static_cast<uint32_t>(FieldNumber::TIME), buffer, false);
          }

          if((0 != uncertainty_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = uncertainty_.serialize_with_id(static_cast<uint32_t>(FieldNumber::UNCERTAINTY), buffer, false);
          }

          return return_value;
        };

        ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
        {
          ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
          ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
          uint32_t id_number = 0;
          FieldNumber id_tag = FieldNumber::NOT_SET;

          ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
          while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
          {
            id_tag = static_cast<FieldNumber>(id_number);
            switch(id_tag)
            {
              case FieldNumber::DELAY:
                return_value = delay_.deserialize_check_type(buffer, wire_type);
                break;

              case FieldNumber::TIME:
                return_value = time_.deserialize_check_type(buffer, wire_type);
                break;

              case FieldNumber::UNCERTAINTY:
                return_value = uncertainty_.deserialize_check_type(buffer, wire_type);
                break;

              case FieldNumber::NOT_SET:
                return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
                break;

              default:
                return_value = skip_unknown_field(buffer, wire_type);
                break;
            }

            if(::EmbeddedProto::Error::NO_ERRORS == return_value)
            {
              // Read the next tag.
              tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
            }
          }

          // When an error was detect while reading the tag but no other errors where found, set it in the return value.
          if((::EmbeddedProto::Error::NO_ERRORS == return_value)
             && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
             && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
          {
            return_value = tag_value;
          }

          return return_value;
        };

        void clear() override
        {
          clear_delay();
          clear_time();
          clear_uncertainty();

        }

    #ifndef DISABLE_FIELD_NUMBER_TO_NAME 

        static char const* field_number_to_name(const FieldNumber fieldNumber)
        {
          char const* name = nullptr;
          switch(fieldNumber)
          {
            case FieldNumber::DELAY:
              name = DELAY_NAME;
              break;
            case FieldNumber::TIME:
              name = TIME_NAME;
              break;
            case FieldNumber::UNCERTAINTY:
              name = UNCERTAINTY_NAME;
              break;
            default:
              name = "Invalid FieldNumber";
              break;
          }
          return name;
        }

    #endif

    #ifdef MSG_TO_STRING

        ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
        {
          return this->to_string(str, 0, nullptr, true);
        }

        ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
        {
          ::EmbeddedProto::string_view left_chars = str;
          int32_t n_chars_used = 0;

          if(!first_field)
          {
            // Add a comma behind the previous field.
            n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
            if(0 < n_chars_used)
            {
              // Update the character pointer and characters left in the array.
              left_chars.data += n_chars_used;
              left_chars.size -= n_chars_used;
            }
          }

          if(nullptr != name)
          {
            if( 0 == indent_level)
            {
              n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
            }
            else
            {
              n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
            }
          }
          else
          {
            if( 0 == indent_level)
            {
              n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
            }
            else
            {
              n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
            }
          }
          
          if(0 < n_chars_used)
          {
            left_chars.data += n_chars_used;
            left_chars.size -= n_chars_used;
          }

          left_chars = delay_.to_string(left_chars, indent_level + 2, DELAY_NAME, true);
          left_chars = time_.to_string(left_chars, indent_level + 2, TIME_NAME, false);
          left_chars = uncertainty_.to_string(left_chars, indent_level + 2, UNCERTAINTY_NAME, false);
      
          if( 0 == indent_level) 
          {
            n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
          }
          else 
          {
            n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
          }

          if(0 < n_chars_used)
          {
            left_chars.data += n_chars_used;
            left_chars.size -= n_chars_used;
          }

          return left_chars;
        }

    #endif // End of MSG_TO_STRING

      private:


          EmbeddedProto::int32 delay_ = 0;
          EmbeddedProto::int64 time_ = 0;
          EmbeddedProto::int32 uncertainty_ = 0;

    };

    template<
        uint32_t StopTimeUpdate_stop_id_LENGTH
    >
    class StopTimeUpdate final: public ::EmbeddedProto::MessageInterface
    {
      public:
        StopTimeUpdate() = default;
        StopTimeUpdate(const StopTimeUpdate& rhs )
        {
          set_stop_sequence(rhs.get_stop_sequence());
          set_stop_id(rhs.get_stop_id());
          set_arrival(rhs.get_arrival());
          set_departure(rhs.get_departure());
          set_schedule_relationship(rhs.get_schedule_relationship());
        }

        StopTimeUpdate(const StopTimeUpdate&& rhs ) noexcept
        {
          set_stop_sequence(rhs.get_stop_sequence());
          set_stop_id(rhs.get_stop_id());
          set_arrival(rhs.get_arrival());
          set_departure(rhs.get_departure());
          set_schedule_relationship(rhs.get_schedule_relationship());
        }

        ~StopTimeUpdate() override = default;

        enum class ScheduleRelationship : uint32_t
        {
          SCHEDULED = 0,
          SKIPPED = 1,
          NO_DATA = 2
        };

        enum class FieldNumber : uint32_t
        {
          NOT_SET = 0,
          STOP_SEQUENCE = 1,
          ARRIVAL = 2,
          DEPARTURE = 3,
          STOP_ID = 4,
          SCHEDULE_RELATIONSHIP = 5
        };

        StopTimeUpdate& operator=(const StopTimeUpdate& rhs)
        {
          set_stop_sequence(rhs.get_stop_sequence());
          set_stop_id(rhs.get_stop_id());
          set_arrival(rhs.get_arrival());
          set_departure(rhs.get_departure());
          set_schedule_relationship(rhs.get_schedule_relationship());
          return *this;
        }

        StopTimeUpdate& operator=(const StopTimeUpdate&& rhs) noexcept
        {
          set_stop_sequence(rhs.get_stop_sequence());
          set_stop_id(rhs.get_stop_id());
          set_arrival(rhs.get_arrival());
          set_departure(rhs.get_departure());
          set_schedule_relationship(rhs.get_schedule_relationship());
          return *this;
        }

        static constexpr char const* STOP_SEQUENCE_NAME = "stop_sequence";
        inline void clear_stop_sequence() { stop_sequence_.clear(); }
        inline void set_stop_sequence(const uint32_t& value) { stop_sequence_ = value; }
        inline void set_stop_sequence(const uint32_t&& value) { stop_sequence_ = value; }
        inline uint32_t& mutable_stop_sequence() { return stop_sequence_.get(); }
        inline const uint32_t& get_stop_sequence() const { return stop_sequence_.get(); }
        inline uint32_t stop_sequence() const { return stop_sequence_.get(); }

        static constexpr char const* STOP_ID_NAME = "stop_id";
        inline void clear_stop_id() { stop_id_.clear(); }
        inline ::EmbeddedProto::FieldString<StopTimeUpdate_stop_id_LENGTH>& mutable_stop_id() { return stop_id_; }
        inline void set_stop_id(const ::EmbeddedProto::FieldString<StopTimeUpdate_stop_id_LENGTH>& rhs) { stop_id_.set(rhs); }
        inline const ::EmbeddedProto::FieldString<StopTimeUpdate_stop_id_LENGTH>& get_stop_id() const { return stop_id_; }
        inline const char* stop_id() const { return stop_id_.get_const(); }

        static constexpr char const* ARRIVAL_NAME = "arrival";
        inline void clear_arrival() { arrival_.clear(); }
        inline void set_arrival(const StopTimeEvent& value) { arrival_ = value; }
        inline void set_arrival(const StopTimeEvent&& value) { arrival_ = value; }
        inline StopTimeEvent& mutable_arrival() { return arrival_; }
        inline const StopTimeEvent& get_arrival() const { return arrival_; }
        inline const StopTimeEvent& arrival() const { return arrival_; }

        static constexpr char const* DEPARTURE_NAME = "departure";
        inline void clear_departure() { departure_.clear(); }
        inline void set_departure(const StopTimeEvent& value) { departure_ = value; }
        inline void set_departure(const StopTimeEvent&& value) { departure_ = value; }
        inline StopTimeEvent& mutable_departure() { return departure_; }
        inline const StopTimeEvent& get_departure() const { return departure_; }
        inline const StopTimeEvent& departure() const { return departure_; }

        static constexpr char const* SCHEDULE_RELATIONSHIP_NAME = "schedule_relationship";
        inline void clear_schedule_relationship() { schedule_relationship_.clear(); }
        inline void set_schedule_relationship(const ScheduleRelationship& value) { schedule_relationship_ = value; }
        inline void set_schedule_relationship(const ScheduleRelationship&& value) { schedule_relationship_ = value; }
        inline const ScheduleRelationship& get_schedule_relationship() const { return schedule_relationship_.get(); }
        inline ScheduleRelationship schedule_relationship() const { return schedule_relationship_.get(); }


        ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
        {
          ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

          if((0U != stop_sequence_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = stop_sequence_.serialize_with_id(static_cast<uint32_t>(FieldNumber::STOP_SEQUENCE), buffer, false);
          }

          if(::EmbeddedProto::Error::NO_ERRORS == return_value)
          {
            return_value = stop_id_.serialize_with_id(static_cast<uint32_t>(FieldNumber::STOP_ID), buffer, false);
          }

          if(::EmbeddedProto::Error::NO_ERRORS == return_value)
          {
            return_value = arrival_.serialize_with_id(static_cast<uint32_t>(FieldNumber::ARRIVAL), buffer, false);
          }

          if(::EmbeddedProto::Error::NO_ERRORS == return_value)
          {
            return_value = departure_.serialize_with_id(static_cast<uint32_t>(FieldNumber::DEPARTURE), buffer, false);
          }

          if((static_cast<ScheduleRelationship>(0) != schedule_relationship_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = schedule_relationship_.serialize_with_id(static_cast<uint32_t>(FieldNumber::SCHEDULE_RELATIONSHIP), buffer, false);
          }

          return return_value;
        };

        ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
        {
          ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
          ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
          uint32_t id_number = 0;
          FieldNumber id_tag = FieldNumber::NOT_SET;

          ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
          while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
          {
            id_tag = static_cast<FieldNumber>(id_number);
            switch(id_tag)
            {
              case FieldNumber::STOP_SEQUENCE:
                return_value = stop_sequence_.deserialize_check_type(buffer, wire_type);
                break;

              case FieldNumber::STOP_ID:
                return_value = stop_id_.deserialize_check_type(buffer, wire_type);
                break;

              case FieldNumber::ARRIVAL:
                return_value = arrival_.deserialize_check_type(buffer, wire_type);
                break;

              case FieldNumber::DEPARTURE:
                return_value = departure_.deserialize_check_type(buffer, wire_type);
                break;

              case FieldNumber::SCHEDULE_RELATIONSHIP:
                return_value = schedule_relationship_.deserialize_check_type(buffer, wire_type);
                break;

              case FieldNumber::NOT_SET:
                return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
                break;

              default:
                return_value = skip_unknown_field(buffer, wire_type);
                break;
            }

            if(::EmbeddedProto::Error::NO_ERRORS == return_value)
            {
              // Read the next tag.
              tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
            }
          }

          // When an error was detect while reading the tag but no other errors where found, set it in the return value.
          if((::EmbeddedProto::Error::NO_ERRORS == return_value)
             && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
             && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
          {
            return_value = tag_value;
          }

          return return_value;
        };

        void clear() override
        {
          clear_stop_sequence();
          clear_stop_id();
          clear_arrival();
          clear_departure();
          clear_schedule_relationship();

        }

    #ifndef DISABLE_FIELD_NUMBER_TO_NAME 

        static char const* field_number_to_name(const FieldNumber fieldNumber)
        {
          char const* name = nullptr;
          switch(fieldNumber)
          {
            case FieldNumber::STOP_SEQUENCE:
              name = STOP_SEQUENCE_NAME;
              break;
            case FieldNumber::STOP_ID:
              name = STOP_ID_NAME;
              break;
            case FieldNumber::ARRIVAL:
              name = ARRIVAL_NAME;
              break;
            case FieldNumber::DEPARTURE:
              name = DEPARTURE_NAME;
              break;
            case FieldNumber::SCHEDULE_RELATIONSHIP:
              name = SCHEDULE_RELATIONSHIP_NAME;
              break;
            default:
              name = "Invalid FieldNumber";
              break;
          }
          return name;
        }

    #endif

    #ifdef MSG_TO_STRING

        ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
        {
          return this->to_string(str, 0, nullptr, true);
        }

        ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
        {
          ::EmbeddedProto::string_view left_chars = str;
          int32_t n_chars_used = 0;

          if(!first_field)
          {
            // Add a comma behind the previous field.
            n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
            if(0 < n_chars_used)
            {
              // Update the character pointer and characters left in the array.
              left_chars.data += n_chars_used;
              left_chars.size -= n_chars_used;
            }
          }

          if(nullptr != name)
          {
            if( 0 == indent_level)
            {
              n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
            }
            else
            {
              n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
            }
          }
          else
          {
            if( 0 == indent_level)
            {
              n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
            }
            else
            {
              n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
            }
          }
          
          if(0 < n_chars_used)
          {
            left_chars.data += n_chars_used;
            left_chars.size -= n_chars_used;
          }

          left_chars = stop_sequence_.to_string(left_chars, indent_level + 2, STOP_SEQUENCE_NAME, true);
          left_chars = stop_id_.to_string(left_chars, indent_level + 2, STOP_ID_NAME, false);
          left_chars = arrival_.to_string(left_chars, indent_level + 2, ARRIVAL_NAME, false);
          left_chars = departure_.to_string(left_chars, indent_level + 2, DEPARTURE_NAME, false);
          left_chars = schedule_relationship_.to_string(left_chars, indent_level + 2, SCHEDULE_RELATIONSHIP_NAME, false);
      
          if( 0 == indent_level) 
          {
            n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
          }
          else 
          {
            n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
          }

          if(0 < n_chars_used)
          {
            left_chars.data += n_chars_used;
            left_chars.size -= n_chars_used;
          }

          return left_chars;
        }

    #endif // End of MSG_TO_STRING

      private:


          EmbeddedProto::uint32 stop_sequence_ = 0U;
          ::EmbeddedProto::FieldString<StopTimeUpdate_stop_id_LENGTH> stop_id_;
          StopTimeEvent arrival_;
          StopTimeEvent departure_;
          EmbeddedProto::enumeration<ScheduleRelationship> schedule_relationship_ = static_cast<ScheduleRelationship>(0);

    };

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      TRIP = 1,
      STOP_TIME_UPDATE = 2,
      VEHICLE = 3,
      TIMESTAMP = 4,
      DELAY = 5
    };

    TripUpdate& operator=(const TripUpdate& rhs)
    {
      set_trip(rhs.get_trip());
      set_vehicle(rhs.get_vehicle());
      set_stop_time_update(rhs.get_stop_time_update());
      set_timestamp(rhs.get_timestamp());
      set_delay(rhs.get_delay());
      return *this;
    }

    TripUpdate& operator=(const TripUpdate&& rhs) noexcept
    {
      set_trip(rhs.get_trip());
      set_vehicle(rhs.get_vehicle());
      set_stop_time_update(rhs.get_stop_time_update());
      set_timestamp(rhs.get_timestamp());
      set_delay(rhs.get_delay());
      return *this;
    }

    static constexpr char const* TRIP_NAME = "trip";
    inline void clear_trip() { trip_.clear(); }
    inline void set_trip(const TripDescriptor<TripUpdate_trip_TripDescriptor_trip_id_LENGTH, TripUpdate_trip_TripDescriptor_route_id_LENGTH, TripUpdate_trip_TripDescriptor_start_time_LENGTH, TripUpdate_trip_TripDescriptor_start_date_LENGTH>& value) { trip_ = value; }
    inline void set_trip(const TripDescriptor<TripUpdate_trip_TripDescriptor_trip_id_LENGTH, TripUpdate_trip_TripDescriptor_route_id_LENGTH, TripUpdate_trip_TripDescriptor_start_time_LENGTH, TripUpdate_trip_TripDescriptor_start_date_LENGTH>&& value) { trip_ = value; }
    inline TripDescriptor<TripUpdate_trip_TripDescriptor_trip_id_LENGTH, TripUpdate_trip_TripDescriptor_route_id_LENGTH, TripUpdate_trip_TripDescriptor_start_time_LENGTH, TripUpdate_trip_TripDescriptor_start_date_LENGTH>& mutable_trip() { return trip_; }
    inline const TripDescriptor<TripUpdate_trip_TripDescriptor_trip_id_LENGTH, TripUpdate_trip_TripDescriptor_route_id_LENGTH, TripUpdate_trip_TripDescriptor_start_time_LENGTH, TripUpdate_trip_TripDescriptor_start_date_LENGTH>& get_trip() const { return trip_; }
    inline const TripDescriptor<TripUpdate_trip_TripDescriptor_trip_id_LENGTH, TripUpdate_trip_TripDescriptor_route_id_LENGTH, TripUpdate_trip_TripDescriptor_start_time_LENGTH, TripUpdate_trip_TripDescriptor_start_date_LENGTH>& trip() const { return trip_; }

    static constexpr char const* VEHICLE_NAME = "vehicle";
    inline void clear_vehicle() { vehicle_.clear(); }
    inline void set_vehicle(const VehicleDescriptor<TripUpdate_vehicle_VehicleDescriptor_id_LENGTH, TripUpdate_vehicle_VehicleDescriptor_label_LENGTH, TripUpdate_vehicle_VehicleDescriptor_license_plate_LENGTH>& value) { vehicle_ = value; }
    inline void set_vehicle(const VehicleDescriptor<TripUpdate_vehicle_VehicleDescriptor_id_LENGTH, TripUpdate_vehicle_VehicleDescriptor_label_LENGTH, TripUpdate_vehicle_VehicleDescriptor_license_plate_LENGTH>&& value) { vehicle_ = value; }
    inline VehicleDescriptor<TripUpdate_vehicle_VehicleDescriptor_id_LENGTH, TripUpdate_vehicle_VehicleDescriptor_label_LENGTH, TripUpdate_vehicle_VehicleDescriptor_license_plate_LENGTH>& mutable_vehicle() { return vehicle_; }
    inline const VehicleDescriptor<TripUpdate_vehicle_VehicleDescriptor_id_LENGTH, TripUpdate_vehicle_VehicleDescriptor_label_LENGTH, TripUpdate_vehicle_VehicleDescriptor_license_plate_LENGTH>& get_vehicle() const { return vehicle_; }
    inline const VehicleDescriptor<TripUpdate_vehicle_VehicleDescriptor_id_LENGTH, TripUpdate_vehicle_VehicleDescriptor_label_LENGTH, TripUpdate_vehicle_VehicleDescriptor_license_plate_LENGTH>& vehicle() const { return vehicle_; }

    static constexpr char const* STOP_TIME_UPDATE_NAME = "stop_time_update";
    inline const StopTimeUpdate<TripUpdate_stop_time_update_StopTimeUpdate_stop_id_LENGTH>& stop_time_update(uint32_t index) const { return stop_time_update_[index]; }
    inline void clear_stop_time_update() { stop_time_update_.clear(); }
    inline void set_stop_time_update(uint32_t index, const StopTimeUpdate<TripUpdate_stop_time_update_StopTimeUpdate_stop_id_LENGTH>& value) { stop_time_update_.set(index, value); }
    inline void set_stop_time_update(uint32_t index, const StopTimeUpdate<TripUpdate_stop_time_update_StopTimeUpdate_stop_id_LENGTH>&& value) { stop_time_update_.set(index, value); }
    inline void set_stop_time_update(const ::EmbeddedProto::RepeatedFieldFixedSize<StopTimeUpdate<TripUpdate_stop_time_update_StopTimeUpdate_stop_id_LENGTH>, TripUpdate_stop_time_update_REP_LENGTH>& values) { stop_time_update_ = values; }
    inline void add_stop_time_update(const StopTimeUpdate<TripUpdate_stop_time_update_StopTimeUpdate_stop_id_LENGTH>& value) { stop_time_update_.add(value); }
    inline ::EmbeddedProto::RepeatedFieldFixedSize<StopTimeUpdate<TripUpdate_stop_time_update_StopTimeUpdate_stop_id_LENGTH>, TripUpdate_stop_time_update_REP_LENGTH>& mutable_stop_time_update() { return stop_time_update_; }
    inline StopTimeUpdate<TripUpdate_stop_time_update_StopTimeUpdate_stop_id_LENGTH>& mutable_stop_time_update(uint32_t index) { return stop_time_update_[index]; }
    inline const ::EmbeddedProto::RepeatedFieldFixedSize<StopTimeUpdate<TripUpdate_stop_time_update_StopTimeUpdate_stop_id_LENGTH>, TripUpdate_stop_time_update_REP_LENGTH>& get_stop_time_update() const { return stop_time_update_; }
    inline const ::EmbeddedProto::RepeatedFieldFixedSize<StopTimeUpdate<TripUpdate_stop_time_update_StopTimeUpdate_stop_id_LENGTH>, TripUpdate_stop_time_update_REP_LENGTH>& stop_time_update() const { return stop_time_update_; }

    static constexpr char const* TIMESTAMP_NAME = "timestamp";
    inline void clear_timestamp() { timestamp_.clear(); }
    inline void set_timestamp(const uint64_t& value) { timestamp_ = value; }
    inline void set_timestamp(const uint64_t&& value) { timestamp_ = value; }
    inline uint64_t& mutable_timestamp() { return timestamp_.get(); }
    inline const uint64_t& get_timestamp() const { return timestamp_.get(); }
    inline uint64_t timestamp() const { return timestamp_.get(); }

    static constexpr char const* DELAY_NAME = "delay";
    inline void clear_delay() { delay_.clear(); }
    inline void set_delay(const int32_t& value) { delay_ = value; }
    inline void set_delay(const int32_t&& value) { delay_ = value; }
    inline int32_t& mutable_delay() { return delay_.get(); }
    inline const int32_t& get_delay() const { return delay_.get(); }
    inline int32_t delay() const { return delay_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = trip_.serialize_with_id(static_cast<uint32_t>(FieldNumber::TRIP), buffer, false);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = vehicle_.serialize_with_id(static_cast<uint32_t>(FieldNumber::VEHICLE), buffer, false);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = stop_time_update_.serialize_with_id(static_cast<uint32_t>(FieldNumber::STOP_TIME_UPDATE), buffer, false);
      }

      if((0U != timestamp_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = timestamp_.serialize_with_id(static_cast<uint32_t>(FieldNumber::TIMESTAMP), buffer, false);
      }

      if((0 != delay_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = delay_.serialize_with_id(static_cast<uint32_t>(FieldNumber::DELAY), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::TRIP:
            return_value = trip_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::VEHICLE:
            return_value = vehicle_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::STOP_TIME_UPDATE:
            return_value = stop_time_update_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::TIMESTAMP:
            return_value = timestamp_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::DELAY:
            return_value = delay_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_trip();
      clear_vehicle();
      clear_stop_time_update();
      clear_timestamp();
      clear_delay();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::TRIP:
          name = TRIP_NAME;
          break;
        case FieldNumber::VEHICLE:
          name = VEHICLE_NAME;
          break;
        case FieldNumber::STOP_TIME_UPDATE:
          name = STOP_TIME_UPDATE_NAME;
          break;
        case FieldNumber::TIMESTAMP:
          name = TIMESTAMP_NAME;
          break;
        case FieldNumber::DELAY:
          name = DELAY_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#endif

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = trip_.to_string(left_chars, indent_level + 2, TRIP_NAME, true);
      left_chars = vehicle_.to_string(left_chars, indent_level + 2, VEHICLE_NAME, false);
      left_chars = stop_time_update_.to_string(left_chars, indent_level + 2, STOP_TIME_UPDATE_NAME, false);
      left_chars = timestamp_.to_string(left_chars, indent_level + 2, TIMESTAMP_NAME, false);
      left_chars = delay_.to_string(left_chars, indent_level + 2, DELAY_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      TripDescriptor<TripUpdate_trip_TripDescriptor_trip_id_LENGTH, TripUpdate_trip_TripDescriptor_route_id_LENGTH, TripUpdate_trip_TripDescriptor_start_time_LENGTH, TripUpdate_trip_TripDescriptor_start_date_LENGTH> trip_;
      VehicleDescriptor<TripUpdate_vehicle_VehicleDescriptor_id_LENGTH, TripUpdate_vehicle_VehicleDescriptor_label_LENGTH, TripUpdate_vehicle_VehicleDescriptor_license_plate_LENGTH> vehicle_;
      ::EmbeddedProto::RepeatedFieldFixedSize<StopTimeUpdate<TripUpdate_stop_time_update_StopTimeUpdate_stop_id_LENGTH>, TripUpdate_stop_time_update_REP_LENGTH> stop_time_update_;
      EmbeddedProto::uint64 timestamp_ = 0U;
      EmbeddedProto::int32 delay_ = 0;

};

template<
    uint32_t VehiclePosition_trip_TripDescriptor_trip_id_LENGTH, 
    uint32_t VehiclePosition_trip_TripDescriptor_route_id_LENGTH, 
    uint32_t VehiclePosition_trip_TripDescriptor_start_time_LENGTH, 
    uint32_t VehiclePosition_trip_TripDescriptor_start_date_LENGTH, 
    uint32_t VehiclePosition_vehicle_VehicleDescriptor_id_LENGTH, 
    uint32_t VehiclePosition_vehicle_VehicleDescriptor_label_LENGTH, 
    uint32_t VehiclePosition_vehicle_VehicleDescriptor_license_plate_LENGTH, 
    uint32_t VehiclePosition_stop_id_LENGTH
>
class VehiclePosition final: public ::EmbeddedProto::MessageInterface
{
  public:
    VehiclePosition() = default;
    VehiclePosition(const VehiclePosition& rhs )
    {
      set_trip(rhs.get_trip());
      set_vehicle(rhs.get_vehicle());
      set_position(rhs.get_position());
      set_current_stop_sequence(rhs.get_current_stop_sequence());
      set_stop_id(rhs.get_stop_id());
      set_current_status(rhs.get_current_status());
      set_timestamp(rhs.get_timestamp());
      set_congestion_level(rhs.get_congestion_level());
      set_occupancy_status(rhs.get_occupancy_status());
    }

    VehiclePosition(const VehiclePosition&& rhs ) noexcept
    {
      set_trip(rhs.get_trip());
      set_vehicle(rhs.get_vehicle());
      set_position(rhs.get_position());
      set_current_stop_sequence(rhs.get_current_stop_sequence());
      set_stop_id(rhs.get_stop_id());
      set_current_status(rhs.get_current_status());
      set_timestamp(rhs.get_timestamp());
      set_congestion_level(rhs.get_congestion_level());
      set_occupancy_status(rhs.get_occupancy_status());
    }

    ~VehiclePosition() override = default;

    enum class VehicleStopStatus : uint32_t
    {
      INCOMING_AT = 0,
      STOPPED_AT = 1,
      IN_TRANSIT_TO = 2
    };

    enum class CongestionLevel : uint32_t
    {
      UNKNOWN_CONGESTION_LEVEL = 0,
      RUNNING_SMOOTHLY = 1,
      STOP_AND_GO = 2,
      CONGESTION = 3,
      SEVERE_CONGESTION = 4
    };

    enum class OccupancyStatus : uint32_t
    {
      EMPTY = 0,
      MANY_SEATS_AVAILABLE = 1,
      FEW_SEATS_AVAILABLE = 2,
      STANDING_ROOM_ONLY = 3,
      CRUSHED_STANDING_ROOM_ONLY = 4,
      FULL = 5,
      NOT_ACCEPTING_PASSENGERS = 6
    };

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      TRIP = 1,
      POSITION = 2,
      CURRENT_STOP_SEQUENCE = 3,
      CURRENT_STATUS = 4,
      TIMESTAMP = 5,
      CONGESTION_LEVEL = 6,
      STOP_ID = 7,
      VEHICLE = 8,
      OCCUPANCY_STATUS = 9
    };

    VehiclePosition& operator=(const VehiclePosition& rhs)
    {
      set_trip(rhs.get_trip());
      set_vehicle(rhs.get_vehicle());
      set_position(rhs.get_position());
      set_current_stop_sequence(rhs.get_current_stop_sequence());
      set_stop_id(rhs.get_stop_id());
      set_current_status(rhs.get_current_status());
      set_timestamp(rhs.get_timestamp());
      set_congestion_level(rhs.get_congestion_level());
      set_occupancy_status(rhs.get_occupancy_status());
      return *this;
    }

    VehiclePosition& operator=(const VehiclePosition&& rhs) noexcept
    {
      set_trip(rhs.get_trip());
      set_vehicle(rhs.get_vehicle());
      set_position(rhs.get_position());
      set_current_stop_sequence(rhs.get_current_stop_sequence());
      set_stop_id(rhs.get_stop_id());
      set_current_status(rhs.get_current_status());
      set_timestamp(rhs.get_timestamp());
      set_congestion_level(rhs.get_congestion_level());
      set_occupancy_status(rhs.get_occupancy_status());
      return *this;
    }

    static constexpr char const* TRIP_NAME = "trip";
    inline void clear_trip() { trip_.clear(); }
    inline void set_trip(const TripDescriptor<VehiclePosition_trip_TripDescriptor_trip_id_LENGTH, VehiclePosition_trip_TripDescriptor_route_id_LENGTH, VehiclePosition_trip_TripDescriptor_start_time_LENGTH, VehiclePosition_trip_TripDescriptor_start_date_LENGTH>& value) { trip_ = value; }
    inline void set_trip(const TripDescriptor<VehiclePosition_trip_TripDescriptor_trip_id_LENGTH, VehiclePosition_trip_TripDescriptor_route_id_LENGTH, VehiclePosition_trip_TripDescriptor_start_time_LENGTH, VehiclePosition_trip_TripDescriptor_start_date_LENGTH>&& value) { trip_ = value; }
    inline TripDescriptor<VehiclePosition_trip_TripDescriptor_trip_id_LENGTH, VehiclePosition_trip_TripDescriptor_route_id_LENGTH, VehiclePosition_trip_TripDescriptor_start_time_LENGTH, VehiclePosition_trip_TripDescriptor_start_date_LENGTH>& mutable_trip() { return trip_; }
    inline const TripDescriptor<VehiclePosition_trip_TripDescriptor_trip_id_LENGTH, VehiclePosition_trip_TripDescriptor_route_id_LENGTH, VehiclePosition_trip_TripDescriptor_start_time_LENGTH, VehiclePosition_trip_TripDescriptor_start_date_LENGTH>& get_trip() const { return trip_; }
    inline const TripDescriptor<VehiclePosition_trip_TripDescriptor_trip_id_LENGTH, VehiclePosition_trip_TripDescriptor_route_id_LENGTH, VehiclePosition_trip_TripDescriptor_start_time_LENGTH, VehiclePosition_trip_TripDescriptor_start_date_LENGTH>& trip() const { return trip_; }

    static constexpr char const* VEHICLE_NAME = "vehicle";
    inline void clear_vehicle() { vehicle_.clear(); }
    inline void set_vehicle(const VehicleDescriptor<VehiclePosition_vehicle_VehicleDescriptor_id_LENGTH, VehiclePosition_vehicle_VehicleDescriptor_label_LENGTH, VehiclePosition_vehicle_VehicleDescriptor_license_plate_LENGTH>& value) { vehicle_ = value; }
    inline void set_vehicle(const VehicleDescriptor<VehiclePosition_vehicle_VehicleDescriptor_id_LENGTH, VehiclePosition_vehicle_VehicleDescriptor_label_LENGTH, VehiclePosition_vehicle_VehicleDescriptor_license_plate_LENGTH>&& value) { vehicle_ = value; }
    inline VehicleDescriptor<VehiclePosition_vehicle_VehicleDescriptor_id_LENGTH, VehiclePosition_vehicle_VehicleDescriptor_label_LENGTH, VehiclePosition_vehicle_VehicleDescriptor_license_plate_LENGTH>& mutable_vehicle() { return vehicle_; }
    inline const VehicleDescriptor<VehiclePosition_vehicle_VehicleDescriptor_id_LENGTH, VehiclePosition_vehicle_VehicleDescriptor_label_LENGTH, VehiclePosition_vehicle_VehicleDescriptor_license_plate_LENGTH>& get_vehicle() const { return vehicle_; }
    inline const VehicleDescriptor<VehiclePosition_vehicle_VehicleDescriptor_id_LENGTH, VehiclePosition_vehicle_VehicleDescriptor_label_LENGTH, VehiclePosition_vehicle_VehicleDescriptor_license_plate_LENGTH>& vehicle() const { return vehicle_; }

    static constexpr char const* POSITION_NAME = "position";
    inline void clear_position() { position_.clear(); }
    inline void set_position(const Position& value) { position_ = value; }
    inline void set_position(const Position&& value) { position_ = value; }
    inline Position& mutable_position() { return position_; }
    inline const Position& get_position() const { return position_; }
    inline const Position& position() const { return position_; }

    static constexpr char const* CURRENT_STOP_SEQUENCE_NAME = "current_stop_sequence";
    inline void clear_current_stop_sequence() { current_stop_sequence_.clear(); }
    inline void set_current_stop_sequence(const uint32_t& value) { current_stop_sequence_ = value; }
    inline void set_current_stop_sequence(const uint32_t&& value) { current_stop_sequence_ = value; }
    inline uint32_t& mutable_current_stop_sequence() { return current_stop_sequence_.get(); }
    inline const uint32_t& get_current_stop_sequence() const { return current_stop_sequence_.get(); }
    inline uint32_t current_stop_sequence() const { return current_stop_sequence_.get(); }

    static constexpr char const* STOP_ID_NAME = "stop_id";
    inline void clear_stop_id() { stop_id_.clear(); }
    inline ::EmbeddedProto::FieldString<VehiclePosition_stop_id_LENGTH>& mutable_stop_id() { return stop_id_; }
    inline void set_stop_id(const ::EmbeddedProto::FieldString<VehiclePosition_stop_id_LENGTH>& rhs) { stop_id_.set(rhs); }
    inline const ::EmbeddedProto::FieldString<VehiclePosition_stop_id_LENGTH>& get_stop_id() const { return stop_id_; }
    inline const char* stop_id() const { return stop_id_.get_const(); }

    static constexpr char const* CURRENT_STATUS_NAME = "current_status";
    inline void clear_current_status() { current_status_.clear(); }
    inline void set_current_status(const VehicleStopStatus& value) { current_status_ = value; }
    inline void set_current_status(const VehicleStopStatus&& value) { current_status_ = value; }
    inline const VehicleStopStatus& get_current_status() const { return current_status_.get(); }
    inline VehicleStopStatus current_status() const { return current_status_.get(); }

    static constexpr char const* TIMESTAMP_NAME = "timestamp";
    inline void clear_timestamp() { timestamp_.clear(); }
    inline void set_timestamp(const uint64_t& value) { timestamp_ = value; }
    inline void set_timestamp(const uint64_t&& value) { timestamp_ = value; }
    inline uint64_t& mutable_timestamp() { return timestamp_.get(); }
    inline const uint64_t& get_timestamp() const { return timestamp_.get(); }
    inline uint64_t timestamp() const { return timestamp_.get(); }

    static constexpr char const* CONGESTION_LEVEL_NAME = "congestion_level";
    inline void clear_congestion_level() { congestion_level_.clear(); }
    inline void set_congestion_level(const CongestionLevel& value) { congestion_level_ = value; }
    inline void set_congestion_level(const CongestionLevel&& value) { congestion_level_ = value; }
    inline const CongestionLevel& get_congestion_level() const { return congestion_level_.get(); }
    inline CongestionLevel congestion_level() const { return congestion_level_.get(); }

    static constexpr char const* OCCUPANCY_STATUS_NAME = "occupancy_status";
    inline void clear_occupancy_status() { occupancy_status_.clear(); }
    inline void set_occupancy_status(const OccupancyStatus& value) { occupancy_status_ = value; }
    inline void set_occupancy_status(const OccupancyStatus&& value) { occupancy_status_ = value; }
    inline const OccupancyStatus& get_occupancy_status() const { return occupancy_status_.get(); }
    inline OccupancyStatus occupancy_status() const { return occupancy_status_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = trip_.serialize_with_id(static_cast<uint32_t>(FieldNumber::TRIP), buffer, false);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = vehicle_.serialize_with_id(static_cast<uint32_t>(FieldNumber::VEHICLE), buffer, false);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = position_.serialize_with_id(static_cast<uint32_t>(FieldNumber::POSITION), buffer, false);
      }

      if((0U != current_stop_sequence_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = current_stop_sequence_.serialize_with_id(static_cast<uint32_t>(FieldNumber::CURRENT_STOP_SEQUENCE), buffer, false);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = stop_id_.serialize_with_id(static_cast<uint32_t>(FieldNumber::STOP_ID), buffer, false);
      }

      if((static_cast<VehicleStopStatus>(0) != current_status_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = current_status_.serialize_with_id(static_cast<uint32_t>(FieldNumber::CURRENT_STATUS), buffer, false);
      }

      if((0U != timestamp_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = timestamp_.serialize_with_id(static_cast<uint32_t>(FieldNumber::TIMESTAMP), buffer, false);
      }

      if((static_cast<CongestionLevel>(0) != congestion_level_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = congestion_level_.serialize_with_id(static_cast<uint32_t>(FieldNumber::CONGESTION_LEVEL), buffer, false);
      }

      if((static_cast<OccupancyStatus>(0) != occupancy_status_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = occupancy_status_.serialize_with_id(static_cast<uint32_t>(FieldNumber::OCCUPANCY_STATUS), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::TRIP:
            return_value = trip_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::VEHICLE:
            return_value = vehicle_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::POSITION:
            return_value = position_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::CURRENT_STOP_SEQUENCE:
            return_value = current_stop_sequence_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::STOP_ID:
            return_value = stop_id_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::CURRENT_STATUS:
            return_value = current_status_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::TIMESTAMP:
            return_value = timestamp_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::CONGESTION_LEVEL:
            return_value = congestion_level_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::OCCUPANCY_STATUS:
            return_value = occupancy_status_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_trip();
      clear_vehicle();
      clear_position();
      clear_current_stop_sequence();
      clear_stop_id();
      clear_current_status();
      clear_timestamp();
      clear_congestion_level();
      clear_occupancy_status();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::TRIP:
          name = TRIP_NAME;
          break;
        case FieldNumber::VEHICLE:
          name = VEHICLE_NAME;
          break;
        case FieldNumber::POSITION:
          name = POSITION_NAME;
          break;
        case FieldNumber::CURRENT_STOP_SEQUENCE:
          name = CURRENT_STOP_SEQUENCE_NAME;
          break;
        case FieldNumber::STOP_ID:
          name = STOP_ID_NAME;
          break;
        case FieldNumber::CURRENT_STATUS:
          name = CURRENT_STATUS_NAME;
          break;
        case FieldNumber::TIMESTAMP:
          name = TIMESTAMP_NAME;
          break;
        case FieldNumber::CONGESTION_LEVEL:
          name = CONGESTION_LEVEL_NAME;
          break;
        case FieldNumber::OCCUPANCY_STATUS:
          name = OCCUPANCY_STATUS_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#endif

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = trip_.to_string(left_chars, indent_level + 2, TRIP_NAME, true);
      left_chars = vehicle_.to_string(left_chars, indent_level + 2, VEHICLE_NAME, false);
      left_chars = position_.to_string(left_chars, indent_level + 2, POSITION_NAME, false);
      left_chars = current_stop_sequence_.to_string(left_chars, indent_level + 2, CURRENT_STOP_SEQUENCE_NAME, false);
      left_chars = stop_id_.to_string(left_chars, indent_level + 2, STOP_ID_NAME, false);
      left_chars = current_status_.to_string(left_chars, indent_level + 2, CURRENT_STATUS_NAME, false);
      left_chars = timestamp_.to_string(left_chars, indent_level + 2, TIMESTAMP_NAME, false);
      left_chars = congestion_level_.to_string(left_chars, indent_level + 2, CONGESTION_LEVEL_NAME, false);
      left_chars = occupancy_status_.to_string(left_chars, indent_level + 2, OCCUPANCY_STATUS_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      TripDescriptor<VehiclePosition_trip_TripDescriptor_trip_id_LENGTH, VehiclePosition_trip_TripDescriptor_route_id_LENGTH, VehiclePosition_trip_TripDescriptor_start_time_LENGTH, VehiclePosition_trip_TripDescriptor_start_date_LENGTH> trip_;
      VehicleDescriptor<VehiclePosition_vehicle_VehicleDescriptor_id_LENGTH, VehiclePosition_vehicle_VehicleDescriptor_label_LENGTH, VehiclePosition_vehicle_VehicleDescriptor_license_plate_LENGTH> vehicle_;
      Position position_;
      EmbeddedProto::uint32 current_stop_sequence_ = 0U;
      ::EmbeddedProto::FieldString<VehiclePosition_stop_id_LENGTH> stop_id_;
      EmbeddedProto::enumeration<VehicleStopStatus> current_status_ = static_cast<VehicleStopStatus>(0);
      EmbeddedProto::uint64 timestamp_ = 0U;
      EmbeddedProto::enumeration<CongestionLevel> congestion_level_ = static_cast<CongestionLevel>(0);
      EmbeddedProto::enumeration<OccupancyStatus> occupancy_status_ = static_cast<OccupancyStatus>(0);

};

template<
    uint32_t Alert_active_period_REP_LENGTH, 
    uint32_t Alert_informed_entity_REP_LENGTH, 
    uint32_t Alert_informed_entity_EntitySelector_agency_id_LENGTH, 
    uint32_t Alert_informed_entity_EntitySelector_route_id_LENGTH, 
    uint32_t Alert_informed_entity_EntitySelector_trip_TripDescriptor_trip_id_LENGTH, 
    uint32_t Alert_informed_entity_EntitySelector_trip_TripDescriptor_route_id_LENGTH, 
    uint32_t Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_time_LENGTH, 
    uint32_t Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_date_LENGTH, 
    uint32_t Alert_informed_entity_EntitySelector_stop_id_LENGTH, 
    uint32_t Alert_url_TranslatedString_translation_REP_LENGTH, 
    uint32_t Alert_url_TranslatedString_translation_Translation_text_LENGTH, 
    uint32_t Alert_url_TranslatedString_translation_Translation_language_LENGTH, 
    uint32_t Alert_header_text_TranslatedString_translation_REP_LENGTH, 
    uint32_t Alert_header_text_TranslatedString_translation_Translation_text_LENGTH, 
    uint32_t Alert_header_text_TranslatedString_translation_Translation_language_LENGTH, 
    uint32_t Alert_description_text_TranslatedString_translation_REP_LENGTH, 
    uint32_t Alert_description_text_TranslatedString_translation_Translation_text_LENGTH, 
    uint32_t Alert_description_text_TranslatedString_translation_Translation_language_LENGTH
>
class Alert final: public ::EmbeddedProto::MessageInterface
{
  public:
    Alert() = default;
    Alert(const Alert& rhs )
    {
      set_active_period(rhs.get_active_period());
      set_informed_entity(rhs.get_informed_entity());
      set_cause(rhs.get_cause());
      set_effect(rhs.get_effect());
      set_url(rhs.get_url());
      set_header_text(rhs.get_header_text());
      set_description_text(rhs.get_description_text());
    }

    Alert(const Alert&& rhs ) noexcept
    {
      set_active_period(rhs.get_active_period());
      set_informed_entity(rhs.get_informed_entity());
      set_cause(rhs.get_cause());
      set_effect(rhs.get_effect());
      set_url(rhs.get_url());
      set_header_text(rhs.get_header_text());
      set_description_text(rhs.get_description_text());
    }

    ~Alert() override = default;

    enum class Cause : uint32_t
    {
      UNKNOWN_CAUSE = 1,
      OTHER_CAUSE = 2,
      TECHNICAL_PROBLEM = 3,
      STRIKE = 4,
      DEMONSTRATION = 5,
      ACCIDENT = 6,
      HOLIDAY = 7,
      WEATHER = 8,
      MAINTENANCE = 9,
      CONSTRUCTION = 10,
      POLICE_ACTIVITY = 11,
      MEDICAL_EMERGENCY = 12
    };

    enum class Effect : uint32_t
    {
      NO_SERVICE = 1,
      REDUCED_SERVICE = 2,
      SIGNIFICANT_DELAYS = 3,
      DETOUR = 4,
      ADDITIONAL_SERVICE = 5,
      MODIFIED_SERVICE = 6,
      OTHER_EFFECT = 7,
      UNKNOWN_EFFECT = 8,
      STOP_MOVED = 9
    };

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      ACTIVE_PERIOD = 1,
      INFORMED_ENTITY = 5,
      CAUSE = 6,
      EFFECT = 7,
      URL = 8,
      HEADER_TEXT = 10,
      DESCRIPTION_TEXT = 11
    };

    Alert& operator=(const Alert& rhs)
    {
      set_active_period(rhs.get_active_period());
      set_informed_entity(rhs.get_informed_entity());
      set_cause(rhs.get_cause());
      set_effect(rhs.get_effect());
      set_url(rhs.get_url());
      set_header_text(rhs.get_header_text());
      set_description_text(rhs.get_description_text());
      return *this;
    }

    Alert& operator=(const Alert&& rhs) noexcept
    {
      set_active_period(rhs.get_active_period());
      set_informed_entity(rhs.get_informed_entity());
      set_cause(rhs.get_cause());
      set_effect(rhs.get_effect());
      set_url(rhs.get_url());
      set_header_text(rhs.get_header_text());
      set_description_text(rhs.get_description_text());
      return *this;
    }

    static constexpr char const* ACTIVE_PERIOD_NAME = "active_period";
    inline const TimeRange& active_period(uint32_t index) const { return active_period_[index]; }
    inline void clear_active_period() { active_period_.clear(); }
    inline void set_active_period(uint32_t index, const TimeRange& value) { active_period_.set(index, value); }
    inline void set_active_period(uint32_t index, const TimeRange&& value) { active_period_.set(index, value); }
    inline void set_active_period(const ::EmbeddedProto::RepeatedFieldFixedSize<TimeRange, Alert_active_period_REP_LENGTH>& values) { active_period_ = values; }
    inline void add_active_period(const TimeRange& value) { active_period_.add(value); }
    inline ::EmbeddedProto::RepeatedFieldFixedSize<TimeRange, Alert_active_period_REP_LENGTH>& mutable_active_period() { return active_period_; }
    inline TimeRange& mutable_active_period(uint32_t index) { return active_period_[index]; }
    inline const ::EmbeddedProto::RepeatedFieldFixedSize<TimeRange, Alert_active_period_REP_LENGTH>& get_active_period() const { return active_period_; }
    inline const ::EmbeddedProto::RepeatedFieldFixedSize<TimeRange, Alert_active_period_REP_LENGTH>& active_period() const { return active_period_; }

    static constexpr char const* INFORMED_ENTITY_NAME = "informed_entity";
    inline const EntitySelector<Alert_informed_entity_EntitySelector_agency_id_LENGTH, Alert_informed_entity_EntitySelector_route_id_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_trip_id_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_route_id_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_time_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_date_LENGTH, Alert_informed_entity_EntitySelector_stop_id_LENGTH>& informed_entity(uint32_t index) const { return informed_entity_[index]; }
    inline void clear_informed_entity() { informed_entity_.clear(); }
    inline void set_informed_entity(uint32_t index, const EntitySelector<Alert_informed_entity_EntitySelector_agency_id_LENGTH, Alert_informed_entity_EntitySelector_route_id_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_trip_id_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_route_id_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_time_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_date_LENGTH, Alert_informed_entity_EntitySelector_stop_id_LENGTH>& value) { informed_entity_.set(index, value); }
    inline void set_informed_entity(uint32_t index, const EntitySelector<Alert_informed_entity_EntitySelector_agency_id_LENGTH, Alert_informed_entity_EntitySelector_route_id_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_trip_id_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_route_id_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_time_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_date_LENGTH, Alert_informed_entity_EntitySelector_stop_id_LENGTH>&& value) { informed_entity_.set(index, value); }
    inline void set_informed_entity(const ::EmbeddedProto::RepeatedFieldFixedSize<EntitySelector<Alert_informed_entity_EntitySelector_agency_id_LENGTH, Alert_informed_entity_EntitySelector_route_id_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_trip_id_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_route_id_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_time_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_date_LENGTH, Alert_informed_entity_EntitySelector_stop_id_LENGTH>, Alert_informed_entity_REP_LENGTH>& values) { informed_entity_ = values; }
    inline void add_informed_entity(const EntitySelector<Alert_informed_entity_EntitySelector_agency_id_LENGTH, Alert_informed_entity_EntitySelector_route_id_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_trip_id_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_route_id_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_time_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_date_LENGTH, Alert_informed_entity_EntitySelector_stop_id_LENGTH>& value) { informed_entity_.add(value); }
    inline ::EmbeddedProto::RepeatedFieldFixedSize<EntitySelector<Alert_informed_entity_EntitySelector_agency_id_LENGTH, Alert_informed_entity_EntitySelector_route_id_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_trip_id_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_route_id_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_time_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_date_LENGTH, Alert_informed_entity_EntitySelector_stop_id_LENGTH>, Alert_informed_entity_REP_LENGTH>& mutable_informed_entity() { return informed_entity_; }
    inline EntitySelector<Alert_informed_entity_EntitySelector_agency_id_LENGTH, Alert_informed_entity_EntitySelector_route_id_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_trip_id_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_route_id_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_time_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_date_LENGTH, Alert_informed_entity_EntitySelector_stop_id_LENGTH>& mutable_informed_entity(uint32_t index) { return informed_entity_[index]; }
    inline const ::EmbeddedProto::RepeatedFieldFixedSize<EntitySelector<Alert_informed_entity_EntitySelector_agency_id_LENGTH, Alert_informed_entity_EntitySelector_route_id_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_trip_id_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_route_id_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_time_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_date_LENGTH, Alert_informed_entity_EntitySelector_stop_id_LENGTH>, Alert_informed_entity_REP_LENGTH>& get_informed_entity() const { return informed_entity_; }
    inline const ::EmbeddedProto::RepeatedFieldFixedSize<EntitySelector<Alert_informed_entity_EntitySelector_agency_id_LENGTH, Alert_informed_entity_EntitySelector_route_id_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_trip_id_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_route_id_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_time_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_date_LENGTH, Alert_informed_entity_EntitySelector_stop_id_LENGTH>, Alert_informed_entity_REP_LENGTH>& informed_entity() const { return informed_entity_; }

    static constexpr char const* CAUSE_NAME = "cause";
    inline void clear_cause() { cause_.clear(); }
    inline void set_cause(const Cause& value) { cause_ = value; }
    inline void set_cause(const Cause&& value) { cause_ = value; }
    inline const Cause& get_cause() const { return cause_.get(); }
    inline Cause cause() const { return cause_.get(); }

    static constexpr char const* EFFECT_NAME = "effect";
    inline void clear_effect() { effect_.clear(); }
    inline void set_effect(const Effect& value) { effect_ = value; }
    inline void set_effect(const Effect&& value) { effect_ = value; }
    inline const Effect& get_effect() const { return effect_.get(); }
    inline Effect effect() const { return effect_.get(); }

    static constexpr char const* URL_NAME = "url";
    inline void clear_url() { url_.clear(); }
    inline void set_url(const TranslatedString<Alert_url_TranslatedString_translation_REP_LENGTH, Alert_url_TranslatedString_translation_Translation_text_LENGTH, Alert_url_TranslatedString_translation_Translation_language_LENGTH>& value) { url_ = value; }
    inline void set_url(const TranslatedString<Alert_url_TranslatedString_translation_REP_LENGTH, Alert_url_TranslatedString_translation_Translation_text_LENGTH, Alert_url_TranslatedString_translation_Translation_language_LENGTH>&& value) { url_ = value; }
    inline TranslatedString<Alert_url_TranslatedString_translation_REP_LENGTH, Alert_url_TranslatedString_translation_Translation_text_LENGTH, Alert_url_TranslatedString_translation_Translation_language_LENGTH>& mutable_url() { return url_; }
    inline const TranslatedString<Alert_url_TranslatedString_translation_REP_LENGTH, Alert_url_TranslatedString_translation_Translation_text_LENGTH, Alert_url_TranslatedString_translation_Translation_language_LENGTH>& get_url() const { return url_; }
    inline const TranslatedString<Alert_url_TranslatedString_translation_REP_LENGTH, Alert_url_TranslatedString_translation_Translation_text_LENGTH, Alert_url_TranslatedString_translation_Translation_language_LENGTH>& url() const { return url_; }

    static constexpr char const* HEADER_TEXT_NAME = "header_text";
    inline void clear_header_text() { header_text_.clear(); }
    inline void set_header_text(const TranslatedString<Alert_header_text_TranslatedString_translation_REP_LENGTH, Alert_header_text_TranslatedString_translation_Translation_text_LENGTH, Alert_header_text_TranslatedString_translation_Translation_language_LENGTH>& value) { header_text_ = value; }
    inline void set_header_text(const TranslatedString<Alert_header_text_TranslatedString_translation_REP_LENGTH, Alert_header_text_TranslatedString_translation_Translation_text_LENGTH, Alert_header_text_TranslatedString_translation_Translation_language_LENGTH>&& value) { header_text_ = value; }
    inline TranslatedString<Alert_header_text_TranslatedString_translation_REP_LENGTH, Alert_header_text_TranslatedString_translation_Translation_text_LENGTH, Alert_header_text_TranslatedString_translation_Translation_language_LENGTH>& mutable_header_text() { return header_text_; }
    inline const TranslatedString<Alert_header_text_TranslatedString_translation_REP_LENGTH, Alert_header_text_TranslatedString_translation_Translation_text_LENGTH, Alert_header_text_TranslatedString_translation_Translation_language_LENGTH>& get_header_text() const { return header_text_; }
    inline const TranslatedString<Alert_header_text_TranslatedString_translation_REP_LENGTH, Alert_header_text_TranslatedString_translation_Translation_text_LENGTH, Alert_header_text_TranslatedString_translation_Translation_language_LENGTH>& header_text() const { return header_text_; }

    static constexpr char const* DESCRIPTION_TEXT_NAME = "description_text";
    inline void clear_description_text() { description_text_.clear(); }
    inline void set_description_text(const TranslatedString<Alert_description_text_TranslatedString_translation_REP_LENGTH, Alert_description_text_TranslatedString_translation_Translation_text_LENGTH, Alert_description_text_TranslatedString_translation_Translation_language_LENGTH>& value) { description_text_ = value; }
    inline void set_description_text(const TranslatedString<Alert_description_text_TranslatedString_translation_REP_LENGTH, Alert_description_text_TranslatedString_translation_Translation_text_LENGTH, Alert_description_text_TranslatedString_translation_Translation_language_LENGTH>&& value) { description_text_ = value; }
    inline TranslatedString<Alert_description_text_TranslatedString_translation_REP_LENGTH, Alert_description_text_TranslatedString_translation_Translation_text_LENGTH, Alert_description_text_TranslatedString_translation_Translation_language_LENGTH>& mutable_description_text() { return description_text_; }
    inline const TranslatedString<Alert_description_text_TranslatedString_translation_REP_LENGTH, Alert_description_text_TranslatedString_translation_Translation_text_LENGTH, Alert_description_text_TranslatedString_translation_Translation_language_LENGTH>& get_description_text() const { return description_text_; }
    inline const TranslatedString<Alert_description_text_TranslatedString_translation_REP_LENGTH, Alert_description_text_TranslatedString_translation_Translation_text_LENGTH, Alert_description_text_TranslatedString_translation_Translation_language_LENGTH>& description_text() const { return description_text_; }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = active_period_.serialize_with_id(static_cast<uint32_t>(FieldNumber::ACTIVE_PERIOD), buffer, false);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = informed_entity_.serialize_with_id(static_cast<uint32_t>(FieldNumber::INFORMED_ENTITY), buffer, false);
      }

      if((static_cast<Cause>(0) != cause_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = cause_.serialize_with_id(static_cast<uint32_t>(FieldNumber::CAUSE), buffer, false);
      }

      if((static_cast<Effect>(0) != effect_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = effect_.serialize_with_id(static_cast<uint32_t>(FieldNumber::EFFECT), buffer, false);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = url_.serialize_with_id(static_cast<uint32_t>(FieldNumber::URL), buffer, false);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = header_text_.serialize_with_id(static_cast<uint32_t>(FieldNumber::HEADER_TEXT), buffer, false);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = description_text_.serialize_with_id(static_cast<uint32_t>(FieldNumber::DESCRIPTION_TEXT), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::ACTIVE_PERIOD:
            return_value = active_period_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::INFORMED_ENTITY:
            return_value = informed_entity_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::CAUSE:
            return_value = cause_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::EFFECT:
            return_value = effect_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::URL:
            return_value = url_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::HEADER_TEXT:
            return_value = header_text_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::DESCRIPTION_TEXT:
            return_value = description_text_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_active_period();
      clear_informed_entity();
      clear_cause();
      clear_effect();
      clear_url();
      clear_header_text();
      clear_description_text();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::ACTIVE_PERIOD:
          name = ACTIVE_PERIOD_NAME;
          break;
        case FieldNumber::INFORMED_ENTITY:
          name = INFORMED_ENTITY_NAME;
          break;
        case FieldNumber::CAUSE:
          name = CAUSE_NAME;
          break;
        case FieldNumber::EFFECT:
          name = EFFECT_NAME;
          break;
        case FieldNumber::URL:
          name = URL_NAME;
          break;
        case FieldNumber::HEADER_TEXT:
          name = HEADER_TEXT_NAME;
          break;
        case FieldNumber::DESCRIPTION_TEXT:
          name = DESCRIPTION_TEXT_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#endif

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = active_period_.to_string(left_chars, indent_level + 2, ACTIVE_PERIOD_NAME, true);
      left_chars = informed_entity_.to_string(left_chars, indent_level + 2, INFORMED_ENTITY_NAME, false);
      left_chars = cause_.to_string(left_chars, indent_level + 2, CAUSE_NAME, false);
      left_chars = effect_.to_string(left_chars, indent_level + 2, EFFECT_NAME, false);
      left_chars = url_.to_string(left_chars, indent_level + 2, URL_NAME, false);
      left_chars = header_text_.to_string(left_chars, indent_level + 2, HEADER_TEXT_NAME, false);
      left_chars = description_text_.to_string(left_chars, indent_level + 2, DESCRIPTION_TEXT_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      ::EmbeddedProto::RepeatedFieldFixedSize<TimeRange, Alert_active_period_REP_LENGTH> active_period_;
      ::EmbeddedProto::RepeatedFieldFixedSize<EntitySelector<Alert_informed_entity_EntitySelector_agency_id_LENGTH, Alert_informed_entity_EntitySelector_route_id_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_trip_id_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_route_id_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_time_LENGTH, Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_date_LENGTH, Alert_informed_entity_EntitySelector_stop_id_LENGTH>, Alert_informed_entity_REP_LENGTH> informed_entity_;
      EmbeddedProto::enumeration<Cause> cause_ = static_cast<Cause>(0);
      EmbeddedProto::enumeration<Effect> effect_ = static_cast<Effect>(0);
      TranslatedString<Alert_url_TranslatedString_translation_REP_LENGTH, Alert_url_TranslatedString_translation_Translation_text_LENGTH, Alert_url_TranslatedString_translation_Translation_language_LENGTH> url_;
      TranslatedString<Alert_header_text_TranslatedString_translation_REP_LENGTH, Alert_header_text_TranslatedString_translation_Translation_text_LENGTH, Alert_header_text_TranslatedString_translation_Translation_language_LENGTH> header_text_;
      TranslatedString<Alert_description_text_TranslatedString_translation_REP_LENGTH, Alert_description_text_TranslatedString_translation_Translation_text_LENGTH, Alert_description_text_TranslatedString_translation_Translation_language_LENGTH> description_text_;

};

template<
    uint32_t FeedEntity_id_LENGTH, 
    uint32_t FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_trip_id_LENGTH, 
    uint32_t FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_route_id_LENGTH, 
    uint32_t FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_start_time_LENGTH, 
    uint32_t FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_start_date_LENGTH, 
    uint32_t FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_id_LENGTH, 
    uint32_t FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_label_LENGTH, 
    uint32_t FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_license_plate_LENGTH, 
    uint32_t FeedEntity_trip_update_TripUpdate_stop_time_update_REP_LENGTH, 
    uint32_t FeedEntity_trip_update_TripUpdate_stop_time_update_StopTimeUpdate_stop_id_LENGTH, 
    uint32_t FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_trip_id_LENGTH, 
    uint32_t FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_route_id_LENGTH, 
    uint32_t FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_start_time_LENGTH, 
    uint32_t FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_start_date_LENGTH, 
    uint32_t FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_id_LENGTH, 
    uint32_t FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_label_LENGTH, 
    uint32_t FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_license_plate_LENGTH, 
    uint32_t FeedEntity_vehicle_VehiclePosition_stop_id_LENGTH, 
    uint32_t FeedEntity_alert_Alert_active_period_REP_LENGTH, 
    uint32_t FeedEntity_alert_Alert_informed_entity_REP_LENGTH, 
    uint32_t FeedEntity_alert_Alert_informed_entity_EntitySelector_agency_id_LENGTH, 
    uint32_t FeedEntity_alert_Alert_informed_entity_EntitySelector_route_id_LENGTH, 
    uint32_t FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_trip_id_LENGTH, 
    uint32_t FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_route_id_LENGTH, 
    uint32_t FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_time_LENGTH, 
    uint32_t FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_date_LENGTH, 
    uint32_t FeedEntity_alert_Alert_informed_entity_EntitySelector_stop_id_LENGTH, 
    uint32_t FeedEntity_alert_Alert_url_TranslatedString_translation_REP_LENGTH, 
    uint32_t FeedEntity_alert_Alert_url_TranslatedString_translation_Translation_text_LENGTH, 
    uint32_t FeedEntity_alert_Alert_url_TranslatedString_translation_Translation_language_LENGTH, 
    uint32_t FeedEntity_alert_Alert_header_text_TranslatedString_translation_REP_LENGTH, 
    uint32_t FeedEntity_alert_Alert_header_text_TranslatedString_translation_Translation_text_LENGTH, 
    uint32_t FeedEntity_alert_Alert_header_text_TranslatedString_translation_Translation_language_LENGTH, 
    uint32_t FeedEntity_alert_Alert_description_text_TranslatedString_translation_REP_LENGTH, 
    uint32_t FeedEntity_alert_Alert_description_text_TranslatedString_translation_Translation_text_LENGTH, 
    uint32_t FeedEntity_alert_Alert_description_text_TranslatedString_translation_Translation_language_LENGTH
>
class FeedEntity final: public ::EmbeddedProto::MessageInterface
{
  public:
    FeedEntity() = default;
    FeedEntity(const FeedEntity& rhs )
    {
      set_id(rhs.get_id());
      set_is_deleted(rhs.get_is_deleted());
      set_trip_update(rhs.get_trip_update());
      set_vehicle(rhs.get_vehicle());
      set_alert(rhs.get_alert());
    }

    FeedEntity(const FeedEntity&& rhs ) noexcept
    {
      set_id(rhs.get_id());
      set_is_deleted(rhs.get_is_deleted());
      set_trip_update(rhs.get_trip_update());
      set_vehicle(rhs.get_vehicle());
      set_alert(rhs.get_alert());
    }

    ~FeedEntity() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      ID = 1,
      IS_DELETED = 2,
      TRIP_UPDATE = 3,
      VEHICLE = 4,
      ALERT = 5
    };

    FeedEntity& operator=(const FeedEntity& rhs)
    {
      set_id(rhs.get_id());
      set_is_deleted(rhs.get_is_deleted());
      set_trip_update(rhs.get_trip_update());
      set_vehicle(rhs.get_vehicle());
      set_alert(rhs.get_alert());
      return *this;
    }

    FeedEntity& operator=(const FeedEntity&& rhs) noexcept
    {
      set_id(rhs.get_id());
      set_is_deleted(rhs.get_is_deleted());
      set_trip_update(rhs.get_trip_update());
      set_vehicle(rhs.get_vehicle());
      set_alert(rhs.get_alert());
      return *this;
    }

    static constexpr char const* ID_NAME = "id";
    inline void clear_id() { id_.clear(); }
    inline ::EmbeddedProto::FieldString<FeedEntity_id_LENGTH>& mutable_id() { return id_; }
    inline void set_id(const ::EmbeddedProto::FieldString<FeedEntity_id_LENGTH>& rhs) { id_.set(rhs); }
    inline const ::EmbeddedProto::FieldString<FeedEntity_id_LENGTH>& get_id() const { return id_; }
    inline const char* id() const { return id_.get_const(); }

    static constexpr char const* IS_DELETED_NAME = "is_deleted";
    inline void clear_is_deleted() { is_deleted_.clear(); }
    inline void set_is_deleted(const bool& value) { is_deleted_ = value; }
    inline void set_is_deleted(const bool&& value) { is_deleted_ = value; }
    inline bool& mutable_is_deleted() { return is_deleted_.get(); }
    inline const bool& get_is_deleted() const { return is_deleted_.get(); }
    inline bool is_deleted() const { return is_deleted_.get(); }

    static constexpr char const* TRIP_UPDATE_NAME = "trip_update";
    inline void clear_trip_update() { trip_update_.clear(); }
    inline void set_trip_update(const TripUpdate<FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_trip_id_LENGTH, FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_route_id_LENGTH, FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_start_time_LENGTH, FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_start_date_LENGTH, FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_id_LENGTH, FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_label_LENGTH, FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_license_plate_LENGTH, FeedEntity_trip_update_TripUpdate_stop_time_update_REP_LENGTH, FeedEntity_trip_update_TripUpdate_stop_time_update_StopTimeUpdate_stop_id_LENGTH>& value) { trip_update_ = value; }
    inline void set_trip_update(const TripUpdate<FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_trip_id_LENGTH, FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_route_id_LENGTH, FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_start_time_LENGTH, FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_start_date_LENGTH, FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_id_LENGTH, FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_label_LENGTH, FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_license_plate_LENGTH, FeedEntity_trip_update_TripUpdate_stop_time_update_REP_LENGTH, FeedEntity_trip_update_TripUpdate_stop_time_update_StopTimeUpdate_stop_id_LENGTH>&& value) { trip_update_ = value; }
    inline TripUpdate<FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_trip_id_LENGTH, FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_route_id_LENGTH, FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_start_time_LENGTH, FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_start_date_LENGTH, FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_id_LENGTH, FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_label_LENGTH, FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_license_plate_LENGTH, FeedEntity_trip_update_TripUpdate_stop_time_update_REP_LENGTH, FeedEntity_trip_update_TripUpdate_stop_time_update_StopTimeUpdate_stop_id_LENGTH>& mutable_trip_update() { return trip_update_; }
    inline const TripUpdate<FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_trip_id_LENGTH, FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_route_id_LENGTH, FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_start_time_LENGTH, FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_start_date_LENGTH, FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_id_LENGTH, FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_label_LENGTH, FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_license_plate_LENGTH, FeedEntity_trip_update_TripUpdate_stop_time_update_REP_LENGTH, FeedEntity_trip_update_TripUpdate_stop_time_update_StopTimeUpdate_stop_id_LENGTH>& get_trip_update() const { return trip_update_; }
    inline const TripUpdate<FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_trip_id_LENGTH, FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_route_id_LENGTH, FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_start_time_LENGTH, FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_start_date_LENGTH, FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_id_LENGTH, FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_label_LENGTH, FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_license_plate_LENGTH, FeedEntity_trip_update_TripUpdate_stop_time_update_REP_LENGTH, FeedEntity_trip_update_TripUpdate_stop_time_update_StopTimeUpdate_stop_id_LENGTH>& trip_update() const { return trip_update_; }

    static constexpr char const* VEHICLE_NAME = "vehicle";
    inline void clear_vehicle() { vehicle_.clear(); }
    inline void set_vehicle(const VehiclePosition<FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_trip_id_LENGTH, FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_route_id_LENGTH, FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_start_time_LENGTH, FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_start_date_LENGTH, FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_id_LENGTH, FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_label_LENGTH, FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_license_plate_LENGTH, FeedEntity_vehicle_VehiclePosition_stop_id_LENGTH>& value) { vehicle_ = value; }
    inline void set_vehicle(const VehiclePosition<FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_trip_id_LENGTH, FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_route_id_LENGTH, FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_start_time_LENGTH, FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_start_date_LENGTH, FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_id_LENGTH, FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_label_LENGTH, FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_license_plate_LENGTH, FeedEntity_vehicle_VehiclePosition_stop_id_LENGTH>&& value) { vehicle_ = value; }
    inline VehiclePosition<FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_trip_id_LENGTH, FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_route_id_LENGTH, FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_start_time_LENGTH, FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_start_date_LENGTH, FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_id_LENGTH, FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_label_LENGTH, FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_license_plate_LENGTH, FeedEntity_vehicle_VehiclePosition_stop_id_LENGTH>& mutable_vehicle() { return vehicle_; }
    inline const VehiclePosition<FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_trip_id_LENGTH, FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_route_id_LENGTH, FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_start_time_LENGTH, FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_start_date_LENGTH, FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_id_LENGTH, FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_label_LENGTH, FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_license_plate_LENGTH, FeedEntity_vehicle_VehiclePosition_stop_id_LENGTH>& get_vehicle() const { return vehicle_; }
    inline const VehiclePosition<FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_trip_id_LENGTH, FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_route_id_LENGTH, FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_start_time_LENGTH, FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_start_date_LENGTH, FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_id_LENGTH, FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_label_LENGTH, FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_license_plate_LENGTH, FeedEntity_vehicle_VehiclePosition_stop_id_LENGTH>& vehicle() const { return vehicle_; }

    static constexpr char const* ALERT_NAME = "alert";
    inline void clear_alert() { alert_.clear(); }
    inline void set_alert(const Alert<FeedEntity_alert_Alert_active_period_REP_LENGTH, FeedEntity_alert_Alert_informed_entity_REP_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_agency_id_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_route_id_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_trip_id_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_route_id_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_time_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_date_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_stop_id_LENGTH, FeedEntity_alert_Alert_url_TranslatedString_translation_REP_LENGTH, FeedEntity_alert_Alert_url_TranslatedString_translation_Translation_text_LENGTH, FeedEntity_alert_Alert_url_TranslatedString_translation_Translation_language_LENGTH, FeedEntity_alert_Alert_header_text_TranslatedString_translation_REP_LENGTH, FeedEntity_alert_Alert_header_text_TranslatedString_translation_Translation_text_LENGTH, FeedEntity_alert_Alert_header_text_TranslatedString_translation_Translation_language_LENGTH, FeedEntity_alert_Alert_description_text_TranslatedString_translation_REP_LENGTH, FeedEntity_alert_Alert_description_text_TranslatedString_translation_Translation_text_LENGTH, FeedEntity_alert_Alert_description_text_TranslatedString_translation_Translation_language_LENGTH>& value) { alert_ = value; }
    inline void set_alert(const Alert<FeedEntity_alert_Alert_active_period_REP_LENGTH, FeedEntity_alert_Alert_informed_entity_REP_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_agency_id_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_route_id_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_trip_id_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_route_id_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_time_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_date_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_stop_id_LENGTH, FeedEntity_alert_Alert_url_TranslatedString_translation_REP_LENGTH, FeedEntity_alert_Alert_url_TranslatedString_translation_Translation_text_LENGTH, FeedEntity_alert_Alert_url_TranslatedString_translation_Translation_language_LENGTH, FeedEntity_alert_Alert_header_text_TranslatedString_translation_REP_LENGTH, FeedEntity_alert_Alert_header_text_TranslatedString_translation_Translation_text_LENGTH, FeedEntity_alert_Alert_header_text_TranslatedString_translation_Translation_language_LENGTH, FeedEntity_alert_Alert_description_text_TranslatedString_translation_REP_LENGTH, FeedEntity_alert_Alert_description_text_TranslatedString_translation_Translation_text_LENGTH, FeedEntity_alert_Alert_description_text_TranslatedString_translation_Translation_language_LENGTH>&& value) { alert_ = value; }
    inline Alert<FeedEntity_alert_Alert_active_period_REP_LENGTH, FeedEntity_alert_Alert_informed_entity_REP_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_agency_id_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_route_id_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_trip_id_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_route_id_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_time_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_date_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_stop_id_LENGTH, FeedEntity_alert_Alert_url_TranslatedString_translation_REP_LENGTH, FeedEntity_alert_Alert_url_TranslatedString_translation_Translation_text_LENGTH, FeedEntity_alert_Alert_url_TranslatedString_translation_Translation_language_LENGTH, FeedEntity_alert_Alert_header_text_TranslatedString_translation_REP_LENGTH, FeedEntity_alert_Alert_header_text_TranslatedString_translation_Translation_text_LENGTH, FeedEntity_alert_Alert_header_text_TranslatedString_translation_Translation_language_LENGTH, FeedEntity_alert_Alert_description_text_TranslatedString_translation_REP_LENGTH, FeedEntity_alert_Alert_description_text_TranslatedString_translation_Translation_text_LENGTH, FeedEntity_alert_Alert_description_text_TranslatedString_translation_Translation_language_LENGTH>& mutable_alert() { return alert_; }
    inline const Alert<FeedEntity_alert_Alert_active_period_REP_LENGTH, FeedEntity_alert_Alert_informed_entity_REP_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_agency_id_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_route_id_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_trip_id_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_route_id_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_time_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_date_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_stop_id_LENGTH, FeedEntity_alert_Alert_url_TranslatedString_translation_REP_LENGTH, FeedEntity_alert_Alert_url_TranslatedString_translation_Translation_text_LENGTH, FeedEntity_alert_Alert_url_TranslatedString_translation_Translation_language_LENGTH, FeedEntity_alert_Alert_header_text_TranslatedString_translation_REP_LENGTH, FeedEntity_alert_Alert_header_text_TranslatedString_translation_Translation_text_LENGTH, FeedEntity_alert_Alert_header_text_TranslatedString_translation_Translation_language_LENGTH, FeedEntity_alert_Alert_description_text_TranslatedString_translation_REP_LENGTH, FeedEntity_alert_Alert_description_text_TranslatedString_translation_Translation_text_LENGTH, FeedEntity_alert_Alert_description_text_TranslatedString_translation_Translation_language_LENGTH>& get_alert() const { return alert_; }
    inline const Alert<FeedEntity_alert_Alert_active_period_REP_LENGTH, FeedEntity_alert_Alert_informed_entity_REP_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_agency_id_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_route_id_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_trip_id_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_route_id_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_time_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_date_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_stop_id_LENGTH, FeedEntity_alert_Alert_url_TranslatedString_translation_REP_LENGTH, FeedEntity_alert_Alert_url_TranslatedString_translation_Translation_text_LENGTH, FeedEntity_alert_Alert_url_TranslatedString_translation_Translation_language_LENGTH, FeedEntity_alert_Alert_header_text_TranslatedString_translation_REP_LENGTH, FeedEntity_alert_Alert_header_text_TranslatedString_translation_Translation_text_LENGTH, FeedEntity_alert_Alert_header_text_TranslatedString_translation_Translation_language_LENGTH, FeedEntity_alert_Alert_description_text_TranslatedString_translation_REP_LENGTH, FeedEntity_alert_Alert_description_text_TranslatedString_translation_Translation_text_LENGTH, FeedEntity_alert_Alert_description_text_TranslatedString_translation_Translation_language_LENGTH>& alert() const { return alert_; }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = id_.serialize_with_id(static_cast<uint32_t>(FieldNumber::ID), buffer, false);
      }

      if((false != is_deleted_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = is_deleted_.serialize_with_id(static_cast<uint32_t>(FieldNumber::IS_DELETED), buffer, false);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = trip_update_.serialize_with_id(static_cast<uint32_t>(FieldNumber::TRIP_UPDATE), buffer, false);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = vehicle_.serialize_with_id(static_cast<uint32_t>(FieldNumber::VEHICLE), buffer, false);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = alert_.serialize_with_id(static_cast<uint32_t>(FieldNumber::ALERT), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::ID:
            return_value = id_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::IS_DELETED:
            return_value = is_deleted_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::TRIP_UPDATE:
            return_value = trip_update_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::VEHICLE:
            return_value = vehicle_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::ALERT:
            return_value = alert_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_id();
      clear_is_deleted();
      clear_trip_update();
      clear_vehicle();
      clear_alert();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::ID:
          name = ID_NAME;
          break;
        case FieldNumber::IS_DELETED:
          name = IS_DELETED_NAME;
          break;
        case FieldNumber::TRIP_UPDATE:
          name = TRIP_UPDATE_NAME;
          break;
        case FieldNumber::VEHICLE:
          name = VEHICLE_NAME;
          break;
        case FieldNumber::ALERT:
          name = ALERT_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#endif

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = id_.to_string(left_chars, indent_level + 2, ID_NAME, true);
      left_chars = is_deleted_.to_string(left_chars, indent_level + 2, IS_DELETED_NAME, false);
      left_chars = trip_update_.to_string(left_chars, indent_level + 2, TRIP_UPDATE_NAME, false);
      left_chars = vehicle_.to_string(left_chars, indent_level + 2, VEHICLE_NAME, false);
      left_chars = alert_.to_string(left_chars, indent_level + 2, ALERT_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      ::EmbeddedProto::FieldString<FeedEntity_id_LENGTH> id_;
      EmbeddedProto::boolean is_deleted_ = false;
      TripUpdate<FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_trip_id_LENGTH, FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_route_id_LENGTH, FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_start_time_LENGTH, FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_start_date_LENGTH, FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_id_LENGTH, FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_label_LENGTH, FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_license_plate_LENGTH, FeedEntity_trip_update_TripUpdate_stop_time_update_REP_LENGTH, FeedEntity_trip_update_TripUpdate_stop_time_update_StopTimeUpdate_stop_id_LENGTH> trip_update_;
      VehiclePosition<FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_trip_id_LENGTH, FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_route_id_LENGTH, FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_start_time_LENGTH, FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_start_date_LENGTH, FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_id_LENGTH, FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_label_LENGTH, FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_license_plate_LENGTH, FeedEntity_vehicle_VehiclePosition_stop_id_LENGTH> vehicle_;
      Alert<FeedEntity_alert_Alert_active_period_REP_LENGTH, FeedEntity_alert_Alert_informed_entity_REP_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_agency_id_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_route_id_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_trip_id_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_route_id_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_time_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_date_LENGTH, FeedEntity_alert_Alert_informed_entity_EntitySelector_stop_id_LENGTH, FeedEntity_alert_Alert_url_TranslatedString_translation_REP_LENGTH, FeedEntity_alert_Alert_url_TranslatedString_translation_Translation_text_LENGTH, FeedEntity_alert_Alert_url_TranslatedString_translation_Translation_language_LENGTH, FeedEntity_alert_Alert_header_text_TranslatedString_translation_REP_LENGTH, FeedEntity_alert_Alert_header_text_TranslatedString_translation_Translation_text_LENGTH, FeedEntity_alert_Alert_header_text_TranslatedString_translation_Translation_language_LENGTH, FeedEntity_alert_Alert_description_text_TranslatedString_translation_REP_LENGTH, FeedEntity_alert_Alert_description_text_TranslatedString_translation_Translation_text_LENGTH, FeedEntity_alert_Alert_description_text_TranslatedString_translation_Translation_language_LENGTH> alert_;

};

template<
    uint32_t FeedMessage_header_FeedHeader_gtfs_realtime_version_LENGTH, 
    uint32_t FeedMessage_entity_REP_LENGTH, 
    uint32_t FeedMessage_entity_FeedEntity_id_LENGTH, 
    uint32_t FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_trip_id_LENGTH, 
    uint32_t FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_route_id_LENGTH, 
    uint32_t FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_start_time_LENGTH, 
    uint32_t FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_start_date_LENGTH, 
    uint32_t FeedMessage_entity_FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_id_LENGTH, 
    uint32_t FeedMessage_entity_FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_label_LENGTH, 
    uint32_t FeedMessage_entity_FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_license_plate_LENGTH, 
    uint32_t FeedMessage_entity_FeedEntity_trip_update_TripUpdate_stop_time_update_REP_LENGTH, 
    uint32_t FeedMessage_entity_FeedEntity_trip_update_TripUpdate_stop_time_update_StopTimeUpdate_stop_id_LENGTH, 
    uint32_t FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_trip_id_LENGTH, 
    uint32_t FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_route_id_LENGTH, 
    uint32_t FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_start_time_LENGTH, 
    uint32_t FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_start_date_LENGTH, 
    uint32_t FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_id_LENGTH, 
    uint32_t FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_label_LENGTH, 
    uint32_t FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_license_plate_LENGTH, 
    uint32_t FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_stop_id_LENGTH, 
    uint32_t FeedMessage_entity_FeedEntity_alert_Alert_active_period_REP_LENGTH, 
    uint32_t FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_REP_LENGTH, 
    uint32_t FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_agency_id_LENGTH, 
    uint32_t FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_route_id_LENGTH, 
    uint32_t FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_trip_id_LENGTH, 
    uint32_t FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_route_id_LENGTH, 
    uint32_t FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_time_LENGTH, 
    uint32_t FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_date_LENGTH, 
    uint32_t FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_stop_id_LENGTH, 
    uint32_t FeedMessage_entity_FeedEntity_alert_Alert_url_TranslatedString_translation_REP_LENGTH, 
    uint32_t FeedMessage_entity_FeedEntity_alert_Alert_url_TranslatedString_translation_Translation_text_LENGTH, 
    uint32_t FeedMessage_entity_FeedEntity_alert_Alert_url_TranslatedString_translation_Translation_language_LENGTH, 
    uint32_t FeedMessage_entity_FeedEntity_alert_Alert_header_text_TranslatedString_translation_REP_LENGTH, 
    uint32_t FeedMessage_entity_FeedEntity_alert_Alert_header_text_TranslatedString_translation_Translation_text_LENGTH, 
    uint32_t FeedMessage_entity_FeedEntity_alert_Alert_header_text_TranslatedString_translation_Translation_language_LENGTH, 
    uint32_t FeedMessage_entity_FeedEntity_alert_Alert_description_text_TranslatedString_translation_REP_LENGTH, 
    uint32_t FeedMessage_entity_FeedEntity_alert_Alert_description_text_TranslatedString_translation_Translation_text_LENGTH, 
    uint32_t FeedMessage_entity_FeedEntity_alert_Alert_description_text_TranslatedString_translation_Translation_language_LENGTH
>
class FeedMessage final: public ::EmbeddedProto::MessageInterface
{
  public:
    FeedMessage() = default;
    FeedMessage(const FeedMessage& rhs )
    {
      set_header(rhs.get_header());
      set_entity(rhs.get_entity());
    }

    FeedMessage(const FeedMessage&& rhs ) noexcept
    {
      set_header(rhs.get_header());
      set_entity(rhs.get_entity());
    }

    ~FeedMessage() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      HEADER = 1,
      ENTITY = 2
    };

    FeedMessage& operator=(const FeedMessage& rhs)
    {
      set_header(rhs.get_header());
      set_entity(rhs.get_entity());
      return *this;
    }

    FeedMessage& operator=(const FeedMessage&& rhs) noexcept
    {
      set_header(rhs.get_header());
      set_entity(rhs.get_entity());
      return *this;
    }

    static constexpr char const* HEADER_NAME = "header";
    inline void clear_header() { header_.clear(); }
    inline void set_header(const FeedHeader<FeedMessage_header_FeedHeader_gtfs_realtime_version_LENGTH>& value) { header_ = value; }
    inline void set_header(const FeedHeader<FeedMessage_header_FeedHeader_gtfs_realtime_version_LENGTH>&& value) { header_ = value; }
    inline FeedHeader<FeedMessage_header_FeedHeader_gtfs_realtime_version_LENGTH>& mutable_header() { return header_; }
    inline const FeedHeader<FeedMessage_header_FeedHeader_gtfs_realtime_version_LENGTH>& get_header() const { return header_; }
    inline const FeedHeader<FeedMessage_header_FeedHeader_gtfs_realtime_version_LENGTH>& header() const { return header_; }

    static constexpr char const* ENTITY_NAME = "entity";
    inline const FeedEntity<FeedMessage_entity_FeedEntity_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_trip_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_route_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_start_time_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_start_date_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_label_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_license_plate_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_stop_time_update_REP_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_stop_time_update_StopTimeUpdate_stop_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_trip_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_route_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_start_time_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_start_date_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_label_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_license_plate_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_stop_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_active_period_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_agency_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_route_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_trip_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_route_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_time_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_date_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_stop_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_url_TranslatedString_translation_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_url_TranslatedString_translation_Translation_text_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_url_TranslatedString_translation_Translation_language_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_header_text_TranslatedString_translation_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_header_text_TranslatedString_translation_Translation_text_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_header_text_TranslatedString_translation_Translation_language_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_description_text_TranslatedString_translation_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_description_text_TranslatedString_translation_Translation_text_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_description_text_TranslatedString_translation_Translation_language_LENGTH>& entity(uint32_t index) const { return entity_[index]; }
    inline void clear_entity() { entity_.clear(); }
    inline void set_entity(uint32_t index, const FeedEntity<FeedMessage_entity_FeedEntity_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_trip_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_route_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_start_time_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_start_date_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_label_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_license_plate_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_stop_time_update_REP_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_stop_time_update_StopTimeUpdate_stop_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_trip_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_route_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_start_time_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_start_date_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_label_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_license_plate_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_stop_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_active_period_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_agency_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_route_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_trip_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_route_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_time_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_date_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_stop_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_url_TranslatedString_translation_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_url_TranslatedString_translation_Translation_text_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_url_TranslatedString_translation_Translation_language_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_header_text_TranslatedString_translation_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_header_text_TranslatedString_translation_Translation_text_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_header_text_TranslatedString_translation_Translation_language_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_description_text_TranslatedString_translation_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_description_text_TranslatedString_translation_Translation_text_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_description_text_TranslatedString_translation_Translation_language_LENGTH>& value) { entity_.set(index, value); }
    inline void set_entity(uint32_t index, const FeedEntity<FeedMessage_entity_FeedEntity_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_trip_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_route_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_start_time_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_start_date_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_label_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_license_plate_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_stop_time_update_REP_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_stop_time_update_StopTimeUpdate_stop_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_trip_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_route_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_start_time_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_start_date_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_label_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_license_plate_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_stop_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_active_period_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_agency_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_route_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_trip_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_route_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_time_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_date_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_stop_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_url_TranslatedString_translation_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_url_TranslatedString_translation_Translation_text_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_url_TranslatedString_translation_Translation_language_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_header_text_TranslatedString_translation_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_header_text_TranslatedString_translation_Translation_text_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_header_text_TranslatedString_translation_Translation_language_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_description_text_TranslatedString_translation_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_description_text_TranslatedString_translation_Translation_text_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_description_text_TranslatedString_translation_Translation_language_LENGTH>&& value) { entity_.set(index, value); }
    inline void set_entity(const ::EmbeddedProto::RepeatedFieldFixedSize<FeedEntity<FeedMessage_entity_FeedEntity_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_trip_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_route_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_start_time_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_start_date_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_label_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_license_plate_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_stop_time_update_REP_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_stop_time_update_StopTimeUpdate_stop_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_trip_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_route_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_start_time_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_start_date_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_label_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_license_plate_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_stop_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_active_period_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_agency_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_route_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_trip_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_route_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_time_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_date_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_stop_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_url_TranslatedString_translation_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_url_TranslatedString_translation_Translation_text_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_url_TranslatedString_translation_Translation_language_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_header_text_TranslatedString_translation_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_header_text_TranslatedString_translation_Translation_text_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_header_text_TranslatedString_translation_Translation_language_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_description_text_TranslatedString_translation_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_description_text_TranslatedString_translation_Translation_text_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_description_text_TranslatedString_translation_Translation_language_LENGTH>, FeedMessage_entity_REP_LENGTH>& values) { entity_ = values; }
    inline void add_entity(const FeedEntity<FeedMessage_entity_FeedEntity_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_trip_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_route_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_start_time_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_start_date_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_label_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_license_plate_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_stop_time_update_REP_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_stop_time_update_StopTimeUpdate_stop_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_trip_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_route_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_start_time_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_start_date_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_label_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_license_plate_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_stop_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_active_period_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_agency_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_route_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_trip_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_route_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_time_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_date_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_stop_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_url_TranslatedString_translation_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_url_TranslatedString_translation_Translation_text_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_url_TranslatedString_translation_Translation_language_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_header_text_TranslatedString_translation_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_header_text_TranslatedString_translation_Translation_text_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_header_text_TranslatedString_translation_Translation_language_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_description_text_TranslatedString_translation_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_description_text_TranslatedString_translation_Translation_text_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_description_text_TranslatedString_translation_Translation_language_LENGTH>& value) { entity_.add(value); }
    inline ::EmbeddedProto::RepeatedFieldFixedSize<FeedEntity<FeedMessage_entity_FeedEntity_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_trip_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_route_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_start_time_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_start_date_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_label_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_license_plate_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_stop_time_update_REP_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_stop_time_update_StopTimeUpdate_stop_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_trip_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_route_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_start_time_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_start_date_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_label_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_license_plate_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_stop_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_active_period_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_agency_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_route_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_trip_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_route_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_time_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_date_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_stop_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_url_TranslatedString_translation_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_url_TranslatedString_translation_Translation_text_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_url_TranslatedString_translation_Translation_language_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_header_text_TranslatedString_translation_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_header_text_TranslatedString_translation_Translation_text_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_header_text_TranslatedString_translation_Translation_language_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_description_text_TranslatedString_translation_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_description_text_TranslatedString_translation_Translation_text_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_description_text_TranslatedString_translation_Translation_language_LENGTH>, FeedMessage_entity_REP_LENGTH>& mutable_entity() { return entity_; }
    inline FeedEntity<FeedMessage_entity_FeedEntity_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_trip_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_route_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_start_time_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_start_date_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_label_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_license_plate_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_stop_time_update_REP_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_stop_time_update_StopTimeUpdate_stop_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_trip_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_route_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_start_time_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_start_date_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_label_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_license_plate_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_stop_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_active_period_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_agency_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_route_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_trip_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_route_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_time_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_date_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_stop_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_url_TranslatedString_translation_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_url_TranslatedString_translation_Translation_text_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_url_TranslatedString_translation_Translation_language_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_header_text_TranslatedString_translation_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_header_text_TranslatedString_translation_Translation_text_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_header_text_TranslatedString_translation_Translation_language_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_description_text_TranslatedString_translation_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_description_text_TranslatedString_translation_Translation_text_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_description_text_TranslatedString_translation_Translation_language_LENGTH>& mutable_entity(uint32_t index) { return entity_[index]; }
    inline const ::EmbeddedProto::RepeatedFieldFixedSize<FeedEntity<FeedMessage_entity_FeedEntity_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_trip_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_route_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_start_time_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_start_date_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_label_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_license_plate_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_stop_time_update_REP_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_stop_time_update_StopTimeUpdate_stop_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_trip_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_route_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_start_time_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_start_date_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_label_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_license_plate_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_stop_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_active_period_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_agency_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_route_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_trip_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_route_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_time_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_date_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_stop_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_url_TranslatedString_translation_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_url_TranslatedString_translation_Translation_text_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_url_TranslatedString_translation_Translation_language_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_header_text_TranslatedString_translation_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_header_text_TranslatedString_translation_Translation_text_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_header_text_TranslatedString_translation_Translation_language_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_description_text_TranslatedString_translation_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_description_text_TranslatedString_translation_Translation_text_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_description_text_TranslatedString_translation_Translation_language_LENGTH>, FeedMessage_entity_REP_LENGTH>& get_entity() const { return entity_; }
    inline const ::EmbeddedProto::RepeatedFieldFixedSize<FeedEntity<FeedMessage_entity_FeedEntity_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_trip_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_route_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_start_time_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_start_date_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_label_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_license_plate_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_stop_time_update_REP_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_stop_time_update_StopTimeUpdate_stop_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_trip_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_route_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_start_time_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_start_date_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_label_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_license_plate_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_stop_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_active_period_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_agency_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_route_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_trip_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_route_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_time_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_date_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_stop_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_url_TranslatedString_translation_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_url_TranslatedString_translation_Translation_text_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_url_TranslatedString_translation_Translation_language_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_header_text_TranslatedString_translation_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_header_text_TranslatedString_translation_Translation_text_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_header_text_TranslatedString_translation_Translation_language_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_description_text_TranslatedString_translation_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_description_text_TranslatedString_translation_Translation_text_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_description_text_TranslatedString_translation_Translation_language_LENGTH>, FeedMessage_entity_REP_LENGTH>& entity() const { return entity_; }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = header_.serialize_with_id(static_cast<uint32_t>(FieldNumber::HEADER), buffer, false);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = entity_.serialize_with_id(static_cast<uint32_t>(FieldNumber::ENTITY), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::HEADER:
            return_value = header_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::ENTITY:
            return_value = entity_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_header();
      clear_entity();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::HEADER:
          name = HEADER_NAME;
          break;
        case FieldNumber::ENTITY:
          name = ENTITY_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#endif

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = header_.to_string(left_chars, indent_level + 2, HEADER_NAME, true);
      left_chars = entity_.to_string(left_chars, indent_level + 2, ENTITY_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      FeedHeader<FeedMessage_header_FeedHeader_gtfs_realtime_version_LENGTH> header_;
      ::EmbeddedProto::RepeatedFieldFixedSize<FeedEntity<FeedMessage_entity_FeedEntity_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_trip_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_route_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_start_time_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_trip_TripDescriptor_start_date_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_id_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_label_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_vehicle_VehicleDescriptor_license_plate_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_stop_time_update_REP_LENGTH, FeedMessage_entity_FeedEntity_trip_update_TripUpdate_stop_time_update_StopTimeUpdate_stop_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_trip_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_route_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_start_time_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_trip_TripDescriptor_start_date_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_id_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_label_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_vehicle_VehicleDescriptor_license_plate_LENGTH, FeedMessage_entity_FeedEntity_vehicle_VehiclePosition_stop_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_active_period_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_agency_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_route_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_trip_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_route_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_time_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_trip_TripDescriptor_start_date_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_informed_entity_EntitySelector_stop_id_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_url_TranslatedString_translation_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_url_TranslatedString_translation_Translation_text_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_url_TranslatedString_translation_Translation_language_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_header_text_TranslatedString_translation_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_header_text_TranslatedString_translation_Translation_text_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_header_text_TranslatedString_translation_Translation_language_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_description_text_TranslatedString_translation_REP_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_description_text_TranslatedString_translation_Translation_text_LENGTH, FeedMessage_entity_FeedEntity_alert_Alert_description_text_TranslatedString_translation_Translation_language_LENGTH>, FeedMessage_entity_REP_LENGTH> entity_;

};

} // End of namespace transit_realtime
#endif // GTFS-REALTIME_H