import QtCore
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

RoundButton {
    property string oText: "Default"
    property string oIconSource
    property font oTextFont: ({family: "Helvetica", pointSize: 12, weight: Font.DemiBold})
    property color oNormalTextColor: "#FFFFFF"
    property color oPressedTextColor: "#FFFFFF"
    property color oHoveredTextColor: "#FFFFFF"
    property color oNormalBackgroundColor: "#303133"
    property color oPressedBackgroundColor: "#909399"
    property color oHoveredBackgroundColor: "#606266"
    property color oNormalBorderColor: "#303133"
    property color oPressedBorderColor: "#909399"
    property color oHoveredBorderColor: "#606266"
    id: control
    topPadding: 8
    bottomPadding: 8
    leftPadding: 10
    rightPadding: 10
    palette.buttonText: control.pressed ? control.oPressedTextColor : (control.hovered ? control.oHoveredTextColor : control.oNormalTextColor)
    font.family: oTextFont.family
    font.pixelSize: oTextFont.pixelSize
    font.weight: oTextFont.weight
    text: oText
    icon.source: oIconSource
    icon.color: control.pressed ? control.oPressedTextColor : (control.hovered ? control.oHoveredTextColor : control.oNormalTextColor)
    background: Rectangle {
        radius: 2
        implicitWidth: {
            if (control.display == AbstractButton.IconOnly){
                return 40
            } else if (control.display == AbstractButton.TextOnly){
                return 100
            } else if (control.display == AbstractButton.TextBesideIcon){
                return 100
            } else if (control.display == AbstractButton.TextUnderIcon){
                return 40
            } else {
                return 100
            }
        }
        implicitHeight: {
            if (control.display == AbstractButton.IconOnly){
                return 40
            } else if (control.display == AbstractButton.TextOnly){
                return 40
            } else if (control.display == AbstractButton.TextBesideIcon){
                return 40
            } else if (control.display == AbstractButton.TextUnderIcon){
                return 60
            } else {
                return 40
            }
        }
        border.width: 1
        border.color: control.pressed ? control.oPressedBorderColor : (control.hovered ? control.oHoveredBorderColor : control.oNormalBorderColor)
        color: control.pressed ? control.oPressedBackgroundColor : (control.hovered ? control.oHoveredBackgroundColor : control.oNormalBackgroundColor)
    }
}
