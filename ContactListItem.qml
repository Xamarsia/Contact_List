import QtQuick 2.5
import QtQuick.Layouts 1.15
import QtGraphicalEffects 1.0

Rectangle
{
    id: root

    property alias text: label.text
    property alias fontColor: label.color
    property alias imageSource: image.source
    property bool favorite: false

    signal callClicked()
    signal backgroundClicked()

    width: 120
    height: 64
    radius: 3
    color: "#ffffff"
    border.color: Qt.darker(color, 1.2)

    MouseArea
    {
        anchors.fill: parent
        onClicked: root.backgroundClicked()
    }

    RowLayout
    {
        anchors.fill: parent

        Image
        {
            id: image
            Layout.alignment: Qt.AlignVCenter | Qt.AlignLeft
            Layout.leftMargin: 4
            Layout.maximumWidth: 56
            Layout.maximumHeight: 56

            fillMode: Image.PreserveAspectCrop
            layer.enabled: true
            layer.effect: OpacityMask
            {
                maskSource: mask
            }

            Rectangle
            {
                id: mask
                anchors.fill: parent
                radius: Math.max(width, height)
                visible: false
            }
        }

        Image
        {
            id: star
            Layout.alignment: Qt.AlignVCenter | Qt.AlignLeft
            Layout.maximumWidth: 32
            Layout.maximumHeight: 32
            source: root.favorite ? "qrc:/star/star.png" : "qrc:/star/emptyStar.png"

            MouseArea
            {
                anchors.fill: parent
                onClicked: root.favorite = !root.favorite
            }
        }

        Text
        {
            id: label
            Layout.fillWidth: true
            font.pixelSize: 24
            color: "#ffffff"
        }

        Image
        {
            id: callImage
            Layout.alignment: Qt.AlignVCenter | Qt.AlignRight
            Layout.rightMargin: 16
            Layout.maximumWidth: 32
            Layout.maximumHeight: 32
            source: "qrc:/call/icons8-call-96.png"

            MouseArea
            {
                anchors.fill: parent
                onClicked: root.callClicked()
            }
        }

    }

}
