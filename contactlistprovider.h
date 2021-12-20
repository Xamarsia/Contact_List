#pragma once

#include <QList>
#include <QString>

class ContactListProvider
{
public:
    struct Contact{
        int id{};
        QString name{};
        QString image{};
    };

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
