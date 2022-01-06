import QtQuick.Window 2.12
import QtQuick 2.5
import QtQuick.Dialogs 1.2
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

ApplicationWindow
{
    id: root

    property bool onlyFavorite: false
    property int currentIndex: 0
    property string currentImage: ""

    width: 440
    height: 480
    visible: true
    title: qsTr("Hello World")

    onOnlyFavoriteChanged: contactProxyModel.showOnlyFavorite(onlyFavorite)

    header: ProgrammToolBar{
        onShowOnlyFavoriteChanged: root.onlyFavorite = showOnlyFavorite
        onShowGridChanged: contactView.grid = showGrid

        onPreviousPage:{
            if(stackView.depth > 1){
                stackView.pop()
            }
        }

        onFilterChanged: function(filter){
            contactProxyModel.setFilter(filter)
        }
    }

    Background{
        id: background

        anchors.fill: parent

        StackView {
            id: stackView
            
            anchors.fill: parent
            initialItem: ContactView {
                id:contactView

                onAddPage:{
                    stackView.push(mainView)
                }

                Component {
                    id: mainView
                    ContactPage{}
                }
            }
        }

        RoundButton {
            id:addButton

            text: qsTr("+")
            highlighted: true

            width: 50
            height: 50
            font.pixelSize: 25
            anchors.margins: 25

            anchors.right: parent.right
            anchors.bottom: parent.bottom
            onClicked:{
                contactView.currentContact = -1;
                createContact();
            }

            function createContact() {
                contactForm.fullName.clear();
                contactForm.phoneNumber.clear();
                contactForm.favorite = false;
                contactForm.tag.currentIndex = 0;
                contactForm.email.clear();
                contactForm.birthday.clear();
                contactForm.notes.clear();

                inputDialog.title = qsTr("Add Contact");
                inputDialog.open();
            }

            function editContact(contact, index) {
                currentIndex = index;
                currentImage = contact.image;

                contactForm.fullName.text = contact.fullName;
                contactForm.phoneNumber.text = contact.phoneNumber;
                contactForm.favorite = contact.favorite;
                contactForm.tag.currentIndex = contact.tag;
                contactForm.email.text = contact.email;
                contactForm.birthday.text = contact.birthday;
                contactForm.notes.text = contact.notes;

                inputDialog.title = qsTr("Edit Contact");
                inputDialog.open();
              }

            Dialog {
                id: inputDialog

                x: (parent.width - width) / 2
                y: (parent.height - height) / 2
                parent: Overlay.overlay

                focus: true
                modal: true
                title: "Add Contact"
                standardButtons: Dialog.Ok | Dialog.Cancel
                onOpened: {
                    inputDialog.standardButton(Dialog.Ok).enabled = contactForm.isValid;
                }

                ContactForm{
                    id: contactForm
                    onIsValidChanged:{
                        inputDialog.standardButton(Dialog.Ok).enabled = contactForm.isValid;
                    }
                }

                onAccepted: {
                    if (contactView.currentContact == -1){
                    contactProxyModel.append(contactForm.fullName.text, contactForm.phoneNumber.text, contactForm.favorite,
                                             contactForm.tag.currentIndex, "qrc:/contacts/defaultImage.png", contactForm.email.text, contactForm.birthday.text, contactForm.notes.text)
                    }
                    else{
                        contactProxyModel.setData(currentIndex, contactForm.fullName.text, contactForm.phoneNumber.text, currentImage, contactForm.favorite,
                                                 contactForm.tag.currentIndex, contactForm.email.text, contactForm.birthday.text, contactForm.notes.text)
                    }
                }
            }
        }
    }
}
