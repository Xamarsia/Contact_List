#include "contactproxymodel.h"
#include "contactlistprovider.h"
#include "contactmodel.h"

ContactProxyModel::ContactProxyModel(QObject *parent) : QSortFilterProxyModel(parent)
{

}

void ContactProxyModel::call(int id)
{
    ContactListProvider::call(id);
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
