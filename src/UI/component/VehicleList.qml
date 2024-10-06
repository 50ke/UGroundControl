import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs
import QmlControls 1.0

Rectangle {
    width: parent.width
    height: parent.height
    color: "#303133"
    ListView {
        id: listViewId
        anchors.fill: parent
        anchors.margins: 5
        focus: true
        clip: true
        spacing: 1
        model: ListModel {}
        delegate: Rectangle {
            id: itemId
            width: listViewId.width
            height: 40
            radius: 5
            color: "#606266"
            Row {
                anchors.fill: parent
                spacing: 10
                leftPadding: 5
                anchors.verticalCenter: parent.verticalCenter
                Image {
                    height: 16
                    width: 16
                    anchors.verticalCenter: parent.verticalCenter
                    source: connected ? "qrc:/resources/icons/lock.svg" : "qrc:/resources/icons/unlock.svg"
                }
                UGCText {
                    anchors.verticalCenter: parent.verticalCenter
                    oText: name
                }
                UGCPadding {
                    width: 165
                }
                Image {
                    height: 16
                    width: 16
                    anchors.verticalCenter: parent.verticalCenter
                    source: own ? "qrc:/resources/icons/unlink.svg" : "qrc:/resources/icons/link.svg"
                }
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    selectedSystemId = systemId
                    selectedName = name
                    selectedOwn = own
                    confirmationDialogId.open()
                }
                hoverEnabled: true
                onEntered: { itemId.color = "#909399"}
                onExited: { itemId.color = "#606266"}
            }
        }
    }

    // 操作确认弹窗
    property int selectedSystemId: 0
    property string selectedName: ""
    property bool selectedOwn: false
    MessageDialog {
           id: confirmationDialogId
           text: selectedOwn ? "确认是否断开%1".arg(selectedName) : "确认是否连接%1".arg(selectedName)
           buttons: MessageDialog.Ok | MessageDialog.Cancel
           onAccepted: {
               if(selectedOwn){
                   vehicleManager.disconnectVehicle(selectedSystemId)
               }else{
                   vehicleManager.connectVehicle(selectedSystemId)
               }
           }
           onRejected: {}
    }

    Connections {
        target: vehicleManager
        function onVehiclesChanged(vehicles) {
            listViewId.model.clear()
            for (var i = 0; i < vehicles.length; i++) {
                listViewId.model.append({
                                            "systemId": vehicles[i].systemId,
                                            "name": vehicles[i].name,
                                            "longitude": vehicles[i].longitude,
                                            "latitude": vehicles[i].latitude,
                                            "type": vehicles[i].type,
                                            "connected": vehicles[i].connected,
                                            "own": vehicles[i].own
                                        })
            }
        }
    }

    Component.onCompleted: {
        vehicleManager.getVehicles()
    }
}
