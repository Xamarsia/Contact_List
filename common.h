#pragma once
#include <QDate>
#include <QDebug>

enum Tag
{
    NONE,
    FRIEND,
    FAMILY,
    COLLEAGUE,
    FAMILIAR
};

static int getUniqueId() {
    static unsigned int Id = 0;
    Id++;
    return Id - 1;
}

struct Contact {
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
    int id{};




};

Q_DECLARE_METATYPE(Contact)
//QDebug << ( Tag.())
