import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import QtLocation
import QtPositioning
import "./Component"

Window {
    width: 1000
    height: 640
    visible: true
    visibility: Window.Maximized
    title: "UGroundControl"

    Column{
        anchors.fill: parent
        StatusBar{
            id: headerId
            width: parent.width
            height: 40
        }
        Loader {
            id: bodyId
            width: parent.width
            height: parent.height - headerId.height
            source: "qrc:/src/UI/Component/OfflineMapView.qml"
        }
    }
}
