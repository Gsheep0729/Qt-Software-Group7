#include <QGuiApplication>
#include <QQmlEngine>        // ← 注意：不是 QQmlApplicationEngine
#include <QQmlComponent>
#include <QQuickWindow>      // ← 用于 qobject_cast

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlEngine engine;
    QQmlComponent component(&engine);

    component.setData(
        "import QtQuick\n"
        "import QtQuick.Controls\n"
        "ApplicationWindow{ visible:true; width:400; height:300; Text{text:\"hello QML!\"} }",
        QUrl());

    auto *window = qobject_cast<QQuickWindow *>(component.create());
    window->setHeight(768);

    return app.exec();
}
