import QtCore
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ComboBox {
    property var oModel: ["AAA", "BBB", "CCC", "DDD", "EEE", "FFF"]

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
    indicator: Canvas {
        id: canvas
        x: control.width - width - control.rightPadding
        y: control.topPadding + (control.availableHeight - height) / 2
        width: 12
        height: 8
        contextType: "2d"
        Connections {
            target: control
            function onPressedChanged() { canvas.requestPaint(); }
        }
        onPaint: {
            context.reset();
            context.moveTo(0, 0);
            context.lineTo(width, 0);
            context.lineTo(width / 2, height);
            context.closePath();
            context.fillStyle = control.pressed ? "#17a81a" : "#21be2b";
            context.fill();
        }
    }
    contentItem: Text {
        leftPadding: 2
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
