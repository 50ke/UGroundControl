import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts

import "./map"
import "./component"

Rectangle{
    width: parent.width
    height: parent.height
    NativeMap{
        anchors.fill: parent
        ToolBox{
            anchors.left: parent.left
            anchors.leftMargin: 20
            anchors.top: parent.top
            anchors.topMargin: 20
            height: 400
            width: 50
        }
    }
    // BaiduWebMap{
    //     anchors.fill: parent
    //     Button{
    //         text: "press"
    //     }
    // }
}
