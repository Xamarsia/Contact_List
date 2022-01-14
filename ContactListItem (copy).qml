import QtQuick 2.5
import QtQuick.Layouts 1.12
import QtGraphicalEffects 1.0
import QtQuick.Controls 2.12

Rectangle
{
    id: root

    onFavoriteChanged: model.favorite = favorite

    property bool favorite: model.favorite
    property bool expandedContact: false;
    signal backgroundClicked()

    width: 120
    height: 74
    radius: 3
    color: ListView.isCurrentItem? "#00838F" : "#00ACC1"

    border.color: Qt.darker(color, 1.2)

    function show()
    {
        grid.visible = true;
        root.height = 74 + grid.height + column.spacing*2;
        expandedContact = !expandedContact;
    }

    function hide()
    {
        grid.visible = false;
        root.height = 74;
    }

    ListView.onCurrentItemChanged: {
        if(ListView.isCurrentItem){
            show();
            expandedContact = true;
        }
        else{
            hide();
            expandedContact = false;
        }
    }

    MouseArea
    {
        anchors.fill: parent
        onClicked: {
        root.backgroundClicked()
            if(!expandedContact){
                show();
                expandedContact = true;
            }
            else{
                hide();
                expandedContact = false;
            }
        }

    }

    Column{
        id:column
        spacing: 10
        anchors.fill: parent

        RowLayout
        {
            height: 74
            width: parent.width

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

//        Rectangle
//        {

//            width: parent.width
//            height: 64
//            color: root.color
//            color: "red"


            GridLayout {
//                fill:parent
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
//                    Layout.fillWidth: true
                }
            }
        }

//    }
//    states: State {
//        name: "expanded"
//        when: onBackgroundClicked

//        PropertyChanges {

//            target: grid
//            visible: false
//        }
//    }

}
