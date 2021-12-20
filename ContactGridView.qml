import QtQuick 2.5

GridView
{
    id: root

    signal callClicked(int id)

    delegate: contactDelegate
    cellHeight: 234
    cellWidth: 182

    Component
    {
        id: contactDelegate

        ContactGridItem
        {
            height: root.cellHeight
            width: root.cellWidth
            imageSource: model.image
            text: model.name
            color: GridView.isCurrentItem? "#00838F" : "#00ACC1"
            onCallClicked: root.callClicked(model.id)
            onBackgroundClicked: root.currentIndex = index
            favorite: model.favorite
            onFavoriteChanged: model.favorite = favorite
        }
    }
}
