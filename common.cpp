#include "common.h"

Contact::Contact(){}

Contact::Contact(const int id): id(id){}

Contact::Contact(QString _fullName, QString _phoneNumber, QString _image, bool _favorite, int _tag, const QString  &_email, QDate _birthday, const QString &_notes):
    fullName(_fullName), phoneNumber(_phoneNumber), image(_image), favorite(_favorite), tag(_tag), email(_email), birthday(_birthday), notes(_notes){}

Contact::Contact(QString _fullName, QString _phoneNumber, QString _image, bool _favorite, int _tag, const QString  &_email, QDate _birthday, const QString &_notes, const int id):
    fullName(_fullName), phoneNumber(_phoneNumber), image(_image), favorite(_favorite), tag(_tag), email(_email), birthday(_birthday), notes(_notes), id(id){}
