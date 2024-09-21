import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs
import QmlControls 1.0

Rectangle {
    width: 200
    height: 350
    color: "#A8ABB2"
    ListView {
        id: listViewId
        anchors.fill: parent
        focus: true
        clip: true
        spacing: 1
        model: ListModel {}
        delegate: Rectangle {
            width: listViewId.width
            height: 40
            radius: 5
            color: "#303133"
            Row {
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
                    width: 75
                }
                Image {
                    height: 16
                    width: 16
                    anchors.verticalCenter: parent.verticalCenter
                    source: owner ? "qrc:/resources/icons/unlink.svg" : "qrc:/resources/icons/link.svg"
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            selectedSystemId = systemId
                            selectedName = name
                            selectedOwner = owner
                            confirmationDialogId.open()

                        }
                    }
                }
            }
        }
    }

    // 操作确认弹窗
    property int selectedSystemId: 0
    property string selectedName: ""
    property bool selectedOwner: false
    MessageDialog {
           id: confirmationDialogId
           text: selectedOwner ? "确认是否断开%1".arg(selectedName) : "确认是否连接%1".arg(selectedName)
           buttons: MessageDialog.Ok | MessageDialog.Cancel
           onAccepted: {
               if(selectedOwner){
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
                                            "owner": vehicles[i].owner
                                        })
            }
        }
    }

    Component.onCompleted: {
        vehicleManager.getVehicles()
    }
}
