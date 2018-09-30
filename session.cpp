#include "session.h"


Session::Session(QObject *parent, Physical *physicalLayer)
    : QObject(parent),
      physicalLayer(physicalLayer)
{

}

void Session::connectSerialPort(QSerialPort *serialPort)
{
    physicalLayer->initializeSerialPort(serialPort);
}

void Session::disconnectSerialPort(QSerialPort *serialPort)
{
    physicalLayer->deInitializeSerialPort(serialPort);
}

void Session::modifySerialPort(QString baudRate, QString dataBits, QString parity, QString stopBits, QString portName, QSerialPort *serialPort)
{
    physicalLayer->modifySerialPort(baudRate, dataBits, parity, stopBits, portName, serialPort);
}

QByteArray Session::readFromSerialPort(QSerialPort *serialPort)
{
    return physicalLayer->readFromSerialPort(serialPort);
}

//void Session::writeToSerialPort(const QByteArray &data, QSerialPort *serialPort)
//{
//    physicalLayer->writeToSerialPort(data, serialPort);
//}
