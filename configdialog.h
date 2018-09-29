#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <QDialog>
#include <qtabwidget.h>

#include "physical.h"
#include "session.h"

namespace Ui {
class ConfigDialog;
}

class ConfigDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConfigDialog(QWidget *parent = nullptr, Physical *physicalLayer = nullptr, Session *sessionLayer = nullptr, QSerialPort *serialPort= nullptr);
    ~ConfigDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ConfigDialog *ui;
    QDialog *configDialog;

    Physical *physicalLayer;
    Session *sessionLayer;
    QSerialPort *serialPort;

};

#endif // CONFIGDIALOG_H
