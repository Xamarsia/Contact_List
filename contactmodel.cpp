#include "contactmodel.h"
#include "csvparser.h"

ContactModel::ContactModel(QObject *parent)
    : QAbstractListModel(parent){
    m_roleNames[NameRole] = "name";
    m_roleNames[PhoneNumberRole] = "phoneNumber";
    m_roleNames[ImageRole] = "image";
    m_roleNames[FavoriteRole] = "favorite";
    m_roleNames[TagRole] = "tag";
    m_roleNames[EmailRole] = "email";
    m_roleNames[BirthdayRole] = "birthday";
    m_roleNames[NotesRole] = "notes";
    m_roleNames[IdRole] = "id";

    m_parser = new CsvParser(this);

    for(const Contact& contact : ContactListProvider::getContactsList()) {
        m_contacts.append(contact);
    }
}

int ContactModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return m_contacts.size();
}

Contact ContactModel::dataContact(const QModelIndex &index){
    int row = index.row();
    if(row < 0 || row >= m_contacts.count()) {
        return {};
    }

    const Contact &contact = m_contacts[row];
    if(ContactRole){
        return contact;
    }
}

QVariant ContactModel::data(const QModelIndex &index, int role) const {
    int row = index.row();
    if(row < 0 || row >= m_contacts.count()) {
        return QVariant();
    }

    const Contact &contact = m_contacts[row];

    switch(role){
        case NameRole:
            return contact.fullName;
        case PhoneNumberRole:
            return contact.phoneNumber;
        case ImageRole:
            return contact.image;
        case FavoriteRole:
            return contact.favorite;
        case TagRole:
            return contact.tag;
        case EmailRole:
            return contact.email;
        case BirthdayRole:
            return contact.birthday;
        case NotesRole:
            return contact.notes;
        case IdRole:
            return contact.id;
        case ContactRole:
            return QVariant::fromValue<Contact>(contact);
    }
    return QVariant();
}

bool ContactModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    int row = index.row();
    if(row < 0 || row >= m_contacts.count()) {
        return false;
    }

    Contact &contact = m_contacts[row];
    switch(role){
        case NameRole:
            contact.fullName = value.toString();
            emit dataChanged(index, index, { role });
            return true;

        case PhoneNumberRole:
            contact.phoneNumber = value.toString();
            emit dataChanged(index, index, { role });
            return true;

        case ImageRole:
            contact.image = value.toString();
            emit dataChanged(index, index, { role });
            return true;

        case FavoriteRole:{
            bool newFavoriteValue = value.toBool();
            if(contact.favorite != newFavoriteValue) {
                contact.favorite = newFavoriteValue;
                emit dataChanged(index, index, { role });
                return true;
            }
        }

        case TagRole:
            contact.tag = value.toInt();
            emit dataChanged(index, index, { role });
            return true;

        case EmailRole:
            contact.email = value.toString();
            emit dataChanged(index, index, { role });
            return true;

        case BirthdayRole:
            contact.birthday = value.toDate();
            emit dataChanged(index, index, { role });
            return true;

        case NotesRole:
            contact.notes = value.toString();
            emit dataChanged(index, index, { role });
            return true;
        case IdRole:
            contact.id = value.toInt();
            emit dataChanged(index, index, { role });
            return true;
    }
    return false;
}




void ContactModel::remove(int row){
    removeRow(row);
}

bool ContactModel::removeRows(int row, int count, const QModelIndex &parent) {

    Q_UNUSED(parent);
    if (count < 1 || row < 0 || (row + count - 1) >= m_contacts.count())
        return false;

    beginRemoveRows(QModelIndex(), row, row + count - 1);
    m_contacts.remove(row, count);
    ContactListProvider::getContactsList().removeAt(row);
    endRemoveRows();
    return true;
}

int ContactModel::Id = 0;

bool ContactModel::insertRows(int row, int count, const QModelIndex &parent)
{
    if (count < 1 || row < 0 || row > m_contacts.count())
        return false;

    beginInsertRows(parent, row, row + count - 1);
    Id++;
    m_contacts.insert(row, count, Contact{Id});
    endInsertRows();
    return true;
}

QHash<int, QByteArray> ContactModel::roleNames() const {
    return m_roleNames;
}

void ContactModel::importFromFile(){
     append(m_parser->read());
}

void  ContactModel::append(const QVector<Contact>& contacts) {
     int rowIndex = rowCount({});
     for(const Contact& contact : contacts) {

         auto iter = std::find_if(m_contacts.begin(), m_contacts.end(),
             [contact] (const Contact &person)
             {
                 return contact.fullName == person.fullName;
             });

         if(iter != m_contacts.end()){
             // TODO suggest replacing contact
             return;
         }


         insertRow(rowCount({}), {});

         setData(rowIndex, contact.fullName, contact.phoneNumber, contact.image, contact.favorite, contact.tag, contact.email, contact.birthday, contact.notes);
         ++rowIndex;
     }
 }

void ContactModel::append(const QString &fullName, const QString &phoneNumber, const bool favorite, const int tag, const QString  &image,
                          const QString  &email, QDate birthday, const QString &notes) {
    int rowIndex = rowCount({});
    insertRow(rowCount({}), {});
    setData(rowIndex, fullName, phoneNumber, image, favorite, tag, email, birthday, notes);
}

void ContactModel::setData(int row, const QString &fullName, const QString &phoneNumber, const QString  &image,
                       const bool favorite, const int tag, const QString  &email, QDate birthday, const QString &notes) {
    if (row < 0 || row >= m_contacts.count())
        return;

    auto itemIndex = index(row);
    //TODO: replace by new Contact object
    setData(itemIndex, fullName, NameRole);
    setData(itemIndex, phoneNumber, PhoneNumberRole);
    setData(itemIndex, image, ImageRole);
    setData(itemIndex, favorite, FavoriteRole);
    setData(itemIndex, tag, TagRole);
    setData(itemIndex, email, EmailRole);
    setData(itemIndex, birthday, BirthdayRole);
    setData(itemIndex, notes, NotesRole);

    Contact contact = Contact(fullName, phoneNumber, image, favorite, tag, email, birthday, notes, Id);
    ContactListProvider::getContactsList().append(contact);
}
