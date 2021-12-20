#include "contactmodel.h"

ContactModel::ContactModel(QObject *parent)
    : QAbstractListModel(parent)
{
    m_roleNames[NameRole] = "name";
    m_roleNames[IdRole] = "id";
    m_roleNames[ImageRole] = "image";
    m_roleNames[FavoriteRole] = "favorite";

    for(const ContactListProvider::Contact& contact : ContactListProvider::getContactsList())
    {
        m_data.append(ContactData{contact, false});
    }
}

int ContactModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return ContactListProvider::getContactsList().size();
}

QVariant ContactModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    if(row < 0 || row >= m_data.count())
    {
        return QVariant();
    }

    const ContactData &contactData = m_data[row];

    switch(role)
    {
        case NameRole:
            return contactData.contact.name;
        case IdRole:
            return contactData.contact.id;
        case ImageRole:
            return contactData.contact.image;
        case FavoriteRole:
            return contactData.favorite;
    }
    return QVariant();
}

bool ContactModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    int row = index.row();
    if(row < 0 || row >= m_data.count())
    {
        return false;
    }

    if (role == FavoriteRole)
    {
        ContactData &contactData = m_data[row];
        bool newFavoriteValue = value.toBool();
        if(contactData.favorite != newFavoriteValue)
        {
            contactData.favorite = newFavoriteValue;
            emit dataChanged(index, index, { role });
            return true;
        }
    }
    return false;
}

QHash<int, QByteArray> ContactModel::roleNames() const
{
    return m_roleNames;
}
