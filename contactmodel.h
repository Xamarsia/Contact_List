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
        PhoneNumberRole,
        ImageRole,
        FavoriteRole,
        TagRole,
        EmailRole,
        BirthdayRole,
        NotesRole,
        IdRole,
        ContactRole
    };

    virtual int rowCount(const QModelIndex &parent) const override;

    virtual QVariant data(const QModelIndex &index, int role) const override;

    virtual bool setData(const QModelIndex &index, const QVariant &value, int role) override;

    virtual QHash<int, QByteArray> roleNames() const override;

    virtual bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    virtual bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;



    Q_INVOKABLE void append(const QString &fullName, const QString &phoneNumber, const bool favorite, const int tag, const QString  &image = "",
                            const QString  &email = "", QDate birthday = QDate(1000, 1, 1), const QString &notes = "");

    Q_INVOKABLE void setData(int row, const QString &fullName, const QString &phoneNumber, const QString  &image,
                         const bool favorite, const int tag, const QString  &email, QDate birthday, const QString &notes);

    Q_INVOKABLE Contact dataContact(const QModelIndex &index);

    Q_INVOKABLE void remove(int row);

    Q_INVOKABLE void importFromFile();

private:
    static int Id;
    QVector<Contact> m_contacts;
    QHash<int, QByteArray> m_roleNames;
    CsvParser* m_parser;

    void append(const QVector<Contact>& contacts);
signals:

    void contactStructChanged();
};
