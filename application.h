#pragma once

#include <QMainWindow>
#include <session.h>




class Session;

namespace Ui {
class Application;
}

class Application : public QMainWindow
{
    Q_OBJECT

public:
    explicit Application(QWidget *parent = nullptr);
    ~Application();

private:
    Ui::Application *ui;
    Session *session;
    QSerialPort *serialPort;

    void initializeUIConnections();

private slots:
    void onClickConnect();
    void onClickDisconnect();
    void onClickModify();



private slots:

};
