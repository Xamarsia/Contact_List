import QtQuick 2.5
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.15

ToolBar
{
    id: root

    property bool showOnlyFavorite: false
    property bool showGrid: false

    signal filterChanged(string filter)

    RowLayout
    {
        anchors.fill: parent
        Button
        {
            Layout.alignment: Qt.AlignVCenter | Qt.AlignLeft
            text: qsTr("Favorite")
            onClicked: showOnlyFavorite = !showOnlyFavorite
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
