#include <QDebug>
#include "mainwindow.h"

MainWindow::MainWindow(QQmlContext *context) :
      QObject(nullptr),
      m_context(context)
{
    context->setContextProperty("mainWindow", this);
}

MainWindow::~MainWindow()
{
}

QString MainWindow::title() const noexcept
{
    return QString(QObject::tr("AuroraVK - Qt Test Project"));
}

void MainWindow::preRender()
{

}

void MainWindow::postRender()
{

}

void MainWindow::setActiveView(ActiveView view)
{
    qDebug() << "View:" << view;

    if (view == ActiveView::Dashboard)
    {
        qDebug() << "DASHBOARD !!";
    }
}
