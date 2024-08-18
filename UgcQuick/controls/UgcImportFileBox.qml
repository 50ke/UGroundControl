import QtCore
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs

import UgcQuick 1.0

Item {
    property string oTitleText: "title"
    property string oTipText: ""
    property string oButtonText: ""


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
        UgcText{
            id: fileId
            oText: ""
            anchors.verticalCenter: parent.verticalCenter
            oTextFont.pointSize: 8
        }
        UgcButton{
            width: 60
            height: 20
            topPadding: 2
            bottomPadding: 2
            leftPadding: 3
            rightPadding: 3
            oNormalTextColor: "#ffffff"
            oPressedTextColor: "#ffffff"
            oHoveredTextColor: "#ffffff"
            oNormalBackgroundColor: "#606266"
            oPressedBackgroundColor: "#73767a"
            oHoveredBackgroundColor: "#b1b3b8"
            oNormalBorderColor: "#606266"
            oPressedBorderColor: "#73767a"
            oHoveredBorderColor: "#b1b3b8"
            oText: oButtonText
            oTextFont.pointSize: 8
            display: AbstractButton.TextBesideIcon
            anchors.verticalCenter: parent.verticalCenter
            oIconSource: "qrc:/resources/icons/import.svg"
            onClicked: {
                importFileDialogId.open()
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

    FileDialog {
        id: importFileDialogId
        title: "选择文件"
        nameFilters: ["文本文件 (*.json)", "所有文件 (*)"]
        onAccepted: {
            console.log("导入文件路径：" + importFileDialogId.currentFile)
            fileId.oText = importFileDialogId.currentFile
        }
        onRejected: {
            console.log("对话框被取消")
        }
    }
}
