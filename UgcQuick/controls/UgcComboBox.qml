import QtCore
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ComboBox {
    property var oModel: ["#1", "#2"]

    id: control
    height: 30
    width: 100
    model: oModel
    delegate: ItemDelegate {
        id: delegate
        required property var model
        required property int index
        width: control.width
        height: control.height
        contentItem: Text {
            text: delegate.model[control.textRole]
            color: "#606266"
            font: control.font
            elide: Text.ElideRight
            verticalAlignment: Text.AlignVCenter
        }
        highlighted: control.highlightedIndex === index
    }
    indicator: Image {
        id: name
        x: control.width - width - control.rightPadding
        y: control.topPadding + (control.availableHeight - height) / 2
        source: control.down ? "qrc:/resources/icons/angle-up.svg" : "qrc:/resources/icons/angle-down.svg"
    }
    contentItem: Text {
        leftPadding: 10
        rightPadding: control.indicator.width + control.spacing
        text: control.displayText
        font: control.font
        color: control.pressed ? "#606266" : "#606266"
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }
    background: Rectangle {
        implicitWidth: 120
        implicitHeight: 40
        border.color: control.focus ? "#409eff" : (control.hovered ? "#c0c4cc" : "#dcdfe6")
        radius: 2
    }

    popup: Popup {
        y: control.height - 1
        width: control.width
        height: control.height * 3
        padding: 1
        contentItem: ListView {
            clip: true
            implicitHeight: contentHeight
            model: control.popup.visible ? control.delegateModel : null
            currentIndex: control.highlightedIndex
            ScrollIndicator.vertical: ScrollIndicator{}
        }
        background: Rectangle {
            border.color: "#c0c4cc"
            radius: 2
        }
    }
}
