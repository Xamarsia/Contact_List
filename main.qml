import QtQuick.Window 2.12
import QtQuick 2.5
import QtQuick.Controls 2.4
import QtQuick.Dialogs 1.2

ApplicationWindow
{
    id: root

    property bool onlyFavorite: false

    width: 440
    height: 480
    visible: true
    title: qsTr("Hello World")

    onOnlyFavoriteChanged: contactProxyModel.showOnlyFavorite(onlyFavorite)

    header: ProgrammToolBar{
        onShowOnlyFavoriteChanged: root.onlyFavorite = showOnlyFavorite
        onShowGridChanged: contactView.grid = showGrid

        onPreviousPage:{
            if(stackView.depth >= 1){
                stackView.pop()
            }
        }

        onFilterChanged: function(filter){
            contactProxyModel.setFilter(filter)
        }
    }

    StackView {
        id: stackView
        
        initialItem: background
        anchors.fill: parent
    }

    Background{
        id: background

        anchors.fill: parent
    }

    ContactView{
        id:contactView
        anchors.fill: parent
        onAddPage:{
            stackView.push("qrc:/ContactPage.qml")
            contactPage.visible = true;
        }
    }
}
