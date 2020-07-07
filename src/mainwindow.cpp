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

void MainWindow::preRender()
{

}

void MainWindow::postRender()
{

}

void MainWindow::setActiveView(ActiveView view)
{
    qDebug() << "View:" << view;

    if (view == ActiveViewClass::ActiveViewEnum::Dashboard)
    {
        qDebug() << "DASHBOARD !!";
    }
}
