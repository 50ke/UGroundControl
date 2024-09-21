import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import QmlControls 1.0

Rectangle {
    width: 200
    height: 350
    color: "#A8ABB2"
    ListView {
        id: listViewId
        anchors.fill: parent
        focus: true
        clip: true
        spacing: 1
        model: ListModel {
            ListElement {
                systemId: 1
                name: "USV01"
                connected: 0
            }
            ListElement {
                systemId: 2
                name: "USV02"
                connected: 0
            }
            ListElement {
                systemId: 3
                name: "USV03"
                connected: 1
            }
        }
        delegate: Rectangle{
            width: listViewId.width
            height: 40
            radius: 5
            color: "#303133"
            Row{
                spacing: 10
                leftPadding: 5
                anchors.verticalCenter: parent.verticalCenter
                Image {
                    height: 16
                    width: 16
                    anchors.verticalCenter: parent.verticalCenter
                    source: connected ? "qrc:/resources/icons/lock.svg" : "qrc:/resources/icons/unlock.svg"
                }
                UGCText{
                    anchors.verticalCenter: parent.verticalCenter
                    oText: name
                }
                UGCPadding{
                    width: 75
                }
                Image {
                    height: 16
                    width: 16
                    anchors.verticalCenter: parent.verticalCenter
                    source: connected ? "qrc:/resources/icons/unlink.svg" : "qrc:/resources/icons/link.svg"
                }
            }
        }
    }
}






// Rectangle {
//     width: 200
//     height: 350
//     color: "#303133"
//     ScrollView {
//         anchors.fill: parent
//         ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
//         ScrollBar.vertical.policy: ScrollBar.AlwaysOff
//         Column {
//             width: parent.width
//             height: parent.height
//             UGCText{
//                 oText: "qqqqqqqq"
//             }
//             UGCText{
//                 oText: "wwwwwwww"
//             }
//             UGCText{
//                 oText: "eeeeeeee"
//             }
//             UGCText{
//                 oText: "rrrrrrrr"
//             }
//         }
//     }
// }
