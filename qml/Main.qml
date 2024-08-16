import QtQuick
import QtWebEngine
import UgcQuick 1.0

import QtWebChannel

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    QtObject {
        id: myObject

        // 注册方法 1
        // 使用注册方法 2 时不需要此行代码
        WebChannel.id: "foo" //这个 id 可以在 html 中使用
        property string hello: "world"
    }

    WebEngineView {
        anchors.fill: parent
        // url: "https://www.baidu.com"
        url: "qrc:/resources/map.html"
        // webChannel: WebChannel{
        //     id: webChannel
        //     registeredObjects: [myObject]
        //     // Component.onCompleted: {
        //     //     webChannel.registerObject("foo", myObject)
        //     // }
        // }
    }
    // UgcText{
    //     text: "11111"
    // }
}
