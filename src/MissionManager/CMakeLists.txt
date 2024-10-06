find_package(Qt6 REQUIRED COMPONENTS Core Quick)
find_package(boost_json REQUIRED CONFIG)

qt_add_library(MissionManager STATIC MissionManager.h MissionManager.cpp)

target_link_libraries(MissionManager
    PUBLIC
        Qt6::Quick
        Qt6::Core
        Boost::json
        LinkManager
        SettingManager
        LinkProtocol
        VehicleManager
)

target_include_directories(MissionManager PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
