#include "application.h"
#include "ui_application.h"
#include "configdialog.h"

Application::Application(QWidget *parent)
: QMainWindow(parent), ui(new Ui::Application), serialPort(new QSerialPort("COM1", this))
{
    ui->setupUi(this);
    initializeUIConnections();
    physicalLayer = new Physical;
}

Application::~Application()
{
    delete ui;
}

void Application::initializeUIConnections()
{
    connect(ui->actionConnect, &QAction::triggered, this, &Application::onClickConnect);        //Connect Menu
    connect(ui->actionDisconnect, &QAction::triggered, this, &Application::onClickDisconnect);  //Disconnect Menu
    connect(ui->actionModify_Settings, &QAction::triggered, this, &Application::onClickModify); //Modify Settings Menu
    connect(serialPort, &QSerialPort::readyRead, this, &Application::readFromSerialPort);       //read from serial port
}

void Application::onClickConnect()
{
    physicalLayer->initializeSerialPort(serialPort);
}

void Application::onClickDisconnect()
{
    physicalLayer->deInitializeSerialPort(serialPort);
}

void Application::onClickModify()
{
    ConfigDialog configDialog(nullptr, physicalLayer, serialPort);
    configDialog.setModal(true);
    configDialog.exec();
}

void Application::readFromSerialPort()
{
    QString previousText = ui->incomingConsole->text().append(physicalLayer->readFromSerialPort(serialPort));
    ui->incomingConsole->setText(QString(previousText));
}

void Application::keyPressEvent(QKeyEvent *e)
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

void Application::on_console_textChanged(const QString &text)
{
    QString data = text.at(text.size() - 1);
    physicalLayer->writeToSerialPort(data.toLocal8Bit(),serialPort);
}
