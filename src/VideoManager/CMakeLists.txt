find_package(Qt6 REQUIRED COMPONENTS Core Quick)
find_package(boost_json REQUIRED CONFIG)

qt_add_library(VideoManager STATIC VideoManager.h VideoManager.cpp)

target_link_libraries(VideoManager
    PUBLIC
        Qt6::Quick
        Qt6::Core
        Boost::json
        Common
)

target_include_directories(VideoManager PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
