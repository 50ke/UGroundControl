import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import QtLocation
import QtPositioning
import "./Component"
import QmlControls 1.0

Window {
    id: root
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

    UGCMessageBox{
        id: messageBoxId
        width: 100
        height: 30
        visible: false
        anchors.top: parent.top
        anchors.topMargin: 60
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Timer {
        id: messageBoxTimerId
        interval: 3000
        onTriggered: {
            messageBoxId.visible = false
        }
    }
    function showInfo(content, type){
        if(!messageBoxId.visible){
            messageBoxId.visible = true
        }
        messageBoxId.show(content, type)
        messageBoxTimerId.start()
    }
}
