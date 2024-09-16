import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import QmlControls 1.0

Window {
    width: 680
    height: 480
    minimumWidth: 400
    minimumHeight: 320
    visible: true
    title: "地面站设置"
    color: "#303133"

    ScrollView {
        anchors.fill: parent
        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
        ScrollBar.vertical.policy: ScrollBar.AlwaysOff
        Column {
            width: parent.width
            height: parent.height
            UGCInputBox{
                oEnabled: false
                oTitleText: "系统设备序列"
                oTipText: "系统设备序列！"
                oPlaceholderText: "-1"
                oText: settingManager.systemId
            }
            UGCInputBox{
                oTitleText: "电台通信串口"
                oTipText: "填写串口名称！"
                oPlaceholderText: "例如：COM1"
                oText: settingManager.serialPort
            }
            UGCInputBox{
                oTitleText: "网络通信服务"
                oTipText: "填写网络服务器地址！"
                oPlaceholderText: "例如：mqtt://127.0.0.1:8080"
                oText: settingManager.networkServer
            }
            UGCInputBox{
                oTitleText: "基础地图服务"
                oTipText: "填写本地路径或在线地址！"
                oPlaceholderText: "例如：http://127.0.0.1:8089/osm"
                oText: settingManager.baseMap
            }
            UGCInputBox{
                oTitleText: "电子航道图层"
                oTipText: "仅支持GeoJson自定义图层！"
                oPlaceholderText: "例如：D://waterway.geojson"
                oText: settingManager.waterwayLayer
            }
            UGCInputBox{
                oTitleText: "航道航标数据"
                oTipText: "填写本地路径或在线地址！"
                oPlaceholderText: "例如：http://127.0.0.1:8089/api"
                oText: settingManager.navigationMarkShipLayer
            }
            UGCInputBox{
                oTitleText: "航道水深数据"
                oTipText: "填写本地路径或在线地址！"
                oPlaceholderText: "例如：http://127.0.0.1:8089/api"
                oText: settingManager.waterwayDepthLayer
            }
            UGCInputBox{
                oTitleText: "航道行船数据"
                oTipText: "填写本地路径或在线地址！"
                oPlaceholderText: "例如：http://127.0.0.1:8089/api"
                oText: settingManager.waterwayAisLayer
            }
            UGCInputBox{
                oTitleText: "航道建筑数据"
                oTipText: "填写本地路径或在线地址！"
                oPlaceholderText: "例如：http://127.0.0.1:8089/api"
                oText: settingManager.waterwayBuildingLayer
            }
        }
    }
}
