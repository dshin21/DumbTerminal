#pragma once

#include "helpdialog.h"

#include <QMainWindow>
#include <physical.h>
#include <QDebug>
#include <QLabel>

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
    QLabel *status = nullptr;
    void initializeUIConnections();
    void showStatusMessage(const QString &message);

  private slots:
    void onClickConnect();
    void onClickDisconnect();
    void onClickModify();
    void onClickHelp();
    void readFromSerialPort();
    void on_console_textChanged(const QString &arg1);
};
