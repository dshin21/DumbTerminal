#pragma once

#include "physical.h"
#include <QObject>

#include <QSerialPort>

class Physical : public QObject
{
    Q_OBJECT
public:
    explicit Physical(QObject *parent = nullptr);

    struct{
        QString baudRate;
        QString dataBits;
        QString parity;
        QString stopBits;
        QString portName;
    };

    public slots:
    void initializePort();
    void readFromSerialPort();
    void writeToSerialPort(const QByteArray &data);


private:

};
