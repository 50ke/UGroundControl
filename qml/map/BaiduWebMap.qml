import QtCore
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs
import QtWebEngine
import QtWebChannel

Item {
    width: parent.width
    height: parent.height
    WebEngineView {
        anchors.fill: parent
        url: "qrc:/resources/map.html"
    }
}
