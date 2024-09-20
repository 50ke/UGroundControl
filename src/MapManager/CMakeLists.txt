find_package(Qt6 REQUIRED COMPONENTS Core Quick)
find_package(boost_json REQUIRED CONFIG)

qt_add_library(MapManager STATIC MapManager.h MapManager.cpp)

target_link_libraries(MapManager
    PUBLIC
        Qt6::Quick
        Qt6::Core
        Boost::json
        Common
)

target_include_directories(MapManager PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
