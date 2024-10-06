import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts

import QmlControls 1.0

Window {
    property string name: "xxxx"

    width: 250
    height: 300
    minimumWidth: 250
    minimumHeight: 300
    visible: true
    title: "任务项编辑 - " + name
    color: "#303133"

    ScrollView {
        anchors.fill: parent
        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
        ScrollBar.vertical.policy: ScrollBar.AlwaysOff
        Column {
            width: parent.width
            height: parent.height
            spacing: 10
            anchors.top: parent.top
            anchors.topMargin: 10
            UGCInputComboBox{
                height: 25
                width: 100
                oTitleText: "任务类型"
                oSelectList: ["起锚", "抛锚", "航点", "盘旋"]
            }
            UGCTextInput{
                oEnabled: false
                height: 25
                width: 100
                oTitleText: "Param1"
                oText: "Param1"
            }
            UGCTextInput{
                height: 25
                width: 100
                oTitleText: "Param2"
                oText: "Param#1"
            }
            UGCTextInput{
                height: 25
                width: 100
                oTitleText: "Param3"
                oText: "Param#1"
            }
            UGCTextInput{
                height: 25
                width: 100
                oTitleText: "Param4"
                oText: "Param#1"
            }
            UGCTextInput{
                height: 25
                width: 100
                oTitleText: "Param5"
                oText: "Param#1"
            }
            UGCTextInput{
                height: 25
                width: 100
                oTitleText: "Param6"
                oText: "Param#1"
            }
            UGCTextInput{
                height: 25
                width: 100
                oTitleText: "Param7"
                oText: "Param#1"
            }
        }
    }
}
