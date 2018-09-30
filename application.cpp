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

    sessionLayer = new Session;
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
    connect(serialPort, &QSerialPort::readyRead, this, &Application::readFromSerialPort);
//    connect(ui->console, &Application::getData, this, &Application::writeToSerialPort);
}

void Application::onClickConnect()
{
    sessionLayer->connectSerialPort(serialPort);
}

void Application::onClickDisconnect()
{
    sessionLayer->disconnectSerialPort(serialPort);
}

void Application::onClickModify()
{
    ConfigDialog configDialog(nullptr, physicalLayer, sessionLayer, serialPort);
    configDialog.setModal(true);
    configDialog.exec();
}

void Application::readFromSerialPort(){
    ui->console->setText(QString(sessionLayer->readFromSerialPort(serialPort)));
}

void Application::writeToSerialPort(const QByteArray &data)
{
    serialPort->write(data);
    qDebug() << "wrote";
}

void Application::keyPressEvent(QKeyEvent *e)
{
    qDebug() << e;
    switch (e->key()) {
    case Qt::Key_Backspace:
    case Qt::Key_Left:
    case Qt::Key_Right:
    case Qt::Key_Up:
    case Qt::Key_Down:
        break;
    default:
            keyPressEvent(e);
        emit getData(e->text().toLocal8Bit());
    }
}



void Application::on_console_textChanged(const QString &arg1)
{
//    qDebug() << arg1;
    serialPort->write(arg1.toLocal8Bit());
}
