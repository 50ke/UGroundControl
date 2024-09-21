cmake_minimum_required(VERSION 3.16)

#######################################################
#                vcpkg配置(必须置于project之前声明)
#######################################################
set(CMAKE_TOOLCHAIN_FILE "D:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(VCPKG_TARGET_ARCHITECTURE x64)

#######################################################
#                项目信息
#######################################################
project(UGroundControl VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(QML_IMPORT_PATH ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/src ${CMAKE_BINARY_DIR} CACHE STRING "" FORCE)

find_package(Qt6 REQUIRED COMPONENTS Quick QuickControls2 WebEngineQuick)
find_package(Qt6 REQUIRED Core Location Network Positioning Qml Sql)
find_package(fmt CONFIG REQUIRED)

add_subdirectory(src/Common)
add_subdirectory(src/LidarManager)
add_subdirectory(src/LinkManager)
add_subdirectory(src/LogManager)
add_subdirectory(src/MapManager)
add_subdirectory(src/MavlinkProtocol)
add_subdirectory(src/MissionManager)
add_subdirectory(src/MockManager)
add_subdirectory(src/QtLocationPlugin)
add_subdirectory(src/SettingManager)
add_subdirectory(src/VehicleManager)
add_subdirectory(src/VideoManager)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appUGroundControl
    src/main.cpp
    UGroundControl.qrc
)

#######################################################
#                JSON文件
#######################################################
configure_file(UGroundControl.json ${CMAKE_CURRENT_BINARY_DIR}/UGroundControl.json COPYONLY)

#######################################################
#                QML文件
#######################################################
qt_add_qml_module(appUGroundControl
    URI UGroundControl
    VERSION 1.0
    QML_FILES src/UI/MainWindow.qml
    QML_FILES src/UI/SettingWindow.qml
    QML_FILES src/UI/Component/StatusBar.qml
    QML_FILES src/UI/Component/ToolBoxBar.qml
    QML_FILES src/UI/Component/OnlineMapView.qml
    QML_FILES src/UI/Component/OfflineMapView.qml
    QML_FILES src/UI/Component/LidarView.qml
    QML_FILES src/UI/Component/VideoView.qml
    QML_FILES src/UI/Component/VehicleList.qml

    QML_FILES src/QmlControls/UGCText.qml
    QML_FILES src/QmlControls/UGCButton.qml
    QML_FILES src/QmlControls/UGCInputBox.qml
    QML_FILES src/QmlControls/UGCComboBox.qml
    QML_FILES src/QmlControls/UGCInputComboBox.qml
    QML_FILES src/QmlControls/UGCImportFileBox.qml
    QML_FILES src/QmlControls/UGCInputMixBox.qml
    QML_FILES src/QmlControls/UGCPadding.qml
    RESOURCES UGroundControl.qrc
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appUGroundControl PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appUGroundControl
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appUGroundControl
    PRIVATE
    Qt6::Quick
    Qt6::Core
    Qt6::Location
    Qt6::LocationPrivate
    Qt6::Positioning
    Qt6::PositioningPrivate
    Qt6::Sql
    Qt6::Network
    Qt6::QuickControls2
    Qt6::WebEngineQuick
    fmt::fmt
    UGCLocation
    SettingManager
)

#######################################################
#		Install Configuration
#######################################################
include(GNUInstallDirs)
install(TARGETS appUGroundControl
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
