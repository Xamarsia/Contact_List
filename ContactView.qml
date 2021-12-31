import QtQuick 2.0
import QtQuick.Layouts 1.12
import QtGraphicalEffects 1.0

Item {
    id: root

    property bool grid: false
    property var contactView: undefined

    signal addPage()

    onGridChanged: changeContactView(grid)
    Component.onCompleted: changeContactView(false)

    function changeContactView(grid)
    {
        if(contactView != undefined)
        {
            contactView.destroy()
        }
        contactView = grid ? gridComponent.createObject(root) : listComponent.createObject(root)
    }

    Component
    {
        id: listComponent

        ContactListView
        {
            id:contactList
            anchors.fill: parent
            model: contactProxyModel

            onOpenPage: addPage();
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
                function(id){
                    contactProxyModel.call(id)
                }
        }
    }
}
