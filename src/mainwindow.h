#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QQmlContext>



class ActiveViewClass : public QObject
{
    Q_OBJECT

public:
    enum class ActiveViewEnum : int
    {
        Dashboard = 0,
        Demo
    };
    Q_ENUM(ActiveViewEnum);
};
typedef ActiveViewClass::ActiveViewEnum ActiveView;



class MainWindow : public QObject
{
    Q_OBJECT

public:
    MainWindow(QQmlContext *context);
    ~MainWindow();

    void preRender();
    void postRender();

    QString title() const noexcept;

    Q_INVOKABLE void setActiveView(ActiveView view);

private:
    QQmlContext *m_context;
};



#endif // MAINWINDOW_H
