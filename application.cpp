#include "application.h"
#include "ui_application.h"
#include "configdialog.h"

Application::Application(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Application),
    serialPort(new QSerialPort("COM1", this))
{
    ui->setupUi(this);
    setCentralWidget(ui->console);
    initializeUIConnections();

    physicalLayer = new Physical;
    sessionLayer = new Session;
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
}

void Application::onClickConnect()
{
    sessionLayer->connectSerialPort(serialPort);
}

void Application::onClickDisconnect()
{
    sessionLayer->disconnectSerialPort();
}

void Application::onClickModify()
{
    ConfigDialog configDialog(nullptr, physicalLayer);
    configDialog.setModal(true);
    configDialog.exec();
}


