import QtQuick 2.5

ListView
{
    id: root

    signal callClicked(int id)
    signal openPage()

    anchors.margins: 20
    delegate: ContactListItem
    {
        onBackgroundClicked: root.currentIndex = index;
        onContactImagePressed: root.openPage()

        width: root.width;
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
