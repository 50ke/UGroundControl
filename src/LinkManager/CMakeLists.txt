find_package(Qt6 REQUIRED COMPONENTS Core Quick)
find_package(PahoMqttCpp CONFIG REQUIRED)

qt_add_library(LinkManager STATIC LinkManager.h LinkManager.cpp MqttLink.h MqttLink.cpp)

target_link_libraries(LinkManager
    PUBLIC
        Qt6::Quick
        Qt6::Core
        PahoMqttCpp::paho-mqttpp3
        Common
        SettingManager
        LinkProtocol
)

target_include_directories(LinkManager PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
