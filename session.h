#ifndef SESSION_H
#define SESSION_H

#include "application.h"

#include <QObject>

class Session : public QObject
{
    Q_OBJECT
public:
    explicit Session(QObject *parent = nullptr);
    Session(Application applicationLayer);

public slots:
    void connectSerialPort();
    void disconnectSerialPort();
    void modifySerialPortSettings();
};

#endif // SESSION_H
