#pragma once

#include "physical.h"
#include <QObject>

#include <QKeyEvent>
#include <QtSerialPort>

class Physical : public QObject
{
    Q_OBJECT
public:
    explicit Physical(QObject *parent = nullptr);

    QString baudRate;
    QString dataBits;
    QString parity;
    QString stopBits;
    QString portName;


public slots:
    void initializeSerialPort(QSerialPort *serialPort);

    void deInitializeSerialPort(QSerialPort *serialPort);

    void modifySerialPort(const QString &baudRate, const QString &dataBits, const QString &parity, const QString &stopBits, const QString &portName, QSerialPort *serialPort);
    void modifySerialPortBaudRate(const QString &baudRate, QSerialPort *serialPort);
    void modifySerialPortDataBits(const QString &dataBits, QSerialPort *serialPort);
    void modifySerialPortParity(const QString &parity, QSerialPort *serialPort);
    void modifySerialPortStopBits(const QString &stopBits, QSerialPort *serialPort);
    void modifySerialPortPortName(const QString &portName, QSerialPort *serialPort);

    QByteArray readFromSerialPort(QSerialPort *serialPort);

    void writeToSerialPort(const QByteArray &data, QSerialPort *serialPort);


private:

};
