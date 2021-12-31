import QtQuick 2.5
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.12

ToolBar
{
    id: root

    property bool showOnlyFavorite: false
    property bool showGrid: false
    signal previousPage()

    signal filterChanged(string filter)

    RowLayout
    {
        anchors.fill: parent

        ToolButton {
            text: qsTr("‹")
            onClicked: root.previousPage()
        }

        TextField
        {
            placeholderText: qsTr("Filter")

            onTextChanged: filterChanged(text)

            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
            Layout.fillWidth: true
        }

        ToolButton {
           text: qsTr("⋮")
           onClicked: optionsMenu.open()
           Layout.alignment: Qt.AlignVCenter | Qt.AlignLeft

           Menu {
               id: optionsMenu
               x: parent.width - width
               transformOrigin: Menu.TopRight

               Action {
                   text: qsTr("All")

                   onTriggered: showOnlyFavorite = false
               }

               Action {
                   text: qsTr("Favorite")

                   onTriggered: showOnlyFavorite = !showOnlyFavorite
               }

               Action
               {
                   text: qsTr("Grid")

                   onTriggered:
                   {
                       showGrid = !showGrid
                       if(showGrid)
                       {
                           text = qsTr("List")
                       }
                       else
                       {
                           text = qsTr("Grid")
                       }
                   }
               }
           }
        }
    }
}
