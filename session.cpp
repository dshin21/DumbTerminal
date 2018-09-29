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

void Session::disconnectSerialPort()
{
    physicalLayer->deInitializeSerialPort();
}

void Session::modifySerialPort(QString baudRate, QString dataBits, QString parity, QString stopBits, QString portName)
{
    physicalLayer->modifySerialPort(baudRate, dataBits, parity, stopBits, portName);
}
