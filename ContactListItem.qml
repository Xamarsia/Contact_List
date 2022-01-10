import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtGraphicalEffects 1.0

Rectangle
{
    id: root

    signal contactImagePressed();
    signal backgroundClicked();
    signal pressAndHold(int index);

    height: 74
    radius: 20
    color: ListView.isCurrentItem ? "#00838F" : "#00ACC1"
    border.color: Qt.darker(color, 1.2)

    ListView.onCurrentItemChanged: {
        if(!ListView.isCurrentItem){
            root.state = "";
        }
        else{
            grid.visible = false;
            root.height = 74;
        }
    }

    MouseArea
    {
        anchors.fill: parent
        onClicked: {
        root.backgroundClicked()
        root.state == 'clicked' ? root.state = "" : root.state = 'clicked';
        }

        onPressAndHold: {
         root.pressAndHold(index);
         baseInfo.contextMenu.popup();
        }
    }

    Column{
        id:column
        spacing: 10
        anchors.fill: parent

        BaseContactInfo{
            id: baseInfo

            width: parent.width
            onImageClicked: {
                root.contactImagePressed()
            }
        }

        FullContactInfo{
        id: grid
        }
    }

    states: [
        State {
            name: "clicked"
            PropertyChanges { target: root; height: 74 + grid.height + column.spacing*2;}
            PropertyChanges { target: grid; visible: true;}
        }
    ]

}

