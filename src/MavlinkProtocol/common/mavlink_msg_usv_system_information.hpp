// MESSAGE USV_SYSTEM_INFORMATION support class

#pragma once

namespace mavlink {
namespace common {
namespace msg {

/**
 * @brief USV_SYSTEM_INFORMATION message
 *
 * system information
 */
struct USV_SYSTEM_INFORMATION : mavlink::Message {
    static constexpr msgid_t MSG_ID = 50005;
    static constexpr size_t LENGTH = 137;
    static constexpr size_t MIN_LENGTH = 137;
    static constexpr uint8_t CRC_EXTRA = 147;
    static constexpr auto NAME = "USV_SYSTEM_INFORMATION";


    std::array<char, 128> name; /*<  system name */
    uint8_t connected; /*<  0: not connected. 1: connected. */
    float lat; /*<  Latitude (WGS84, EGM96 ellipsoid) */
    float lon; /*<  Longitude (WGS84, EGM96 ellipsoid) */


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
        ss << "  name: \"" << to_string(name) << "\"" << std::endl;
        ss << "  connected: " << +connected << std::endl;
        ss << "  lat: " << lat << std::endl;
        ss << "  lon: " << lon << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << lat;                           // offset: 0
        map << lon;                           // offset: 4
        map << name;                          // offset: 8
        map << connected;                     // offset: 136
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> lat;                           // offset: 0
        map >> lon;                           // offset: 4
        map >> name;                          // offset: 8
        map >> connected;                     // offset: 136
    }
};

} // namespace msg
} // namespace common
} // namespace mavlink
