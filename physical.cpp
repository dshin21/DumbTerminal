#include "physical.h"
#include <QtDebug>

Physical::Physical(QObject *parent)
    : QObject(parent)
{

}

void Physical::initializeSerialPort(QSerialPort *serialPort)
{
    if(serialPort && !serialPort->isOpen())
    {
        serialPort->open(QIODevice::ReadWrite);
        if(serialPort->isOpen())
        {
            serialPort->setPortName("COM1");
            serialPort->setBaudRate(QSerialPort::Baud2400);
            serialPort->setDataBits(QSerialPort::Data8);
            serialPort->setParity(QSerialPort::NoParity);
            serialPort->setStopBits(QSerialPort::OneStop);
            serialPort->setFlowControl(QSerialPort::HardwareControl);
            serialPort->open(QIODevice::ReadWrite);
            qDebug() << "Opened";
        }
        else
        {
            qDebug() << "Error";

        }
    }
}

void Physical::deInitializeSerialPort(QSerialPort *serialPort)
{
    if(serialPort->isOpen())    {
        serialPort->flush();
        serialPort->close();
        qDebug() << "Closed";
    }else{
        qDebug() << "Error";
    }
}

void Physical::modifySerialPort(const QString &baudRate, const QString &dataBits, const QString &parity, const QString &stopBits, const QString &portName, QSerialPort *serialPort)
{
    modifySerialPortBaudRate(baudRate, serialPort);
    modifySerialPortDataBits(dataBits, serialPort);
    modifySerialPortParity(parity, serialPort);
    modifySerialPortStopBits(stopBits, serialPort);
    modifySerialPortPortName(portName, serialPort);
}

void Physical::modifySerialPortBaudRate(const QString &baudRate, QSerialPort *serialPort)
{
    switch (baudRate.toInt()) {
    case 1200:
        serialPort->setBaudRate(QSerialPort::Baud1200);
        break;
    case 2400:
        serialPort->setBaudRate(QSerialPort::Baud2400);
        break;
    default:
        break;
    }
    qDebug() << serialPort->baudRate();
}

void Physical::modifySerialPortDataBits(const QString &dataBits, QSerialPort *serialPort)
{
    switch (dataBits.toInt()) {
    case 8:
        serialPort->setDataBits(QSerialPort::Data8);
        break;
    case 7:
        serialPort->setDataBits(QSerialPort::Data7);
        break;
    case 6:
        serialPort->setDataBits(QSerialPort::Data6);
        break;
    case 5:
        serialPort->setDataBits(QSerialPort::Data5);
        break;
    default:
        break;
    }
    qDebug() << serialPort->dataBits();
}

void Physical::modifySerialPortParity(const QString &parity, QSerialPort *serialPort)
{
    if(parity.compare("None") == 0){
        serialPort->setParity(QSerialPort::NoParity);
    }else if(parity.compare("Even") == 0){
        serialPort->setParity(QSerialPort::EvenParity);
    }else if(parity.compare("Odd") == 0){
        serialPort->setParity(QSerialPort::OddParity);
    }
    qDebug() << serialPort->parity();
}

void Physical::modifySerialPortStopBits(const QString &stopBits, QSerialPort *serialPort)
{
    if(stopBits.toInt() == 1){
        serialPort->setStopBits( QSerialPort::OneStop);
    }else if(stopBits.toDouble() == 1.5){
        serialPort->setStopBits( QSerialPort::OneAndHalfStop);
    }else if(stopBits.toInt() == 2){
        serialPort->setStopBits( QSerialPort::TwoStop);
    }
    qDebug() << serialPort->stopBits();
}

void Physical::modifySerialPortPortName(const QString &portName, QSerialPort *serialPort)
{
    serialPort->setPortName(portName);
    qDebug() << serialPort->portName();
}

QByteArray Physical::readFromSerialPort(QSerialPort *serialPort)
{
    return serialPort->readAll();
}

void Physical::writeToSerialPort(const QByteArray &data, QSerialPort *serialPort)
{

    serialPort->write(data);
    qDebug() << "wrote";
}



