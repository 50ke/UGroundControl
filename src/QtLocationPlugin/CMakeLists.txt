find_package(Qt6 REQUIRED COMPONENTS Core Location Network Positioning Qml Sql)

qt_add_plugin(UGCLocation STATIC
    CLASS_NAME UGCQGeoServiceProviderFactory
    OUTPUT_TARGETS UGCLocation_targets
    UGCQGeoServiceProviderFactory.h
    UGCQGeoServiceProviderFactory.cpp
    UGCQGeoTiledMappingManagerEngine.h
    UGCQGeoTiledMappingManagerEngine.cpp
    UGCQGeoTileFetcher.h
    UGCQGeoTileFetcher.cpp
    UGCGeoTiledMapReply.h
    UGCGeoTiledMapReply.cpp
)

target_link_libraries(UGCLocation
    PUBLIC
        Qt6::Core
        Qt6::Location
        Qt6::LocationPrivate
        Qt6::Positioning
        Qt6::PositioningPrivate
        Qt6::Sql
        Qt6::Network
)

target_include_directories(UGCLocation
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
