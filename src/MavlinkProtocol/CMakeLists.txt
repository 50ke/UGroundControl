find_package(Qt6 REQUIRED COMPONENTS Core Quick)

file(GLOB SOURCES *.h *.hpp)

qt_add_library(MavlinkProtocol STATIC ${SOURCES})

target_link_libraries(MavlinkProtocol
    PUBLIC
        Qt6::Quick
        Qt6::Core
)

target_include_directories(MavlinkProtocol PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
