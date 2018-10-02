/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: physical.cpp - An application that provides essential functions using the serial port to
--                             transmit & receive data.
--
-- PROGRAM: DumbTerminal
--
-- FUNCTIONS:
--      explicit Physical(QObject *parent = nullptr);
--		bool initializeSerialPort(QSerialPort *serialPort);
--		bool deInitializeSerialPort(QSerialPort *serialPort);
--		void modifySerialPort(const QString &baudRate, const QString &dataBits, const QString &parity, const QString &stopBits, 
--                            const QString &portName, QSerialPort *serialPort);
--      void modifySerialPortBaudRate(const QString &baudRate, QSerialPort *serialPort);
--      void modifySerialPortDataBits(const QString &dataBits, QSerialPort *serialPort);
--      void modifySerialPortParity(const QString &parity, QSerialPort *serialPort);
--      void modifySerialPortStopBits(const QString &stopBits, QSerialPort *serialPort);
--      void modifySerialPortPortName(const QString &portName, QSerialPort *serialPort);
--      QByteArray readFromSerialPort(QSerialPort *serialPort);
--		void writeToSerialPort(const QByteArray &data, QSerialPort *serialPort);
--
--
-- DATE: September 29, 2018
--
-- REVISIONS: None
--
-- DESIGNER: Daniel Shin
--
-- PROGRAMMER: Daniel Shin
--
-- NOTES:
-- This file contains helper functions that directly interacts with the serial port for the session layer to utilize.
----------------------------------------------------------------------------------------------------------------------*/

#include "physical.h"
#include <QtDebug>

Physical::Physical(QObject *parent) : QObject(parent) {}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: initializeSerialPort
--
-- DATE: September 29, 2018
--
-- REVISIONS: None
--
-- DESIGNER: Daniel Shin
--
-- PROGRAMMER: Daniel Shin
--
-- INTERFACE: void initializeSerialPort(QSerialPort *serialPort)
--
-- RETURNS: bool, returns true if the port is successfully initialized, false otherwise.
--
-- NOTES:
-- This function is used to initialize the serial port and sets the default serial port parameters if the user decides to
-- connect without modifying the serial port properties.
----------------------------------------------------------------------------------------------------------------------*/
bool Physical::initializeSerialPort(QSerialPort *serialPort)
{
    if (serialPort && !serialPort->isOpen())
    {
        serialPort->open(QIODevice::ReadWrite);
        if (serialPort->isOpen())
        {
            serialPort->setPortName("COM1");
            serialPort->setBaudRate(QSerialPort::Baud2400);
            serialPort->setDataBits(QSerialPort::Data8);
            serialPort->setParity(QSerialPort::NoParity);
            serialPort->setStopBits(QSerialPort::OneStop);
            serialPort->setFlowControl(QSerialPort::HardwareControl);
            serialPort->open(QIODevice::ReadWrite);
            qDebug() << "Port opened";

            return true;
        }
    }

    return false;
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: deInitializeSerialPort
--
-- DATE: September 29, 2018
--
-- REVISIONS: None
--
-- DESIGNER: Daniel Shin
--
-- PROGRAMMER: Daniel Shin
--
-- INTERFACE: void deInitializeSerialPort(QSerialPort *serialPort)
--
-- RETURNS: bool, returns true if the port is successfully disconnected, otherwise false.
--
-- NOTES:
-- This function is used to deinitialize the serial port.
----------------------------------------------------------------------------------------------------------------------*/
bool Physical::deInitializeSerialPort(QSerialPort *serialPort)
{
    if (serialPort->isOpen())
    {
        serialPort->flush();
        serialPort->close();
        qDebug() << "Port closed";
        return true;
    }
    else
    {
        qDebug() << "Port is not open";
        return false;
    }
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: modifySerialPort
--
-- DATE: September 29, 2018
--
-- REVISIONS: None
--
-- DESIGNER: Daniel Shin
--
-- PROGRAMMER: Daniel Shin
--
-- INTERFACE: void modifySerialPort(const QString &baudRate,
--                                  const QString &dataBits, 
--                                  const QString &parity, 
--                                  const QString &stopBits, 
--                                  const QString &portName, 
--                                  QSerialPort *serialPort)
--
-- RETURNS: void
--
-- NOTES:
-- This function is used to modify the settings of the serial port.
----------------------------------------------------------------------------------------------------------------------*/
void Physical::modifySerialPort(const QString &baudRate, const QString &dataBits, const QString &parity, const QString &stopBits, const QString &portName, QSerialPort *serialPort)
{
    deInitializeSerialPort(serialPort);
    modifySerialPortBaudRate(baudRate, serialPort);
    modifySerialPortDataBits(dataBits, serialPort);
    modifySerialPortParity(parity, serialPort);
    modifySerialPortStopBits(stopBits, serialPort);
    modifySerialPortPortName(portName, serialPort);

    qDebug() << "Set to: ";
    qDebug() << "Bit Rate: " <<serialPort->baudRate();
    qDebug() << "Data Bits: " <<serialPort->dataBits();
    qDebug() << "Parity: " <<serialPort->parity();
    qDebug() << "Stop Bits: " <<serialPort->stopBits();
    qDebug() << "Port Name: " <<serialPort->portName();
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: modifySerialPortBaudRate
--
-- DATE: September 29, 2018
--
-- REVISIONS: None
--
-- DESIGNER: Daniel Shin
--
-- PROGRAMMER: Daniel Shin
--
-- INTERFACE: void modifySerialPortBaudRate(const QString &baudRate, QSerialPort *serialPort)
--
-- RETURNS: void
--
-- NOTES:
-- This function is used to modify the Baud Rate of the serial port.
----------------------------------------------------------------------------------------------------------------------*/
void Physical::modifySerialPortBaudRate(const QString &baudRate, QSerialPort *serialPort)
{
    switch (baudRate.toInt())
    {
    case 1200:
        serialPort->setBaudRate(QSerialPort::Baud1200);
        break;
    case 2400:
        serialPort->setBaudRate(QSerialPort::Baud2400);
        break;
    case 4800:
        serialPort->setBaudRate(QSerialPort::Baud4800);
        break;
    case 9600:
        serialPort->setBaudRate(QSerialPort::Baud9600);
        break;
    default:
        break;
    }
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: modifySerialPortDataBits
--
-- DATE: September 29, 2018
--
-- REVISIONS: None
--
-- DESIGNER: Daniel Shin
--
-- PROGRAMMER: Daniel Shin
--
-- INTERFACE: void modifySerialPortDataBits(const QString &dataBits, QSerialPort *serialPort)
--
-- RETURNS: void
--
-- NOTES:
-- This function is used to modify the data bits of the serial port.
----------------------------------------------------------------------------------------------------------------------*/
void Physical::modifySerialPortDataBits(const QString &dataBits, QSerialPort *serialPort)
{
    switch (dataBits.toInt())
    {
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
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: modifySerialPortParity
--
-- DATE: September 29, 2018
--
-- REVISIONS: None
--
-- DESIGNER: Daniel Shin
--
-- PROGRAMMER: Daniel Shin
--
-- INTERFACE: void modifySerialPortParity(const QString &parity, QSerialPort *serialPort)
--
-- RETURNS: void
--
-- NOTES:
-- This function is used to modify the parity bits of the serial port.
----------------------------------------------------------------------------------------------------------------------*/
void Physical::modifySerialPortParity(const QString &parity, QSerialPort *serialPort)
{
    if (parity.compare("None") == 0)
    {
        serialPort->setParity(QSerialPort::NoParity);
    }
    else if (parity.compare("Even") == 0)
    {
        serialPort->setParity(QSerialPort::EvenParity);
    }
    else if (parity.compare("Odd") == 0)
    {
        serialPort->setParity(QSerialPort::OddParity);
    }
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: modifySerialPortStopBits
--
-- DATE: September 29, 2018
--
-- REVISIONS: None
--
-- DESIGNER: Daniel Shin
--
-- PROGRAMMER: Daniel Shin
--
-- INTERFACE: void modifySerialPortStopBits(const QString &stopBits, QSerialPort *serialPort)
--
-- RETURNS: void
--
-- NOTES:
-- This function is used to modify the stop bits of the serial port.
----------------------------------------------------------------------------------------------------------------------*/
void Physical::modifySerialPortStopBits(const QString &stopBits, QSerialPort *serialPort)
{
    if (stopBits.toInt() == 1)
    {
        serialPort->setStopBits(QSerialPort::OneStop);
    }
    else if (stopBits.toDouble() == 1.5)
    {
        serialPort->setStopBits(QSerialPort::OneAndHalfStop);
    }
    else if (stopBits.toInt() == 2)
    {
        serialPort->setStopBits(QSerialPort::TwoStop);
    }
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: modifySerialPortPortName
--
-- DATE: September 29, 2018
--
-- REVISIONS: None
--
-- DESIGNER: Daniel Shin
--
-- PROGRAMMER: Daniel Shin
--
-- INTERFACE: void modifySerialPortPortName(const QString &portName, QSerialPort *serialPort)
--
-- RETURNS: void
--
-- NOTES:
-- This function is used to modify the port name of the serial port.
----------------------------------------------------------------------------------------------------------------------*/
void Physical::modifySerialPortPortName(const QString &portName, QSerialPort *serialPort)
{
    serialPort->setPortName(portName);
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: readFromSerialPort
--
-- DATE: September 29, 2018
--
-- REVISIONS: None
--
-- DESIGNER: Daniel Shin
--
-- PROGRAMMER: Daniel Shin
--
-- INTERFACE: QByteArray readFromSerialPort(QSerialPort *serialPort)
--
-- RETURNS: QByteArray
--
-- NOTES:
-- This function is used to read from the serial port.
----------------------------------------------------------------------------------------------------------------------*/
QByteArray Physical::readFromSerialPort(QSerialPort *serialPort)
{
    return serialPort->readAll();
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: writeToSerialPort
--
-- DATE: September 29, 2018
--
-- REVISIONS: None
--
-- DESIGNER: Daniel Shin
--
-- PROGRAMMER: Daniel Shin
--
-- INTERFACE: void writeToSerialPort(const QByteArray &data, QSerialPort *serialPort)
--
-- RETURNS: void
--
-- NOTES:
-- This function is used to write to the serial port.
----------------------------------------------------------------------------------------------------------------------*/
void Physical::writeToSerialPort(const QByteArray &data, QSerialPort *serialPort)
{
    serialPort->write(data);
}
