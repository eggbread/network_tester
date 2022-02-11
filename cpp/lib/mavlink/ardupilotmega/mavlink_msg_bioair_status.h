#pragma once
// MESSAGE BIOAIR_STATUS PACKING

#define MAVLINK_MSG_ID_BIOAIR_STATUS 20005


typedef struct __mavlink_bioair_status_t {
 uint16_t message_type; /*<  A code that identifies the software component that understands this message (analogous to USB device classes or mime type strings). If this code is less than 32768, it is considered a 'registered' protocol extension and the corresponding entry should be added to https://github.com/mavlink/mavlink/definition_files/extension_message_ids.xml. Software creators can register blocks of message IDs as needed (useful for GCS specific metadata, etc...). Message_types greater than 32767 are considered local experiments and should not be checked in to any widely distributed codebase.*/
 uint8_t payload[249]; /*<  Variable length payload. The length must be encoded in the payload as part of the message_type protocol, e.g. by including the length as payload data, or by terminating the payload data with a non-zero marker. This is required in order to reconstruct zero-terminated payloads that are (or otherwise would be) trimmed by MAVLink 2 empty-byte truncation. The entire content of the payload block is opaque unless you understand the encoding message_type. The particular encoding used can be extension specific and might not always be documented as part of the MAVLink specification.*/
} mavlink_bioair_status_t;

#define MAVLINK_MSG_ID_BIOAIR_STATUS_LEN 251
#define MAVLINK_MSG_ID_BIOAIR_STATUS_MIN_LEN 251
#define MAVLINK_MSG_ID_20005_LEN 251
#define MAVLINK_MSG_ID_20005_MIN_LEN 251

#define MAVLINK_MSG_ID_BIOAIR_STATUS_CRC 138
#define MAVLINK_MSG_ID_20005_CRC 138

#define MAVLINK_MSG_BIOAIR_STATUS_FIELD_PAYLOAD_LEN 249

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_BIOAIR_STATUS { \
    20005, \
    "BIOAIR_STATUS", \
    2, \
    {  { "message_type", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_bioair_status_t, message_type) }, \
         { "payload", NULL, MAVLINK_TYPE_UINT8_T, 249, 2, offsetof(mavlink_bioair_status_t, payload) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_BIOAIR_STATUS { \
    "BIOAIR_STATUS", \
    2, \
    {  { "message_type", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_bioair_status_t, message_type) }, \
         { "payload", NULL, MAVLINK_TYPE_UINT8_T, 249, 2, offsetof(mavlink_bioair_status_t, payload) }, \
         } \
}
#endif

/**
 * @brief Pack a bioair_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param message_type  A code that identifies the software component that understands this message (analogous to USB device classes or mime type strings). If this code is less than 32768, it is considered a 'registered' protocol extension and the corresponding entry should be added to https://github.com/mavlink/mavlink/definition_files/extension_message_ids.xml. Software creators can register blocks of message IDs as needed (useful for GCS specific metadata, etc...). Message_types greater than 32767 are considered local experiments and should not be checked in to any widely distributed codebase.
 * @param payload  Variable length payload. The length must be encoded in the payload as part of the message_type protocol, e.g. by including the length as payload data, or by terminating the payload data with a non-zero marker. This is required in order to reconstruct zero-terminated payloads that are (or otherwise would be) trimmed by MAVLink 2 empty-byte truncation. The entire content of the payload block is opaque unless you understand the encoding message_type. The particular encoding used can be extension specific and might not always be documented as part of the MAVLink specification.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_bioair_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t message_type, const uint8_t *payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BIOAIR_STATUS_LEN];
    _mav_put_uint16_t(buf, 0, message_type);
    _mav_put_uint8_t_array(buf, 2, payload, 249);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BIOAIR_STATUS_LEN);
#else
    mavlink_bioair_status_t packet;
    packet.message_type = message_type;
    mav_array_memcpy(packet.payload, payload, sizeof(uint8_t)*249);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BIOAIR_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_BIOAIR_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_BIOAIR_STATUS_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_STATUS_LEN, MAVLINK_MSG_ID_BIOAIR_STATUS_CRC);
}

/**
 * @brief Pack a bioair_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param message_type  A code that identifies the software component that understands this message (analogous to USB device classes or mime type strings). If this code is less than 32768, it is considered a 'registered' protocol extension and the corresponding entry should be added to https://github.com/mavlink/mavlink/definition_files/extension_message_ids.xml. Software creators can register blocks of message IDs as needed (useful for GCS specific metadata, etc...). Message_types greater than 32767 are considered local experiments and should not be checked in to any widely distributed codebase.
 * @param payload  Variable length payload. The length must be encoded in the payload as part of the message_type protocol, e.g. by including the length as payload data, or by terminating the payload data with a non-zero marker. This is required in order to reconstruct zero-terminated payloads that are (or otherwise would be) trimmed by MAVLink 2 empty-byte truncation. The entire content of the payload block is opaque unless you understand the encoding message_type. The particular encoding used can be extension specific and might not always be documented as part of the MAVLink specification.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_bioair_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t message_type,const uint8_t *payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BIOAIR_STATUS_LEN];
    _mav_put_uint16_t(buf, 0, message_type);
    _mav_put_uint8_t_array(buf, 2, payload, 249);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BIOAIR_STATUS_LEN);
#else
    mavlink_bioair_status_t packet;
    packet.message_type = message_type;
    mav_array_memcpy(packet.payload, payload, sizeof(uint8_t)*249);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BIOAIR_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_BIOAIR_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_BIOAIR_STATUS_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_STATUS_LEN, MAVLINK_MSG_ID_BIOAIR_STATUS_CRC);
}

/**
 * @brief Encode a bioair_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param bioair_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_bioair_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_bioair_status_t* bioair_status)
{
    return mavlink_msg_bioair_status_pack(system_id, component_id, msg, bioair_status->message_type, bioair_status->payload);
}

/**
 * @brief Encode a bioair_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param bioair_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_bioair_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_bioair_status_t* bioair_status)
{
    return mavlink_msg_bioair_status_pack_chan(system_id, component_id, chan, msg, bioair_status->message_type, bioair_status->payload);
}

/**
 * @brief Send a bioair_status message
 * @param chan MAVLink channel to send the message
 *
 * @param message_type  A code that identifies the software component that understands this message (analogous to USB device classes or mime type strings). If this code is less than 32768, it is considered a 'registered' protocol extension and the corresponding entry should be added to https://github.com/mavlink/mavlink/definition_files/extension_message_ids.xml. Software creators can register blocks of message IDs as needed (useful for GCS specific metadata, etc...). Message_types greater than 32767 are considered local experiments and should not be checked in to any widely distributed codebase.
 * @param payload  Variable length payload. The length must be encoded in the payload as part of the message_type protocol, e.g. by including the length as payload data, or by terminating the payload data with a non-zero marker. This is required in order to reconstruct zero-terminated payloads that are (or otherwise would be) trimmed by MAVLink 2 empty-byte truncation. The entire content of the payload block is opaque unless you understand the encoding message_type. The particular encoding used can be extension specific and might not always be documented as part of the MAVLink specification.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_bioair_status_send(mavlink_channel_t chan, uint16_t message_type, const uint8_t *payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BIOAIR_STATUS_LEN];
    _mav_put_uint16_t(buf, 0, message_type);
    _mav_put_uint8_t_array(buf, 2, payload, 249);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BIOAIR_STATUS, buf, MAVLINK_MSG_ID_BIOAIR_STATUS_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_STATUS_LEN, MAVLINK_MSG_ID_BIOAIR_STATUS_CRC);
#else
    mavlink_bioair_status_t packet;
    packet.message_type = message_type;
    mav_array_memcpy(packet.payload, payload, sizeof(uint8_t)*249);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BIOAIR_STATUS, (const char *)&packet, MAVLINK_MSG_ID_BIOAIR_STATUS_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_STATUS_LEN, MAVLINK_MSG_ID_BIOAIR_STATUS_CRC);
#endif
}

/**
 * @brief Send a bioair_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_bioair_status_send_struct(mavlink_channel_t chan, const mavlink_bioair_status_t* bioair_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_bioair_status_send(chan, bioair_status->message_type, bioair_status->payload);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BIOAIR_STATUS, (const char *)bioair_status, MAVLINK_MSG_ID_BIOAIR_STATUS_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_STATUS_LEN, MAVLINK_MSG_ID_BIOAIR_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_BIOAIR_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_bioair_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t message_type, const uint8_t *payload)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, message_type);
    _mav_put_uint8_t_array(buf, 2, payload, 249);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BIOAIR_STATUS, buf, MAVLINK_MSG_ID_BIOAIR_STATUS_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_STATUS_LEN, MAVLINK_MSG_ID_BIOAIR_STATUS_CRC);
#else
    mavlink_bioair_status_t *packet = (mavlink_bioair_status_t *)msgbuf;
    packet->message_type = message_type;
    mav_array_memcpy(packet->payload, payload, sizeof(uint8_t)*249);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BIOAIR_STATUS, (const char *)packet, MAVLINK_MSG_ID_BIOAIR_STATUS_MIN_LEN, MAVLINK_MSG_ID_BIOAIR_STATUS_LEN, MAVLINK_MSG_ID_BIOAIR_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE BIOAIR_STATUS UNPACKING


/**
 * @brief Get field message_type from bioair_status message
 *
 * @return  A code that identifies the software component that understands this message (analogous to USB device classes or mime type strings). If this code is less than 32768, it is considered a 'registered' protocol extension and the corresponding entry should be added to https://github.com/mavlink/mavlink/definition_files/extension_message_ids.xml. Software creators can register blocks of message IDs as needed (useful for GCS specific metadata, etc...). Message_types greater than 32767 are considered local experiments and should not be checked in to any widely distributed codebase.
 */
static inline uint16_t mavlink_msg_bioair_status_get_message_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field payload from bioair_status message
 *
 * @return  Variable length payload. The length must be encoded in the payload as part of the message_type protocol, e.g. by including the length as payload data, or by terminating the payload data with a non-zero marker. This is required in order to reconstruct zero-terminated payloads that are (or otherwise would be) trimmed by MAVLink 2 empty-byte truncation. The entire content of the payload block is opaque unless you understand the encoding message_type. The particular encoding used can be extension specific and might not always be documented as part of the MAVLink specification.
 */
static inline uint16_t mavlink_msg_bioair_status_get_payload(const mavlink_message_t* msg, uint8_t *payload)
{
    return _MAV_RETURN_uint8_t_array(msg, payload, 249,  2);
}

/**
 * @brief Decode a bioair_status message into a struct
 *
 * @param msg The message to decode
 * @param bioair_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_bioair_status_decode(const mavlink_message_t* msg, mavlink_bioair_status_t* bioair_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    bioair_status->message_type = mavlink_msg_bioair_status_get_message_type(msg);
    mavlink_msg_bioair_status_get_payload(msg, bioair_status->payload);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_BIOAIR_STATUS_LEN? msg->len : MAVLINK_MSG_ID_BIOAIR_STATUS_LEN;
        memset(bioair_status, 0, MAVLINK_MSG_ID_BIOAIR_STATUS_LEN);
    memcpy(bioair_status, _MAV_PAYLOAD(msg), len);
#endif
}
