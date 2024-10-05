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
            model: ListModel {}
            delegate: Rectangle{
                width: listViewId.width
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

    Connections {
        target: vehicleManager
        function onReadVehicleParamsCompleted(params) {
            listViewId.model.clear()
            for (var i = 0; i < params.length; i++) {
                listViewId.model.append({
                    "paramId": params[i].paramId,
                    "paramValue": params[i].paramValue
                })
            }
        }
    }

    Component.onCompleted: {
        var params = vehicleManager.readVehicleParams()
        listViewId.model.clear()
        for (var i = 0; i < params.length; i++) {
            listViewId.model.append({
                "paramId": params[i].paramId,
                "paramValue": params[i].paramValue
            })
        }
    }
}
