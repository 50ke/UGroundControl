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
        Rectangle {
            width: parent.width
            height: parent.height / 3
            color: "#303133"
            ListView {
                id: listViewId
                anchors.fill: parent
                focus: true
                clip: true
                spacing: 1
                model: ListModel {
                    ListElement{
                        latitude: "12.122"
                        longitude: "12.122"
                    }
                    ListElement{
                        latitude: "12.122"
                        longitude: "12.122"
                    }
                    ListElement{
                        latitude: "12.122"
                        longitude: "12.1244442"
                    }
                    ListElement{
                        latitude: "12.122"
                        longitude: "12.122"
                    }
                    ListElement{
                        latitude: "12.124442"
                        longitude: "12.122"
                    }
                }
                delegate: Rectangle {
                    id: itemId
                    width: listViewId.width
                    height: 20
                    color: "#606266"
                    Row {
                        anchors.fill: parent
                        spacing: 10
                        leftPadding: 5
                        anchors.verticalCenter: parent.verticalCenter
                        UGCText {
                            anchors.verticalCenter: parent.verticalCenter
                            oText: model.index
                        }
                        ToolSeparator {
                            height: parent.height
                            orientation: Qt.Vertical
                        }
                        UGCText {
                            anchors.verticalCenter: parent.verticalCenter
                            oText: latitude
                        }
                        ToolSeparator {
                            height: parent.height
                            orientation: Qt.Vertical
                        }
                        UGCText {
                            anchors.verticalCenter: parent.verticalCenter
                            oText: longitude
                        }
                    }
                }
            }
        }
        ToolSeparator {
            width: parent.width
            orientation: Qt.Horizontal
        }
    }
}
