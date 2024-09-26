import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts

import QmlControls 1.0

Rectangle {
    width: parent.width
    height: parent.height
    color: "#303133"
    Column{
        spacing: 1
        width: parent.width
        anchors.horizontalCenter: parent.horizontalCenter
        UGCButton{
            oText: "位置"
            width: parent.width
            oTextFont.pointSize: 10
            display: AbstractButton.TextUnderIcon
            oIconSource: "qrc:/resources/icons/location.svg"
        }
        UGCButton{
            oText: "规划"
            width: parent.width
            oTextFont.pointSize: 10
            display: AbstractButton.TextUnderIcon
            oIconSource: "qrc:/resources/icons/plan.svg"
            onClicked: {
                loaderId.source = (loaderId.source == "qrc:/src/UI/Component/MissionBoxBar.qml") ? "" : "qrc:/src/UI/Component/MissionBoxBar.qml"
            }
        }
        UGCButton{
            oText: "雷达"
            width: parent.width
            oTextFont.pointSize: 10
            display: AbstractButton.TextUnderIcon
            oIconSource: "qrc:/resources/icons/lidar.svg"
            onClicked: {
                createComponent("Lidar")
            }
        }
        UGCButton{
            oText: "视频"
            width: parent.width
            oTextFont.pointSize: 10
            display: AbstractButton.TextUnderIcon
            oIconSource: "qrc:/resources/icons/monitoring.svg"
            onClicked: {
                createComponent("Video")
            }
        }
        UGCButton{
            oText: "配置"
            width: parent.width
            oTextFont.pointSize: 10
            display: AbstractButton.TextUnderIcon
            oIconSource: "qrc:/resources/icons/config.svg"
            onClicked: {
                loaderId.source = (loaderId.source == "qrc:/src/UI/Component/ParameterView.qml") ? "" : "qrc:/src/UI/Component/ParameterView.qml"
            }
        }
        UGCButton{
            id: vehicleBtnId
            oText: "USV"
            width: parent.width
            oTextFont.pointSize: 10
            display: AbstractButton.TextUnderIcon
            oIconSource: "qrc:/resources/icons/boats.svg"
            onClicked: {
                loaderId.source = (loaderId.source == "qrc:/src/UI/Component/VehicleList.qml") ? "" : "qrc:/src/UI/Component/VehicleList.qml"
            }
        }
        UGCButton{
            oText: "设置"
            width: parent.width
            oTextFont.pointSize: 10
            display: AbstractButton.TextUnderIcon
            oIconSource: "qrc:/resources/icons/setting.svg"
            onClicked: {
                createComponent("Setting")
            }
        }
    }

    Loader{
        id: loaderId
        width: 300
        anchors.left: parent.right
        anchors.leftMargin: 5
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        source: ""
    }

    function createComponent(name){
        var component
        if(name === "Lidar"){
            component = Qt.createComponent("qrc:/src/UI/Component/LidarView.qml")
            component.createObject(parent);
        }else if(name === "Video"){
            component = Qt.createComponent("qrc:/src/UI/Component/VideoView.qml")
            component.createObject(parent);
        }else if(name === "Setting"){
            component = Qt.createComponent("qrc:/src/UI/SettingWindow.qml")
            component.createObject(parent);
        }
    }
}
