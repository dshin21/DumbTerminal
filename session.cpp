/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: session.cpp - An application that displays two text windows used for the Dumb Terminal Emulator.
--
-- PROGRAM: DumbTerminal
--
-- FUNCTIONS:
--      explicit Session(QWidget *parent = nullptr);
--      ~Session();
--      
--		void onClickConnect();
--      void onClickDisconnect();
--      void onClickModify();
--      void readFromSerialPort();
--      void on_console_textChanged(const QString &arg1);
--      void keyPressEvent(QKeyEvent *e);
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
-- This program displays two text windows, one for sending text to the serial port and one for receiving incoming text from
-- the serial port. It listens to keypress events from the sending QLineEdit and interacts with the Phyiscal layer to transmit
-- the text to the serial port. Furthermore, it simultaneously listens to the serial port for any incoming data and write to
-- the incoming QLineEdit on the console.
----------------------------------------------------------------------------------------------------------------------*/

#include "session.h"
#include "ui_application.h"
#include "configdialog.h"

Session::Session(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Application), serialPort(new QSerialPort("COM1", this))
{
    ui->setupUi(this);
    initializeUIConnections();
    physicalLayer = new Physical;
}

Session::~Session()
{
    delete ui;
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: initializeUIConnections
--
-- DATE: September 29, 2018
--
-- REVISIONS: None
--
-- DESIGNER: Daniel Shin
--
-- PROGRAMMER: Daniel Shin
--
-- INTERFACE: void initializeUIConnections()
--
-- RETURNS: void
--
-- NOTES:
-- This function is used to initialize all the UI components events.
----------------------------------------------------------------------------------------------------------------------*/

void Session::initializeUIConnections()
{
    connect(ui->actionConnect, &QAction::triggered, this, &Session::onClickConnect);        //Connect Menu
    connect(ui->actionDisconnect, &QAction::triggered, this, &Session::onClickDisconnect);  //Disconnect Menu
    connect(ui->actionModify_Settings, &QAction::triggered, this, &Session::onClickModify); //Modify Settings Menu
    connect(serialPort, &QSerialPort::readyRead, this, &Session::readFromSerialPort);       //read from serial port
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: onClickConnect
--
-- DATE: September 29, 2018
--
-- REVISIONS: None
--
-- DESIGNER: Daniel Shin
--
-- PROGRAMMER: Daniel Shin
--
-- INTERFACE: void onClickConnect()
--
-- RETURNS: void
--
-- NOTES:
-- This function is used to trigger the initialization of the serial port on clicking the "Connect" menu item.
----------------------------------------------------------------------------------------------------------------------*/

void Session::onClickConnect()
{
    physicalLayer->initializeSerialPort(serialPort);
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: onClickDisconnect
--
-- DATE: September 29, 2018
--
-- REVISIONS: None
--
-- DESIGNER: Daniel Shin
--
-- PROGRAMMER: Daniel Shin
--
-- INTERFACE: void onClickDisconnect()
--
-- RETURNS: void
--
-- NOTES:
-- This function is used to trigger the deinitialization of the serial port on clicking the "Disconnect" menu item.
----------------------------------------------------------------------------------------------------------------------*/

void Session::onClickDisconnect()
{
    physicalLayer->deInitializeSerialPort(serialPort);
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: onClickModify
--
-- DATE: September 29, 2018
--
-- REVISIONS: None
--
-- DESIGNER: Daniel Shin
--
-- PROGRAMMER: Daniel Shin
--
-- INTERFACE: void onClickModify()
--
-- RETURNS: void
--
-- NOTES:
-- This function is used to trigger the configuration settings of the serial port on clicking the "Modify Settings" menu item.
----------------------------------------------------------------------------------------------------------------------*/

void Session::onClickModify()
{
    ConfigDialog configDialog(nullptr, physicalLayer, serialPort);
    configDialog.setModal(true);
    configDialog.exec();
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
-- INTERFACE: void readFromSerialPort()
--
-- RETURNS: void
--
-- NOTES:
-- This function is used to monitor the serial port and displays the incoming text to the incoming QLineEdit.
----------------------------------------------------------------------------------------------------------------------*/

void Session::readFromSerialPort()
{
    QString previousText = ui->incomingConsole->text().append(physicalLayer->readFromSerialPort(serialPort));
    ui->incomingConsole->setText(QString(previousText));
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: on_console_textChanged
--
-- DATE: September 29, 2018
--
-- REVISIONS: None
--
-- DESIGNER: Daniel Shin
--
-- PROGRAMMER: Daniel Shin
--
-- INTERFACE: on_console_textChanged(const QString &text)
--
-- RETURNS: void
--
-- NOTES:
-- This function is used to monitor the sending QLineEdit and sends to the serial port.
----------------------------------------------------------------------------------------------------------------------*/

void Session::on_console_textChanged(const QString &text)
{
    QString data = text.at(text.size() - 1);
    physicalLayer->writeToSerialPort(data.toLocal8Bit(), serialPort);
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: keyPressEvent
--
-- DATE: September 29, 2018
--
-- REVISIONS: None
--
-- DESIGNER: Daniel Shin
--
-- PROGRAMMER: Daniel Shin
--
-- INTERFACE: void keyPressEvent(QKeyEvent *e)
--
-- RETURNS: void
--
-- NOTES:
-- This function is used to listen to the keypresses and emit a signal to be handled by the event handler.
----------------------------------------------------------------------------------------------------------------------*/

void Session::keyPressEvent(QKeyEvent *e)
{
    qDebug() << e;
    switch (e->key())
    {
    case Qt::Key_Backspace:
    case Qt::Key_Left:
    case Qt::Key_Right:
    case Qt::Key_Up:
    case Qt::Key_Down:
        break;
    default:
        emit getData(e->text().toLocal8Bit());
    }
}
