/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: physical.cpp -
--
-- PROGRAM: console
--
-- FUNCTIONS:
--      explicit Physical(QObject *parent = nullptr);
--		void initializeSerialPort(QSerialPort *serialPort);
--		void deInitializeSerialPort(QSerialPort *serialPort);
--		void modifySerialPort(const QString &baudRate, const QString &dataBits, const QString &parity, const QString &stopBits, const QString &portName, QSerialPort *serialPort);
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
-- This program displays and reads in the characters that are sent over the serial connection. It handles keystrokes
-- and shows incoming characters.
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
-- RETURNS: void
--
-- NOTES:
-- This function is used to initialize the serial port and sets the default serial port parameters.
----------------------------------------------------------------------------------------------------------------------*/
void Physical::initializeSerialPort(QSerialPort *serialPort)
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
        }
        else
        {
            qDebug() << "Error";
        }
    }
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
-- RETURNS: void
--
-- NOTES:
-- This function is used to deinitialize the serial port.
----------------------------------------------------------------------------------------------------------------------*/
void Physical::deInitializeSerialPort(QSerialPort *serialPort)
{
    if (serialPort->isOpen())
    {
        serialPort->flush();
        serialPort->close();
    }
    else
    {
        qDebug() << "Error";
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
    qDebug() << serialPort->stopBits();
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
    qDebug() << serialPort->portName();
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
