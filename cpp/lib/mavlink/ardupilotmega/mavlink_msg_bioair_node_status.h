#pragma once
// MESSAGE BIOAIR_NODE_STATUS PACKING

#define MAVLINK_MSG_ID_BIOAIR_NODE_STATUS 20010


typedef struct __mavlink_bioair_node_status_t {
 double real_target_pos_llla[3]; /*<  Real Target Position LLA*/
 double pos_lla[3]; /*<  Position LLA*/
 uint32_t time_validity; /*<  Time of Validity*/
 float node_signal; /*<  Node Signal*/
 uint8_t node_state; /*<  Node State*/
 uint8_t tentacle_state; /*<  Tentacle State*/
 uint8_t node_id; /*<  Node ID*/
 uint8_t num_connected_node; /*<  Number of Connected Nodes*/
 uint8_t num_edge; /*<  Number of Edges*/
} mavlink_bioair_node_status_t;

#define MAVLINK_MSG_ID_BIOAIR_NODE_STATUS_LEN 61
#define MAVLINK_MSG_ID_BIOAIR_NODE_STATUS_MIN_LEN 61
#define MAVLINK_MSG_ID_20010_LEN 61
#define MAVLINK_MSG_ID_20010_MIN_LEN 61

#define MAVLINK_MSG_ID_BIOAIR_NODE_STATUS_CRC 116
#define MAVLINK_MSG_ID_20010_CRC 116

#define MAVLINK_MSG_BIOAIR_NODE_STATUS_FIELD_REAL_TARGET_POS_LLLA_LEN 3
#define MAVLINK_MSG_BIOAIR_NODE_STATUS_FIELD_POS_LLA_LEN 3

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_BIOAIR_NODE_STATUS { \
    20010, \
    "BIOAIR_NODE_STATUS", \
    9, \
    {  { "real_target_pos_llla", NULL, MAVLINK_TYPE_DOUBLE, 3, 0, offsetof(mavlink_bioair_node_status_t, real_target_pos_llla) }, \
         { "pos_lla", NULL, MAVLINK_TYPE_DOUBLE, 3, 24, offsetof(mavlink_bioair_node_status_t, pos_lla) }, \
         { "time_validity", NULL, MAVLINK_TYPE_UINT32_T, 0, 48, offsetof(mavlink_bioair_node_status_t, time_validity) }, \
         { "node_signal", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_bioair_node_status_t, node_signal) }, \
         { "node_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 56, offsetof(mavlink_bioair_node_status_t, node_state) }, \
         { "tentacle_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 57, offsetof(mavlink_bioair_node_status_t, tentacle_state) }, \
         { "node_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 58, offsetof(mavlink_bioair_node_status_t, node_id) }, \
         { "num_connected_node", NULL, MAVLINK_TYPE_UINT8_T, 0, 59, offsetof(mavlink_bioair_node_status_t, num_connected_node) }, \
         { "num_edge", NULL, MAVLINK_TYPE_UINT8_T, 0, 60, offsetof(mavlink_bioair_node_status_t, num_edge) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_BIOAIR_NODE_STATUS { \
    "BIOAIR_NODE_STATUS", \
    9, \
    {  { "real_target_pos_llla", NULL, MAVLINK_TYPE_DOUBLE, 3, 0, offsetof(mavlink_bioair_node_status_t, real_target_pos_llla) }, \
         { "pos_lla", NULL, MAVLINK_TYPE_DOUBLE, 3, 24, offsetof(mavlink_bioair_node_status_t, pos_lla) }, \
         { "time_validity", NULL, MAVLINK_TYPE_UINT32_T, 0, 48, offsetof(mavlink_bioair_node_status_t, time_validity) }, \
         { "node_signal", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_bioair_node_status_t, node_signal) }, \
         { "node_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 56, offsetof(mavlink_bioair_node_status_t, node_state) }, \
         { "tentacle_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 57, offsetof(mavlink_bioair_node_status_t, tentacle_state) }, \
         { "node_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 58, offsetof(mavlink_bioair_node_status_t, node_id) }, \
         { "num_connected_node", NULL, MAVLINK_TYPE_UINT8_T, 0, 59, offsetof(mavlink_bioair_node_status_t, num_connected_node) }, \
         { "num_edge", NULL, MAVLINK_TYPE_UINT8_T, 0, 60, offsetof(mavlink_bioair_node_status_t, num_edge) }, \
         } \
}
#endif

/**
 * @brief Pack a bioair_node_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param real_target_pos_llla  Real Target Position LLA
 * @param pos_lla  Position LLA
 * @param time_validity  Time of Validity
 * @param node_signal  Node Signal
 * @param node_state  Node State
 * @param tentacle_state  Tentacle State
 * @param node_id  Node ID
 * @param num_connected_node  Number of Connected Nodes
 * @param num_edge  Number of Edges
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_bioair_node_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const double *real_target_pos_llla, const double *pos_lla, uint32_t time_validity, float node_signal, uint8_t node_state, uint8_t tentacle_state, uint8_t node_id, uint8_t num_connected_node, uint8_t num_edge)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BIOAIR_NODE_STATUS_LEN];
    _mav_put_uint32_t(buf, 48, time_validity);
    _mav_put_float(buf, 52, node_signal);
    _mav_put_uint8_t(buf, 56, node_state);
    _mav_put_uint8_t(buf, 57, tentacle_state);
    _mav_put_uint8_t(buf, 58, node_id);
    _mav_put_uint8_t(buf, 59, num_connected_node);
    _mav_put_uint8_t(buf, 60, num_edge);
    _mav_put_double_array(buf, 0, real_target_pos_llla, 3);
    _mav_put_double_array(buf, 24, pos_lla, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BIOAIR_NODE_STATUS_LEN);
#else
    mavlink_bioair_node_status_t packet;
    packet.time_validity = time_validity;
    packet.node_signal = node_signal;
    packet.node_state = node_state;
    packet.tentacle_state = tentacle_state;
    packet.node_id = node_id;
    packet.num_connected_node = num_connected_node;
    packet.num_edge = num_edge;
    mav_array_memcpy(packet.real_target_pos_llla, real_target_pos_llla, sizeof(double)*3);
    mav_array_memcpy(packet.pos_lla, pos_lla, sizeof(double)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BIOAIR_NODE_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_BIOAIR_NODE_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_BIOAIR_NODE_STATUS_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_STATUS_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_STATUS_CRC);
}

/**
 * @brief Pack a bioair_node_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param real_target_pos_llla  Real Target Position LLA
 * @param pos_lla  Position LLA
 * @param time_validity  Time of Validity
 * @param node_signal  Node Signal
 * @param node_state  Node State
 * @param tentacle_state  Tentacle State
 * @param node_id  Node ID
 * @param num_connected_node  Number of Connected Nodes
 * @param num_edge  Number of Edges
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_bioair_node_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const double *real_target_pos_llla,const double *pos_lla,uint32_t time_validity,float node_signal,uint8_t node_state,uint8_t tentacle_state,uint8_t node_id,uint8_t num_connected_node,uint8_t num_edge)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BIOAIR_NODE_STATUS_LEN];
    _mav_put_uint32_t(buf, 48, time_validity);
    _mav_put_float(buf, 52, node_signal);
    _mav_put_uint8_t(buf, 56, node_state);
    _mav_put_uint8_t(buf, 57, tentacle_state);
    _mav_put_uint8_t(buf, 58, node_id);
    _mav_put_uint8_t(buf, 59, num_connected_node);
    _mav_put_uint8_t(buf, 60, num_edge);
    _mav_put_double_array(buf, 0, real_target_pos_llla, 3);
    _mav_put_double_array(buf, 24, pos_lla, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BIOAIR_NODE_STATUS_LEN);
#else
    mavlink_bioair_node_status_t packet;
    packet.time_validity = time_validity;
    packet.node_signal = node_signal;
    packet.node_state = node_state;
    packet.tentacle_state = tentacle_state;
    packet.node_id = node_id;
    packet.num_connected_node = num_connected_node;
    packet.num_edge = num_edge;
    mav_array_memcpy(packet.real_target_pos_llla, real_target_pos_llla, sizeof(double)*3);
    mav_array_memcpy(packet.pos_lla, pos_lla, sizeof(double)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BIOAIR_NODE_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_BIOAIR_NODE_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_BIOAIR_NODE_STATUS_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_STATUS_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_STATUS_CRC);
}

/**
 * @brief Encode a bioair_node_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param bioair_node_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_bioair_node_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_bioair_node_status_t* bioair_node_status)
{
    return mavlink_msg_bioair_node_status_pack(system_id, component_id, msg, bioair_node_status->real_target_pos_llla, bioair_node_status->pos_lla, bioair_node_status->time_validity, bioair_node_status->node_signal, bioair_node_status->node_state, bioair_node_status->tentacle_state, bioair_node_status->node_id, bioair_node_status->num_connected_node, bioair_node_status->num_edge);
}

/**
 * @brief Encode a bioair_node_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param bioair_node_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_bioair_node_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_bioair_node_status_t* bioair_node_status)
{
    return mavlink_msg_bioair_node_status_pack_chan(system_id, component_id, chan, msg, bioair_node_status->real_target_pos_llla, bioair_node_status->pos_lla, bioair_node_status->time_validity, bioair_node_status->node_signal, bioair_node_status->node_state, bioair_node_status->tentacle_state, bioair_node_status->node_id, bioair_node_status->num_connected_node, bioair_node_status->num_edge);
}

/**
 * @brief Send a bioair_node_status message
 * @param chan MAVLink channel to send the message
 *
 * @param real_target_pos_llla  Real Target Position LLA
 * @param pos_lla  Position LLA
 * @param time_validity  Time of Validity
 * @param node_signal  Node Signal
 * @param node_state  Node State
 * @param tentacle_state  Tentacle State
 * @param node_id  Node ID
 * @param num_connected_node  Number of Connected Nodes
 * @param num_edge  Number of Edges
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_bioair_node_status_send(mavlink_channel_t chan, const double *real_target_pos_llla, const double *pos_lla, uint32_t time_validity, float node_signal, uint8_t node_state, uint8_t tentacle_state, uint8_t node_id, uint8_t num_connected_node, uint8_t num_edge)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BIOAIR_NODE_STATUS_LEN];
    _mav_put_uint32_t(buf, 48, time_validity);
    _mav_put_float(buf, 52, node_signal);
    _mav_put_uint8_t(buf, 56, node_state);
    _mav_put_uint8_t(buf, 57, tentacle_state);
    _mav_put_uint8_t(buf, 58, node_id);
    _mav_put_uint8_t(buf, 59, num_connected_node);
    _mav_put_uint8_t(buf, 60, num_edge);
    _mav_put_double_array(buf, 0, real_target_pos_llla, 3);
    _mav_put_double_array(buf, 24, pos_lla, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BIOAIR_NODE_STATUS, buf, MAVLINK_MSG_ID_BIOAIR_NODE_STATUS_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_STATUS_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_STATUS_CRC);
#else
    mavlink_bioair_node_status_t packet;
    packet.time_validity = time_validity;
    packet.node_signal = node_signal;
    packet.node_state = node_state;
    packet.tentacle_state = tentacle_state;
    packet.node_id = node_id;
    packet.num_connected_node = num_connected_node;
    packet.num_edge = num_edge;
    mav_array_memcpy(packet.real_target_pos_llla, real_target_pos_llla, sizeof(double)*3);
    mav_array_memcpy(packet.pos_lla, pos_lla, sizeof(double)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BIOAIR_NODE_STATUS, (const char *)&packet, MAVLINK_MSG_ID_BIOAIR_NODE_STATUS_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_STATUS_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_STATUS_CRC);
#endif
}

/**
 * @brief Send a bioair_node_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_bioair_node_status_send_struct(mavlink_channel_t chan, const mavlink_bioair_node_status_t* bioair_node_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_bioair_node_status_send(chan, bioair_node_status->real_target_pos_llla, bioair_node_status->pos_lla, bioair_node_status->time_validity, bioair_node_status->node_signal, bioair_node_status->node_state, bioair_node_status->tentacle_state, bioair_node_status->node_id, bioair_node_status->num_connected_node, bioair_node_status->num_edge);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BIOAIR_NODE_STATUS, (const char *)bioair_node_status, MAVLINK_MSG_ID_BIOAIR_NODE_STATUS_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_STATUS_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_BIOAIR_NODE_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_bioair_node_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const double *real_target_pos_llla, const double *pos_lla, uint32_t time_validity, float node_signal, uint8_t node_state, uint8_t tentacle_state, uint8_t node_id, uint8_t num_connected_node, uint8_t num_edge)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 48, time_validity);
    _mav_put_float(buf, 52, node_signal);
    _mav_put_uint8_t(buf, 56, node_state);
    _mav_put_uint8_t(buf, 57, tentacle_state);
    _mav_put_uint8_t(buf, 58, node_id);
    _mav_put_uint8_t(buf, 59, num_connected_node);
    _mav_put_uint8_t(buf, 60, num_edge);
    _mav_put_double_array(buf, 0, real_target_pos_llla, 3);
    _mav_put_double_array(buf, 24, pos_lla, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BIOAIR_NODE_STATUS, buf, MAVLINK_MSG_ID_BIOAIR_NODE_STATUS_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_STATUS_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_STATUS_CRC);
#else
    mavlink_bioair_node_status_t *packet = (mavlink_bioair_node_status_t *)msgbuf;
    packet->time_validity = time_validity;
    packet->node_signal = node_signal;
    packet->node_state = node_state;
    packet->tentacle_state = tentacle_state;
    packet->node_id = node_id;
    packet->num_connected_node = num_connected_node;
    packet->num_edge = num_edge;
    mav_array_memcpy(packet->real_target_pos_llla, real_target_pos_llla, sizeof(double)*3);
    mav_array_memcpy(packet->pos_lla, pos_lla, sizeof(double)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BIOAIR_NODE_STATUS, (const char *)packet, MAVLINK_MSG_ID_BIOAIR_NODE_STATUS_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_STATUS_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE BIOAIR_NODE_STATUS UNPACKING


/**
 * @brief Get field real_target_pos_llla from bioair_node_status message
 *
 * @return  Real Target Position LLA
 */
static inline uint16_t mavlink_msg_bioair_node_status_get_real_target_pos_llla(const mavlink_message_t* msg, double *real_target_pos_llla)
{
    return _MAV_RETURN_double_array(msg, real_target_pos_llla, 3,  0);
}

/**
 * @brief Get field pos_lla from bioair_node_status message
 *
 * @return  Position LLA
 */
static inline uint16_t mavlink_msg_bioair_node_status_get_pos_lla(const mavlink_message_t* msg, double *pos_lla)
{
    return _MAV_RETURN_double_array(msg, pos_lla, 3,  24);
}

/**
 * @brief Get field time_validity from bioair_node_status message
 *
 * @return  Time of Validity
 */
static inline uint32_t mavlink_msg_bioair_node_status_get_time_validity(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  48);
}

/**
 * @brief Get field node_signal from bioair_node_status message
 *
 * @return  Node Signal
 */
static inline float mavlink_msg_bioair_node_status_get_node_signal(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  52);
}

/**
 * @brief Get field node_state from bioair_node_status message
 *
 * @return  Node State
 */
static inline uint8_t mavlink_msg_bioair_node_status_get_node_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  56);
}

/**
 * @brief Get field tentacle_state from bioair_node_status message
 *
 * @return  Tentacle State
 */
static inline uint8_t mavlink_msg_bioair_node_status_get_tentacle_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  57);
}

/**
 * @brief Get field node_id from bioair_node_status message
 *
 * @return  Node ID
 */
static inline uint8_t mavlink_msg_bioair_node_status_get_node_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  58);
}

/**
 * @brief Get field num_connected_node from bioair_node_status message
 *
 * @return  Number of Connected Nodes
 */
static inline uint8_t mavlink_msg_bioair_node_status_get_num_connected_node(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  59);
}

/**
 * @brief Get field num_edge from bioair_node_status message
 *
 * @return  Number of Edges
 */
static inline uint8_t mavlink_msg_bioair_node_status_get_num_edge(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  60);
}

/**
 * @brief Decode a bioair_node_status message into a struct
 *
 * @param msg The message to decode
 * @param bioair_node_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_bioair_node_status_decode(const mavlink_message_t* msg, mavlink_bioair_node_status_t* bioair_node_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_bioair_node_status_get_real_target_pos_llla(msg, bioair_node_status->real_target_pos_llla);
    mavlink_msg_bioair_node_status_get_pos_lla(msg, bioair_node_status->pos_lla);
    bioair_node_status->time_validity = mavlink_msg_bioair_node_status_get_time_validity(msg);
    bioair_node_status->node_signal = mavlink_msg_bioair_node_status_get_node_signal(msg);
    bioair_node_status->node_state = mavlink_msg_bioair_node_status_get_node_state(msg);
    bioair_node_status->tentacle_state = mavlink_msg_bioair_node_status_get_tentacle_state(msg);
    bioair_node_status->node_id = mavlink_msg_bioair_node_status_get_node_id(msg);
    bioair_node_status->num_connected_node = mavlink_msg_bioair_node_status_get_num_connected_node(msg);
    bioair_node_status->num_edge = mavlink_msg_bioair_node_status_get_num_edge(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_BIOAIR_NODE_STATUS_LEN? msg->len : MAVLINK_MSG_ID_BIOAIR_NODE_STATUS_LEN;
        memset(bioair_node_status, 0, MAVLINK_MSG_ID_BIOAIR_NODE_STATUS_LEN);
    memcpy(bioair_node_status, _MAV_PAYLOAD(msg), len);
#endif
}
