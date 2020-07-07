#ifndef BACKGROUNDWORKER_H
#define BACKGROUNDWORKER_H

#include <QObject>
#include "../compatibility.h"

class BackgroundWorker : public QObject
{
    Q_OBJECT

public:
    BackgroundWorker(QObject *parent = nullptr);
    ~BackgroundWorker();

    Q_DISABLE_COPY_MOVE(BackgroundWorker);
};

#endif // BACKGROUNDWORKER_H
