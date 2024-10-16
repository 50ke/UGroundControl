import QtQuick

Item {
    width: 2 * radius
    height: 2 * radius

    required property double radius
    property double roll: 0
    property double pitch: 0
    readonly property double pixelPerDegree: 1.7

    property double deltaFaceX: 0
    property double deltaFaceY: 0

    onRollChanged: update()
    onPitchChanged: update()

    function update()
    {
        var tempPitch = pitch
        if(tempPitch < -20) tempPitch = -20
        if(tempPitch > 20) tempPitch = 20

        deltaFaceX = (face.width  / 240) * pixelPerDegree * tempPitch * Math.sin(Math.PI * roll / 180.0)
        deltaFaceY = (face.height / 240) * pixelPerDegree * tempPitch * Math.cos(Math.PI * roll / 180.0)
    }

    Image {
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
        cache: false
        smooth: true
        antialiasing: true
        mipmap:true
        source: "qrc:/resources/icons/ai_back.svg"
        rotation: -roll
    }


    Image {
        id: face
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
        cache: false
        smooth: true
        antialiasing: true
        mipmap:true
        source: "qrc:/resources/icons/ai_face.svg"

        transform: [
            Rotation {
                origin.x: 0.5 * face.width
                origin.y: 0.5 * face.height
                axis {
                    x: 0
                    y: 0
                    z: 1
                }
                angle: -roll
            },

            Translate {
                x: deltaFaceX
                y: deltaFaceY
            }
        ]
    }

    Image {
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
        cache: false
        smooth: true
        antialiasing: true
        mipmap:true
        source: "qrc:/resources/icons/ai_ring.svg"
        rotation: -roll
    }

    Image {
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
        cache: false
        smooth: true
        antialiasing: true
        mipmap:true
        source: "qrc:/resources/icons/ai_case.svg"
    }
}


