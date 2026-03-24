/*
 *  This file is generated with Embedded Proto, PLEASE DO NOT EDIT!
 *  source: nyct-subway.proto
 */

// This file is generated. Please do not edit!
#ifndef NYCT-SUBWAY_H
#define NYCT-SUBWAY_H

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
#include "gtfs-realtime.h"


template<
    uint32_t NyctStopTimeUpdate_scheduled_track_LENGTH, 
    uint32_t NyctStopTimeUpdate_actual_track_LENGTH
>
class NyctStopTimeUpdate final: public ::EmbeddedProto::MessageInterface
{
  public:
    NyctStopTimeUpdate() = default;
    NyctStopTimeUpdate(const NyctStopTimeUpdate& rhs )
    {
      set_scheduled_track(rhs.get_scheduled_track());
      set_actual_track(rhs.get_actual_track());
    }

    NyctStopTimeUpdate(const NyctStopTimeUpdate&& rhs ) noexcept
    {
      set_scheduled_track(rhs.get_scheduled_track());
      set_actual_track(rhs.get_actual_track());
    }

    ~NyctStopTimeUpdate() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      SCHEDULED_TRACK = 1,
      ACTUAL_TRACK = 2
    };

    NyctStopTimeUpdate& operator=(const NyctStopTimeUpdate& rhs)
    {
      set_scheduled_track(rhs.get_scheduled_track());
      set_actual_track(rhs.get_actual_track());
      return *this;
    }

    NyctStopTimeUpdate& operator=(const NyctStopTimeUpdate&& rhs) noexcept
    {
      set_scheduled_track(rhs.get_scheduled_track());
      set_actual_track(rhs.get_actual_track());
      return *this;
    }

    static constexpr char const* SCHEDULED_TRACK_NAME = "scheduled_track";
    inline void clear_scheduled_track() { scheduled_track_.clear(); }
    inline ::EmbeddedProto::FieldString<NyctStopTimeUpdate_scheduled_track_LENGTH>& mutable_scheduled_track() { return scheduled_track_; }
    inline void set_scheduled_track(const ::EmbeddedProto::FieldString<NyctStopTimeUpdate_scheduled_track_LENGTH>& rhs) { scheduled_track_.set(rhs); }
    inline const ::EmbeddedProto::FieldString<NyctStopTimeUpdate_scheduled_track_LENGTH>& get_scheduled_track() const { return scheduled_track_; }
    inline const char* scheduled_track() const { return scheduled_track_.get_const(); }

    static constexpr char const* ACTUAL_TRACK_NAME = "actual_track";
    inline void clear_actual_track() { actual_track_.clear(); }
    inline ::EmbeddedProto::FieldString<NyctStopTimeUpdate_actual_track_LENGTH>& mutable_actual_track() { return actual_track_; }
    inline void set_actual_track(const ::EmbeddedProto::FieldString<NyctStopTimeUpdate_actual_track_LENGTH>& rhs) { actual_track_.set(rhs); }
    inline const ::EmbeddedProto::FieldString<NyctStopTimeUpdate_actual_track_LENGTH>& get_actual_track() const { return actual_track_; }
    inline const char* actual_track() const { return actual_track_.get_const(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = scheduled_track_.serialize_with_id(static_cast<uint32_t>(FieldNumber::SCHEDULED_TRACK), buffer, false);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = actual_track_.serialize_with_id(static_cast<uint32_t>(FieldNumber::ACTUAL_TRACK), buffer, false);
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
          case FieldNumber::SCHEDULED_TRACK:
            return_value = scheduled_track_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::ACTUAL_TRACK:
            return_value = actual_track_.deserialize_check_type(buffer, wire_type);
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
      clear_scheduled_track();
      clear_actual_track();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::SCHEDULED_TRACK:
          name = SCHEDULED_TRACK_NAME;
          break;
        case FieldNumber::ACTUAL_TRACK:
          name = ACTUAL_TRACK_NAME;
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

      left_chars = scheduled_track_.to_string(left_chars, indent_level + 2, SCHEDULED_TRACK_NAME, true);
      left_chars = actual_track_.to_string(left_chars, indent_level + 2, ACTUAL_TRACK_NAME, false);
  
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


      ::EmbeddedProto::FieldString<NyctStopTimeUpdate_scheduled_track_LENGTH> scheduled_track_;
      ::EmbeddedProto::FieldString<NyctStopTimeUpdate_actual_track_LENGTH> actual_track_;

};

template<
    uint32_t NyctTripDescriptor_train_id_LENGTH
>
class NyctTripDescriptor final: public ::EmbeddedProto::MessageInterface
{
  public:
    NyctTripDescriptor() = default;
    NyctTripDescriptor(const NyctTripDescriptor& rhs )
    {
      set_train_id(rhs.get_train_id());
      set_is_assigned(rhs.get_is_assigned());
      set_direction(rhs.get_direction());
    }

    NyctTripDescriptor(const NyctTripDescriptor&& rhs ) noexcept
    {
      set_train_id(rhs.get_train_id());
      set_is_assigned(rhs.get_is_assigned());
      set_direction(rhs.get_direction());
    }

    ~NyctTripDescriptor() override = default;

    enum class Direction : uint32_t
    {
      NORTH = 1,
      EAST = 2,
      SOUTH = 3,
      WEST = 4
    };

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      TRAIN_ID = 1,
      IS_ASSIGNED = 2,
      DIRECTION = 3
    };

    NyctTripDescriptor& operator=(const NyctTripDescriptor& rhs)
    {
      set_train_id(rhs.get_train_id());
      set_is_assigned(rhs.get_is_assigned());
      set_direction(rhs.get_direction());
      return *this;
    }

    NyctTripDescriptor& operator=(const NyctTripDescriptor&& rhs) noexcept
    {
      set_train_id(rhs.get_train_id());
      set_is_assigned(rhs.get_is_assigned());
      set_direction(rhs.get_direction());
      return *this;
    }

    static constexpr char const* TRAIN_ID_NAME = "train_id";
    inline void clear_train_id() { train_id_.clear(); }
    inline ::EmbeddedProto::FieldString<NyctTripDescriptor_train_id_LENGTH>& mutable_train_id() { return train_id_; }
    inline void set_train_id(const ::EmbeddedProto::FieldString<NyctTripDescriptor_train_id_LENGTH>& rhs) { train_id_.set(rhs); }
    inline const ::EmbeddedProto::FieldString<NyctTripDescriptor_train_id_LENGTH>& get_train_id() const { return train_id_; }
    inline const char* train_id() const { return train_id_.get_const(); }

    static constexpr char const* IS_ASSIGNED_NAME = "is_assigned";
    inline void clear_is_assigned() { is_assigned_.clear(); }
    inline void set_is_assigned(const bool& value) { is_assigned_ = value; }
    inline void set_is_assigned(const bool&& value) { is_assigned_ = value; }
    inline bool& mutable_is_assigned() { return is_assigned_.get(); }
    inline const bool& get_is_assigned() const { return is_assigned_.get(); }
    inline bool is_assigned() const { return is_assigned_.get(); }

    static constexpr char const* DIRECTION_NAME = "direction";
    inline void clear_direction() { direction_.clear(); }
    inline void set_direction(const Direction& value) { direction_ = value; }
    inline void set_direction(const Direction&& value) { direction_ = value; }
    inline const Direction& get_direction() const { return direction_.get(); }
    inline Direction direction() const { return direction_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = train_id_.serialize_with_id(static_cast<uint32_t>(FieldNumber::TRAIN_ID), buffer, false);
      }

      if((false != is_assigned_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = is_assigned_.serialize_with_id(static_cast<uint32_t>(FieldNumber::IS_ASSIGNED), buffer, false);
      }

      if((static_cast<Direction>(0) != direction_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = direction_.serialize_with_id(static_cast<uint32_t>(FieldNumber::DIRECTION), buffer, false);
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
          case FieldNumber::TRAIN_ID:
            return_value = train_id_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::IS_ASSIGNED:
            return_value = is_assigned_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::DIRECTION:
            return_value = direction_.deserialize_check_type(buffer, wire_type);
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
      clear_train_id();
      clear_is_assigned();
      clear_direction();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::TRAIN_ID:
          name = TRAIN_ID_NAME;
          break;
        case FieldNumber::IS_ASSIGNED:
          name = IS_ASSIGNED_NAME;
          break;
        case FieldNumber::DIRECTION:
          name = DIRECTION_NAME;
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

      left_chars = train_id_.to_string(left_chars, indent_level + 2, TRAIN_ID_NAME, true);
      left_chars = is_assigned_.to_string(left_chars, indent_level + 2, IS_ASSIGNED_NAME, false);
      left_chars = direction_.to_string(left_chars, indent_level + 2, DIRECTION_NAME, false);
  
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


      ::EmbeddedProto::FieldString<NyctTripDescriptor_train_id_LENGTH> train_id_;
      EmbeddedProto::boolean is_assigned_ = false;
      EmbeddedProto::enumeration<Direction> direction_ = static_cast<Direction>(0);

};

template<
    uint32_t TripReplacementPeriod_route_id_LENGTH
>
class TripReplacementPeriod final: public ::EmbeddedProto::MessageInterface
{
  public:
    TripReplacementPeriod() = default;
    TripReplacementPeriod(const TripReplacementPeriod& rhs )
    {
      set_route_id(rhs.get_route_id());
      set_replacement_period(rhs.get_replacement_period());
    }

    TripReplacementPeriod(const TripReplacementPeriod&& rhs ) noexcept
    {
      set_route_id(rhs.get_route_id());
      set_replacement_period(rhs.get_replacement_period());
    }

    ~TripReplacementPeriod() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      ROUTE_ID = 1,
      REPLACEMENT_PERIOD = 2
    };

    TripReplacementPeriod& operator=(const TripReplacementPeriod& rhs)
    {
      set_route_id(rhs.get_route_id());
      set_replacement_period(rhs.get_replacement_period());
      return *this;
    }

    TripReplacementPeriod& operator=(const TripReplacementPeriod&& rhs) noexcept
    {
      set_route_id(rhs.get_route_id());
      set_replacement_period(rhs.get_replacement_period());
      return *this;
    }

    static constexpr char const* ROUTE_ID_NAME = "route_id";
    inline void clear_route_id() { route_id_.clear(); }
    inline ::EmbeddedProto::FieldString<TripReplacementPeriod_route_id_LENGTH>& mutable_route_id() { return route_id_; }
    inline void set_route_id(const ::EmbeddedProto::FieldString<TripReplacementPeriod_route_id_LENGTH>& rhs) { route_id_.set(rhs); }
    inline const ::EmbeddedProto::FieldString<TripReplacementPeriod_route_id_LENGTH>& get_route_id() const { return route_id_; }
    inline const char* route_id() const { return route_id_.get_const(); }

    static constexpr char const* REPLACEMENT_PERIOD_NAME = "replacement_period";
    inline void clear_replacement_period() { replacement_period_.clear(); }
    inline void set_replacement_period(const transit_realtime::TimeRange& value) { replacement_period_ = value; }
    inline void set_replacement_period(const transit_realtime::TimeRange&& value) { replacement_period_ = value; }
    inline transit_realtime::TimeRange& mutable_replacement_period() { return replacement_period_; }
    inline const transit_realtime::TimeRange& get_replacement_period() const { return replacement_period_; }
    inline const transit_realtime::TimeRange& replacement_period() const { return replacement_period_; }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = route_id_.serialize_with_id(static_cast<uint32_t>(FieldNumber::ROUTE_ID), buffer, false);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = replacement_period_.serialize_with_id(static_cast<uint32_t>(FieldNumber::REPLACEMENT_PERIOD), buffer, false);
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
          case FieldNumber::ROUTE_ID:
            return_value = route_id_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::REPLACEMENT_PERIOD:
            return_value = replacement_period_.deserialize_check_type(buffer, wire_type);
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
      clear_route_id();
      clear_replacement_period();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::ROUTE_ID:
          name = ROUTE_ID_NAME;
          break;
        case FieldNumber::REPLACEMENT_PERIOD:
          name = REPLACEMENT_PERIOD_NAME;
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

      left_chars = route_id_.to_string(left_chars, indent_level + 2, ROUTE_ID_NAME, true);
      left_chars = replacement_period_.to_string(left_chars, indent_level + 2, REPLACEMENT_PERIOD_NAME, false);
  
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


      ::EmbeddedProto::FieldString<TripReplacementPeriod_route_id_LENGTH> route_id_;
      transit_realtime::TimeRange replacement_period_;

};

template<
    uint32_t NyctFeedHeader_nyct_subway_version_LENGTH, 
    uint32_t NyctFeedHeader_trip_replacement_period_REP_LENGTH, 
    uint32_t NyctFeedHeader_trip_replacement_period_TripReplacementPeriod_route_id_LENGTH
>
class NyctFeedHeader final: public ::EmbeddedProto::MessageInterface
{
  public:
    NyctFeedHeader() = default;
    NyctFeedHeader(const NyctFeedHeader& rhs )
    {
      set_nyct_subway_version(rhs.get_nyct_subway_version());
      set_trip_replacement_period(rhs.get_trip_replacement_period());
    }

    NyctFeedHeader(const NyctFeedHeader&& rhs ) noexcept
    {
      set_nyct_subway_version(rhs.get_nyct_subway_version());
      set_trip_replacement_period(rhs.get_trip_replacement_period());
    }

    ~NyctFeedHeader() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      NYCT_SUBWAY_VERSION = 1,
      TRIP_REPLACEMENT_PERIOD = 2
    };

    NyctFeedHeader& operator=(const NyctFeedHeader& rhs)
    {
      set_nyct_subway_version(rhs.get_nyct_subway_version());
      set_trip_replacement_period(rhs.get_trip_replacement_period());
      return *this;
    }

    NyctFeedHeader& operator=(const NyctFeedHeader&& rhs) noexcept
    {
      set_nyct_subway_version(rhs.get_nyct_subway_version());
      set_trip_replacement_period(rhs.get_trip_replacement_period());
      return *this;
    }

    static constexpr char const* NYCT_SUBWAY_VERSION_NAME = "nyct_subway_version";
    inline void clear_nyct_subway_version() { nyct_subway_version_.clear(); }
    inline ::EmbeddedProto::FieldString<NyctFeedHeader_nyct_subway_version_LENGTH>& mutable_nyct_subway_version() { return nyct_subway_version_; }
    inline void set_nyct_subway_version(const ::EmbeddedProto::FieldString<NyctFeedHeader_nyct_subway_version_LENGTH>& rhs) { nyct_subway_version_.set(rhs); }
    inline const ::EmbeddedProto::FieldString<NyctFeedHeader_nyct_subway_version_LENGTH>& get_nyct_subway_version() const { return nyct_subway_version_; }
    inline const char* nyct_subway_version() const { return nyct_subway_version_.get_const(); }

    static constexpr char const* TRIP_REPLACEMENT_PERIOD_NAME = "trip_replacement_period";
    inline const TripReplacementPeriod<NyctFeedHeader_trip_replacement_period_TripReplacementPeriod_route_id_LENGTH>& trip_replacement_period(uint32_t index) const { return trip_replacement_period_[index]; }
    inline void clear_trip_replacement_period() { trip_replacement_period_.clear(); }
    inline void set_trip_replacement_period(uint32_t index, const TripReplacementPeriod<NyctFeedHeader_trip_replacement_period_TripReplacementPeriod_route_id_LENGTH>& value) { trip_replacement_period_.set(index, value); }
    inline void set_trip_replacement_period(uint32_t index, const TripReplacementPeriod<NyctFeedHeader_trip_replacement_period_TripReplacementPeriod_route_id_LENGTH>&& value) { trip_replacement_period_.set(index, value); }
    inline void set_trip_replacement_period(const ::EmbeddedProto::RepeatedFieldFixedSize<TripReplacementPeriod<NyctFeedHeader_trip_replacement_period_TripReplacementPeriod_route_id_LENGTH>, NyctFeedHeader_trip_replacement_period_REP_LENGTH>& values) { trip_replacement_period_ = values; }
    inline void add_trip_replacement_period(const TripReplacementPeriod<NyctFeedHeader_trip_replacement_period_TripReplacementPeriod_route_id_LENGTH>& value) { trip_replacement_period_.add(value); }
    inline ::EmbeddedProto::RepeatedFieldFixedSize<TripReplacementPeriod<NyctFeedHeader_trip_replacement_period_TripReplacementPeriod_route_id_LENGTH>, NyctFeedHeader_trip_replacement_period_REP_LENGTH>& mutable_trip_replacement_period() { return trip_replacement_period_; }
    inline TripReplacementPeriod<NyctFeedHeader_trip_replacement_period_TripReplacementPeriod_route_id_LENGTH>& mutable_trip_replacement_period(uint32_t index) { return trip_replacement_period_[index]; }
    inline const ::EmbeddedProto::RepeatedFieldFixedSize<TripReplacementPeriod<NyctFeedHeader_trip_replacement_period_TripReplacementPeriod_route_id_LENGTH>, NyctFeedHeader_trip_replacement_period_REP_LENGTH>& get_trip_replacement_period() const { return trip_replacement_period_; }
    inline const ::EmbeddedProto::RepeatedFieldFixedSize<TripReplacementPeriod<NyctFeedHeader_trip_replacement_period_TripReplacementPeriod_route_id_LENGTH>, NyctFeedHeader_trip_replacement_period_REP_LENGTH>& trip_replacement_period() const { return trip_replacement_period_; }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = nyct_subway_version_.serialize_with_id(static_cast<uint32_t>(FieldNumber::NYCT_SUBWAY_VERSION), buffer, false);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = trip_replacement_period_.serialize_with_id(static_cast<uint32_t>(FieldNumber::TRIP_REPLACEMENT_PERIOD), buffer, false);
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
          case FieldNumber::NYCT_SUBWAY_VERSION:
            return_value = nyct_subway_version_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::TRIP_REPLACEMENT_PERIOD:
            return_value = trip_replacement_period_.deserialize_check_type(buffer, wire_type);
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
      clear_nyct_subway_version();
      clear_trip_replacement_period();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::NYCT_SUBWAY_VERSION:
          name = NYCT_SUBWAY_VERSION_NAME;
          break;
        case FieldNumber::TRIP_REPLACEMENT_PERIOD:
          name = TRIP_REPLACEMENT_PERIOD_NAME;
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

      left_chars = nyct_subway_version_.to_string(left_chars, indent_level + 2, NYCT_SUBWAY_VERSION_NAME, true);
      left_chars = trip_replacement_period_.to_string(left_chars, indent_level + 2, TRIP_REPLACEMENT_PERIOD_NAME, false);
  
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


      ::EmbeddedProto::FieldString<NyctFeedHeader_nyct_subway_version_LENGTH> nyct_subway_version_;
      ::EmbeddedProto::RepeatedFieldFixedSize<TripReplacementPeriod<NyctFeedHeader_trip_replacement_period_TripReplacementPeriod_route_id_LENGTH>, NyctFeedHeader_trip_replacement_period_REP_LENGTH> trip_replacement_period_;

};

#endif // NYCT-SUBWAY_H