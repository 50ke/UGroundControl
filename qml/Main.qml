import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import QtWebEngine
import QtWebChannel

import UgcQuick 1.0

Window {
    width: 1000
    height: 640
    visible: true
    visibility: Window.Maximized
    title: "UGroundControl"

    Column{
        anchors.fill: parent
        Header{
            width: parent.width
            height: 40
        }
        Body{
            width: parent.width
            height: parent.height - 40
        }
    }
}
