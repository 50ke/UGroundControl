#pragma once
// MESSAGE USV_DISCONNECT_RESPONSE PACKING

#define MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE 50004


typedef struct __mavlink_usv_disconnect_response_t {
 uint8_t target_system; /*<  gcs system id.*/
 uint8_t ack; /*<  0: disconnect failed. 1: disconnect succeed.*/
} mavlink_usv_disconnect_response_t;

#define MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_LEN 2
#define MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_MIN_LEN 2
#define MAVLINK_MSG_ID_50004_LEN 2
#define MAVLINK_MSG_ID_50004_MIN_LEN 2

#define MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_CRC 151
#define MAVLINK_MSG_ID_50004_CRC 151



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_USV_DISCONNECT_RESPONSE { \
    50004, \
    "USV_DISCONNECT_RESPONSE", \
    2, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_usv_disconnect_response_t, target_system) }, \
         { "ack", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_usv_disconnect_response_t, ack) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_USV_DISCONNECT_RESPONSE { \
    "USV_DISCONNECT_RESPONSE", \
    2, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_usv_disconnect_response_t, target_system) }, \
         { "ack", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_usv_disconnect_response_t, ack) }, \
         } \
}
#endif

/**
 * @brief Pack a usv_disconnect_response message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  gcs system id.
 * @param ack  0: disconnect failed. 1: disconnect succeed.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_usv_disconnect_response_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, ack);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_LEN);
#else
    mavlink_usv_disconnect_response_t packet;
    packet.target_system = target_system;
    packet.ack = ack;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_LEN, MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_CRC);
}

/**
 * @brief Pack a usv_disconnect_response message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  gcs system id.
 * @param ack  0: disconnect failed. 1: disconnect succeed.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_usv_disconnect_response_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, ack);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_LEN);
#else
    mavlink_usv_disconnect_response_t packet;
    packet.target_system = target_system;
    packet.ack = ack;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_LEN, MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_LEN);
#endif
}

/**
 * @brief Pack a usv_disconnect_response message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  gcs system id.
 * @param ack  0: disconnect failed. 1: disconnect succeed.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_usv_disconnect_response_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, ack);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_LEN);
#else
    mavlink_usv_disconnect_response_t packet;
    packet.target_system = target_system;
    packet.ack = ack;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_LEN, MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_CRC);
}

/**
 * @brief Encode a usv_disconnect_response struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param usv_disconnect_response C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_usv_disconnect_response_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_usv_disconnect_response_t* usv_disconnect_response)
{
    return mavlink_msg_usv_disconnect_response_pack(system_id, component_id, msg, usv_disconnect_response->target_system, usv_disconnect_response->ack);
}

/**
 * @brief Encode a usv_disconnect_response struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param usv_disconnect_response C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_usv_disconnect_response_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_usv_disconnect_response_t* usv_disconnect_response)
{
    return mavlink_msg_usv_disconnect_response_pack_chan(system_id, component_id, chan, msg, usv_disconnect_response->target_system, usv_disconnect_response->ack);
}

/**
 * @brief Encode a usv_disconnect_response struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param usv_disconnect_response C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_usv_disconnect_response_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_usv_disconnect_response_t* usv_disconnect_response)
{
    return mavlink_msg_usv_disconnect_response_pack_status(system_id, component_id, _status, msg,  usv_disconnect_response->target_system, usv_disconnect_response->ack);
}

/**
 * @brief Send a usv_disconnect_response message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system  gcs system id.
 * @param ack  0: disconnect failed. 1: disconnect succeed.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_usv_disconnect_response_send(mavlink_channel_t chan, uint8_t target_system, uint8_t ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, ack);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE, buf, MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_LEN, MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_CRC);
#else
    mavlink_usv_disconnect_response_t packet;
    packet.target_system = target_system;
    packet.ack = ack;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE, (const char *)&packet, MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_LEN, MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_CRC);
#endif
}

/**
 * @brief Send a usv_disconnect_response message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_usv_disconnect_response_send_struct(mavlink_channel_t chan, const mavlink_usv_disconnect_response_t* usv_disconnect_response)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_usv_disconnect_response_send(chan, usv_disconnect_response->target_system, usv_disconnect_response->ack);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE, (const char *)usv_disconnect_response, MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_LEN, MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_CRC);
#endif
}

#if MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_usv_disconnect_response_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, ack);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE, buf, MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_LEN, MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_CRC);
#else
    mavlink_usv_disconnect_response_t *packet = (mavlink_usv_disconnect_response_t *)msgbuf;
    packet->target_system = target_system;
    packet->ack = ack;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE, (const char *)packet, MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_LEN, MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_CRC);
#endif
}
#endif

#endif

// MESSAGE USV_DISCONNECT_RESPONSE UNPACKING


/**
 * @brief Get field target_system from usv_disconnect_response message
 *
 * @return  gcs system id.
 */
static inline uint8_t mavlink_msg_usv_disconnect_response_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field ack from usv_disconnect_response message
 *
 * @return  0: disconnect failed. 1: disconnect succeed.
 */
static inline uint8_t mavlink_msg_usv_disconnect_response_get_ack(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Decode a usv_disconnect_response message into a struct
 *
 * @param msg The message to decode
 * @param usv_disconnect_response C-struct to decode the message contents into
 */
static inline void mavlink_msg_usv_disconnect_response_decode(const mavlink_message_t* msg, mavlink_usv_disconnect_response_t* usv_disconnect_response)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    usv_disconnect_response->target_system = mavlink_msg_usv_disconnect_response_get_target_system(msg);
    usv_disconnect_response->ack = mavlink_msg_usv_disconnect_response_get_ack(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_LEN? msg->len : MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_LEN;
        memset(usv_disconnect_response, 0, MAVLINK_MSG_ID_USV_DISCONNECT_RESPONSE_LEN);
    memcpy(usv_disconnect_response, _MAV_PAYLOAD(msg), len);
#endif
}
