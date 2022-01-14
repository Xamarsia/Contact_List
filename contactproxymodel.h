#pragma once
#include <QSortFilterProxyModel>
#include "common.h"

class ContactProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    explicit ContactProxyModel(QObject *parent = nullptr);

    Q_INVOKABLE void call(int id);
    Q_INVOKABLE void showOnlyFavorite(bool showFavorite);
    Q_INVOKABLE void setFilter(QString filter);

    Q_INVOKABLE void append(const QString &fullName, const QString &phoneNumber, const bool favorite, const int tag, const QString  &image = "",
                            const QString  &email = "", QDate birthday = QDate(1000, 1, 1), const QString &notes = "");

    Q_INVOKABLE void setData(int row, const QString &fullName, const QString &phoneNumber, const QString  &image,
                         const bool favorite, const int tag, const QString  &email, QDate birthday, const QString &notes);

    Q_INVOKABLE QVariant data(const QModelIndex &index, int role);

    Q_INVOKABLE Contact getContact(const int row);

    Q_INVOKABLE void remove(int row);

    Q_INVOKABLE void importFromFile();

//    Q_INVOKABLE void importToFile();

private:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const  override;

    bool m_showOnlyFavorite{false};
    QString m_filter;
};


