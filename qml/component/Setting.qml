import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import UgcQuick 1.0

Window {
    width: 560
    height: 400
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
            UgcInputBox{
                oTitleText: "电台通信串口"
                oTipText: "填写串口名称！"
                oPlaceholderText: "例如：COM1"
            }
            UgcInputBox{
                oTitleText: "网络通信服务"
                oTipText: "暂时支持mqtt、udp、tcp、websocket！"
                oPlaceholderText: "例如：mqtt://127.0.0.1:2345"
            }
            UgcInputBox{
                oTitleText: "状态维护服务"
                oTipText: "注册、注销等服务"
                oPlaceholderText: "例如：https://127.0.0.1:2346"
            }
            UgcInputComboBox{
                oBoxWidth: 200
                oBoxHeight: 30
                oTitleText: "基础地图类型"
                oTipText: "基础地图服务"
                oSelectList: ["原生地图（离线）","百度地图（在线）"]
            }
            UgcImportFileBox{
                oTitleText: "电子航道图层"
                oTipText: "仅支持GeoJson自定义图层"
                oButtonText: "导入"
            }
            UgcInputBox{
                oTitleText: "航道航标数据"
                oTipText: "航道航标数据获取Api接口，数据返回需要满足规定格式"
                oPlaceholderText: "例如：https://127.0.0.1:2346/mark-boats"
            }
            UgcInputBox{
                oTitleText: "航道水深数据"
                oTipText: "航道水深数据获取Api接口，数据返回需要满足规定格式"
                oPlaceholderText: "例如：https://127.0.0.1:2346/water-depth"
            }
            UgcInputBox{
                oTitleText: "航道行船数据"
                oTipText: "航道AIS数据获取Api接口，数据返回需要满足规定格式"
                oPlaceholderText: "例如：https://127.0.0.1:2346/ais"
            }
            UgcInputBox{
                oTitleText: "航道建筑数据"
                oTipText: "航道建筑数据获取Api接口，数据返回需要满足规定格式"
                oPlaceholderText: "例如：https://127.0.0.1:2346/building"
            }
        }
    }
}
