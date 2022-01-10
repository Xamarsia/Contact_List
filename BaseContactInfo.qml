import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtGraphicalEffects 1.0

RowLayout
{
    id:root

    property bool favorite: model.favorite
    signal imageClicked()
    onFavoriteChanged: model.favorite = favorite

    height: 74

    Image
    {
        id: image

        Layout.alignment: Qt.AlignVCenter | Qt.AlignLeft
        Layout.leftMargin: 12
        Layout.maximumWidth: 56
        Layout.maximumHeight: 56
        source: model.image

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

        MouseArea{
            anchors.fill: parent
            onClicked: root.imageClicked()
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
        text: model.name
        color: "#ffffff"
    }

//    Text
//    {
//        font.pixelSize: 24
//        text: model.id
//        color: "#ffffff"
//    }

    Image
    {
        id: editImage

        Layout.alignment: Qt.AlignVCenter | Qt.AlignRight
        Layout.rightMargin: 16
        Layout.maximumWidth: 24
        Layout.maximumHeight: 26
        source: "qrc:/call/edit.png"

        MouseArea
        {
            anchors.fill: parent
            onClicked: {
                let contact = contactProxyModel.getContact(index);
                contact.image = (model.image)? model.image : "";
                addButton.editContact(contact, index)
            }
        }
    }

    Image
    {
        id: deleteImage

        Layout.alignment: Qt.AlignVCenter | Qt.AlignRight
        Layout.rightMargin: 16
        Layout.maximumWidth: 24
        Layout.maximumHeight: 26
        source: "qrc:/call/delete.png"

        MouseArea
        {
            anchors.fill: parent
            onClicked: contactProxyModel.remove(index)
        }
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
            onClicked: contactProxyModel.call(model.id)
        }
    }
}
