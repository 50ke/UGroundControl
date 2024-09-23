import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs
import QmlControls 1.0

Rectangle {
    width: parent.width
    height: parent.height
    color: "#303133"
    Column{
        anchors.fill: parent
        anchors.margins: 5
        UGCText{
            oText: "创建任务"
        }
        ToolSeparator {
            width: parent.width
            orientation: Qt.Horizontal
        }
    }
}
