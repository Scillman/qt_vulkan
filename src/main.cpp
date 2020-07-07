#include <QApplication>
#include <QFontDatabase>
#include <QTranslator>
#include <QQuickView>
#include <QObject>
#include <QQmlEngine>
#include <QDir>
#include "mainwindow.h"

/** Forward declarations */
static void qmlRegisterAll();

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("scillman.eu");
    QCoreApplication::setApplicationName("AuroraQt");
    QCoreApplication::setApplicationVersion("0.1");

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_UseOpenGLES);

    QApplication app(argc, argv);

    QFontDatabase fontDatabase;
    for (const QString &file: QDir(":/fonts").entryList())
    {
        fontDatabase.addApplicationFont(file);
    }
    app.setFont(QFont("NotoSans-Regular"));

    QTranslator translator;
    translator.load(":/translations/nl_NL");
    bool installed = app.installTranslator(&translator);
    //Q_ASSERT(installed);

    QQuickView viewer;
    QQmlEngine *engine = viewer.engine();
    engine->addImportPath(QGuiApplication::applicationDirPath());
    QObject::connect(engine, &QQmlEngine::quit, &viewer, &QWindow::close);

    qmlRegisterAll();

    MainWindow window(viewer.rootContext());
    window.preRender();

    viewer.setTitle(window.title());
    viewer.setSource(QUrl(QLatin1String("qrc:/main.qml")));
    viewer.setResizeMode(QQuickView::SizeRootObjectToView);
    viewer.show();

    window.postRender();
    return app.exec();
}

#define REGISTER_NAME               "Aurora.Qt"
#define REGISTER_VERSION_MAJOR      1
#define REGISTER_VERSION_MINOR      0

#define REGISTER_CLASS(name) \
    qmlRegisterType<name>(REGISTER_NAME, REGISTER_VERSION_MAJOR, REGISTER_VERSION_MINOR, #name)

#define REGISTER_ENUM(name) \
    qmlRegisterType<name ## Class>(REGISTER_NAME, REGISTER_VERSION_MAJOR, REGISTER_VERSION_MINOR, #name); \
    qRegisterMetaType<name ## Class:: name ## Enum>(#name)

#define REGISTER_SINGLETON(name) \
    qmlRegisterSingletonType<name>(REGISTER_NAME, REGISTER_VERSION_MAJOR, REGISTER_VERSION_MINOR, #name, &getInstance<name>);

template<class T>
static QObject* getInstance(QQmlEngine*, QJSEngine*)
{
    return T::GetInstance();
}

static void qmlRegisterAll()
{
    //REGISTER_CLASS(className);

    REGISTER_ENUM(ActiveView);

    //REGISTER_SINGLETON(className);
}

