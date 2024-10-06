import QtCore
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import QmlControls 1.0

Item {
    property bool oEnabled: true
    property string oTitleText: "title"
    property string oTipText: ""
    property string oPlaceholderText: ""
    property string oText: ""

    height: parent.height
    width: parent.width
    Row {
        spacing: 10
        leftPadding: 10
        width: parent.width
        height: parent.height
        anchors.verticalCenter: parent.verticalCenter
        UGCText{
            anchors.verticalCenter: parent.verticalCenter
            oText: oTitleText
            oTextFont.pointSize: 10
        }
        TextField{
            id: control
            width: parent.width
            height: parent.height
            enabled: oEnabled
            verticalAlignment: Text.AlignVCenter
            anchors.verticalCenter: parent.verticalCenter
            text: oText
            placeholderText: oPlaceholderText
            background: Rectangle {
                radius: 2
                implicitWidth: parent.width
                implicitHeight: parent.height
                border.color: control.focus ? "#409eff" : (control.hovered ? "#c0c4cc" : "#dcdfe6")
            }
        }
        UGCText {
            oText: oTipText
            oTextFont.pointSize: 8
            anchors.verticalCenter: parent.verticalCenter
        }
    }

    function getText(){
        return control.text
    }
}
