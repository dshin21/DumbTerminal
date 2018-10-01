#include "configdialog.h"
#include "ui_configdialog.h"

ConfigDialog::ConfigDialog(QWidget *parent, Physical *physicalLayer, Session *sessionLayer, QSerialPort *serialPort) 
: QDialog(parent), ui(new Ui::ConfigDialog), physicalLayer(physicalLayer), sessionLayer(sessionLayer), serialPort(serialPort)
{
    ui->setupUi(this);
}

ConfigDialog::~ConfigDialog()
{
    delete ui;
}

void ConfigDialog::on_buttonBox_accepted()
{
    QString baudRate = ui->comboBoxBps->currentText();
    QString dataBits = ui->comboBoxDataBits->currentText();
    QString parity = ui->comboBoxParity->currentText();
    QString stopBits = ui->comboBoxStopBits->currentText();
    QString portName = ui->comboBoxPortName->currentText();

    sessionLayer->modifySerialPort(baudRate, dataBits, parity, stopBits, portName, serialPort);
}
