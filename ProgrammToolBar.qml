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

        ToolButton {
           text: qsTr("⋮")
           onClicked: optionsMenu.open()
           Layout.alignment: Qt.AlignVCenter | Qt.AlignLeft

           Menu {
               id: optionsMenu
               x: parent.width - width
               Action {
                   text: qsTr("Favorite")
                   onTriggered: showOnlyFavorite = !showOnlyFavorite
               }
           }
        }

        Button
        {
            Layout.alignment: Qt.AlignVCenter | Qt.AlignLeft
            text: qsTr("Grid")
            onClicked:
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

        TextField
        {
            placeholderText: qsTr("Filter")
            Layout.alignment: Qt.AlignVCenter | Qt.AlignLeft
            onTextChanged: filterChanged(text)
        }
    }
}
