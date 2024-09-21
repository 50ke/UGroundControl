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
        }
        UGCButton{
            id: vehicleBtnId
            oText: "USV"
            width: parent.width
            oTextFont.pointSize: 10
            display: AbstractButton.TextUnderIcon
            oIconSource: "qrc:/resources/icons/boats.svg"
            onClicked: {
                vehicleListLoaderId.source = (vehicleListLoaderId.source == "") ? "qrc:/src/UI/Component/VehicleList.qml" : ""
            }

            Loader{
                id: vehicleListLoaderId
                anchors.left: parent.right
                anchors.leftMargin: 5
                anchors.top: parent.top
                source: ""
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
