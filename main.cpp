#include <QApplication>
#include <QtQml>
#include <QQmlContext>

#include "contactmodel.h"
#include "contactproxymodel.h"

#include <QStandardItemModel>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ContactProxyModel* contactProxyModel = new ContactProxyModel(&app);
    ContactModel* contactModel = new ContactModel(&app);

    QQmlApplicationEngine engine; 
    qRegisterMetaType<Contact>();

    contactProxyModel->setSourceModel(contactModel);
    contactProxyModel->setSortRole(ContactModel::RoleNames::NameRole);
    contactProxyModel->sort(0);
    engine.rootContext()->setContextProperty("contactProxyModel", contactProxyModel);

    QStandardItemModel *model = new QStandardItemModel(&app);
    engine.rootContext()->setContextProperty("testModel", model);


    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}
