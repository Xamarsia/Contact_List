import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

GridLayout {
    id: root

    property alias fullName: fullName_
    property alias phoneNumber: phoneNumber_
    property bool favorite: false
    property alias tag: tag_
    property alias email: email_
    property alias birthday: birthday_
    property alias notes: notes_
    property bool isValid: false

    function isValidContact() {
           isValid = fullName_.acceptableInput && phoneNumber_.acceptableInput;
    }

    rows: 4
    columns: 2

    Label {
        text: qsTr("Full Name")
    }

    TextField {
        id: fullName_
        focus: true
        onTextChanged: isValidContact()
    }

    Label {
        text: qsTr("Phone Number")
    }

    TextField {
        id: phoneNumber_

        validator: RegularExpressionValidator{regularExpression: /\+?\d{1,4}?[-.\s]?\(?\d{1,3}?\)?[-.\s]?\d{1,4}[-.\s]?\d{1,4}[-.\s]?\d{1,9}/g}

        onTextChanged: {
            isValidContact();
        }
    }

    Label {
        text: "Favorite"
    }

    Image
    {
        id: favorite
        Layout.maximumWidth: 32
        Layout.maximumHeight: 32
        source: root.favorite ? "qrc:/star/star.png" : "qrc:/star/emptyStar.png"

        MouseArea
        {
            anchors.fill: parent
            onClicked: root.favorite = !root.favorite
        }
    }

    Label {
        text: qsTr("Tag")
    }

    ComboBox {
        id: tag_

        editable: true
        Layout.fillWidth: true
        model: ListModel {
            id:listModel
            ListElement { text: "none" }
            ListElement { text: "Friend" }
            ListElement { text: "Family" }
            ListElement { text: "Colleague" }
            ListElement { text: "Familiar" }
        }
    }

    Label {
        text: qsTr("Email")
    }

    TextField {
        id: email_

        validator : RegularExpressionValidator { regularExpression: /^([\w-]+(?:\.[\w-]+)*)@((?:[\w-]+\.)*\w[\w-]{0,66})\.([a-z]{2,6}(?:\.[a-z]{2})?)$/i}

        onTextChanged: {
            console.log(acceptableInput)
        }
    }

    Label {
        text: qsTr("Birthday")
    }

    TextField {
        id: birthday_
    }

    Label {
        text: qsTr("Notes")
    }

    TextField {
        id: notes_
    }

//    Calendar {
//        minimumDate: new Date(2000, 0, 1)
//        maximumDate: new Date(2022, 0, 1)
//    }
}
