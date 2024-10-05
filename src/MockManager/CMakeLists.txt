find_package(Qt6 REQUIRED COMPONENTS Core Quick)
find_package(boost_json REQUIRED CONFIG)

qt_add_library(MockManager STATIC MockManager.h MockManager.cpp Heartbeat.h Heartbeat.cpp)

target_link_libraries(MockManager
    PUBLIC
        Qt6::Quick
        Qt6::Core
        Boost::json
        Common
        LinkProtocol
        LinkManager
        SettingManager
)

target_include_directories(MockManager PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
