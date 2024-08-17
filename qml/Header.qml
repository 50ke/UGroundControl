import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: headerId
    color: "#303133"
    Row{
        spacing: 2
        anchors.verticalCenter: parent.verticalCenter
        leftPadding: 5
        // Logo
        Image {
            height: 28
            width: 28
            source: "qrc:/resources/icons/ugc.png"
        }
        Item{
            width: 20
            height: 28
        }
        // 卫星
        Image {
            height: 28
            width: 28
            source: "qrc:/resources/icons/satellite.svg"
        }
        Text{
            text: "10"
            color: "#FFFFFF"
            font.pointSize: 12
            anchors.verticalCenter: parent.verticalCenter
        }
        Item{
            width: 20
            height: 28
        }
        // 电台
        Image {
            height: 28
            width: 28
            source: "qrc:/resources/icons/radio.svg"
        }
        Text{
            text: "12kb/s"
            color: "#FFFFFF"
            font.pointSize: 12
            anchors.verticalCenter: parent.verticalCenter
        }
        Item{
            width: 20
            height: 28
        }
        // 网络
        Image {
            height: 28
            width: 28
            source: "qrc:/resources/icons/network.svg"
        }
        Text{
            text: "15kb/s"
            color: "#FFFFFF"
            font.pointSize: 12
            anchors.verticalCenter: parent.verticalCenter
        }
        Item{
            width: 20
            height: 28
        }
        // 电量
        Image {
            height: 28
            width: 28
            source: "qrc:/resources/icons/battery.svg"
        }
        Text{
            text: "98%"
            color: "#FFFFFF"
            font.pointSize: 12
            anchors.verticalCenter: parent.verticalCenter
        }
    }
}
