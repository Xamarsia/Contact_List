#include "csvparser.h"
#include "common.h"

#include <QFile>
#include <QTextStream>
#include <QStandardItemModel>
#include <QDebug>
#include <QTableView>
#include <QDate>

CsvParser::CsvParser(QObject *parent)
    : QObject{parent}
{}

bool CsvParser::getIndex(){

    QFile file(mSource);
    if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
        qDebug() << "File not exists";
        return false;
    }

    QTextStream in(&file);
    if (in.atEnd()){
        return false;
    }

    const QString line = in.readLine();
    int i = 0;
    mTitlesMap.clear();
    for (const QString& item : line.split(",")) {
        if(item.isEmpty()){
            qDebug() << item;
        }
        else if(item == "Name"){
            mTitlesMap[Characteristics::NAME] = i;
        }
        else if(item == "Notes"){
            mTitlesMap[Characteristics::NOTES] = i;
        }
        else if(item == "E-mail 1 - Value"){
            mTitlesMap[Characteristics::EMAIL] = i;
        }
        else if(item == "Phone 1 - Value"){
            mTitlesMap[Characteristics::PHONENUMBER] = i;
        }
        else if(item == "Photo"){
            mTitlesMap[Characteristics::IMAGE] = i;
        }
        else if(item == "Birthday"){
            mTitlesMap[Characteristics::BIRTHDAY] = i;
        }
        ++i;
    }
    return true;
}


QVector<Contact> CsvParser::read(){
    QFile file(mSource);
    if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
        qDebug() << "File not exists";
        return {};
    }

    QTextStream in(&file);

    int count = 0;
    m_fileContent.clear();

    while (!in.atEnd())
    {
        const QString line = in.readLine();
        QStringList headerLabels{};
        if(!count){
            getIndex();
            ++count;
        }
        else{
            for (const QString& item : line.split(",")) {
                headerLabels.append(item);
            }

            QDate date;
            if(headerLabels[mTitlesMap[Characteristics::BIRTHDAY]].isEmpty()){
                date = {};
            }
            else{
                date = QDate::fromString(headerLabels[mTitlesMap[Characteristics::BIRTHDAY]], "mm/dd/yyyy");
            }
            Contact contact = Contact(headerLabels[mTitlesMap[Characteristics::NAME]],
                    headerLabels[mTitlesMap[Characteristics::PHONENUMBER]],
                    headerLabels[mTitlesMap[Characteristics::IMAGE]],
                    headerLabels[mTitlesMap[Characteristics::FAVORITE]].isEmpty(),
                    {},
                    headerLabels[mTitlesMap[Characteristics::EMAIL]],
                    date,
                    headerLabels[mTitlesMap[Characteristics::NOTES]]);

            m_fileContent.append(contact);
        }
    }

    file.close();
    return m_fileContent;
}


//bool CsvParser::write(const QString& data)
//{
//    if (mSource.isEmpty())
//        return false;

//    QFile csvFile(mSource);
//    if (!csvFile.open(QIODevice::WriteOnly | QIODevice::Truncate))
//        return false;


//    QTextStream out( &csvFile );

//    QStringList stringList;


////    for( int row = 0; row < this->countRow(); row++ )
//    for( int row = 0; row < 41; row++ )
//    {
//        stringList.clear();
//        for( int column = 0; column < 4; column++ )
//        {
////            stringList << this->data(index(row, column), Qt::UserRole + 1 + column).toString();
//            out << data;
//            qDebug() << data;
//        }
//        out << stringList.join( ';' )+"\n";
//    }
//    csvFile.close();


////    QTextStream out(&csvFile);
////    out << data;

////    file.close();

//    return true;
//}
