find_package(Qt6 REQUIRED COMPONENTS Core Quick)

qt_add_library(Common STATIC
    UGCApplication.h UGCApplication.cpp
    UGCContext.h UGCContext.cpp
)


target_link_libraries(Common
    PUBLIC
        Qt6::Quick
        Qt6::Core
        SettingManager
        LinkManager
        VehicleManager
)

target_include_directories(Common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
