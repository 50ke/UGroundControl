find_package(Qt6 REQUIRED COMPONENTS Core Quick)
find_package(boost_json REQUIRED CONFIG)

qt_add_library(LogManager STATIC LogManager.h LogManager.cpp)

target_link_libraries(LogManager
    PUBLIC
        Qt6::Quick
        Qt6::Core
        Boost::json
        Common
)

target_include_directories(LogManager PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
