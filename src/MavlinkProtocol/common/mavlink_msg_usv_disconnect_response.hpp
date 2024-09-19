// MESSAGE USV_DISCONNECT_RESPONSE support class

#pragma once

namespace mavlink {
namespace common {
namespace msg {

/**
 * @brief USV_DISCONNECT_RESPONSE message
 *
 * usv disconnect response
 */
struct USV_DISCONNECT_RESPONSE : mavlink::Message {
    static constexpr msgid_t MSG_ID = 50004;
    static constexpr size_t LENGTH = 2;
    static constexpr size_t MIN_LENGTH = 2;
    static constexpr uint8_t CRC_EXTRA = 151;
    static constexpr auto NAME = "USV_DISCONNECT_RESPONSE";


    uint8_t target_system; /*<  gcs system id. */
    uint8_t ack; /*<  0: disconnect failed. 1: disconnect succeed. */


    inline std::string get_name(void) const override
    {
            return NAME;
    }

    inline Info get_message_info(void) const override
    {
            return { MSG_ID, LENGTH, MIN_LENGTH, CRC_EXTRA };
    }

    inline std::string to_yaml(void) const override
    {
        std::stringstream ss;

        ss << NAME << ":" << std::endl;
        ss << "  target_system: " << +target_system << std::endl;
        ss << "  ack: " << +ack << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << target_system;                 // offset: 0
        map << ack;                           // offset: 1
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> target_system;                 // offset: 0
        map >> ack;                           // offset: 1
    }
};

} // namespace msg
} // namespace common
} // namespace mavlink
