find_package(Qt6 REQUIRED COMPONENTS Core Quick)
find_package(boost_json REQUIRED CONFIG)

qt_add_library(LidarManager STATIC LidarManager.h LidarManager.cpp)

target_link_libraries(LidarManager
    PUBLIC
        Qt6::Quick
        Qt6::Core
        Boost::json
        Common
)

target_include_directories(LidarManager PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
