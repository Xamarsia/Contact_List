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

    Label {
        text: qsTr("Address:")
        Layout.leftMargin: 60
    }

    Label {
        text: qsTr("address")
        font.bold: true
        elide: Text.ElideRight
        Layout.fillWidth: true
    }

    Label {
        text: qsTr("City:")
        Layout.leftMargin: 60
    }

    Label {
        text: qsTr("city")
        font.bold: true
        elide: Text.ElideRight
        Layout.fillWidth: true
    }

    Label {
        text: qsTr("Number:")
        Layout.leftMargin: 60
    }

    Label {
        text: qsTr("number")
        font.bold: true
        elide: Text.ElideRight
    }
}
