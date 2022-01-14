#pragma once

#include <QObject>
#include <QMap>
#include "common.h"

class QStandardItemModel;
//struct Contact;

class CsvParser : public QObject
{
    Q_OBJECT
public:
    explicit CsvParser(QObject *parent = nullptr);
    Q_INVOKABLE QVector<Contact> read();
//    Q_INVOKABLE bool write(const QString& data);

    QString source() { return mSource; };

public slots:
    void setSource(const QString& source) { mSource = source; };

signals:
    void sourceChanged(const QString& source);
private:

    bool getIndex();
    QVector<Contact> m_fileContent{};
    QString mSource = ":/csexample/contacts.csv";
    QMap<Characteristics, int> mTitlesMap;
};

