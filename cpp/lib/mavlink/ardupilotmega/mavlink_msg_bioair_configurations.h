#pragma once
// MESSAGE BIOAIR_CONFIGURATIONS PACKING

#define MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS 20000


typedef struct __mavlink_bioair_configurations_t {
 float origin_north; /*<  Origin North*/
 float origin_east; /*< [m] Origin East*/
 float origin_down; /*< [m] Origin Down*/
 float dest_north; /*< [m] Destination North*/
 float dest_east; /*< [m] Destination East*/
 float dest_down; /*< [m] Destination Down*/
 int32_t min_relative_alt; /*< [mm] Minimum Relative Altitude*/
 float sig_high; /*<  Signal High*/
 float sig_low; /*<  Signal Low*/
 float sig_gamma; /*<  Signal Gamma*/
 float sig_alpha; /*<  Signal Alpha*/
 float sig_beta; /*<  Signal Beta*/
 float virtual_a; /*<  Virtual A*/
 float repulsor; /*<  Repulsor*/
 float target_proximity; /*<  Target Proximity*/
 float target_force; /*<  Target Force*/
 uint8_t node_id; /*<  Node ID*/
 uint8_t origin_id; /*<  Origin ID*/
 uint8_t dest_id; /*<  Destination ID*/
 uint8_t node_state; /*<  Node State*/
 uint8_t tentacle_state; /*<  Tentacle State*/
} mavlink_bioair_configurations_t;

#define MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS_LEN 69
#define MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS_MIN_LEN 69
#define MAVLINK_MSG_ID_20000_LEN 69
#define MAVLINK_MSG_ID_20000_MIN_LEN 69

#define MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS_CRC 122
#define MAVLINK_MSG_ID_20000_CRC 122



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_BIOAIR_CONFIGURATIONS { \
    20000, \
    "BIOAIR_CONFIGURATIONS", \
    21, \
    {  { "node_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 64, offsetof(mavlink_bioair_configurations_t, node_id) }, \
         { "origin_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 65, offsetof(mavlink_bioair_configurations_t, origin_id) }, \
         { "dest_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 66, offsetof(mavlink_bioair_configurations_t, dest_id) }, \
         { "node_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 67, offsetof(mavlink_bioair_configurations_t, node_state) }, \
         { "tentacle_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 68, offsetof(mavlink_bioair_configurations_t, tentacle_state) }, \
         { "origin_north", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_bioair_configurations_t, origin_north) }, \
         { "origin_east", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_bioair_configurations_t, origin_east) }, \
         { "origin_down", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_bioair_configurations_t, origin_down) }, \
         { "dest_north", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_bioair_configurations_t, dest_north) }, \
         { "dest_east", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_bioair_configurations_t, dest_east) }, \
         { "dest_down", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_bioair_configurations_t, dest_down) }, \
         { "min_relative_alt", NULL, MAVLINK_TYPE_INT32_T, 0, 24, offsetof(mavlink_bioair_configurations_t, min_relative_alt) }, \
         { "sig_high", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_bioair_configurations_t, sig_high) }, \
         { "sig_low", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_bioair_configurations_t, sig_low) }, \
         { "sig_gamma", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_bioair_configurations_t, sig_gamma) }, \
         { "sig_alpha", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_bioair_configurations_t, sig_alpha) }, \
         { "sig_beta", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_bioair_configurations_t, sig_beta) }, \
         { "virtual_a", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_bioair_configurations_t, virtual_a) }, \
         { "repulsor", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_bioair_configurations_t, repulsor) }, \
         { "target_proximity", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_bioair_configurations_t, target_proximity) }, \
         { "target_force", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_bioair_configurations_t, target_force) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_BIOAIR_CONFIGURATIONS { \
    "BIOAIR_CONFIGURATIONS", \
    21, \
    {  { "node_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 64, offsetof(mavlink_bioair_configurations_t, node_id) }, \
         { "origin_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 65, offsetof(mavlink_bioair_configurations_t, origin_id) }, \
         { "dest_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 66, offsetof(mavlink_bioair_configurations_t, dest_id) }, \
         { "node_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 67, offsetof(mavlink_bioair_configurations_t, node_state) }, \
         { "tentacle_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 68, offsetof(mavlink_bioair_configurations_t, tentacle_state) }, \
         { "origin_north", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_bioair_configurations_t, origin_north) }, \
         { "origin_east", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_bioair_configurations_t, origin_east) }, \
         { "origin_down", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_bioair_configurations_t, origin_down) }, \
         { "dest_north", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_bioair_configurations_t, dest_north) }, \
         { "dest_east", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_bioair_configurations_t, dest_east) }, \
         { "dest_down", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_bioair_configurations_t, dest_down) }, \
         { "min_relative_alt", NULL, MAVLINK_TYPE_INT32_T, 0, 24, offsetof(mavlink_bioair_configurations_t, min_relative_alt) }, \
         { "sig_high", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_bioair_configurations_t, sig_high) }, \
         { "sig_low", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_bioair_configurations_t, sig_low) }, \
         { "sig_gamma", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_bioair_configurations_t, sig_gamma) }, \
         { "sig_alpha", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_bioair_configurations_t, sig_alpha) }, \
         { "sig_beta", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_bioair_configurations_t, sig_beta) }, \
         { "virtual_a", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_bioair_configurations_t, virtual_a) }, \
         { "repulsor", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_bioair_configurations_t, repulsor) }, \
         { "target_proximity", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_bioair_configurations_t, target_proximity) }, \
         { "target_force", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_bioair_configurations_t, target_force) }, \
         } \
}
#endif

/**
 * @brief Pack a bioair_configurations message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param node_id  Node ID
 * @param origin_id  Origin ID
 * @param dest_id  Destination ID
 * @param node_state  Node State
 * @param tentacle_state  Tentacle State
 * @param origin_north  Origin North
 * @param origin_east [m] Origin East
 * @param origin_down [m] Origin Down
 * @param dest_north [m] Destination North
 * @param dest_east [m] Destination East
 * @param dest_down [m] Destination Down
 * @param min_relative_alt [mm] Minimum Relative Altitude
 * @param sig_high  Signal High
 * @param sig_low  Signal Low
 * @param sig_gamma  Signal Gamma
 * @param sig_alpha  Signal Alpha
 * @param sig_beta  Signal Beta
 * @param virtual_a  Virtual A
 * @param repulsor  Repulsor
 * @param target_proximity  Target Proximity
 * @param target_force  Target Force
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_bioair_configurations_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t node_id, uint8_t origin_id, uint8_t dest_id, uint8_t node_state, uint8_t tentacle_state, float origin_north, float origin_east, float origin_down, float dest_north, float dest_east, float dest_down, int32_t min_relative_alt, float sig_high, float sig_low, float sig_gamma, float sig_alpha, float sig_beta, float virtual_a, float repulsor, float target_proximity, float target_force)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS_LEN];
    _mav_put_float(buf, 0, origin_north);
    _mav_put_float(buf, 4, origin_east);
    _mav_put_float(buf, 8, origin_down);
    _mav_put_float(buf, 12, dest_north);
    _mav_put_float(buf, 16, dest_east);
    _mav_put_float(buf, 20, dest_down);
    _mav_put_int32_t(buf, 24, min_relative_alt);
    _mav_put_float(buf, 28, sig_high);
    _mav_put_float(buf, 32, sig_low);
    _mav_put_float(buf, 36, sig_gamma);
    _mav_put_float(buf, 40, sig_alpha);
    _mav_put_float(buf, 44, sig_beta);
    _mav_put_float(buf, 48, virtual_a);
    _mav_put_float(buf, 52, repulsor);
    _mav_put_float(buf, 56, target_proximity);
    _mav_put_float(buf, 60, target_force);
    _mav_put_uint8_t(buf, 64, node_id);
    _mav_put_uint8_t(buf, 65, origin_id);
    _mav_put_uint8_t(buf, 66, dest_id);
    _mav_put_uint8_t(buf, 67, node_state);
    _mav_put_uint8_t(buf, 68, tentacle_state);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS_LEN);
#else
    mavlink_bioair_configurations_t packet;
    packet.origin_north = origin_north;
    packet.origin_east = origin_east;
    packet.origin_down = origin_down;
    packet.dest_north = dest_north;
    packet.dest_east = dest_east;
    packet.dest_down = dest_down;
    packet.min_relative_alt = min_relative_alt;
    packet.sig_high = sig_high;
    packet.sig_low = sig_low;
    packet.sig_gamma = sig_gamma;
    packet.sig_alpha = sig_alpha;
    packet.sig_beta = sig_beta;
    packet.virtual_a = virtual_a;
    packet.repulsor = repulsor;
    packet.target_proximity = target_proximity;
    packet.target_force = target_force;
    packet.node_id = node_id;
    packet.origin_id = origin_id;
    packet.dest_id = dest_id;
    packet.node_state = node_state;
    packet.tentacle_state = tentacle_state;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS_LEN, MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS_CRC);
}

/**
 * @brief Pack a bioair_configurations message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param node_id  Node ID
 * @param origin_id  Origin ID
 * @param dest_id  Destination ID
 * @param node_state  Node State
 * @param tentacle_state  Tentacle State
 * @param origin_north  Origin North
 * @param origin_east [m] Origin East
 * @param origin_down [m] Origin Down
 * @param dest_north [m] Destination North
 * @param dest_east [m] Destination East
 * @param dest_down [m] Destination Down
 * @param min_relative_alt [mm] Minimum Relative Altitude
 * @param sig_high  Signal High
 * @param sig_low  Signal Low
 * @param sig_gamma  Signal Gamma
 * @param sig_alpha  Signal Alpha
 * @param sig_beta  Signal Beta
 * @param virtual_a  Virtual A
 * @param repulsor  Repulsor
 * @param target_proximity  Target Proximity
 * @param target_force  Target Force
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_bioair_configurations_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t node_id,uint8_t origin_id,uint8_t dest_id,uint8_t node_state,uint8_t tentacle_state,float origin_north,float origin_east,float origin_down,float dest_north,float dest_east,float dest_down,int32_t min_relative_alt,float sig_high,float sig_low,float sig_gamma,float sig_alpha,float sig_beta,float virtual_a,float repulsor,float target_proximity,float target_force)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS_LEN];
    _mav_put_float(buf, 0, origin_north);
    _mav_put_float(buf, 4, origin_east);
    _mav_put_float(buf, 8, origin_down);
    _mav_put_float(buf, 12, dest_north);
    _mav_put_float(buf, 16, dest_east);
    _mav_put_float(buf, 20, dest_down);
    _mav_put_int32_t(buf, 24, min_relative_alt);
    _mav_put_float(buf, 28, sig_high);
    _mav_put_float(buf, 32, sig_low);
    _mav_put_float(buf, 36, sig_gamma);
    _mav_put_float(buf, 40, sig_alpha);
    _mav_put_float(buf, 44, sig_beta);
    _mav_put_float(buf, 48, virtual_a);
    _mav_put_float(buf, 52, repulsor);
    _mav_put_float(buf, 56, target_proximity);
    _mav_put_float(buf, 60, target_force);
    _mav_put_uint8_t(buf, 64, node_id);
    _mav_put_uint8_t(buf, 65, origin_id);
    _mav_put_uint8_t(buf, 66, dest_id);
    _mav_put_uint8_t(buf, 67, node_state);
    _mav_put_uint8_t(buf, 68, tentacle_state);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS_LEN);
#else
    mavlink_bioair_configurations_t packet;
    packet.origin_north = origin_north;
    packet.origin_east = origin_east;
    packet.origin_down = origin_down;
    packet.dest_north = dest_north;
    packet.dest_east = dest_east;
    packet.dest_down = dest_down;
    packet.min_relative_alt = min_relative_alt;
    packet.sig_high = sig_high;
    packet.sig_low = sig_low;
    packet.sig_gamma = sig_gamma;
    packet.sig_alpha = sig_alpha;
    packet.sig_beta = sig_beta;
    packet.virtual_a = virtual_a;
    packet.repulsor = repulsor;
    packet.target_proximity = target_proximity;
    packet.target_force = target_force;
    packet.node_id = node_id;
    packet.origin_id = origin_id;
    packet.dest_id = dest_id;
    packet.node_state = node_state;
    packet.tentacle_state = tentacle_state;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS_LEN, MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS_CRC);
}

/**
 * @brief Encode a bioair_configurations struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param bioair_configurations C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_bioair_configurations_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_bioair_configurations_t* bioair_configurations)
{
    return mavlink_msg_bioair_configurations_pack(system_id, component_id, msg, bioair_configurations->node_id, bioair_configurations->origin_id, bioair_configurations->dest_id, bioair_configurations->node_state, bioair_configurations->tentacle_state, bioair_configurations->origin_north, bioair_configurations->origin_east, bioair_configurations->origin_down, bioair_configurations->dest_north, bioair_configurations->dest_east, bioair_configurations->dest_down, bioair_configurations->min_relative_alt, bioair_configurations->sig_high, bioair_configurations->sig_low, bioair_configurations->sig_gamma, bioair_configurations->sig_alpha, bioair_configurations->sig_beta, bioair_configurations->virtual_a, bioair_configurations->repulsor, bioair_configurations->target_proximity, bioair_configurations->target_force);
}

/**
 * @brief Encode a bioair_configurations struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param bioair_configurations C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_bioair_configurations_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_bioair_configurations_t* bioair_configurations)
{
    return mavlink_msg_bioair_configurations_pack_chan(system_id, component_id, chan, msg, bioair_configurations->node_id, bioair_configurations->origin_id, bioair_configurations->dest_id, bioair_configurations->node_state, bioair_configurations->tentacle_state, bioair_configurations->origin_north, bioair_configurations->origin_east, bioair_configurations->origin_down, bioair_configurations->dest_north, bioair_configurations->dest_east, bioair_configurations->dest_down, bioair_configurations->min_relative_alt, bioair_configurations->sig_high, bioair_configurations->sig_low, bioair_configurations->sig_gamma, bioair_configurations->sig_alpha, bioair_configurations->sig_beta, bioair_configurations->virtual_a, bioair_configurations->repulsor, bioair_configurations->target_proximity, bioair_configurations->target_force);
}

/**
 * @brief Send a bioair_configurations message
 * @param chan MAVLink channel to send the message
 *
 * @param node_id  Node ID
 * @param origin_id  Origin ID
 * @param dest_id  Destination ID
 * @param node_state  Node State
 * @param tentacle_state  Tentacle State
 * @param origin_north  Origin North
 * @param origin_east [m] Origin East
 * @param origin_down [m] Origin Down
 * @param dest_north [m] Destination North
 * @param dest_east [m] Destination East
 * @param dest_down [m] Destination Down
 * @param min_relative_alt [mm] Minimum Relative Altitude
 * @param sig_high  Signal High
 * @param sig_low  Signal Low
 * @param sig_gamma  Signal Gamma
 * @param sig_alpha  Signal Alpha
 * @param sig_beta  Signal Beta
 * @param virtual_a  Virtual A
 * @param repulsor  Repulsor
 * @param target_proximity  Target Proximity
 * @param target_force  Target Force
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_bioair_configurations_send(mavlink_channel_t chan, uint8_t node_id, uint8_t origin_id, uint8_t dest_id, uint8_t node_state, uint8_t tentacle_state, float origin_north, float origin_east, float origin_down, float dest_north, float dest_east, float dest_down, int32_t min_relative_alt, float sig_high, float sig_low, float sig_gamma, float sig_alpha, float sig_beta, float virtual_a, float repulsor, float target_proximity, float target_force)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS_LEN];
    _mav_put_float(buf, 0, origin_north);
    _mav_put_float(buf, 4, origin_east);
    _mav_put_float(buf, 8, origin_down);
    _mav_put_float(buf, 12, dest_north);
    _mav_put_float(buf, 16, dest_east);
    _mav_put_float(buf, 20, dest_down);
    _mav_put_int32_t(buf, 24, min_relative_alt);
    _mav_put_float(buf, 28, sig_high);
    _mav_put_float(buf, 32, sig_low);
    _mav_put_float(buf, 36, sig_gamma);
    _mav_put_float(buf, 40, sig_alpha);
    _mav_put_float(buf, 44, sig_beta);
    _mav_put_float(buf, 48, virtual_a);
    _mav_put_float(buf, 52, repulsor);
    _mav_put_float(buf, 56, target_proximity);
    _mav_put_float(buf, 60, target_force);
    _mav_put_uint8_t(buf, 64, node_id);
    _mav_put_uint8_t(buf, 65, origin_id);
    _mav_put_uint8_t(buf, 66, dest_id);
    _mav_put_uint8_t(buf, 67, node_state);
    _mav_put_uint8_t(buf, 68, tentacle_state);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS, buf, MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS_LEN, MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS_CRC);
#else
    mavlink_bioair_configurations_t packet;
    packet.origin_north = origin_north;
    packet.origin_east = origin_east;
    packet.origin_down = origin_down;
    packet.dest_north = dest_north;
    packet.dest_east = dest_east;
    packet.dest_down = dest_down;
    packet.min_relative_alt = min_relative_alt;
    packet.sig_high = sig_high;
    packet.sig_low = sig_low;
    packet.sig_gamma = sig_gamma;
    packet.sig_alpha = sig_alpha;
    packet.sig_beta = sig_beta;
    packet.virtual_a = virtual_a;
    packet.repulsor = repulsor;
    packet.target_proximity = target_proximity;
    packet.target_force = target_force;
    packet.node_id = node_id;
    packet.origin_id = origin_id;
    packet.dest_id = dest_id;
    packet.node_state = node_state;
    packet.tentacle_state = tentacle_state;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS, (const char *)&packet, MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS_LEN, MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS_CRC);
#endif
}

/**
 * @brief Send a bioair_configurations message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_bioair_configurations_send_struct(mavlink_channel_t chan, const mavlink_bioair_configurations_t* bioair_configurations)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_bioair_configurations_send(chan, bioair_configurations->node_id, bioair_configurations->origin_id, bioair_configurations->dest_id, bioair_configurations->node_state, bioair_configurations->tentacle_state, bioair_configurations->origin_north, bioair_configurations->origin_east, bioair_configurations->origin_down, bioair_configurations->dest_north, bioair_configurations->dest_east, bioair_configurations->dest_down, bioair_configurations->min_relative_alt, bioair_configurations->sig_high, bioair_configurations->sig_low, bioair_configurations->sig_gamma, bioair_configurations->sig_alpha, bioair_configurations->sig_beta, bioair_configurations->virtual_a, bioair_configurations->repulsor, bioair_configurations->target_proximity, bioair_configurations->target_force);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS, (const char *)bioair_configurations, MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS_LEN, MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS_CRC);
#endif
}

#if MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_bioair_configurations_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t node_id, uint8_t origin_id, uint8_t dest_id, uint8_t node_state, uint8_t tentacle_state, float origin_north, float origin_east, float origin_down, float dest_north, float dest_east, float dest_down, int32_t min_relative_alt, float sig_high, float sig_low, float sig_gamma, float sig_alpha, float sig_beta, float virtual_a, float repulsor, float target_proximity, float target_force)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, origin_north);
    _mav_put_float(buf, 4, origin_east);
    _mav_put_float(buf, 8, origin_down);
    _mav_put_float(buf, 12, dest_north);
    _mav_put_float(buf, 16, dest_east);
    _mav_put_float(buf, 20, dest_down);
    _mav_put_int32_t(buf, 24, min_relative_alt);
    _mav_put_float(buf, 28, sig_high);
    _mav_put_float(buf, 32, sig_low);
    _mav_put_float(buf, 36, sig_gamma);
    _mav_put_float(buf, 40, sig_alpha);
    _mav_put_float(buf, 44, sig_beta);
    _mav_put_float(buf, 48, virtual_a);
    _mav_put_float(buf, 52, repulsor);
    _mav_put_float(buf, 56, target_proximity);
    _mav_put_float(buf, 60, target_force);
    _mav_put_uint8_t(buf, 64, node_id);
    _mav_put_uint8_t(buf, 65, origin_id);
    _mav_put_uint8_t(buf, 66, dest_id);
    _mav_put_uint8_t(buf, 67, node_state);
    _mav_put_uint8_t(buf, 68, tentacle_state);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS, buf, MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS_LEN, MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS_CRC);
#else
    mavlink_bioair_configurations_t *packet = (mavlink_bioair_configurations_t *)msgbuf;
    packet->origin_north = origin_north;
    packet->origin_east = origin_east;
    packet->origin_down = origin_down;
    packet->dest_north = dest_north;
    packet->dest_east = dest_east;
    packet->dest_down = dest_down;
    packet->min_relative_alt = min_relative_alt;
    packet->sig_high = sig_high;
    packet->sig_low = sig_low;
    packet->sig_gamma = sig_gamma;
    packet->sig_alpha = sig_alpha;
    packet->sig_beta = sig_beta;
    packet->virtual_a = virtual_a;
    packet->repulsor = repulsor;
    packet->target_proximity = target_proximity;
    packet->target_force = target_force;
    packet->node_id = node_id;
    packet->origin_id = origin_id;
    packet->dest_id = dest_id;
    packet->node_state = node_state;
    packet->tentacle_state = tentacle_state;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS, (const char *)packet, MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS_LEN, MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS_CRC);
#endif
}
#endif

#endif

// MESSAGE BIOAIR_CONFIGURATIONS UNPACKING


/**
 * @brief Get field node_id from bioair_configurations message
 *
 * @return  Node ID
 */
static inline uint8_t mavlink_msg_bioair_configurations_get_node_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  64);
}

/**
 * @brief Get field origin_id from bioair_configurations message
 *
 * @return  Origin ID
 */
static inline uint8_t mavlink_msg_bioair_configurations_get_origin_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  65);
}

/**
 * @brief Get field dest_id from bioair_configurations message
 *
 * @return  Destination ID
 */
static inline uint8_t mavlink_msg_bioair_configurations_get_dest_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  66);
}

/**
 * @brief Get field node_state from bioair_configurations message
 *
 * @return  Node State
 */
static inline uint8_t mavlink_msg_bioair_configurations_get_node_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  67);
}

/**
 * @brief Get field tentacle_state from bioair_configurations message
 *
 * @return  Tentacle State
 */
static inline uint8_t mavlink_msg_bioair_configurations_get_tentacle_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  68);
}

/**
 * @brief Get field origin_north from bioair_configurations message
 *
 * @return  Origin North
 */
static inline float mavlink_msg_bioair_configurations_get_origin_north(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field origin_east from bioair_configurations message
 *
 * @return [m] Origin East
 */
static inline float mavlink_msg_bioair_configurations_get_origin_east(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field origin_down from bioair_configurations message
 *
 * @return [m] Origin Down
 */
static inline float mavlink_msg_bioair_configurations_get_origin_down(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field dest_north from bioair_configurations message
 *
 * @return [m] Destination North
 */
static inline float mavlink_msg_bioair_configurations_get_dest_north(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field dest_east from bioair_configurations message
 *
 * @return [m] Destination East
 */
static inline float mavlink_msg_bioair_configurations_get_dest_east(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field dest_down from bioair_configurations message
 *
 * @return [m] Destination Down
 */
static inline float mavlink_msg_bioair_configurations_get_dest_down(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field min_relative_alt from bioair_configurations message
 *
 * @return [mm] Minimum Relative Altitude
 */
static inline int32_t mavlink_msg_bioair_configurations_get_min_relative_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  24);
}

/**
 * @brief Get field sig_high from bioair_configurations message
 *
 * @return  Signal High
 */
static inline float mavlink_msg_bioair_configurations_get_sig_high(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field sig_low from bioair_configurations message
 *
 * @return  Signal Low
 */
static inline float mavlink_msg_bioair_configurations_get_sig_low(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field sig_gamma from bioair_configurations message
 *
 * @return  Signal Gamma
 */
static inline float mavlink_msg_bioair_configurations_get_sig_gamma(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field sig_alpha from bioair_configurations message
 *
 * @return  Signal Alpha
 */
static inline float mavlink_msg_bioair_configurations_get_sig_alpha(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field sig_beta from bioair_configurations message
 *
 * @return  Signal Beta
 */
static inline float mavlink_msg_bioair_configurations_get_sig_beta(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field virtual_a from bioair_configurations message
 *
 * @return  Virtual A
 */
static inline float mavlink_msg_bioair_configurations_get_virtual_a(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field repulsor from bioair_configurations message
 *
 * @return  Repulsor
 */
static inline float mavlink_msg_bioair_configurations_get_repulsor(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  52);
}

/**
 * @brief Get field target_proximity from bioair_configurations message
 *
 * @return  Target Proximity
 */
static inline float mavlink_msg_bioair_configurations_get_target_proximity(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  56);
}

/**
 * @brief Get field target_force from bioair_configurations message
 *
 * @return  Target Force
 */
static inline float mavlink_msg_bioair_configurations_get_target_force(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  60);
}

/**
 * @brief Decode a bioair_configurations message into a struct
 *
 * @param msg The message to decode
 * @param bioair_configurations C-struct to decode the message contents into
 */
static inline void mavlink_msg_bioair_configurations_decode(const mavlink_message_t* msg, mavlink_bioair_configurations_t* bioair_configurations)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    bioair_configurations->origin_north = mavlink_msg_bioair_configurations_get_origin_north(msg);
    bioair_configurations->origin_east = mavlink_msg_bioair_configurations_get_origin_east(msg);
    bioair_configurations->origin_down = mavlink_msg_bioair_configurations_get_origin_down(msg);
    bioair_configurations->dest_north = mavlink_msg_bioair_configurations_get_dest_north(msg);
    bioair_configurations->dest_east = mavlink_msg_bioair_configurations_get_dest_east(msg);
    bioair_configurations->dest_down = mavlink_msg_bioair_configurations_get_dest_down(msg);
    bioair_configurations->min_relative_alt = mavlink_msg_bioair_configurations_get_min_relative_alt(msg);
    bioair_configurations->sig_high = mavlink_msg_bioair_configurations_get_sig_high(msg);
    bioair_configurations->sig_low = mavlink_msg_bioair_configurations_get_sig_low(msg);
    bioair_configurations->sig_gamma = mavlink_msg_bioair_configurations_get_sig_gamma(msg);
    bioair_configurations->sig_alpha = mavlink_msg_bioair_configurations_get_sig_alpha(msg);
    bioair_configurations->sig_beta = mavlink_msg_bioair_configurations_get_sig_beta(msg);
    bioair_configurations->virtual_a = mavlink_msg_bioair_configurations_get_virtual_a(msg);
    bioair_configurations->repulsor = mavlink_msg_bioair_configurations_get_repulsor(msg);
    bioair_configurations->target_proximity = mavlink_msg_bioair_configurations_get_target_proximity(msg);
    bioair_configurations->target_force = mavlink_msg_bioair_configurations_get_target_force(msg);
    bioair_configurations->node_id = mavlink_msg_bioair_configurations_get_node_id(msg);
    bioair_configurations->origin_id = mavlink_msg_bioair_configurations_get_origin_id(msg);
    bioair_configurations->dest_id = mavlink_msg_bioair_configurations_get_dest_id(msg);
    bioair_configurations->node_state = mavlink_msg_bioair_configurations_get_node_state(msg);
    bioair_configurations->tentacle_state = mavlink_msg_bioair_configurations_get_tentacle_state(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS_LEN? msg->len : MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS_LEN;
        memset(bioair_configurations, 0, MAVLINK_MSG_ID_BIOAIR_CONFIGURATIONS_LEN);
    memcpy(bioair_configurations, _MAV_PAYLOAD(msg), len);
#endif
}
