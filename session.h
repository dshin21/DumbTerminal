#pragma once

#include <QMainWindow>
#include <physical.h>
#include <QDebug>

class Session;

namespace Ui
{
class Application;
}

class Session : public QMainWindow
{
    Q_OBJECT

  public:
    explicit Session(QWidget *parent = nullptr);
    ~Session();

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
