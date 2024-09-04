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
                oTitleText: "电台通信串口"
                oTipText: "填写串口名称！"
                oPlaceholderText: "例如：COM1"
            }
            UGCInputBox{
                oTitleText: "网络通信服务"
                oTipText: "暂时支持mqtt、udp、tcp、websocket！"
                oPlaceholderText: "例如：mqtt://127.0.0.1:2345"
            }
            UGCInputMixBox{
                oBoxWidth: 100
                oBoxHeight: 30
                oTitleText: "基础地图类型"
                oTipText: "离线地图-本地目录，在线地图-在线API"
                oSelectList: ["离线地图","在线地图"]
            }
            UGCImportFileBox{
                oTitleText: "电子航道图层"
                oTipText: "仅支持GeoJson自定义图层"
                oButtonText: "导入"
            }
            UGCInputMixBox{
                oBoxWidth: 100
                oBoxHeight: 30
                oTitleText: "航道航标数据"
                oTipText: "本地数据-本地目录，在线数据-在线API"
                oSelectList: ["本地数据","在线数据"]
            }
            UGCInputMixBox{
                oBoxWidth: 100
                oBoxHeight: 30
                oTitleText: "航道水深数据"
                oTipText: "本地数据-本地目录，在线数据-在线API"
                oSelectList: ["本地数据","在线数据"]
            }
            UGCInputMixBox{
                oBoxWidth: 100
                oBoxHeight: 30
                oTitleText: "航道行船数据"
                oTipText: "本地数据-本地目录，在线数据-在线API"
                oSelectList: ["本地数据","在线数据"]
            }
            UGCInputMixBox{
                oBoxWidth: 100
                oBoxHeight: 30
                oTitleText: "航道建筑数据"
                oTipText: "本地数据-本地目录，在线数据-在线API"
                oSelectList: ["本地数据","在线数据"]
            }
        }
    }
}
