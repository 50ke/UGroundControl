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
            PluginParameter {
                name: "mapPath"
                value: "D:/workspace/GisProject/lzhdj"
            }
        }
        anchors.fill: parent
        map.layer.enabled: true
        map.layer.samples: 8
        map.zoomLevel: 16
        map.minimumZoomLevel: 10
        map.maximumZoomLevel: 16
        map.center: QtPositioning.coordinate(centerCoordination.latitude,
                                             centerCoordination.longitude)
        map.copyrightsVisible: false
        map.onZoomLevelChanged: {
            console.log("地图比例尺: " + map.zoomLevel)
        }

        ToolBoxBar {
            id: toolBoxBarId
            anchors.left: parent.left
            anchors.leftMargin: 20
            anchors.top: parent.top
            anchors.topMargin: 20
            height: 400
            width: 50
        }

        // 版权信息
        Rectangle {
            id: copyrightId
            width: copyrightTextId.implicitWidth
            height: 15
            color: "#303133"
            opacity: 0.7
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 2
            UGCText {
                id: copyrightTextId
                anchors.verticalCenter: parent.verticalCenter
                text: "离线地图 | Map © 武汉大学 | Data © 泸州航道局 | Zoom %1 | Center %2,%3".arg(
                          mapViewId.map.zoomLevel).arg(
                          mapViewId.map.center.longitude).arg(
                          mapViewId.map.center.latitude)
            }
        }

        //---------------------地图覆盖物----------------------//
        // 添加无人船到地图
        MapItemView {
            id: vehiclesItemId
            parent: mapViewId.map
            model: ListModel {}
            delegate: MapQuickItem {
                parent: mapViewId.map
                coordinate: QtPositioning.coordinate(latitude, longitude)
                anchorPoint.x: vehicleLocationId.width / 2
                anchorPoint.y: vehicleLocationId.height / 2
                sourceItem: Rectangle {
                    id: vehicleLocationId
                    width: 32
                    height: 32
                    radius: 16
                    color: "transparent"
                    border.width: 3
                    border.color: own ? "#F56C6C" : "#67C23A"
                    Image {
                        anchors.centerIn: parent
                        width: 16
                        height: 16
                        source: "qrc:/resources/icons/usv.svg"
                    }
                    UGCText {
                        id: vehicleNameId
                        anchors.bottom: parent.top
                        oText: name
                        color: own ? "#F56C6C" : "#67C23A"
                    }
                }
            }

            Connections {
                target: vehicleManager
                function onVehiclesChanged(vehicles) {
                    vehiclesItemId.model.clear()
                    for (var i = 0; i < vehicles.length; i++) {
                        vehiclesItemId.model.append({
                                                        "systemId": vehicles[i].systemId,
                                                        "name": vehicles[i].name,
                                                        "longitude": vehicles[i].longitude,
                                                        "latitude": vehicles[i].latitude,
                                                        "type": vehicles[i].type,
                                                        "connected": vehicles[i].connected,
                                                        "own": vehicles[i].own
                                                    })
                    }
                }
            }
        }
        // 添加无人船轨迹到地图
        MapPolyline {
            id: trajectoryItemId
            parent: mapViewId.map
            line.width: 3
            line.color: "red"
            smooth: true
            opacity: 0.8
            Connections {
                target: vehicleManager
                function onVehicleTrajectoryChanged(waypoint) {
                    trajectoryItemId.addCoordinate(waypoint)
                }
            }
        }

        //---------------------任务规划----------------------//
        // 添加航点到地图
        MapItemGroup {
            id: missionItemId
            parent: mapViewId.map
            MapItemView {
                id: missionPointItemId
                parent: mapViewId.map
                model: ListModel {}
                delegate: MapQuickItem {
                    parent: mapViewId.map
                    coordinate: QtPositioning.coordinate(latitude, longitude)
                    anchorPoint.x: missionPointId.width / 2
                    anchorPoint.y: missionPointId.height / 2
                    sourceItem: Rectangle {
                        id: missionPointId
                        width: 24
                        height: 24
                        radius: 12
                        color: "#67C23A"
                        UGCText {
                            anchors.centerIn: parent
                            anchors.margins: 4
                            oText: model.index
                        }
                        MouseArea {
                            anchors.fill: parent
                            onDoubleClicked: {
                                removeWaypoint(model.index)
                            }
                        }
                    }
                    DragHandler {
                        id: waypointDragHandlerId
                        acceptedButtons: Qt.RightButton
                        onGrabChanged: (transition, eventPoint) => {
                            if (transition === 2) {
                                var selectedPoint = mapViewId.map.toCoordinate(eventPoint.position)
                                updateWaypoint(model.index, selectedPoint)
                            }
                        }
                    }
                }
            }

            MapPolyline {
                id: missionRouteItemId
                parent: mapViewId.map
                line.width: 2
                line.color: "#F56C6C"
                smooth: true
                path: []
            }
        }
        // 地图鼠标操作
        TapHandler {
            id: tapHandlerId
            acceptedButtons: Qt.LeftButton | Qt.RightButton
            onSingleTapped: (eventPoint, button) => {
                                if (button === Qt.LeftButton) {
                                    var selectedPoint = mapViewId.map.toCoordinate(tapHandlerId.point.position)
                                    addWaypoint(selectedPoint)
                                }
                            }
            onDoubleTapped: (eventPoint, button) => {
                                if (button === Qt.RightButton) {
                                    clearWaypoint()
                                }
                            }
        }
    }

    property bool enabledPlanView: false
    function addWaypoint(selectedPoint){
        console.log("点击地图获取坐标点经度: %1, 纬度: %2".arg(selectedPoint.longitude).arg(selectedPoint.latitude))
        if(enabledPlanView){
            missionPointItemId.model.append({"latitude": selectedPoint.latitude,"longitude": selectedPoint.longitude})
            missionRouteItemId.addCoordinate(selectedPoint)
            missionManager.addWaypoint(selectedPoint)
        }
    }
    function updateWaypoint(index, selectedPoint){
        missionPointItemId.model.set(index, {"latitude": selectedPoint.latitude,"longitude": selectedPoint.longitude})
        missionRouteItemId.path[index] = selectedPoint
        missionManager.updateWaypoint(index, selectedPoint)
    }
    function removeWaypoint(index){
        missionRouteItemId.path.splice(index, 1)
        missionPointItemId.model.remove(index, 1)
        missionManager.removeWaypoint(index)
    }
    function clearWaypoint(){
        missionPointItemId.model.clear()
        missionRouteItemId.path = []
        missionManager.clearWaypoint()
    }
    Connections{
        target: toolBoxBarId
        function onPlanView(enabled){
            enabledPlanView = enabled
            if(!enabled){
                clearWaypoint()
            }
        }
    }
}
