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

void Physical::deInitializeSerialPort()
{
//    if(serialPort->isOpen())    {
//        serialPort->flush();
//        serialPort->close();
//        qDebug() << "Closed";
//    }else{
//        qDebug() << "Error";
//    }
}

void Physical::modifySerialPort(const QString &baudRate, const QString &dataBits, const QString &parity, const QString &stopBits, const QString &portName)
{

}

void Physical::readFromSerialPort()
{

}

void Physical::writeToSerialPort(const QByteArray &data)
{

}
