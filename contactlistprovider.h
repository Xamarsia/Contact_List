#pragma once

#include <QList>
#include <QString>
#include "common.h"

class ContactListProvider
{
public:

    static const QList<Contact>& getContactsList();

    static void call(int id);

private:
    static ContactListProvider& instance();

    ContactListProvider();
    ~ContactListProvider(){}
    ContactListProvider(const ContactListProvider&) = delete;
    ContactListProvider& operator=(const ContactListProvider&)= delete;

    QList<Contact> m_contactsList;
};
