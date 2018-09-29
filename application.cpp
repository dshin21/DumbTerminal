#include "application.h"
#include "ui_application.h"

Application::Application(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Application),
    serialPort(new QSerialPort)
{
    ui->setupUi(this);
    initializeUIConnections();

}

Application::~Application()
{
    delete ui;
}

void Application::initializeUIConnections()
{
    connect(ui->actionConnect, &QAction::triggered, this, &Application::onClickConnect);
}

void Application::onClickConnect()
{
    session->connectSerialPort(serialPort);
}

void Application::onClickDisconnect()
{
    session->disconnectSerialPort(serialPort);
}

void Application::onClickModify()
{
//    session->modifySerialPortSettings(serialPort);
}


