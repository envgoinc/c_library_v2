#pragma once
// MESSAGE ESC_INFO PACKING

#define MAVLINK_MSG_ID_ESC_INFO 290


typedef struct __mavlink_esc_info_t {
 uint64_t time_usec; /*< [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number.*/
 uint32_t error_count[8]; /*<  Number of reported errors by each ESC since boot.*/
 uint16_t counter; /*<  Counter of data packets received.*/
 uint16_t failure_flags[8]; /*<  Bitmap of ESC failure flags.*/
 int16_t temperature[8]; /*< [cdegC] Temperature of each ESC. INT16_MAX: if data not supplied by ESC.*/
 uint8_t index; /*<  Index of the first ESC in this message. minValue = 0, maxValue = 60, increment = 4.*/
 uint8_t count; /*<  Total number of ESCs in all messages of this type. Message fields with an index higher than this should be ignored because they contain invalid data.*/
 uint8_t connection_type; /*<  Connection type protocol for all ESC.*/
 uint8_t info; /*<  Information regarding online/offline status of each ESC.*/
 uint8_t state[8]; /*<  State of each ESC.*/
} mavlink_esc_info_t;

#define MAVLINK_MSG_ID_ESC_INFO_LEN 86
#define MAVLINK_MSG_ID_ESC_INFO_MIN_LEN 86
#define MAVLINK_MSG_ID_290_LEN 86
#define MAVLINK_MSG_ID_290_MIN_LEN 86

#define MAVLINK_MSG_ID_ESC_INFO_CRC 152
#define MAVLINK_MSG_ID_290_CRC 152

#define MAVLINK_MSG_ESC_INFO_FIELD_ERROR_COUNT_LEN 8
#define MAVLINK_MSG_ESC_INFO_FIELD_FAILURE_FLAGS_LEN 8
#define MAVLINK_MSG_ESC_INFO_FIELD_TEMPERATURE_LEN 8
#define MAVLINK_MSG_ESC_INFO_FIELD_STATE_LEN 8

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ESC_INFO { \
    290, \
    "ESC_INFO", \
    10, \
    {  { "index", NULL, MAVLINK_TYPE_UINT8_T, 0, 74, offsetof(mavlink_esc_info_t, index) }, \
         { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_esc_info_t, time_usec) }, \
         { "counter", NULL, MAVLINK_TYPE_UINT16_T, 0, 40, offsetof(mavlink_esc_info_t, counter) }, \
         { "count", NULL, MAVLINK_TYPE_UINT8_T, 0, 75, offsetof(mavlink_esc_info_t, count) }, \
         { "connection_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 76, offsetof(mavlink_esc_info_t, connection_type) }, \
         { "info", NULL, MAVLINK_TYPE_UINT8_T, 0, 77, offsetof(mavlink_esc_info_t, info) }, \
         { "failure_flags", NULL, MAVLINK_TYPE_UINT16_T, 8, 42, offsetof(mavlink_esc_info_t, failure_flags) }, \
         { "error_count", NULL, MAVLINK_TYPE_UINT32_T, 8, 8, offsetof(mavlink_esc_info_t, error_count) }, \
         { "temperature", NULL, MAVLINK_TYPE_INT16_T, 8, 58, offsetof(mavlink_esc_info_t, temperature) }, \
         { "state", NULL, MAVLINK_TYPE_UINT8_T, 8, 78, offsetof(mavlink_esc_info_t, state) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ESC_INFO { \
    "ESC_INFO", \
    10, \
    {  { "index", NULL, MAVLINK_TYPE_UINT8_T, 0, 74, offsetof(mavlink_esc_info_t, index) }, \
         { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_esc_info_t, time_usec) }, \
         { "counter", NULL, MAVLINK_TYPE_UINT16_T, 0, 40, offsetof(mavlink_esc_info_t, counter) }, \
         { "count", NULL, MAVLINK_TYPE_UINT8_T, 0, 75, offsetof(mavlink_esc_info_t, count) }, \
         { "connection_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 76, offsetof(mavlink_esc_info_t, connection_type) }, \
         { "info", NULL, MAVLINK_TYPE_UINT8_T, 0, 77, offsetof(mavlink_esc_info_t, info) }, \
         { "failure_flags", NULL, MAVLINK_TYPE_UINT16_T, 8, 42, offsetof(mavlink_esc_info_t, failure_flags) }, \
         { "error_count", NULL, MAVLINK_TYPE_UINT32_T, 8, 8, offsetof(mavlink_esc_info_t, error_count) }, \
         { "temperature", NULL, MAVLINK_TYPE_INT16_T, 8, 58, offsetof(mavlink_esc_info_t, temperature) }, \
         { "state", NULL, MAVLINK_TYPE_UINT8_T, 8, 78, offsetof(mavlink_esc_info_t, state) }, \
         } \
}
#endif

/**
 * @brief Pack a esc_info message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param index  Index of the first ESC in this message. minValue = 0, maxValue = 60, increment = 4.
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number.
 * @param counter  Counter of data packets received.
 * @param count  Total number of ESCs in all messages of this type. Message fields with an index higher than this should be ignored because they contain invalid data.
 * @param connection_type  Connection type protocol for all ESC.
 * @param info  Information regarding online/offline status of each ESC.
 * @param failure_flags  Bitmap of ESC failure flags.
 * @param error_count  Number of reported errors by each ESC since boot.
 * @param temperature [cdegC] Temperature of each ESC. INT16_MAX: if data not supplied by ESC.
 * @param state  State of each ESC.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_esc_info_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t index, uint64_t time_usec, uint16_t counter, uint8_t count, uint8_t connection_type, uint8_t info, const uint16_t *failure_flags, const uint32_t *error_count, const int16_t *temperature, const uint8_t *state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ESC_INFO_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint16_t(buf, 40, counter);
    _mav_put_uint8_t(buf, 74, index);
    _mav_put_uint8_t(buf, 75, count);
    _mav_put_uint8_t(buf, 76, connection_type);
    _mav_put_uint8_t(buf, 77, info);
    _mav_put_uint32_t_array(buf, 8, error_count, 8);
    _mav_put_uint16_t_array(buf, 42, failure_flags, 8);
    _mav_put_int16_t_array(buf, 58, temperature, 8);
    _mav_put_uint8_t_array(buf, 78, state, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ESC_INFO_LEN);
#else
    mavlink_esc_info_t packet;
    packet.time_usec = time_usec;
    packet.counter = counter;
    packet.index = index;
    packet.count = count;
    packet.connection_type = connection_type;
    packet.info = info;
    mav_array_memcpy(packet.error_count, error_count, sizeof(uint32_t)*8);
    mav_array_memcpy(packet.failure_flags, failure_flags, sizeof(uint16_t)*8);
    mav_array_memcpy(packet.temperature, temperature, sizeof(int16_t)*8);
    mav_array_memcpy(packet.state, state, sizeof(uint8_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ESC_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ESC_INFO;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ESC_INFO_MIN_LEN, MAVLINK_MSG_ID_ESC_INFO_LEN, MAVLINK_MSG_ID_ESC_INFO_CRC);
}

/**
 * @brief Pack a esc_info message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param index  Index of the first ESC in this message. minValue = 0, maxValue = 60, increment = 4.
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number.
 * @param counter  Counter of data packets received.
 * @param count  Total number of ESCs in all messages of this type. Message fields with an index higher than this should be ignored because they contain invalid data.
 * @param connection_type  Connection type protocol for all ESC.
 * @param info  Information regarding online/offline status of each ESC.
 * @param failure_flags  Bitmap of ESC failure flags.
 * @param error_count  Number of reported errors by each ESC since boot.
 * @param temperature [cdegC] Temperature of each ESC. INT16_MAX: if data not supplied by ESC.
 * @param state  State of each ESC.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_esc_info_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t index,uint64_t time_usec,uint16_t counter,uint8_t count,uint8_t connection_type,uint8_t info,const uint16_t *failure_flags,const uint32_t *error_count,const int16_t *temperature,const uint8_t *state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ESC_INFO_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint16_t(buf, 40, counter);
    _mav_put_uint8_t(buf, 74, index);
    _mav_put_uint8_t(buf, 75, count);
    _mav_put_uint8_t(buf, 76, connection_type);
    _mav_put_uint8_t(buf, 77, info);
    _mav_put_uint32_t_array(buf, 8, error_count, 8);
    _mav_put_uint16_t_array(buf, 42, failure_flags, 8);
    _mav_put_int16_t_array(buf, 58, temperature, 8);
    _mav_put_uint8_t_array(buf, 78, state, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ESC_INFO_LEN);
#else
    mavlink_esc_info_t packet;
    packet.time_usec = time_usec;
    packet.counter = counter;
    packet.index = index;
    packet.count = count;
    packet.connection_type = connection_type;
    packet.info = info;
    mav_array_memcpy(packet.error_count, error_count, sizeof(uint32_t)*8);
    mav_array_memcpy(packet.failure_flags, failure_flags, sizeof(uint16_t)*8);
    mav_array_memcpy(packet.temperature, temperature, sizeof(int16_t)*8);
    mav_array_memcpy(packet.state, state, sizeof(uint8_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ESC_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ESC_INFO;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ESC_INFO_MIN_LEN, MAVLINK_MSG_ID_ESC_INFO_LEN, MAVLINK_MSG_ID_ESC_INFO_CRC);
}

/**
 * @brief Encode a esc_info struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param esc_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_esc_info_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_esc_info_t* esc_info)
{
    return mavlink_msg_esc_info_pack(system_id, component_id, msg, esc_info->index, esc_info->time_usec, esc_info->counter, esc_info->count, esc_info->connection_type, esc_info->info, esc_info->failure_flags, esc_info->error_count, esc_info->temperature, esc_info->state);
}

/**
 * @brief Encode a esc_info struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param esc_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_esc_info_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_esc_info_t* esc_info)
{
    return mavlink_msg_esc_info_pack_chan(system_id, component_id, chan, msg, esc_info->index, esc_info->time_usec, esc_info->counter, esc_info->count, esc_info->connection_type, esc_info->info, esc_info->failure_flags, esc_info->error_count, esc_info->temperature, esc_info->state);
}

/**
 * @brief Send a esc_info message
 * @param chan MAVLink channel to send the message
 *
 * @param index  Index of the first ESC in this message. minValue = 0, maxValue = 60, increment = 4.
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number.
 * @param counter  Counter of data packets received.
 * @param count  Total number of ESCs in all messages of this type. Message fields with an index higher than this should be ignored because they contain invalid data.
 * @param connection_type  Connection type protocol for all ESC.
 * @param info  Information regarding online/offline status of each ESC.
 * @param failure_flags  Bitmap of ESC failure flags.
 * @param error_count  Number of reported errors by each ESC since boot.
 * @param temperature [cdegC] Temperature of each ESC. INT16_MAX: if data not supplied by ESC.
 * @param state  State of each ESC.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_esc_info_send(mavlink_channel_t chan, uint8_t index, uint64_t time_usec, uint16_t counter, uint8_t count, uint8_t connection_type, uint8_t info, const uint16_t *failure_flags, const uint32_t *error_count, const int16_t *temperature, const uint8_t *state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ESC_INFO_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint16_t(buf, 40, counter);
    _mav_put_uint8_t(buf, 74, index);
    _mav_put_uint8_t(buf, 75, count);
    _mav_put_uint8_t(buf, 76, connection_type);
    _mav_put_uint8_t(buf, 77, info);
    _mav_put_uint32_t_array(buf, 8, error_count, 8);
    _mav_put_uint16_t_array(buf, 42, failure_flags, 8);
    _mav_put_int16_t_array(buf, 58, temperature, 8);
    _mav_put_uint8_t_array(buf, 78, state, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESC_INFO, buf, MAVLINK_MSG_ID_ESC_INFO_MIN_LEN, MAVLINK_MSG_ID_ESC_INFO_LEN, MAVLINK_MSG_ID_ESC_INFO_CRC);
#else
    mavlink_esc_info_t packet;
    packet.time_usec = time_usec;
    packet.counter = counter;
    packet.index = index;
    packet.count = count;
    packet.connection_type = connection_type;
    packet.info = info;
    mav_array_memcpy(packet.error_count, error_count, sizeof(uint32_t)*8);
    mav_array_memcpy(packet.failure_flags, failure_flags, sizeof(uint16_t)*8);
    mav_array_memcpy(packet.temperature, temperature, sizeof(int16_t)*8);
    mav_array_memcpy(packet.state, state, sizeof(uint8_t)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESC_INFO, (const char *)&packet, MAVLINK_MSG_ID_ESC_INFO_MIN_LEN, MAVLINK_MSG_ID_ESC_INFO_LEN, MAVLINK_MSG_ID_ESC_INFO_CRC);
#endif
}

/**
 * @brief Send a esc_info message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_esc_info_send_struct(mavlink_channel_t chan, const mavlink_esc_info_t* esc_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_esc_info_send(chan, esc_info->index, esc_info->time_usec, esc_info->counter, esc_info->count, esc_info->connection_type, esc_info->info, esc_info->failure_flags, esc_info->error_count, esc_info->temperature, esc_info->state);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESC_INFO, (const char *)esc_info, MAVLINK_MSG_ID_ESC_INFO_MIN_LEN, MAVLINK_MSG_ID_ESC_INFO_LEN, MAVLINK_MSG_ID_ESC_INFO_CRC);
#endif
}

#if MAVLINK_MSG_ID_ESC_INFO_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_esc_info_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t index, uint64_t time_usec, uint16_t counter, uint8_t count, uint8_t connection_type, uint8_t info, const uint16_t *failure_flags, const uint32_t *error_count, const int16_t *temperature, const uint8_t *state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint16_t(buf, 40, counter);
    _mav_put_uint8_t(buf, 74, index);
    _mav_put_uint8_t(buf, 75, count);
    _mav_put_uint8_t(buf, 76, connection_type);
    _mav_put_uint8_t(buf, 77, info);
    _mav_put_uint32_t_array(buf, 8, error_count, 8);
    _mav_put_uint16_t_array(buf, 42, failure_flags, 8);
    _mav_put_int16_t_array(buf, 58, temperature, 8);
    _mav_put_uint8_t_array(buf, 78, state, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESC_INFO, buf, MAVLINK_MSG_ID_ESC_INFO_MIN_LEN, MAVLINK_MSG_ID_ESC_INFO_LEN, MAVLINK_MSG_ID_ESC_INFO_CRC);
#else
    mavlink_esc_info_t *packet = (mavlink_esc_info_t *)msgbuf;
    packet->time_usec = time_usec;
    packet->counter = counter;
    packet->index = index;
    packet->count = count;
    packet->connection_type = connection_type;
    packet->info = info;
    mav_array_memcpy(packet->error_count, error_count, sizeof(uint32_t)*8);
    mav_array_memcpy(packet->failure_flags, failure_flags, sizeof(uint16_t)*8);
    mav_array_memcpy(packet->temperature, temperature, sizeof(int16_t)*8);
    mav_array_memcpy(packet->state, state, sizeof(uint8_t)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESC_INFO, (const char *)packet, MAVLINK_MSG_ID_ESC_INFO_MIN_LEN, MAVLINK_MSG_ID_ESC_INFO_LEN, MAVLINK_MSG_ID_ESC_INFO_CRC);
#endif
}
#endif

#endif

// MESSAGE ESC_INFO UNPACKING


/**
 * @brief Get field index from esc_info message
 *
 * @return  Index of the first ESC in this message. minValue = 0, maxValue = 60, increment = 4.
 */
static inline uint8_t mavlink_msg_esc_info_get_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  74);
}

/**
 * @brief Get field time_usec from esc_info message
 *
 * @return [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number.
 */
static inline uint64_t mavlink_msg_esc_info_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field counter from esc_info message
 *
 * @return  Counter of data packets received.
 */
static inline uint16_t mavlink_msg_esc_info_get_counter(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  40);
}

/**
 * @brief Get field count from esc_info message
 *
 * @return  Total number of ESCs in all messages of this type. Message fields with an index higher than this should be ignored because they contain invalid data.
 */
static inline uint8_t mavlink_msg_esc_info_get_count(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  75);
}

/**
 * @brief Get field connection_type from esc_info message
 *
 * @return  Connection type protocol for all ESC.
 */
static inline uint8_t mavlink_msg_esc_info_get_connection_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  76);
}

/**
 * @brief Get field info from esc_info message
 *
 * @return  Information regarding online/offline status of each ESC.
 */
static inline uint8_t mavlink_msg_esc_info_get_info(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  77);
}

/**
 * @brief Get field failure_flags from esc_info message
 *
 * @return  Bitmap of ESC failure flags.
 */
static inline uint16_t mavlink_msg_esc_info_get_failure_flags(const mavlink_message_t* msg, uint16_t *failure_flags)
{
    return _MAV_RETURN_uint16_t_array(msg, failure_flags, 8,  42);
}

/**
 * @brief Get field error_count from esc_info message
 *
 * @return  Number of reported errors by each ESC since boot.
 */
static inline uint16_t mavlink_msg_esc_info_get_error_count(const mavlink_message_t* msg, uint32_t *error_count)
{
    return _MAV_RETURN_uint32_t_array(msg, error_count, 8,  8);
}

/**
 * @brief Get field temperature from esc_info message
 *
 * @return [cdegC] Temperature of each ESC. INT16_MAX: if data not supplied by ESC.
 */
static inline uint16_t mavlink_msg_esc_info_get_temperature(const mavlink_message_t* msg, int16_t *temperature)
{
    return _MAV_RETURN_int16_t_array(msg, temperature, 8,  58);
}

/**
 * @brief Get field state from esc_info message
 *
 * @return  State of each ESC.
 */
static inline uint16_t mavlink_msg_esc_info_get_state(const mavlink_message_t* msg, uint8_t *state)
{
    return _MAV_RETURN_uint8_t_array(msg, state, 8,  78);
}

/**
 * @brief Decode a esc_info message into a struct
 *
 * @param msg The message to decode
 * @param esc_info C-struct to decode the message contents into
 */
static inline void mavlink_msg_esc_info_decode(const mavlink_message_t* msg, mavlink_esc_info_t* esc_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    esc_info->time_usec = mavlink_msg_esc_info_get_time_usec(msg);
    mavlink_msg_esc_info_get_error_count(msg, esc_info->error_count);
    esc_info->counter = mavlink_msg_esc_info_get_counter(msg);
    mavlink_msg_esc_info_get_failure_flags(msg, esc_info->failure_flags);
    mavlink_msg_esc_info_get_temperature(msg, esc_info->temperature);
    esc_info->index = mavlink_msg_esc_info_get_index(msg);
    esc_info->count = mavlink_msg_esc_info_get_count(msg);
    esc_info->connection_type = mavlink_msg_esc_info_get_connection_type(msg);
    esc_info->info = mavlink_msg_esc_info_get_info(msg);
    mavlink_msg_esc_info_get_state(msg, esc_info->state);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ESC_INFO_LEN? msg->len : MAVLINK_MSG_ID_ESC_INFO_LEN;
        memset(esc_info, 0, MAVLINK_MSG_ID_ESC_INFO_LEN);
    memcpy(esc_info, _MAV_PAYLOAD(msg), len);
#endif
}
