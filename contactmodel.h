#pragma once

#include <QAbstractListModel>
#include "contactlistprovider.h"

class ContactModel: public QAbstractListModel
{
     Q_OBJECT

public:
    explicit ContactModel(QObject *parent = 0);

    enum RoleNames
    {
        NameRole = Qt::UserRole + 1,
        IdRole,
        ImageRole,
        FavoriteRole,
    };

    virtual int rowCount(const QModelIndex &parent) const override;

    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role) override;

    virtual QHash<int, QByteArray> roleNames() const override;

private:
    struct ContactData
    {
        ContactListProvider::Contact contact;
        bool favorite = false;
    };

    QVector<ContactData> m_data;
    QHash<int, QByteArray> m_roleNames;
};
