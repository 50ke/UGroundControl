import QtCore
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import QmlControls 1.0

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
        UGCText{
            anchors.verticalCenter: parent.verticalCenter
            oText: oTitleText
            oTextFont.pointSize: 10
        }
        UGCComboBox{
            width: oBoxWidth
            height: oBoxHeight
            anchors.verticalCenter: parent.verticalCenter
            oModel: oSelectList
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
            UGCText {
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
