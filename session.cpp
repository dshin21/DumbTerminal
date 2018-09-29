#include "session.h"
//TODO: delete all debugs
#include <QtDebug>

Session::Session(QObject *parent) : QObject(parent)
{

}

void Session::connectSerialPort(QSerialPort *serialPort)
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
            qDebug() << "Opened";
        }
        else
        {
            qDebug() << "Error";

        }
    }
}

void Session::disconnectSerialPort(QSerialPort *serialPort)
{
    if(serialPort->isOpen())    {
        serialPort->flush();
        serialPort->close();
        qDebug() << "Closed";
    }
}

//void Session::modifySerialPortSettings(QSerialPort *serialPort)
//{

//}
