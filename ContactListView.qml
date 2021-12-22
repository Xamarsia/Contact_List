import QtQuick 2.5

ListView
{
    id: root

    signal callClicked(int id)

    anchors.margins: 20
    delegate: contactDelegate
    focus: true
    clip: true
    spacing: 5

    section.property: "name"
    section.criteria: ViewSection.FirstCharacter
    section.delegate: SectionDelegate {
        width: root.width
    }

    Component
    {
        id: contactDelegate

        ContactListItem
        {
            text: model.name
            width: root.width
            color: ListView.isCurrentItem? "#00838F" : "#00ACC1"
            imageSource: model.image
            onCallClicked: root.callClicked(model.id)
            onBackgroundClicked: root.currentIndex = index
            favorite: model.favorite
            onFavoriteChanged: model.favorite = favorite
        }
    }
}
