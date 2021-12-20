#include <QApplication>
#include <QtQml>
#include <QQmlContext>

#include "contactmodel.h"
#include "contactproxymodel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ContactProxyModel* contactProxyModel = new ContactProxyModel(&app);
    ContactModel* contactModel = new ContactModel(&app);

    QQmlApplicationEngine engine; 


    contactProxyModel->setSourceModel(contactModel);
    contactProxyModel->setSortRole(ContactModel::RoleNames::NameRole);
    contactProxyModel->sort(0);
    engine.rootContext()->setContextProperty("contactProxyModel", contactProxyModel);


    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}
