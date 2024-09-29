find_package(Protobuf CONFIG REQUIRED)

file(GLOB SOURCES *.h *.cc)

qt_add_library(LinkProtocol STATIC ${SOURCES})

target_link_libraries(LinkProtocol
    PUBLIC
        protobuf::libprotoc
        protobuf::libprotobuf
        protobuf::libprotobuf-lite
)

target_include_directories(LinkProtocol PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
