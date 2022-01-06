import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

GridLayout {

    id: grid

    visible: false
    Layout.margins: 10
    columns: 2
    rowSpacing: 10
    columnSpacing: 40

    function tagToString(num){
        switch(num){
            case 0:
                return "none";
            case 1:
                return "friend";
            case 2:
                return "family";
            case 3:
                return "colleague";
            case 4:
                return "familiar";
        }
    }

    function tagToColor(num){
        switch(num){
            case 0:
                return "cornflowerblue";
            case 1:
                return "lightcoral";
            case 2:
                return "lightskyblue";
            case 3:
                return "mediumturquoise";
            case 4:
                return "lightsalmon";
        }
    }

    Label {
        text: qsTr("Phone number:")
        Layout.leftMargin: 60
    }

    Label {
        text: qsTr(model.phoneNumber)
        font.bold: true
        elide: Text.ElideRight
        Layout.fillWidth: true
    }

    Label {
        text: qsTr("Tag:")
        Layout.leftMargin: 60
    }

    Label {
        text: qsTr(tagToString(model.tag))
        color:  tagToColor(model.tag)
        font.bold: true
        elide: Text.ElideRight
    }

    Label {
        text: qsTr("Email:")
        Layout.leftMargin: 60
    }

    Label {
        text: qsTr(model.email)
        font.bold: true
        elide: Text.ElideRight
        Layout.fillWidth: true
    }

    Label {
        text: qsTr("Notes:")
        Layout.leftMargin: 60
    }

    Label {
        text: qsTr(model.notes)
        font.bold: true
        elide: Text.ElideRight
    } 
}
