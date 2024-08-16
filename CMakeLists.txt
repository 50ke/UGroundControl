cmake_minimum_required(VERSION 3.16)

project(UGroundControl VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(QML_IMPORT_PATH ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR} CACHE STRING "" FORCE)

find_package(Qt6 REQUIRED COMPONENTS Quick WebEngineQuick)

include_directories(src)
aux_source_directory(src SRC_LIST)


qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appUGroundControl
    src/main.cpp ${SRC_LIST} UGroundControl.qrc
)

qt_add_qml_module(appUGroundControl
    URI UGroundControl
    VERSION 1.0
    QML_FILES
        qml/Main.qml
        RESOURCES UGroundControl.qrc
        QML_FILES
        QML_FILES UgcQuick/controls/UgcText.qml
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
    Qt6::WebEngineQuick
)

include(GNUInstallDirs)
install(TARGETS appUGroundControl
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
