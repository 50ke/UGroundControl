import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts

import QmlControls 1.0

Window {
    property int seq: 0
    property real latitude: 1.1
    property real longitude: 0.0

    width: 350
    height: 350
    minimumWidth: 350
    minimumHeight: 350
    visible: true
    title: "编辑任务项-" + seq
    color: "#303133"

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
        var missionMetadata= missionManager.loadMissionMetadata()
        var types = []
        for (var i = 0; i < missionMetadata.length; i++) {
            types.push(missionMetadata[i].cmdName)
        }
        if(missionMetadata.length > 0){
            missionTypeId.oSelectList = types
            paramId1.oEnabled = missionMetadata[0].paramEditable1
            paramId1.oText = missionMetadata[0].paramValue1
            paramId1.oTipText = missionMetadata[0].paramDesc1
            paramId2.oEnabled = missionMetadata[0].paramEditable2
            paramId2.oText = missionMetadata[0].paramValue2
            paramId2.oTipText = missionMetadata[0].paramDesc2
            paramId3.oEnabled = missionMetadata[0].paramEditable3
            paramId3.oText = missionMetadata[0].paramValue3
            paramId3.oTipText = missionMetadata[0].paramDesc3
            paramId4.oEnabled = missionMetadata[0].paramEditable4
            paramId4.oText = missionMetadata[0].paramValue4
            paramId4.oTipText = missionMetadata[0].paramDesc4
            paramId5.oEnabled = missionMetadata[0].paramEditable5
            paramId5.oText = missionMetadata[0].paramValue5
            paramId5.oTipText = missionMetadata[0].paramDesc5
            paramId6.oEnabled = missionMetadata[0].paramEditable6
            paramId6.oText = missionMetadata[0].paramValue6
            paramId6.oTipText = missionMetadata[0].paramDesc6
            paramId7.oEnabled = missionMetadata[0].paramEditable7
            paramId7.oText = missionMetadata[0].paramValue7
            paramId7.oTipText = missionMetadata[0].paramDesc7
        }
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
