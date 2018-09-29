#pragma once

#include "physical.h"
#include <QObject>



class Session : public QObject
{
    Q_OBJECT
public:
    explicit Session(QObject *parent = nullptr);

    void connectSerialPort(QSerialPort *serialPort);
    void disconnectSerialPort(QSerialPort *serialPort);
//    void modifySerialPortSettings(QSerialPort *serialPort);

public slots:


private:
    Physical *physical;
};
