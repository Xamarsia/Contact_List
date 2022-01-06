import QtQuick 2.5
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

ListView
{
    id: root

    signal pressAndHold(int index)
    signal callClicked(int id)
    signal openPage()

    anchors.leftMargin: 20
    anchors.rightMargin: 20
    anchors.bottomMargin: 5
    anchors.topMargin: 2

    delegate: ContactListItem
    {
        width: root.width;

        onBackgroundClicked: root.currentIndex = index;
        onContactImagePressed: root.openPage()
        onPressAndHold: root.pressAndHold(index) 
    }

    focus: true
    clip: true
    spacing: 5

    section.property: "name"
    section.criteria: ViewSection.FirstCharacter
    section.delegate: SectionDelegate {
        width: root.width
    }
}
