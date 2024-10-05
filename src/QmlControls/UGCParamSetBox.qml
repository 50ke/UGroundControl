import QtCore
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import QmlControls 1.0

Item {
    property bool oEnabled: true
    property string oTitleText: "title"
    property string oText: ""

    height: parent.height
    width: parent.width
    Row {
        spacing: 10
        leftPadding: 5
        anchors.fill: parent
        anchors.verticalCenter: parent.verticalCenter
        UGCText{
            anchors.verticalCenter: parent.verticalCenter
            oText: oTitleText
            oTextFont.pointSize: 10
        }
        TextField{
            id: control
            width: 60
            height: 30
            enabled: oEnabled
            verticalAlignment: Text.AlignVCenter
            anchors.verticalCenter: parent.verticalCenter
            text: oText
            background: Rectangle {
                radius: 2
                implicitWidth: 60
                implicitHeight: 30
                border.color: control.focus ? "#409eff" : (control.hovered ? "#c0c4cc" : "#dcdfe6")
            }
        }
        Image {
            id: downloadId
            height: 16
            width: 16
            anchors.verticalCenter: parent.verticalCenter
            source: "qrc:/resources/icons/download-fill.svg"
            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {
                    vehicleManager.readVehicleParam(oTitleText)
                }
                onEntered: {
                    downloadId.source = "qrc:/resources/icons/download.svg"
                }
                onExited: {
                    downloadId.source = "qrc:/resources/icons/download-fill.svg"
                }
            }
        }
        Image {
            id: uploadId
            height: 16
            width: 16
            anchors.verticalCenter: parent.verticalCenter
            source: "qrc:/resources/icons/upload-fill.svg"
            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {
                    vehicleManager.writeVehicleParam(oTitleText, control.text)
                }
                onEntered: {
                    uploadId.source = "qrc:/resources/icons/upload.svg"
                }
                onExited: {
                    uploadId.source = "qrc:/resources/icons/upload-fill.svg"
                }
            }
        }
    }

    function getText(){
        return control.text
    }
}
