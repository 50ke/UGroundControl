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
            oText: "参数设置"
        }
        ToolSeparator {
            width: parent.width
            orientation: Qt.Horizontal
        }
        ListView {
            id: listViewId
            width: parent.width
            height: parent.height * 0.9
            focus: true
            clip: true
            spacing: 10
            model: ListModel {
                ListElement{
                    paramId: "PARAM_01"
                    paramValue: "1"
                }
                ListElement{
                    paramId: "PARAM_01"
                    paramValue: "1"
                }
                ListElement{
                    paramId: "PARAM_01"
                    paramValue: "1"
                }
                ListElement{
                    paramId: "PARAM_01"
                    paramValue: "2"
                }
                ListElement{
                    paramId: "PARAM_01"
                    paramValue: "1"
                }
                ListElement{
                    paramId: "PARAM_01"
                    paramValue: "1"
                }
                ListElement{
                    paramId: "PARAM_01"
                    paramValue: "1"
                }
                ListElement{
                    paramId: "PARAM_01"
                    paramValue: "1"
                }
                ListElement{
                    paramId: "PARAM_01"
                    paramValue: "1"
                }
                ListElement{
                    paramId: "PARAM_01"
                    paramValue: "1"
                }
                ListElement{
                    paramId: "PARAM_01"
                    paramValue: "1"
                }
                ListElement{
                    paramId: "PARAM_01"
                    paramValue: "1"
                }
                ListElement{
                    paramId: "PARAM_01"
                    paramValue: "1"
                }
                ListElement{
                    paramId: "PARAM_01"
                    paramValue: "1"
                }
                ListElement{
                    paramId: "PARAM_01"
                    paramValue: "1"
                }
            }
            delegate: Rectangle{
                width: parent.width
                height: 30
                color: "transparent"
                UGCParamSetBox{
                    anchors.fill: parent
                    oTitleText: paramId
                    oText: paramValue
                }
            }
        }
        ToolSeparator {
            width: parent.width
            orientation: Qt.Horizontal
        }
    }
}
