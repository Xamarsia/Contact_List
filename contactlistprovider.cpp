#include "contactlistprovider.h"
#include <QMessageBox>
#include <stdlib.h>

ContactListProvider::ContactListProvider()
{
    QList<QString> firstNames = {"Oliver", "Henry", "Evelyn", "Charlotte", "Liam", "Emma", "Ava",
                                 "Amelia", "Lucas", "Isabella", "Aria", "Leo", "Gianna", "Ella" };

    QList<QString> lastNames = {"Smith", "Johnson", "Williams", "Brown", "Miller", "Davis", "Rodriguez",
                                "Adams", "Roberts", "Carter", "Baker", "Rivera", "Torres", "Walker"};


    QList<QString> contactsImageURL = {"qrc:/contacts/beard.png", "qrc:/contacts/customer-service(1).png",
                                       "qrc:/contacts/curly-hair-man.png", "qrc:/contacts/customer-service.png",
                                       "qrc:/contacts/man(1).png", "qrc:/contacts/happy.png",
                                       "qrc:/contacts/help-desk.png", "qrc:/contacts/man(2).png",
                                       "qrc:/contacts/man(3).png", "qrc:/contacts/man(4).png",
                                       "qrc:/contacts/man(5).png", "qrc:/contacts/man(6).png",
                                       "qrc:/contacts/man(7).png", "qrc:/contacts/man(8).png",
                                       "qrc:/contacts/man(9).png", "qrc:/contacts/man.png",
                                       "qrc:/contacts/man11.png", "qrc:/contacts/man12.png",
                                       "qrc:/contacts/woman(1).png", "qrc:/contacts/woman.png"};
    for(int i = 0; i < 100; i++)
    {
        int firstNameIndex = rand() % 14;
        int lastNameIndex = rand() % 14;
        int imageIndex = rand() % 19;
        m_contactsList.append(Contact{i, firstNames[firstNameIndex] + " " + lastNames[lastNameIndex], contactsImageURL[imageIndex]});
    }
}

const QList<ContactListProvider::Contact>& ContactListProvider::getContactsList()
{
    return instance().m_contactsList;
}


void ContactListProvider::call(int id)
{
    auto iter = std::find_if(getContactsList().begin(), getContactsList().end(),
    [id] (const Contact &contact)
    {
        return contact.id == id;
    });


    QMessageBox msgBox;
    msgBox.setText("Call");
    msgBox.setInformativeText("You pressed on call to id: " + QString::number(iter->id) +
                              " name: " + iter->name);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Save);
    msgBox.exec();
}

ContactListProvider& ContactListProvider::instance()
{
    static ContactListProvider contactListProvider;
    return contactListProvider;
}
