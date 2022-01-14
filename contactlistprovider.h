#pragma once

#include <QList>
#include <QString>

#include "common.h"
#include "csvparser.h"

class ContactListProvider
{
public:

    static QList<Contact>& getContactsList();

    static void call(int id);

private:
    static ContactListProvider& instance();

    ContactListProvider();
    ~ContactListProvider(){}
    ContactListProvider(const ContactListProvider&) = delete;
    ContactListProvider& operator=(const ContactListProvider&)= delete;

    QList<Contact> m_contactsList;

};
