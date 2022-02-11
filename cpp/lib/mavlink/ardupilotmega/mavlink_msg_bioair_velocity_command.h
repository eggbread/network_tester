#pragma once
// MESSAGE BIOAIR_VELOCITY_COMMAND PACKING

#define MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND 20010


typedef struct __mavlink_bioair_velocity_command_t {
 float vn; /*<  Velocity in North*/
 float ve; /*<  Velocity in East*/
 float vd; /*<  Velocity in Down*/
 uint8_t target_system; /*<  System ID*/
 uint8_t target_component; /*<  Component ID*/
 uint8_t node_id; /*<  Node ID*/
} mavlink_bioair_velocity_command_t;

#define MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND_LEN 15
#define MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND_MIN_LEN 15
#define MAVLINK_MSG_ID_20010_LEN 15
#define MAVLINK_MSG_ID_20010_MIN_LEN 15

#define MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND_CRC 151
#define MAVLINK_MSG_ID_20010_CRC 151



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_BIOAIR_VELOCITY_COMMAND { \
    20010, \
    "BIOAIR_VELOCITY_COMMAND", \
    6, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_bioair_velocity_command_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_bioair_velocity_command_t, target_component) }, \
         { "node_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 14, offsetof(mavlink_bioair_velocity_command_t, node_id) }, \
         { "vn", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_bioair_velocity_command_t, vn) }, \
         { "ve", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_bioair_velocity_command_t, ve) }, \
         { "vd", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_bioair_velocity_command_t, vd) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_BIOAIR_VELOCITY_COMMAND { \
    "BIOAIR_VELOCITY_COMMAND", \
    6, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_bioair_velocity_command_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_bioair_velocity_command_t, target_component) }, \
         { "node_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 14, offsetof(mavlink_bioair_velocity_command_t, node_id) }, \
         { "vn", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_bioair_velocity_command_t, vn) }, \
         { "ve", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_bioair_velocity_command_t, ve) }, \
         { "vd", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_bioair_velocity_command_t, vd) }, \
         } \
}
#endif

/**
 * @brief Pack a bioair_velocity_command message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param node_id  Node ID
 * @param vn  Velocity in North
 * @param ve  Velocity in East
 * @param vd  Velocity in Down
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_bioair_velocity_command_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint8_t node_id, float vn, float ve, float vd)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND_LEN];
    _mav_put_float(buf, 0, vn);
    _mav_put_float(buf, 4, ve);
    _mav_put_float(buf, 8, vd);
    _mav_put_uint8_t(buf, 12, target_system);
    _mav_put_uint8_t(buf, 13, target_component);
    _mav_put_uint8_t(buf, 14, node_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND_LEN);
#else
    mavlink_bioair_velocity_command_t packet;
    packet.vn = vn;
    packet.ve = ve;
    packet.vd = vd;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.node_id = node_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND_LEN, MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND_CRC);
}

/**
 * @brief Pack a bioair_velocity_command message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param node_id  Node ID
 * @param vn  Velocity in North
 * @param ve  Velocity in East
 * @param vd  Velocity in Down
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_bioair_velocity_command_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,uint8_t node_id,float vn,float ve,float vd)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND_LEN];
    _mav_put_float(buf, 0, vn);
    _mav_put_float(buf, 4, ve);
    _mav_put_float(buf, 8, vd);
    _mav_put_uint8_t(buf, 12, target_system);
    _mav_put_uint8_t(buf, 13, target_component);
    _mav_put_uint8_t(buf, 14, node_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND_LEN);
#else
    mavlink_bioair_velocity_command_t packet;
    packet.vn = vn;
    packet.ve = ve;
    packet.vd = vd;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.node_id = node_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND_LEN, MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND_CRC);
}

/**
 * @brief Encode a bioair_velocity_command struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param bioair_velocity_command C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_bioair_velocity_command_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_bioair_velocity_command_t* bioair_velocity_command)
{
    return mavlink_msg_bioair_velocity_command_pack(system_id, component_id, msg, bioair_velocity_command->target_system, bioair_velocity_command->target_component, bioair_velocity_command->node_id, bioair_velocity_command->vn, bioair_velocity_command->ve, bioair_velocity_command->vd);
}

/**
 * @brief Encode a bioair_velocity_command struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param bioair_velocity_command C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_bioair_velocity_command_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_bioair_velocity_command_t* bioair_velocity_command)
{
    return mavlink_msg_bioair_velocity_command_pack_chan(system_id, component_id, chan, msg, bioair_velocity_command->target_system, bioair_velocity_command->target_component, bioair_velocity_command->node_id, bioair_velocity_command->vn, bioair_velocity_command->ve, bioair_velocity_command->vd);
}

/**
 * @brief Send a bioair_velocity_command message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param node_id  Node ID
 * @param vn  Velocity in North
 * @param ve  Velocity in East
 * @param vd  Velocity in Down
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_bioair_velocity_command_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint8_t node_id, float vn, float ve, float vd)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND_LEN];
    _mav_put_float(buf, 0, vn);
    _mav_put_float(buf, 4, ve);
    _mav_put_float(buf, 8, vd);
    _mav_put_uint8_t(buf, 12, target_system);
    _mav_put_uint8_t(buf, 13, target_component);
    _mav_put_uint8_t(buf, 14, node_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND, buf, MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND_LEN, MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND_CRC);
#else
    mavlink_bioair_velocity_command_t packet;
    packet.vn = vn;
    packet.ve = ve;
    packet.vd = vd;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.node_id = node_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND, (const char *)&packet, MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND_LEN, MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND_CRC);
#endif
}

/**
 * @brief Send a bioair_velocity_command message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_bioair_velocity_command_send_struct(mavlink_channel_t chan, const mavlink_bioair_velocity_command_t* bioair_velocity_command)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_bioair_velocity_command_send(chan, bioair_velocity_command->target_system, bioair_velocity_command->target_component, bioair_velocity_command->node_id, bioair_velocity_command->vn, bioair_velocity_command->ve, bioair_velocity_command->vd);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND, (const char *)bioair_velocity_command, MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND_LEN, MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND_CRC);
#endif
}

#if MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_bioair_velocity_command_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, uint8_t node_id, float vn, float ve, float vd)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, vn);
    _mav_put_float(buf, 4, ve);
    _mav_put_float(buf, 8, vd);
    _mav_put_uint8_t(buf, 12, target_system);
    _mav_put_uint8_t(buf, 13, target_component);
    _mav_put_uint8_t(buf, 14, node_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND, buf, MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND_LEN, MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND_CRC);
#else
    mavlink_bioair_velocity_command_t *packet = (mavlink_bioair_velocity_command_t *)msgbuf;
    packet->vn = vn;
    packet->ve = ve;
    packet->vd = vd;
    packet->target_system = target_system;
    packet->target_component = target_component;
    packet->node_id = node_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND, (const char *)packet, MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND_LEN, MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND_CRC);
#endif
}
#endif

#endif

// MESSAGE BIOAIR_VELOCITY_COMMAND UNPACKING


/**
 * @brief Get field target_system from bioair_velocity_command message
 *
 * @return  System ID
 */
static inline uint8_t mavlink_msg_bioair_velocity_command_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Get field target_component from bioair_velocity_command message
 *
 * @return  Component ID
 */
static inline uint8_t mavlink_msg_bioair_velocity_command_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  13);
}

/**
 * @brief Get field node_id from bioair_velocity_command message
 *
 * @return  Node ID
 */
static inline uint8_t mavlink_msg_bioair_velocity_command_get_node_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  14);
}

/**
 * @brief Get field vn from bioair_velocity_command message
 *
 * @return  Velocity in North
 */
static inline float mavlink_msg_bioair_velocity_command_get_vn(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field ve from bioair_velocity_command message
 *
 * @return  Velocity in East
 */
static inline float mavlink_msg_bioair_velocity_command_get_ve(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field vd from bioair_velocity_command message
 *
 * @return  Velocity in Down
 */
static inline float mavlink_msg_bioair_velocity_command_get_vd(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Decode a bioair_velocity_command message into a struct
 *
 * @param msg The message to decode
 * @param bioair_velocity_command C-struct to decode the message contents into
 */
static inline void mavlink_msg_bioair_velocity_command_decode(const mavlink_message_t* msg, mavlink_bioair_velocity_command_t* bioair_velocity_command)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    bioair_velocity_command->vn = mavlink_msg_bioair_velocity_command_get_vn(msg);
    bioair_velocity_command->ve = mavlink_msg_bioair_velocity_command_get_ve(msg);
    bioair_velocity_command->vd = mavlink_msg_bioair_velocity_command_get_vd(msg);
    bioair_velocity_command->target_system = mavlink_msg_bioair_velocity_command_get_target_system(msg);
    bioair_velocity_command->target_component = mavlink_msg_bioair_velocity_command_get_target_component(msg);
    bioair_velocity_command->node_id = mavlink_msg_bioair_velocity_command_get_node_id(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND_LEN? msg->len : MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND_LEN;
        memset(bioair_velocity_command, 0, MAVLINK_MSG_ID_BIOAIR_VELOCITY_COMMAND_LEN);
    memcpy(bioair_velocity_command, _MAV_PAYLOAD(msg), len);
#endif
}
