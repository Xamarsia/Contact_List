#pragma once
#include <QDate>
#include <QDebug>
#include <iostream>

enum Tag
{
    NONE,
    FRIEND,
    FAMILY,
    COLLEAGUE,
    FAMILIAR
};

enum Characteristics
{
    NAME,
    PHONENUMBER,
    IMAGE,
    FAVORITE,
    TAG,
    EMAIL,
    BIRTHDAY,
    NOTES,
};

class Contact {
    Q_GADGET

    Q_PROPERTY(QString fullName MEMBER fullName)
    Q_PROPERTY(QString phoneNumber MEMBER phoneNumber)
    Q_PROPERTY(QString image MEMBER image)
    Q_PROPERTY(bool favorite MEMBER favorite)
    Q_PROPERTY(int tag MEMBER tag)
    Q_PROPERTY(QString email MEMBER email)
    Q_PROPERTY(QDate birthday MEMBER birthday)
    Q_PROPERTY(QString notes MEMBER notes)
    Q_PROPERTY(int id MEMBER id)

public:
    QString fullName{};
    QString phoneNumber{};

    QString image{};
    bool favorite{};
    int tag{};

    QString email{};
    QDate birthday{};
    QString notes{};
    int id = 0;

    Contact();
    Contact(const int id);
    Contact(QString _fullName, QString _phoneNumber, QString _image, bool _favorite, int _tag, const QString  &_email = "", QDate _birthday = QDate(1000, 1, 1), const QString &_notes = "");
    Contact(QString _fullName, QString _phoneNumber, QString _image, bool _favorite, int _tag, const QString  &_email, QDate _birthday, const QString &_notes, const int id);
};

Q_DECLARE_METATYPE(Contact)




