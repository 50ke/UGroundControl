import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs
import QmlControls 1.0

Rectangle {

    property var createMissionItems: []

    width: parent.width
    height: parent.height
    color: "#303133"
    Column{
        anchors.fill: parent
        anchors.margins: 5
        UGCText{
            oText: "任务"
        }
        ToolSeparator {
            width: parent.width
            orientation: Qt.Horizontal
        }
        Rectangle {
            width: parent.width
            height: parent.height / 4
            color: "#303133"
            ListView {
                id: missionListViewId
                anchors.fill: parent
                focus: true
                clip: true
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
                    ListElement{
                        latitude: "12.124442"
                        longitude: "12.122"
                    }
                    ListElement{
                        latitude: "12.124442"
                        longitude: "12.122"
                    }
                    ListElement{
                        latitude: "12.124442"
                        longitude: "12.122"
                    }
                }
                delegate: Rectangle {
                    width: missionListViewId.width
                    height: 20
                    color: "#606266"
                    Row {
                        anchors.fill: parent
                        spacing: 5
                        leftPadding: 5
                        anchors.verticalCenter: parent.verticalCenter
                        UGCText {
                            anchors.verticalCenter: parent.verticalCenter
                            oText: model.index
                            oTextFont.pointSize: 10
                        }
                        ToolSeparator {
                            height: parent.height
                            orientation: Qt.Vertical
                        }
                        UGCText {
                            anchors.verticalCenter: parent.verticalCenter
                            oText: latitude
                            oTextFont.pointSize: 10
                        }
                        ToolSeparator {
                            height: parent.height
                            orientation: Qt.Vertical
                        }
                        UGCText {
                            anchors.verticalCenter: parent.verticalCenter
                            oText: longitude
                            oTextFont.pointSize: 10
                        }
                    }
                }
            }
        }
        UGCText{
            oText: "新建"
        }
        ToolSeparator {
            width: parent.width
            orientation: Qt.Horizontal
        }
        Rectangle {
            width: parent.width
            height: parent.height / 4
            color: "#303133"
            ListView {
                id: createListViewId
                anchors.fill: parent
                focus: true
                clip: true
                model: ListModel {}
                delegate: Rectangle {
                    width: createListViewId.width
                    height: 20
                    color: "#606266"
                    Row {
                        anchors.fill: parent
                        spacing: 2
                        leftPadding: 5
                        anchors.verticalCenter: parent.verticalCenter
                        UGCText {
                            anchors.verticalCenter: parent.verticalCenter
                            oText: model.index
                            oTextFont.pointSize: 10
                        }
                        ToolSeparator {
                            height: parent.height
                            orientation: Qt.Vertical
                        }
                        UGCText {
                            anchors.verticalCenter: parent.verticalCenter
                            oText: latitude
                            oTextFont.pointSize: 10
                        }
                        ToolSeparator {
                            height: parent.height
                            orientation: Qt.Vertical
                        }
                        UGCText {
                            anchors.verticalCenter: parent.verticalCenter
                            oText: longitude
                            oTextFont.pointSize: 10
                        }
                        ToolSeparator {
                            height: parent.height
                            orientation: Qt.Vertical
                        }
                        UGCText {
                            anchors.verticalCenter: parent.verticalCenter
                            oText: cmdName
                            oTextFont.pointSize: 10
                        }
                        ToolSeparator {
                            height: parent.height
                            orientation: Qt.Vertical
                        }
                        Image {
                            height: 16
                            width: 16
                            anchors.verticalCenter: parent.verticalCenter
                            source: "qrc:/resources/icons/edit.svg"
                            MouseArea {
                                anchors.fill: parent
                                onClicked: {
                                    Qt.createComponent("qrc:/src/UI/Component/MissionItemEdit.qml")
                                    .createObject(parent, {
                                        seq: model.index,
                                        item: createMissionItems[model.index]
                                    });
                                }
                            }
                        }
                    }
                }
            }
        }

        UGCText{
            oText: "存储"
        }
        ToolSeparator {
            width: parent.width
            orientation: Qt.Horizontal
        }
        Row {
            spacing: 5
            width: parent.width
            height: 25
            UGCButton{
                oText: "导入"
                width: 50
                height: parent.height
                oTextFont.pointSize: 10
                display: AbstractButton.TextOnly
                oNormalTextColor: "#ffffff"
                oPressedTextColor: "#ffffff"
                oHoveredTextColor: "#ffffff"
                oNormalBackgroundColor: "#606266"
                oPressedBackgroundColor: "#73767a"
                oHoveredBackgroundColor: "#b1b3b8"
                oNormalBorderColor: "#606266"
                oPressedBorderColor: "#73767a"
                oHoveredBorderColor: "#b1b3b8"
            }
            UGCButton{
                oText: "导出"
                width: 50
                height: parent.height
                oTextFont.pointSize: 10
                display: AbstractButton.TextOnly
                oNormalTextColor: "#ffffff"
                oPressedTextColor: "#ffffff"
                oHoveredTextColor: "#ffffff"
                oNormalBackgroundColor: "#606266"
                oPressedBackgroundColor: "#73767a"
                oHoveredBackgroundColor: "#b1b3b8"
                oNormalBorderColor: "#606266"
                oPressedBorderColor: "#73767a"
                oHoveredBorderColor: "#b1b3b8"
            }
        }
        UGCText{
            oText: "操作"
        }
        ToolSeparator {
            width: parent.width
            orientation: Qt.Horizontal
        }
        Row {
            spacing: 5
            width: parent.width
            height: 25
            UGCButton{
                oText: "上传"
                width: 50
                height: parent.height
                oTextFont.pointSize: 10
                display: AbstractButton.TextOnly
                oNormalTextColor: "#ffffff"
                oPressedTextColor: "#ffffff"
                oHoveredTextColor: "#ffffff"
                oNormalBackgroundColor: "#606266"
                oPressedBackgroundColor: "#73767a"
                oHoveredBackgroundColor: "#b1b3b8"
                oNormalBorderColor: "#606266"
                oPressedBorderColor: "#73767a"
                oHoveredBorderColor: "#b1b3b8"
                onClicked: {
                    uploadMissionDialogId.open()
                }
            }
            UGCButton{
                oText: "下载"
                width: 50
                height: parent.height
                oTextFont.pointSize: 10
                display: AbstractButton.TextOnly
                oNormalTextColor: "#ffffff"
                oPressedTextColor: "#ffffff"
                oHoveredTextColor: "#ffffff"
                oNormalBackgroundColor: "#606266"
                oPressedBackgroundColor: "#73767a"
                oHoveredBackgroundColor: "#b1b3b8"
                oNormalBorderColor: "#606266"
                oPressedBorderColor: "#73767a"
                oHoveredBorderColor: "#b1b3b8"
                onClicked: {
                    downloadMissionDialogId.open()
                }
            }
            UGCButton{
                oText: "清除"
                width: 50
                height: parent.height
                oTextFont.pointSize: 10
                display: AbstractButton.TextOnly
                oNormalTextColor: "#ffffff"
                oPressedTextColor: "#ffffff"
                oHoveredTextColor: "#ffffff"
                oNormalBackgroundColor: "#606266"
                oPressedBackgroundColor: "#73767a"
                oHoveredBackgroundColor: "#b1b3b8"
                oNormalBorderColor: "#606266"
                oPressedBorderColor: "#73767a"
                oHoveredBorderColor: "#b1b3b8"
                onClicked: {
                    clearMissionDialogId.open()
                }
            }
        }
    }

    MessageDialog {
           id: clearMissionDialogId
           text: "确认是否清除当前任务？"
           buttons: MessageDialog.Ok | MessageDialog.Cancel
           onAccepted: {
               missionManager.clearMission()
           }
           onRejected: {}
    }

    MessageDialog {
           id: downloadMissionDialogId
           text: "确认是否下载当前任务？"
           buttons: MessageDialog.Ok | MessageDialog.Cancel
           onAccepted: {
               missionManager.downloadMission()
           }
           onRejected: {}
    }

    MessageDialog {
           id: uploadMissionDialogId
           text: "确认是否创建新任务？"
           buttons: MessageDialog.Ok | MessageDialog.Cancel
           onAccepted: {
               missionManager.uploadMission(createMissionItems)
           }
           onRejected: {}
    }

    Connections{
        target: missionManager
        function onWaypointAdded(waypoint){
            var defaultMissionItem = missionManager.getDefaultMissionItem()
            defaultMissionItem["latitude"] = waypoint.latitude.toFixed(7)
            defaultMissionItem["longitude"] = waypoint.longitude.toFixed(7)
            createMissionItems.push(defaultMissionItem)
            createListViewId.model.append({"cmdName":defaultMissionItem["cmdName"], "latitude": waypoint.latitude.toFixed(7),"longitude": waypoint.longitude.toFixed(7)})
        }
        function onWaypointUpdated(index, waypoint){
            createListViewId.model.set(index, {"latitude": waypoint.latitude.toFixed(7),"longitude": waypoint.longitude.toFixed(7)})
            createMissionItems[index]["latitude"] = waypoint.latitude.toFixed(7)
            createMissionItems[index]["longitude"] = waypoint.longitude.toFixed(7)
        }
        function onWaypointRemoved(index){
            createListViewId.model.remove(index, 1)
            createMissionItems.splice(index, 1)
        }
        function onWaypointCleared(){
            createListViewId.model.clear()
            createMissionItems = []
        }
        function onMissionItemEdited(index, missionItem){
            createMissionItems[index]["cmdId"] = missionManager.getMissionTypeIdByName(missionItem["cmdName"])
            createMissionItems[index]["cmdName"] = missionItem["cmdName"]
            createMissionItems[index]["paramValue1"] = missionItem["paramValue1"]
            createMissionItems[index]["paramValue2"] = missionItem["paramValue2"]
            createMissionItems[index]["paramValue3"] = missionItem["paramValue3"]
            createMissionItems[index]["paramValue4"] = missionItem["paramValue4"]
            createMissionItems[index]["paramValue5"] = missionItem["paramValue5"]
            createMissionItems[index]["paramValue6"] = missionItem["paramValue6"]
            createMissionItems[index]["paramValue7"] = missionItem["paramValue7"]

            createListViewId.model.setProperty(index, "cmdName", missionItem["cmdName"])

            console.log("----------------------" + createMissionItems[index]["latitude"])
            console.log("----------------------" + createMissionItems[index]["longitude"])
            console.log("----------------------" + createMissionItems[index]["cmdId"])
            console.log("----------------------" + createMissionItems[index]["cmdName"])
            console.log("----------------------" + createMissionItems[index]["paramValue1"])
            console.log("----------------------" + createMissionItems[index]["paramValue2"])
            console.log("----------------------" + createMissionItems[index]["paramValue3"])
            console.log("----------------------" + createMissionItems[index]["paramValue4"])
            console.log("----------------------" + createMissionItems[index]["paramValue5"])
            console.log("----------------------" + createMissionItems[index]["paramValue6"])
            console.log("----------------------" + createMissionItems[index]["paramValue7"])
        }
    }
}
