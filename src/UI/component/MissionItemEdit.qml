import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts

import QmlControls 1.0

ApplicationWindow {
    property int seq: 0
    property var item: null

    width: 350
    height: 350
    minimumWidth: 350
    minimumHeight: 350
    visible: true
    title: "编辑任务项-" + seq
    color: "#303133"
    onClosing: {
        var data = {
            "cmdName": missionTypeId.getSelectedItem(),
            "paramValue1": parseFloat(paramId1.getText()),
            "paramValue2": parseFloat(paramId2.getText()),
            "paramValue3": parseFloat(paramId3.getText()),
            "paramValue4": parseFloat(paramId4.getText()),
            "paramValue5": parseFloat(paramId5.getText()),
            "paramValue6": parseFloat(paramId6.getText()),
            "paramValue7": parseFloat(paramId7.getText()),
        }
        missionManager.editMissionItem(seq, data)
    }

    ScrollView {
        anchors.fill: parent
        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
        ScrollBar.vertical.policy: ScrollBar.AlwaysOff
        Column {
            width: parent.width
            height: parent.height
            spacing: 10
            anchors.top: parent.top
            anchors.topMargin: 10
            UGCTextInput{
                id: missionSeqId
                oEnabled: false
                height: 25
                width: 100
                oTitleText: "任务编号"
                oText: seq
            }
            UGCInputComboBox{
                id: missionTypeId
                height: 25
                width: 100
                oTitleText: "任务类型"
                oSelectList: []
            }
            UGCTextInput{
                id: paramId1
                height: 25
                width: 100
                oTitleText: "     参数1"
                oText: "Param1"
            }
            UGCTextInput{
                id: paramId2
                height: 25
                width: 100
                oTitleText: "     参数2"
                oText: "Param#1"
            }
            UGCTextInput{
                id: paramId3
                height: 25
                width: 100
                oTitleText: "     参数3"
                oText: "Param#1"
            }
            UGCTextInput{
                id: paramId4
                height: 25
                width: 100
                oTitleText: "     参数4"
                oText: "Param#1"
            }
            UGCTextInput{
                id: paramId5
                height: 25
                width: 100
                oTitleText: "     参数5"
                oText: "Param#1"
            }
            UGCTextInput{
                id: paramId6
                height: 25
                width: 100
                oTitleText: "     参数6"
                oText: "Param#1"
            }
            UGCTextInput{
                id: paramId7
                height: 25
                width: 100
                oTitleText: "     参数7"
                oText: "Param#1"
            }
        }
    }

    Component.onCompleted: {
        console.log("----------------------====" + item["latitude"])
        console.log("----------------------====" + item["longitude"])
        console.log("----------------------====" + item["cmdId"])
        console.log("----------------------====" + item["cmdName"])
        console.log("----------------------====" + item["paramValue1"])
        console.log("----------------------====" + item["paramValue2"])
        console.log("----------------------====" + item["paramValue3"])
        console.log("----------------------====" + item["paramValue4"])
        console.log("----------------------====" + item["paramValue5"])
        console.log("----------------------====" + item["paramValue6"])
        console.log("----------------------====" + item["paramValue7"])

        var missionMetadata= missionManager.loadMissionMetadata()
        var types = []
        var currentIndex = 0

        for (var i = 0; i < missionMetadata.length; i++) {
            types.push(missionMetadata[i].cmdName)
            if(missionMetadata[i].cmdName === item["cmdName"]){
                currentIndex = i
                paramId1.oEnabled = missionMetadata[i].paramEditable1
                paramId1.oText = item["paramValue1"]
                paramId1.oTipText = missionMetadata[i].paramDesc1
                paramId2.oEnabled = missionMetadata[i].paramEditable2
                paramId2.oText = item["paramValue2"]
                paramId2.oTipText = missionMetadata[i].paramDesc2
                paramId3.oEnabled = missionMetadata[i].paramEditable3
                paramId3.oText = item["paramValue3"]
                paramId3.oTipText = missionMetadata[i].paramDesc3
                paramId4.oEnabled = missionMetadata[i].paramEditable4
                paramId4.oText = item["paramValue4"]
                paramId4.oTipText = missionMetadata[i].paramDesc4
                paramId5.oEnabled = missionMetadata[i].paramEditable5
                paramId5.oText = item["paramValue5"]
                paramId5.oTipText = missionMetadata[i].paramDesc5
                paramId6.oEnabled = missionMetadata[i].paramEditable6
                paramId6.oText = item["paramValue6"]
                paramId6.oTipText = missionMetadata[i].paramDesc6
                paramId7.oEnabled = missionMetadata[i].paramEditable7
                paramId7.oText = item["paramValue7"]
                paramId7.oTipText = missionMetadata[i].paramDesc7
            }
        }
        missionTypeId.oSelectList = types
        missionTypeId.setSelectedItem(currentIndex)
    }

    Connections{
        target: missionTypeId
        function onSelectItemChanged(selectItem){
            var missionMetadata= missionManager.loadMissionMetadata()
            for (var i = 0; i < missionMetadata.length; i++) {
                if(selectItem === missionMetadata[i].cmdName){
                    paramId1.oEnabled = missionMetadata[i].paramEditable1
                    paramId1.oText = missionMetadata[i].paramValue1
                    paramId1.oTipText = missionMetadata[i].paramDesc1
                    paramId2.oEnabled = missionMetadata[i].paramEditable2
                    paramId2.oText = missionMetadata[i].paramValue2
                    paramId2.oTipText = missionMetadata[i].paramDesc2
                    paramId3.oEnabled = missionMetadata[i].paramEditable3
                    paramId3.oText = missionMetadata[i].paramValue3
                    paramId3.oTipText = missionMetadata[i].paramDesc3
                    paramId4.oEnabled = missionMetadata[i].paramEditable4
                    paramId4.oText = missionMetadata[i].paramValue4
                    paramId4.oTipText = missionMetadata[i].paramDesc4
                    paramId5.oEnabled = missionMetadata[i].paramEditable5
                    paramId5.oText = missionMetadata[i].paramValue5
                    paramId5.oTipText = missionMetadata[i].paramDesc5
                    paramId6.oEnabled = missionMetadata[i].paramEditable6
                    paramId6.oText = missionMetadata[i].paramValue6
                    paramId6.oTipText = missionMetadata[i].paramDesc6
                    paramId7.oEnabled = missionMetadata[i].paramEditable7
                    paramId7.oText = missionMetadata[i].paramValue7
                    paramId7.oTipText = missionMetadata[i].paramDesc7
                }
            }
        }
    }
}
