import QtCore
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs
import QtLocation
import QtPositioning

import QmlControls 1.0

Item {
    property var centerCoordination: {
        "longitude": 105.458048,
        "latitude": 28.873177
    }
    width: parent.width
    height: parent.height
    MapView {
        id: mapViewId
        map.plugin: Plugin {
            name: "ugc_map"
            PluginParameter { name: "mapPath"; value: "D:/workspace/GisProject/lzhdj" }
        }
        anchors.fill: parent
        map.layer.enabled: true
        map.layer.samples: 8
        map.zoomLevel: 16
        map.minimumZoomLevel: 10
        map.maximumZoomLevel: 16
        map.center: QtPositioning.coordinate(centerCoordination.latitude, centerCoordination.longitude)
        map.copyrightsVisible: false
        map.onZoomLevelChanged: {
            console.log("地图比例尺: " + map.zoomLevel)
        }

        ToolBoxBar{
            anchors.left: parent.left
            anchors.leftMargin: 20
            anchors.top: parent.top
            anchors.topMargin: 20
            height: 400
            width: 50
        }

        // 版权信息
        Rectangle{
            id: copyrightId
            width: copyrightTextId.implicitWidth
            height: 15
            color: "#303133"
            opacity: 0.7
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 2
            UGCText{
                id: copyrightTextId
                anchors.verticalCenter: parent.verticalCenter
                text: "离线地图 | Map © 武汉大学 | Data © 泸州航道局 | Zoom %1 | Center %2,%3".arg(mapViewId.map.zoomLevel).arg(mapViewId.map.center.longitude).arg(mapViewId.map.center.latitude)
            }
        }

        //---------------------地图相关----------------------//
        // 载具定位
        MapQuickItem {
            id: vehicleLocationItemId
            parent: mapViewId.map
            anchorPoint.x: vehicleLocationIconId.width / 2
            anchorPoint.y: vehicleLocationIconId.height / 2
            sourceItem: Rectangle{
                width: 32
                height: 32
                radius: 16
                color: "transparent"
                border.width: 1
                border.color: "#F56C6C"
                Image {
                    id: vehicleLocationIconId
                    anchors.centerIn: parent
                    width: 16
                    height: 16
                    source: "qrc:/resources/icons/usv.svg"
                }
            }
        }
        Component.onCompleted: {
            vehicleLocationItemId.coordinate = QtPositioning.coordinate(centerCoordination.latitude, centerCoordination.longitude)
        }
    }
}
