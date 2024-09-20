find_package(Qt6 REQUIRED COMPONENTS Core Quick)
find_package(boost_json REQUIRED CONFIG)

qt_add_library(VehicleManager STATIC
    VehicleSetup.h VehicleSetup.cpp
    VehicleManager.h VehicleManager.cpp
)

target_link_libraries(VehicleManager
    PUBLIC
        Qt6::Quick
        Qt6::Core
        Boost::json
        Common
        LinkManager
        SettingManager
        MavlinkProtocol
)

target_include_directories(VehicleManager PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
