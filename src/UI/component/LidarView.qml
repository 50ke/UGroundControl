import QtCore
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs
import QtLocation
import QtPositioning
import QtQuick.Shapes

Window {
    width: 405
    height: 405
    minimumWidth: 205
    minimumHeight: 205
    visible: true
    title: "雷达感知"
    color: "#303133"

    Rectangle {
        id: root
        width: Math.min(parent.width, parent.height)
        height: Math.min(parent.width, parent.height)
        property int m_Angle: 0
        Timer {
            interval: 25
            running: true
            repeat: true
            onTriggered: {
                root.m_Angle = root.m_Angle + 1
                if (root.m_Angle == 360) {
                    root.m_Angle = 0
                }
            }
        }
        color: "transparent"
        anchors.centerIn: parent
        Rectangle {
            anchors.fill: parent
            anchors.centerIn: parent
            color: "transparent"
            Canvas {
                anchors.fill: parent
                onPaint: {
                    var ctx = getContext("2d")
                    ctx.lineWidth = 2
                    ctx.strokeStyle = "#75F94D"
                    ctx.fillStyle = "#75F94D"
                    ctx.globalAlpha = 1.0
                    // 圆心
                    ctx.beginPath()
                    ctx.arc(width/2, width/2, 2, 0, 2 * Math.PI)
                    ctx.stroke()
                    ctx.fill()
                    ctx.restore()
                    for(var i = 1; i <= 10; i++){
                        ctx.beginPath()
                        ctx.arc(width/2, width/2, (width/20)*i, 0, 2*Math.PI)
                        ctx.stroke()
                        ctx.fillText(i*10, width/2+(width/20)*i, width/2)
                        ctx.fillText(i*10, width/2, width/2-(width/20)*i)
                        ctx.restore()
                    }
                    // x和y轴
                    ctx.beginPath()
                    ctx.lineTo(0, width/2)
                    ctx.lineTo(width, width/2)
                    ctx.stroke()
                    ctx.restore()
                    ctx.beginPath()
                    ctx.lineTo(width/2, 0)
                    ctx.lineTo(width/2, width)
                    ctx.stroke()
                    ctx.restore()
                }
            }
            Canvas {
                anchors.fill: parent
                rotation: root.m_Angle
                onPaint: {
                    var ctx = getContext("2d")
                    var grd = ctx.createRadialGradient(width/2, width/2, 0, width/2, width/2, width/2);
                    // 设置渐变颜色
                    grd.addColorStop(0, 'rgba(117,249,77,1)');
                    grd.addColorStop(1, 'rgba(117,249,77,0.05)');
                    ctx.lineWidth = 2
                    ctx.fillStyle = grd
                    ctx.beginPath();
                    //定义起点
                    ctx.moveTo(width/2,width/2);
                    //以起点为圆心，画一个半径为100的圆弧
                    ctx.arc(width/2,width/2,width/2,0, Math.PI/4);
                    ctx.closePath();
                    ctx.fill();
                    ctx.restore()
                }
            }
        }
    }
}
