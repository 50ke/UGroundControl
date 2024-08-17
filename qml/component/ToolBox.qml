import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts

import UgcQuick 1.0

Rectangle {
    width: parent.width
    height: parent.height
    color: "#303133"
    Column{
        spacing: 1
        width: parent.width
        anchors.horizontalCenter: parent.horizontalCenter
        UgcButton{
            oText: "位置"
            width: parent.width
            oTextFont.pointSize: 10
            display: AbstractButton.TextUnderIcon
            oIconSource: "qrc:/resources/icons/location.svg"
        }
        UgcButton{
            oText: "规划"
            width: parent.width
            oTextFont.pointSize: 10
            display: AbstractButton.TextUnderIcon
            oIconSource: "qrc:/resources/icons/plan.svg"
        }
        UgcButton{
            oText: "雷达"
            width: parent.width
            oTextFont.pointSize: 10
            display: AbstractButton.TextUnderIcon
            oIconSource: "qrc:/resources/icons/lidar.svg"
            onClicked: {
                var component = Qt.createComponent("Lidar.qml")
                if (component.status === Component.Ready) {
                    var object = component.createObject(parent)
                }
            }
        }
        UgcButton{
            oText: "视频"
            width: parent.width
            oTextFont.pointSize: 10
            display: AbstractButton.TextUnderIcon
            oIconSource: "qrc:/resources/icons/monitoring.svg"
        }
        UgcButton{
            oText: "配置"
            width: parent.width
            oTextFont.pointSize: 10
            display: AbstractButton.TextUnderIcon
            oIconSource: "qrc:/resources/icons/config.svg"
        }
        UgcButton{
            oText: "USV"
            width: parent.width
            oTextFont.pointSize: 10
            display: AbstractButton.TextUnderIcon
            oIconSource: "qrc:/resources/icons/boats.svg"
        }
        UgcButton{
            oText: "设置"
            width: parent.width
            oTextFont.pointSize: 10
            display: AbstractButton.TextUnderIcon
            oIconSource: "qrc:/resources/icons/setting.svg"
        }
    }
}
