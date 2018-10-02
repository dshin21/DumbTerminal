/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: session.cpp - An application that displays two text windows (INCOMING & SENDING) and UI components
--                            used for the Dumb Terminal Emulator.
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
--      void showStatusMessage(const QString &message);
--      void onClickHelp();
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
-- the serial port.
-- It listens to keypress events from the SENDING QLineEdit and interacts with the Phyiscal layer to transmit the text to 
-- the serial port. Furthermore, it simultaneously receives the charcters from the serial port processed by the physical layer
-- and displays them on to the INCOMING QLineEdit.
-- The session layer is also responsible for the UI components of Qt such as the menu items (QMenu) and the status bar (QLabel).
----------------------------------------------------------------------------------------------------------------------*/

#include "session.h"
#include "ui_application.h"
#include "configdialog.h"

Session::Session(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Application), serialPort(new QSerialPort("COM1", this)), status(new QLabel)
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
    connect(ui->actionHelp, &QAction::triggered, this, &Session::onClickHelp);
    ui->statusBar->addWidget(status);
    showStatusMessage("Command Mode (Modify port settings)");
    status->setStyleSheet("QLabel { background-color : red; color : blue; }");
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
    if(physicalLayer->initializeSerialPort(serialPort)){
        status->setStyleSheet("QLabel { background-color : green; color : blue; }");
        showStatusMessage("Connect Mode (ESC to return to Command Mode)");
    }

    qDebug() << "Bit Rate: " <<serialPort->baudRate();
    qDebug() << "Data Bits: " <<serialPort->dataBits();
    qDebug() << "Parity: " <<serialPort->parity();
    qDebug() << "Stop Bits: " <<serialPort->stopBits();
    qDebug() << "Port Name: " <<serialPort->portName();
    qDebug() << "Port already opened";

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
    if(physicalLayer->deInitializeSerialPort(serialPort)){
        showStatusMessage("Command Mode (Modify port settings)");
        status->setStyleSheet("QLabel { background-color : red; color : blue; }");
    }
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
    if(status->text() == "Connect Mode (ESC to return to Command Mode)"){
        showStatusMessage("Command Mode (Modify port settings)");
        status->setStyleSheet("QLabel { background-color : red; color : blue; }");
    }
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
    case Qt::Key_Escape:
        if(status->text() == "Connect Mode (ESC to return to Command Mode)"){
            physicalLayer->deInitializeSerialPort(serialPort);
            showStatusMessage("Command Mode (Modify port settings)");
            status->setStyleSheet("QLabel { background-color : red; color : blue; }");
        }
        break;
    default:
        emit getData(e->text().toLocal8Bit());
    }
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: showStatusMessage
--
-- DATE: September 29, 2018
--
-- REVISIONS: None
--
-- DESIGNER: Daniel Shin
--
-- PROGRAMMER: Daniel Shin
--
-- INTERFACE: void showStatusMessage(const QString &message)
--
-- RETURNS: void
--
-- NOTES:
-- This function is used to change the status message to indicate the mode (state) of the emulator.
----------------------------------------------------------------------------------------------------------------------*/

void Session::showStatusMessage(const QString &message)
{
    status->setText(message);
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: showStatusMessage
--
-- DATE: September 29, 2018
--
-- REVISIONS: None
--
-- DESIGNER: Daniel Shin
--
-- PROGRAMMER: Daniel Shin
--
-- INTERFACE: void showStatusMessage(const QString &message)
--
-- RETURNS: void
--
-- NOTES:
-- This function is used to change the status message to indicate the mode (state) of the emulator.
----------------------------------------------------------------------------------------------------------------------*/

void Session::onClickHelp()
{
    HelpDialog helpDialog;
    helpDialog.setModal(true);
    helpDialog.exec();
}
