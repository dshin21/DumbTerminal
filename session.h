#pragma once

#include "physical.h"
#include <QObject>



class Session : public QObject
{
    Q_OBJECT
public:
    explicit Session(QObject *parent = nullptr, Physical *physicalLayer = nullptr);

    void connectSerialPort(QSerialPort *serialPort);
    void disconnectSerialPort();
    void modifySerialPort(QString baudRate, QString dataBits, QString parity, QString stopBits, QString portName);

public slots:


private:
    Physical *physicalLayer;
};
