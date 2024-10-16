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
        "longitude": 114.347231,
        "latitude": 30.574839
    }
    width: parent.width
    height: parent.height
    MapView {
        id: mapViewId
        map.plugin: Plugin {
            name: "osm"
            PluginParameter { name: "osm.mapping.providersrepository.address"; value: "http://110.187.226.202:8089/osm" }
            PluginParameter { name: "osm.mapping.highdpi_tiles"; value: true }
        }
        anchors.fill: parent
        map.activeMapType: map.supportedMapTypes[3]
        map.center: QtPositioning.coordinate(centerCoordination.latitude, centerCoordination.longitude)
        map.zoomLevel: 16
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
                text: "在线地图 | Map © 武汉大学 | Data © 泸州航道局 | Zoom %1 | Center %2,%3".arg(mapViewId.map.zoomLevel).arg(mapViewId.map.center.longitude).arg(mapViewId.map.center.latitude)
            }
        }
    }
}
