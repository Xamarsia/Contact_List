#pragma once
#include <QSortFilterProxyModel>

class ContactProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    explicit ContactProxyModel(QObject *parent = nullptr);

    Q_INVOKABLE void call(int id);
    Q_INVOKABLE void showOnlyFavorite(bool showFavorite);
    Q_INVOKABLE void setFilter(QString filter);

private:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const  override;

    bool m_showOnlyFavorite{false};
    QString m_filter;
};


