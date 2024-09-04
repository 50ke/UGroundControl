find_package(Qt6 REQUIRED COMPONENTS Core Quick)

qt_add_library(SettingManager STATIC SettingManager.h SettingManager.cpp)


target_link_libraries(SettingManager
    PUBLIC
        Qt6::Quick
        Qt6::Core
        Common
)

target_include_directories(SettingManager PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
