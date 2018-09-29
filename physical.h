#pragma once

#include "physical.h"
#include <QObject>

#include <QSerialPort>

class Physical : public QObject
{
    Q_OBJECT
public:
    explicit Physical(QObject *parent = nullptr);
    QSerialPort *serialPort;

    QString baudRate;
    QString dataBits;
    QString parity;
    QString stopBits;
    QString portName;


public slots:
    void initializeSerialPort(QSerialPort *serialPort);
    void deInitializeSerialPort();
    void modifySerialPort(const QString &baudRate, const QString &dataBits, const QString &parity, const QString &stopBits, const QString &portName);
    void readFromSerialPort();
    void writeToSerialPort(const QByteArray &data);


private:

};
