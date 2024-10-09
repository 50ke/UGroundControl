import QtQuick

import QmlControls 1.0

Rectangle{

    id: rectId
    width: parent.width
    height: parent.height
    color: "#909399"
    radius: 2
    UGCText{
        id: textId
        anchors.centerIn: parent
    }

    function getColor(type){
        if(type === "success"){
            return "#67C23A"
        }else if(type === "warning"){
            return "#E6A23C"
        }else if(type === "error"){
            return "#F56C6C"
        }else{
            return "#909399"
        }
    }

    function show(content, type){
        textId.oText = content
        rectId.color = getColor(type)
    }
}
