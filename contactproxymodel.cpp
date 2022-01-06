#include "contactproxymodel.h"
#include "contactlistprovider.h"
#include "contactmodel.h"
#include "QDebug"

ContactProxyModel::ContactProxyModel(QObject *parent) : QSortFilterProxyModel(parent)
{

}

void ContactProxyModel::call(int id)
{
    ContactListProvider::call(id);
}

void ContactProxyModel::append(const QString &fullName, const QString &phoneNumber, const bool favorite, const int tag, const QString  &image,
                               const QString  &email, QDate birthday, const QString &notes)
{
    ContactModel* contactModel = dynamic_cast<ContactModel*>(sourceModel());
    if(contactModel == nullptr)
    {
        return;
    }
    contactModel->append(fullName, phoneNumber, favorite, tag, image, email, birthday, notes);
}

void ContactProxyModel::setData(int row, const QString &fullName, const QString &phoneNumber, const QString  &image,
             const bool favorite, const int tag, const QString  &email, QDate birthday, const QString &notes)
{
    ContactModel* contactModel = dynamic_cast<ContactModel*>(sourceModel());
    if(contactModel == nullptr)
    {
        return;
    }

    QModelIndex i = mapToSource(index(row, 0));

    contactModel->setData(i.row(), fullName, phoneNumber, image, favorite, tag, email, birthday, notes);
}

QVariant ContactProxyModel::data(const QModelIndex &index, int role){
    ContactModel* contactModel = dynamic_cast<ContactModel*>(sourceModel());
    if(contactModel == nullptr)
    {
        return QVariant{};
    }
    return contactModel->data(mapToSource(index), role);
}


Contact ContactProxyModel::getContact(const int row){
    auto i = index(row, 0);
    QVariant contactData = data(i, ContactModel::ContactRole);
    auto data =  contactData.value<Contact>();

    return data;
}

void ContactProxyModel::remove(int row){
    auto i = mapToSource(index(row, 0));
    ContactModel* contactModel = dynamic_cast<ContactModel*>(sourceModel());
    if(contactModel == nullptr)
    {
        return;
    }
     contactModel->remove(i.row());
}

void ContactProxyModel::showOnlyFavorite(bool showFavorite)
{
    m_showOnlyFavorite = showFavorite;
    invalidateFilter();
}

void ContactProxyModel::setFilter(QString filter)
{
    m_filter = filter;
    invalidateFilter();
}

bool ContactProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
    QModelIndex index = sourceModel()->index(sourceRow, 0, sourceParent);

    bool isAcceptable = true;
    if(m_showOnlyFavorite)
    {
        bool isFavorite = sourceModel()->data(index, ContactModel::FavoriteRole).toBool();
        if(!isFavorite)
        {
            isAcceptable = false;
        }
    }

    if(!m_filter.isEmpty())
    {
        QString name = sourceModel()->data(index, ContactModel::NameRole).toString();

        if(!name.contains(m_filter, Qt::CaseSensitivity::CaseInsensitive))
        {
            isAcceptable = false;
        }
    }

    return isAcceptable;
}
