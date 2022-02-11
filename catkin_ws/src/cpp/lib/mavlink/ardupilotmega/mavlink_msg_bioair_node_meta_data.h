#pragma once
// MESSAGE BIOAIR_NODE_META_DATA PACKING

#define MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA 20015


typedef struct __mavlink_bioair_node_meta_data_t {
 int32_t lat[5]; /*<  Position Latitude*/
 int32_t lon[5]; /*<  Position Longitude*/
 float alt[5]; /*<  Position Altitude*/
 int8_t time_validity_delta[5]; /*<  Time of Validity Delta*/
 uint8_t node_state[5]; /*<  Node State*/
 uint8_t tentacle_state[5]; /*<  Tentacle State*/
 uint8_t node_id[5]; /*<  Node ID*/
} mavlink_bioair_node_meta_data_t;

#define MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA_LEN 80
#define MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA_MIN_LEN 80
#define MAVLINK_MSG_ID_20015_LEN 80
#define MAVLINK_MSG_ID_20015_MIN_LEN 80

#define MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA_CRC 32
#define MAVLINK_MSG_ID_20015_CRC 32

#define MAVLINK_MSG_BIOAIR_NODE_META_DATA_FIELD_LAT_LEN 5
#define MAVLINK_MSG_BIOAIR_NODE_META_DATA_FIELD_LON_LEN 5
#define MAVLINK_MSG_BIOAIR_NODE_META_DATA_FIELD_ALT_LEN 5
#define MAVLINK_MSG_BIOAIR_NODE_META_DATA_FIELD_TIME_VALIDITY_DELTA_LEN 5
#define MAVLINK_MSG_BIOAIR_NODE_META_DATA_FIELD_NODE_STATE_LEN 5
#define MAVLINK_MSG_BIOAIR_NODE_META_DATA_FIELD_TENTACLE_STATE_LEN 5
#define MAVLINK_MSG_BIOAIR_NODE_META_DATA_FIELD_NODE_ID_LEN 5

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_BIOAIR_NODE_META_DATA { \
    20015, \
    "BIOAIR_NODE_META_DATA", \
    7, \
    {  { "lat", NULL, MAVLINK_TYPE_INT32_T, 5, 0, offsetof(mavlink_bioair_node_meta_data_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 5, 20, offsetof(mavlink_bioair_node_meta_data_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 5, 40, offsetof(mavlink_bioair_node_meta_data_t, alt) }, \
         { "time_validity_delta", NULL, MAVLINK_TYPE_INT8_T, 5, 60, offsetof(mavlink_bioair_node_meta_data_t, time_validity_delta) }, \
         { "node_state", NULL, MAVLINK_TYPE_UINT8_T, 5, 65, offsetof(mavlink_bioair_node_meta_data_t, node_state) }, \
         { "tentacle_state", NULL, MAVLINK_TYPE_UINT8_T, 5, 70, offsetof(mavlink_bioair_node_meta_data_t, tentacle_state) }, \
         { "node_id", NULL, MAVLINK_TYPE_UINT8_T, 5, 75, offsetof(mavlink_bioair_node_meta_data_t, node_id) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_BIOAIR_NODE_META_DATA { \
    "BIOAIR_NODE_META_DATA", \
    7, \
    {  { "lat", NULL, MAVLINK_TYPE_INT32_T, 5, 0, offsetof(mavlink_bioair_node_meta_data_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 5, 20, offsetof(mavlink_bioair_node_meta_data_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 5, 40, offsetof(mavlink_bioair_node_meta_data_t, alt) }, \
         { "time_validity_delta", NULL, MAVLINK_TYPE_INT8_T, 5, 60, offsetof(mavlink_bioair_node_meta_data_t, time_validity_delta) }, \
         { "node_state", NULL, MAVLINK_TYPE_UINT8_T, 5, 65, offsetof(mavlink_bioair_node_meta_data_t, node_state) }, \
         { "tentacle_state", NULL, MAVLINK_TYPE_UINT8_T, 5, 70, offsetof(mavlink_bioair_node_meta_data_t, tentacle_state) }, \
         { "node_id", NULL, MAVLINK_TYPE_UINT8_T, 5, 75, offsetof(mavlink_bioair_node_meta_data_t, node_id) }, \
         } \
}
#endif

/**
 * @brief Pack a bioair_node_meta_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param lat  Position Latitude
 * @param lon  Position Longitude
 * @param alt  Position Altitude
 * @param time_validity_delta  Time of Validity Delta
 * @param node_state  Node State
 * @param tentacle_state  Tentacle State
 * @param node_id  Node ID
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_bioair_node_meta_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const int32_t *lat, const int32_t *lon, const float *alt, const int8_t *time_validity_delta, const uint8_t *node_state, const uint8_t *tentacle_state, const uint8_t *node_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA_LEN];

    _mav_put_int32_t_array(buf, 0, lat, 5);
    _mav_put_int32_t_array(buf, 20, lon, 5);
    _mav_put_float_array(buf, 40, alt, 5);
    _mav_put_int8_t_array(buf, 60, time_validity_delta, 5);
    _mav_put_uint8_t_array(buf, 65, node_state, 5);
    _mav_put_uint8_t_array(buf, 70, tentacle_state, 5);
    _mav_put_uint8_t_array(buf, 75, node_id, 5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA_LEN);
#else
    mavlink_bioair_node_meta_data_t packet;

    mav_array_memcpy(packet.lat, lat, sizeof(int32_t)*5);
    mav_array_memcpy(packet.lon, lon, sizeof(int32_t)*5);
    mav_array_memcpy(packet.alt, alt, sizeof(float)*5);
    mav_array_memcpy(packet.time_validity_delta, time_validity_delta, sizeof(int8_t)*5);
    mav_array_memcpy(packet.node_state, node_state, sizeof(uint8_t)*5);
    mav_array_memcpy(packet.tentacle_state, tentacle_state, sizeof(uint8_t)*5);
    mav_array_memcpy(packet.node_id, node_id, sizeof(uint8_t)*5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA_CRC);
}

/**
 * @brief Pack a bioair_node_meta_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param lat  Position Latitude
 * @param lon  Position Longitude
 * @param alt  Position Altitude
 * @param time_validity_delta  Time of Validity Delta
 * @param node_state  Node State
 * @param tentacle_state  Tentacle State
 * @param node_id  Node ID
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_bioair_node_meta_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const int32_t *lat,const int32_t *lon,const float *alt,const int8_t *time_validity_delta,const uint8_t *node_state,const uint8_t *tentacle_state,const uint8_t *node_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA_LEN];

    _mav_put_int32_t_array(buf, 0, lat, 5);
    _mav_put_int32_t_array(buf, 20, lon, 5);
    _mav_put_float_array(buf, 40, alt, 5);
    _mav_put_int8_t_array(buf, 60, time_validity_delta, 5);
    _mav_put_uint8_t_array(buf, 65, node_state, 5);
    _mav_put_uint8_t_array(buf, 70, tentacle_state, 5);
    _mav_put_uint8_t_array(buf, 75, node_id, 5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA_LEN);
#else
    mavlink_bioair_node_meta_data_t packet;

    mav_array_memcpy(packet.lat, lat, sizeof(int32_t)*5);
    mav_array_memcpy(packet.lon, lon, sizeof(int32_t)*5);
    mav_array_memcpy(packet.alt, alt, sizeof(float)*5);
    mav_array_memcpy(packet.time_validity_delta, time_validity_delta, sizeof(int8_t)*5);
    mav_array_memcpy(packet.node_state, node_state, sizeof(uint8_t)*5);
    mav_array_memcpy(packet.tentacle_state, tentacle_state, sizeof(uint8_t)*5);
    mav_array_memcpy(packet.node_id, node_id, sizeof(uint8_t)*5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA_CRC);
}

/**
 * @brief Encode a bioair_node_meta_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param bioair_node_meta_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_bioair_node_meta_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_bioair_node_meta_data_t* bioair_node_meta_data)
{
    return mavlink_msg_bioair_node_meta_data_pack(system_id, component_id, msg, bioair_node_meta_data->lat, bioair_node_meta_data->lon, bioair_node_meta_data->alt, bioair_node_meta_data->time_validity_delta, bioair_node_meta_data->node_state, bioair_node_meta_data->tentacle_state, bioair_node_meta_data->node_id);
}

/**
 * @brief Encode a bioair_node_meta_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param bioair_node_meta_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_bioair_node_meta_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_bioair_node_meta_data_t* bioair_node_meta_data)
{
    return mavlink_msg_bioair_node_meta_data_pack_chan(system_id, component_id, chan, msg, bioair_node_meta_data->lat, bioair_node_meta_data->lon, bioair_node_meta_data->alt, bioair_node_meta_data->time_validity_delta, bioair_node_meta_data->node_state, bioair_node_meta_data->tentacle_state, bioair_node_meta_data->node_id);
}

/**
 * @brief Send a bioair_node_meta_data message
 * @param chan MAVLink channel to send the message
 *
 * @param lat  Position Latitude
 * @param lon  Position Longitude
 * @param alt  Position Altitude
 * @param time_validity_delta  Time of Validity Delta
 * @param node_state  Node State
 * @param tentacle_state  Tentacle State
 * @param node_id  Node ID
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_bioair_node_meta_data_send(mavlink_channel_t chan, const int32_t *lat, const int32_t *lon, const float *alt, const int8_t *time_validity_delta, const uint8_t *node_state, const uint8_t *tentacle_state, const uint8_t *node_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA_LEN];

    _mav_put_int32_t_array(buf, 0, lat, 5);
    _mav_put_int32_t_array(buf, 20, lon, 5);
    _mav_put_float_array(buf, 40, alt, 5);
    _mav_put_int8_t_array(buf, 60, time_validity_delta, 5);
    _mav_put_uint8_t_array(buf, 65, node_state, 5);
    _mav_put_uint8_t_array(buf, 70, tentacle_state, 5);
    _mav_put_uint8_t_array(buf, 75, node_id, 5);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA, buf, MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA_CRC);
#else
    mavlink_bioair_node_meta_data_t packet;

    mav_array_memcpy(packet.lat, lat, sizeof(int32_t)*5);
    mav_array_memcpy(packet.lon, lon, sizeof(int32_t)*5);
    mav_array_memcpy(packet.alt, alt, sizeof(float)*5);
    mav_array_memcpy(packet.time_validity_delta, time_validity_delta, sizeof(int8_t)*5);
    mav_array_memcpy(packet.node_state, node_state, sizeof(uint8_t)*5);
    mav_array_memcpy(packet.tentacle_state, tentacle_state, sizeof(uint8_t)*5);
    mav_array_memcpy(packet.node_id, node_id, sizeof(uint8_t)*5);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA, (const char *)&packet, MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA_CRC);
#endif
}

/**
 * @brief Send a bioair_node_meta_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_bioair_node_meta_data_send_struct(mavlink_channel_t chan, const mavlink_bioair_node_meta_data_t* bioair_node_meta_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_bioair_node_meta_data_send(chan, bioair_node_meta_data->lat, bioair_node_meta_data->lon, bioair_node_meta_data->alt, bioair_node_meta_data->time_validity_delta, bioair_node_meta_data->node_state, bioair_node_meta_data->tentacle_state, bioair_node_meta_data->node_id);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA, (const char *)bioair_node_meta_data, MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA_CRC);
#endif
}

#if MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_bioair_node_meta_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const int32_t *lat, const int32_t *lon, const float *alt, const int8_t *time_validity_delta, const uint8_t *node_state, const uint8_t *tentacle_state, const uint8_t *node_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;

    _mav_put_int32_t_array(buf, 0, lat, 5);
    _mav_put_int32_t_array(buf, 20, lon, 5);
    _mav_put_float_array(buf, 40, alt, 5);
    _mav_put_int8_t_array(buf, 60, time_validity_delta, 5);
    _mav_put_uint8_t_array(buf, 65, node_state, 5);
    _mav_put_uint8_t_array(buf, 70, tentacle_state, 5);
    _mav_put_uint8_t_array(buf, 75, node_id, 5);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA, buf, MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA_CRC);
#else
    mavlink_bioair_node_meta_data_t *packet = (mavlink_bioair_node_meta_data_t *)msgbuf;

    mav_array_memcpy(packet->lat, lat, sizeof(int32_t)*5);
    mav_array_memcpy(packet->lon, lon, sizeof(int32_t)*5);
    mav_array_memcpy(packet->alt, alt, sizeof(float)*5);
    mav_array_memcpy(packet->time_validity_delta, time_validity_delta, sizeof(int8_t)*5);
    mav_array_memcpy(packet->node_state, node_state, sizeof(uint8_t)*5);
    mav_array_memcpy(packet->tentacle_state, tentacle_state, sizeof(uint8_t)*5);
    mav_array_memcpy(packet->node_id, node_id, sizeof(uint8_t)*5);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA, (const char *)packet, MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA_CRC);
#endif
}
#endif

#endif

// MESSAGE BIOAIR_NODE_META_DATA UNPACKING


/**
 * @brief Get field lat from bioair_node_meta_data message
 *
 * @return  Position Latitude
 */
static inline uint16_t mavlink_msg_bioair_node_meta_data_get_lat(const mavlink_message_t* msg, int32_t *lat)
{
    return _MAV_RETURN_int32_t_array(msg, lat, 5,  0);
}

/**
 * @brief Get field lon from bioair_node_meta_data message
 *
 * @return  Position Longitude
 */
static inline uint16_t mavlink_msg_bioair_node_meta_data_get_lon(const mavlink_message_t* msg, int32_t *lon)
{
    return _MAV_RETURN_int32_t_array(msg, lon, 5,  20);
}

/**
 * @brief Get field alt from bioair_node_meta_data message
 *
 * @return  Position Altitude
 */
static inline uint16_t mavlink_msg_bioair_node_meta_data_get_alt(const mavlink_message_t* msg, float *alt)
{
    return _MAV_RETURN_float_array(msg, alt, 5,  40);
}

/**
 * @brief Get field time_validity_delta from bioair_node_meta_data message
 *
 * @return  Time of Validity Delta
 */
static inline uint16_t mavlink_msg_bioair_node_meta_data_get_time_validity_delta(const mavlink_message_t* msg, int8_t *time_validity_delta)
{
    return _MAV_RETURN_int8_t_array(msg, time_validity_delta, 5,  60);
}

/**
 * @brief Get field node_state from bioair_node_meta_data message
 *
 * @return  Node State
 */
static inline uint16_t mavlink_msg_bioair_node_meta_data_get_node_state(const mavlink_message_t* msg, uint8_t *node_state)
{
    return _MAV_RETURN_uint8_t_array(msg, node_state, 5,  65);
}

/**
 * @brief Get field tentacle_state from bioair_node_meta_data message
 *
 * @return  Tentacle State
 */
static inline uint16_t mavlink_msg_bioair_node_meta_data_get_tentacle_state(const mavlink_message_t* msg, uint8_t *tentacle_state)
{
    return _MAV_RETURN_uint8_t_array(msg, tentacle_state, 5,  70);
}

/**
 * @brief Get field node_id from bioair_node_meta_data message
 *
 * @return  Node ID
 */
static inline uint16_t mavlink_msg_bioair_node_meta_data_get_node_id(const mavlink_message_t* msg, uint8_t *node_id)
{
    return _MAV_RETURN_uint8_t_array(msg, node_id, 5,  75);
}

/**
 * @brief Decode a bioair_node_meta_data message into a struct
 *
 * @param msg The message to decode
 * @param bioair_node_meta_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_bioair_node_meta_data_decode(const mavlink_message_t* msg, mavlink_bioair_node_meta_data_t* bioair_node_meta_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_bioair_node_meta_data_get_lat(msg, bioair_node_meta_data->lat);
    mavlink_msg_bioair_node_meta_data_get_lon(msg, bioair_node_meta_data->lon);
    mavlink_msg_bioair_node_meta_data_get_alt(msg, bioair_node_meta_data->alt);
    mavlink_msg_bioair_node_meta_data_get_time_validity_delta(msg, bioair_node_meta_data->time_validity_delta);
    mavlink_msg_bioair_node_meta_data_get_node_state(msg, bioair_node_meta_data->node_state);
    mavlink_msg_bioair_node_meta_data_get_tentacle_state(msg, bioair_node_meta_data->tentacle_state);
    mavlink_msg_bioair_node_meta_data_get_node_id(msg, bioair_node_meta_data->node_id);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA_LEN? msg->len : MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA_LEN;
        memset(bioair_node_meta_data, 0, MAVLINK_MSG_ID_BIOAIR_NODE_META_DATA_LEN);
    memcpy(bioair_node_meta_data, _MAV_PAYLOAD(msg), len);
#endif
}
