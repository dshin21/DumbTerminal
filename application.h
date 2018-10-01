#pragma once

#include <QMainWindow>
#include <physical.h>
#include <QDebug>

class Session;

namespace Ui
{
class Application;
}

class Application : public QMainWindow
{
    Q_OBJECT

  public:
    explicit Application(QWidget *parent = nullptr);
    ~Application();

    void keyPressEvent(QKeyEvent *e);

  signals:
    void getData(const QByteArray &data);

  private:
    Ui::Application *ui;
    Physical *physicalLayer;
    QSerialPort *serialPort;

    void initializeUIConnections();

  private slots:
    void onClickConnect();
    void onClickDisconnect();
    void onClickModify();
    void readFromSerialPort();
    void on_console_textChanged(const QString &arg1);
};
