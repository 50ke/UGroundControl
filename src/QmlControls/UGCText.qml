import QtQuick 2.15

Text{
    property font oTextFont: ({family: "Helvetica", pointSize: 12, weight: Font.DemiBold})
    property string oText: "Default"

    color: "#FFFFFF"
    font.family: oTextFont.family
    font.pixelSize: oTextFont.pixelSize
    font.weight: oTextFont.weight
    text: oText
}
