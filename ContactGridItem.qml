import QtQuick 2.5
import QtQuick.Layouts 1.12
import QtGraphicalEffects 1.0

Item
{
    id: root

    property alias imageSource: image.source
    property alias text: label.text
    property alias color: rectangle.color
    property bool favorite: false

    signal callClicked()
    signal backgroundClicked()

    Rectangle
    {
        id: rectangle

        color: "#00ACC1"
        anchors.fill: parent
        anchors.margins: 10
        radius: 6
        border.color: Qt.darker(color, 1.2)

        MouseArea
        {
            anchors.fill: parent
            onClicked: root.backgroundClicked()
        }

        ColumnLayout
        {
            anchors.fill: parent

            Image
            {
                id: image

                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                Layout.topMargin: 4
                Layout.maximumWidth: 128
                Layout.maximumHeight: 128

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

            Text
            {
                id: label

                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                Layout.topMargin: 4
                font.pixelSize: 16

                color: "#ffffff"
            }

            RowLayout
            {
                Layout.bottomMargin: 16
                Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
                Image
                {
                    id: star
                    Layout.alignment: Qt.AlignVCenter | Qt.AlignRight
                    Layout.rightMargin: 8
                    Layout.maximumWidth: 32
                    Layout.maximumHeight: 32

                    source: root.favorite ? "qrc:/star/star.png" : "qrc:/star/emptyStar.png"

                    MouseArea
                    {
                        anchors.fill: parent
                        onClicked: root.favorite = !root.favorite
                    }
                }

                Image
                {
                    Layout.alignment: Qt.AlignVCenter | Qt.AlignLeft
                    Layout.leftMargin: 8
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


    }
}


