import QtCore
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import QmlControls 1.0

Item {
    property string oTitleText: "title"
    property var oSelectList: ["#1", "#2"]

    signal selectItemChanged(string item)

    height: parent.height
    width: parent.width
    Row {
        spacing: 10
        leftPadding: 10
        height: parent.height
        width: parent.width
        anchors.verticalCenter: parent.verticalCenter
        UGCText{
            anchors.verticalCenter: parent.verticalCenter
            oText: oTitleText
            oTextFont.pointSize: 10
        }
        UGCComboBox{
            id: comId
            height: parent.height
            width: parent.width
            anchors.verticalCenter: parent.verticalCenter
            oModel: oSelectList
            onActivated: {
                selectItemChanged(comId.displayText)
            }
        }
    }
}
