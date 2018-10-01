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

void Session::initializeUIConnections()
{
    connect(ui->actionConnect, &QAction::triggered, this, &Session::onClickConnect);        //Connect Menu
    connect(ui->actionDisconnect, &QAction::triggered, this, &Session::onClickDisconnect);  //Disconnect Menu
    connect(ui->actionModify_Settings, &QAction::triggered, this, &Session::onClickModify); //Modify Settings Menu
    connect(serialPort, &QSerialPort::readyRead, this, &Session::readFromSerialPort);       //read from serial port
}

void Session::onClickConnect()
{
    physicalLayer->initializeSerialPort(serialPort);
}

void Session::onClickDisconnect()
{
    physicalLayer->deInitializeSerialPort(serialPort);
}

void Session::onClickModify()
{
    ConfigDialog configDialog(nullptr, physicalLayer, serialPort);
    configDialog.setModal(true);
    configDialog.exec();
}

void Session::readFromSerialPort()
{
    QString previousText = ui->incomingConsole->text().append(physicalLayer->readFromSerialPort(serialPort));
    ui->incomingConsole->setText(QString(previousText));
}

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

void Session::on_console_textChanged(const QString &text)
{
    QString data = text.at(text.size() - 1);
    physicalLayer->writeToSerialPort(data.toLocal8Bit(),serialPort);
}
