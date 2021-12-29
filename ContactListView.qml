import QtQuick 2.5

ListView
{
    id: root

    signal callClicked(int id)

    anchors.margins: 20
    delegate: ContactListItem
    {
        onBackgroundClicked: root.currentIndex = index

        width: root.width
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
