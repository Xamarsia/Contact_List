import QtQuick 2.4
import QtQuick.Controls 2.4

Rectangle {
    id: root
    width: ListView.view.width
    height: 54
    color: '#00000000'

    Text {
        id: label
        anchors.centerIn: parent
        font.pixelSize: 24
        text: section
        color: '#e3e3e3'
    }
}

