import QtQuick.Window 2.15
import QtQuick 2.5
import QtQuick.Controls 2.4
import QtQuick.Dialogs 1.2

ApplicationWindow
{
    id: root

    property bool onlyFavorite: false
    property bool grid: false
    property var contactView: undefined

    width: 440
    height: 480
    visible: true
    title: qsTr("Hello World")

    onGridChanged: changeContactView(grid)
    onOnlyFavoriteChanged: contactProxyModel.showOnlyFavorite(onlyFavorite)
    Component.onCompleted: changeContactView(false)

    function changeContactView(grid)
    {
        if(contactView != undefined)
        {
            contactView.destroy()
        }
        contactView = grid? gridComponent.createObject(background) : listComponent.createObject(background)
    }

    header: ProgrammToolBar
    {
        onShowOnlyFavoriteChanged: root.onlyFavorite = showOnlyFavorite
        onShowGridChanged: root.grid = showGrid
        onFilterChanged:
            function(filter)
            {
                contactProxyModel.setFilter(filter)
            }
    }

    Background
    {
        id: background
        anchors.fill: parent
    }

    Component
    {
        id: listComponent
        ContactListView
        {
            anchors.fill: parent
            model: contactProxyModel
            onCallClicked:
                function(id)
                {
                    contactProxyModel.call(id)
                }
        }
    }

    Component
    {
        id: gridComponent
        ContactGridView
        {
            anchors.fill: parent
            model: contactProxyModel
            onCallClicked:
                function(id)
                {
                    contactProxyModel.call(id)
                }
        }
    }
}
