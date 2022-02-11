#pragma once
// MESSAGE BIOAIR_NODE_NETWORK_EDGE PACKING

#define MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE 20020


typedef struct __mavlink_bioair_node_network_edge_t {
 int8_t time_validity_delta[50]; /*<  Time of Validity Delta*/
 uint8_t node_id_A[50]; /*<  Node ID A*/
 uint8_t node_id_B[50]; /*<  Node ID B*/
} mavlink_bioair_node_network_edge_t;

#define MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE_LEN 150
#define MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE_MIN_LEN 150
#define MAVLINK_MSG_ID_20020_LEN 150
#define MAVLINK_MSG_ID_20020_MIN_LEN 150

#define MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE_CRC 228
#define MAVLINK_MSG_ID_20020_CRC 228

#define MAVLINK_MSG_BIOAIR_NODE_NETWORK_EDGE_FIELD_TIME_VALIDITY_DELTA_LEN 50
#define MAVLINK_MSG_BIOAIR_NODE_NETWORK_EDGE_FIELD_NODE_ID_A_LEN 50
#define MAVLINK_MSG_BIOAIR_NODE_NETWORK_EDGE_FIELD_NODE_ID_B_LEN 50

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_BIOAIR_NODE_NETWORK_EDGE { \
    20020, \
    "BIOAIR_NODE_NETWORK_EDGE", \
    3, \
    {  { "time_validity_delta", NULL, MAVLINK_TYPE_INT8_T, 50, 0, offsetof(mavlink_bioair_node_network_edge_t, time_validity_delta) }, \
         { "node_id_A", NULL, MAVLINK_TYPE_UINT8_T, 50, 50, offsetof(mavlink_bioair_node_network_edge_t, node_id_A) }, \
         { "node_id_B", NULL, MAVLINK_TYPE_UINT8_T, 50, 100, offsetof(mavlink_bioair_node_network_edge_t, node_id_B) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_BIOAIR_NODE_NETWORK_EDGE { \
    "BIOAIR_NODE_NETWORK_EDGE", \
    3, \
    {  { "time_validity_delta", NULL, MAVLINK_TYPE_INT8_T, 50, 0, offsetof(mavlink_bioair_node_network_edge_t, time_validity_delta) }, \
         { "node_id_A", NULL, MAVLINK_TYPE_UINT8_T, 50, 50, offsetof(mavlink_bioair_node_network_edge_t, node_id_A) }, \
         { "node_id_B", NULL, MAVLINK_TYPE_UINT8_T, 50, 100, offsetof(mavlink_bioair_node_network_edge_t, node_id_B) }, \
         } \
}
#endif

/**
 * @brief Pack a bioair_node_network_edge message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_validity_delta  Time of Validity Delta
 * @param node_id_A  Node ID A
 * @param node_id_B  Node ID B
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_bioair_node_network_edge_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const int8_t *time_validity_delta, const uint8_t *node_id_A, const uint8_t *node_id_B)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE_LEN];

    _mav_put_int8_t_array(buf, 0, time_validity_delta, 50);
    _mav_put_uint8_t_array(buf, 50, node_id_A, 50);
    _mav_put_uint8_t_array(buf, 100, node_id_B, 50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE_LEN);
#else
    mavlink_bioair_node_network_edge_t packet;

    mav_array_memcpy(packet.time_validity_delta, time_validity_delta, sizeof(int8_t)*50);
    mav_array_memcpy(packet.node_id_A, node_id_A, sizeof(uint8_t)*50);
    mav_array_memcpy(packet.node_id_B, node_id_B, sizeof(uint8_t)*50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE_CRC);
}

/**
 * @brief Pack a bioair_node_network_edge message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_validity_delta  Time of Validity Delta
 * @param node_id_A  Node ID A
 * @param node_id_B  Node ID B
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_bioair_node_network_edge_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const int8_t *time_validity_delta,const uint8_t *node_id_A,const uint8_t *node_id_B)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE_LEN];

    _mav_put_int8_t_array(buf, 0, time_validity_delta, 50);
    _mav_put_uint8_t_array(buf, 50, node_id_A, 50);
    _mav_put_uint8_t_array(buf, 100, node_id_B, 50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE_LEN);
#else
    mavlink_bioair_node_network_edge_t packet;

    mav_array_memcpy(packet.time_validity_delta, time_validity_delta, sizeof(int8_t)*50);
    mav_array_memcpy(packet.node_id_A, node_id_A, sizeof(uint8_t)*50);
    mav_array_memcpy(packet.node_id_B, node_id_B, sizeof(uint8_t)*50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE_CRC);
}

/**
 * @brief Encode a bioair_node_network_edge struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param bioair_node_network_edge C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_bioair_node_network_edge_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_bioair_node_network_edge_t* bioair_node_network_edge)
{
    return mavlink_msg_bioair_node_network_edge_pack(system_id, component_id, msg, bioair_node_network_edge->time_validity_delta, bioair_node_network_edge->node_id_A, bioair_node_network_edge->node_id_B);
}

/**
 * @brief Encode a bioair_node_network_edge struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param bioair_node_network_edge C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_bioair_node_network_edge_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_bioair_node_network_edge_t* bioair_node_network_edge)
{
    return mavlink_msg_bioair_node_network_edge_pack_chan(system_id, component_id, chan, msg, bioair_node_network_edge->time_validity_delta, bioair_node_network_edge->node_id_A, bioair_node_network_edge->node_id_B);
}

/**
 * @brief Send a bioair_node_network_edge message
 * @param chan MAVLink channel to send the message
 *
 * @param time_validity_delta  Time of Validity Delta
 * @param node_id_A  Node ID A
 * @param node_id_B  Node ID B
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_bioair_node_network_edge_send(mavlink_channel_t chan, const int8_t *time_validity_delta, const uint8_t *node_id_A, const uint8_t *node_id_B)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE_LEN];

    _mav_put_int8_t_array(buf, 0, time_validity_delta, 50);
    _mav_put_uint8_t_array(buf, 50, node_id_A, 50);
    _mav_put_uint8_t_array(buf, 100, node_id_B, 50);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE, buf, MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE_CRC);
#else
    mavlink_bioair_node_network_edge_t packet;

    mav_array_memcpy(packet.time_validity_delta, time_validity_delta, sizeof(int8_t)*50);
    mav_array_memcpy(packet.node_id_A, node_id_A, sizeof(uint8_t)*50);
    mav_array_memcpy(packet.node_id_B, node_id_B, sizeof(uint8_t)*50);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE, (const char *)&packet, MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE_CRC);
#endif
}

/**
 * @brief Send a bioair_node_network_edge message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_bioair_node_network_edge_send_struct(mavlink_channel_t chan, const mavlink_bioair_node_network_edge_t* bioair_node_network_edge)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_bioair_node_network_edge_send(chan, bioair_node_network_edge->time_validity_delta, bioair_node_network_edge->node_id_A, bioair_node_network_edge->node_id_B);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE, (const char *)bioair_node_network_edge, MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE_CRC);
#endif
}

#if MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_bioair_node_network_edge_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const int8_t *time_validity_delta, const uint8_t *node_id_A, const uint8_t *node_id_B)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;

    _mav_put_int8_t_array(buf, 0, time_validity_delta, 50);
    _mav_put_uint8_t_array(buf, 50, node_id_A, 50);
    _mav_put_uint8_t_array(buf, 100, node_id_B, 50);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE, buf, MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE_CRC);
#else
    mavlink_bioair_node_network_edge_t *packet = (mavlink_bioair_node_network_edge_t *)msgbuf;

    mav_array_memcpy(packet->time_validity_delta, time_validity_delta, sizeof(int8_t)*50);
    mav_array_memcpy(packet->node_id_A, node_id_A, sizeof(uint8_t)*50);
    mav_array_memcpy(packet->node_id_B, node_id_B, sizeof(uint8_t)*50);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE, (const char *)packet, MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE_LEN, MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE_CRC);
#endif
}
#endif

#endif

// MESSAGE BIOAIR_NODE_NETWORK_EDGE UNPACKING


/**
 * @brief Get field time_validity_delta from bioair_node_network_edge message
 *
 * @return  Time of Validity Delta
 */
static inline uint16_t mavlink_msg_bioair_node_network_edge_get_time_validity_delta(const mavlink_message_t* msg, int8_t *time_validity_delta)
{
    return _MAV_RETURN_int8_t_array(msg, time_validity_delta, 50,  0);
}

/**
 * @brief Get field node_id_A from bioair_node_network_edge message
 *
 * @return  Node ID A
 */
static inline uint16_t mavlink_msg_bioair_node_network_edge_get_node_id_A(const mavlink_message_t* msg, uint8_t *node_id_A)
{
    return _MAV_RETURN_uint8_t_array(msg, node_id_A, 50,  50);
}

/**
 * @brief Get field node_id_B from bioair_node_network_edge message
 *
 * @return  Node ID B
 */
static inline uint16_t mavlink_msg_bioair_node_network_edge_get_node_id_B(const mavlink_message_t* msg, uint8_t *node_id_B)
{
    return _MAV_RETURN_uint8_t_array(msg, node_id_B, 50,  100);
}

/**
 * @brief Decode a bioair_node_network_edge message into a struct
 *
 * @param msg The message to decode
 * @param bioair_node_network_edge C-struct to decode the message contents into
 */
static inline void mavlink_msg_bioair_node_network_edge_decode(const mavlink_message_t* msg, mavlink_bioair_node_network_edge_t* bioair_node_network_edge)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_bioair_node_network_edge_get_time_validity_delta(msg, bioair_node_network_edge->time_validity_delta);
    mavlink_msg_bioair_node_network_edge_get_node_id_A(msg, bioair_node_network_edge->node_id_A);
    mavlink_msg_bioair_node_network_edge_get_node_id_B(msg, bioair_node_network_edge->node_id_B);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE_LEN? msg->len : MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE_LEN;
        memset(bioair_node_network_edge, 0, MAVLINK_MSG_ID_BIOAIR_NODE_NETWORK_EDGE_LEN);
    memcpy(bioair_node_network_edge, _MAV_PAYLOAD(msg), len);
#endif
}
