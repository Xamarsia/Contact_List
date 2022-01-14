#include "contactlistprovider.h"
#include <QMessageBox>
#include <stdlib.h>
#include <QDebug>



ContactListProvider::ContactListProvider()
{
    m_contactsList.append(Contact{"Oliver Smith", "0","qrc:/contacts/beard.png", 0, Tag::NONE, "",QDate(2012, 7, 6)});
    m_contactsList.append(Contact{"Henry Johnson", "1","qrc:/contacts/customer-service(1).png", 0, Tag::NONE, "",QDate(2012, 7, 6)});
    m_contactsList.append(Contact{"Evelyn Williams", "2","qrc:/contacts/curly-hair-man.png", 0, Tag::NONE, "",QDate(2012, 7, 6)});
    m_contactsList.append(Contact{"Charlotte Brown", "3","qrc:/contacts/customer-service.png", 0, Tag::NONE, "",QDate(2012, 7, 6)});
    m_contactsList.append(Contact{"Liam Miller", "4","qrc:/contacts/man(1).png", 0, Tag::NONE, "",QDate(2012, 7, 6)});
    m_contactsList.append(Contact{"Emma Davis", "5","qrc:/contacts/happy.png", 0, Tag::NONE, "",QDate(2012, 7, 6)});
    m_contactsList.append(Contact{"Ava Rodriguez", "6","qrc:/contacts/help-desk.png", 0, Tag::NONE, "",QDate(2012, 7, 6)});
    m_contactsList.append(Contact{"Amelia Adams", "7","qrc:/contacts/man(2).png", 0, Tag::NONE, "",QDate(2012, 7, 6)});
    m_contactsList.append(Contact{"Lucas Roberts", "8","qrc:/contacts/man(3).png", 0, Tag::NONE, "",QDate(2012, 7, 6)});
    m_contactsList.append(Contact{"Isabella Carter", "9","qrc:/contacts/man(4).png", 0, Tag::NONE, "",QDate(2012, 7, 6)});
    m_contactsList.append(Contact{"Aria Baker", "10","qrc:/contacts/man(5).png", 0, Tag::NONE, "",QDate(2012, 7, 6)});
    m_contactsList.append(Contact{"Leo Rivera", "11","qrc:/contacts/man(6).png", 0, Tag::NONE, "",QDate(2012, 7, 6)});
    m_contactsList.append(Contact{"Gianna Torres", "12","qrc:/contacts/man(7).png", 0, Tag::NONE, "",QDate(2012, 7, 6)});
    m_contactsList.append(Contact{"Ella Walker", "13","qrc:/contacts/man(8).png", 0, Tag::NONE, "",QDate(2012, 7, 6)});
}


QList<Contact>& ContactListProvider::getContactsList()
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
    msgBox.setInformativeText("You pressed on call to phone number: " + iter->phoneNumber +
                              " name: " + iter->fullName);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Save);
    msgBox.exec();
}

ContactListProvider& ContactListProvider::instance()
{
    static ContactListProvider contactListProvider;
    return contactListProvider;
}

