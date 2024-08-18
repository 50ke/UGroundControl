import QtCore
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import UgcQuick 1.0

Item {
    property string oTitleText: "title"
    property string oTipText: ""
    property var oSelectList: ["#1", "#2"]
    property int oBoxWidth: 100
    property int oBoxHeight: 30

    height: 40
    width: parent.width
    Row {
        spacing: 10
        leftPadding: 10
        anchors.fill: parent
        anchors.verticalCenter: parent.verticalCenter
        UgcText{
            anchors.verticalCenter: parent.verticalCenter
            oText: oTitleText
            oTextFont.pointSize: 10
        }
        Row{
            spacing: 3
            anchors.verticalCenter: parent.verticalCenter
            UgcComboBox{
                width: oBoxWidth
                height: oBoxHeight
                anchors.verticalCenter: parent.verticalCenter
                oModel: oSelectList
            }
            TextField{
                id: control
                width: 200
                height: 30
                verticalAlignment: Text.AlignVCenter
                anchors.verticalCenter: parent.verticalCenter
                background: Rectangle {
                    radius: 2
                    implicitWidth: 200
                    implicitHeight: 30
                    border.color: control.focus ? "#409eff" : (control.hovered ? "#c0c4cc" : "#dcdfe6")
                }
            }
        }
        Image {
            id: tipImgId
            anchors.verticalCenter: parent.verticalCenter
            source: "qrc:/resources/icons/tip.svg"
            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onEntered: {
                    tooltipText.visible = true
                }
                onExited: {
                    tooltipText.visible = false
                }
            }
            UgcText {
                id: tooltipText
                oText: oTipText
                visible: false
                oTextFont.pointSize: 8
                anchors.left: tipImgId.right
                anchors.leftMargin: 5
                anchors.verticalCenter: parent.verticalCenter
            }
        }
    }
}
