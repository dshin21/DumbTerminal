#ifndef PHYSICAL_H
#define PHYSICAL_H

#include "session.h"

#include <QObject>

#include <QtSerialPort/QSerialPort>

class Physical : public QObject
{
    Q_OBJECT
public:
    explicit Physical(QObject *parent = nullptr);
    Physical(Session sessionLayer);

    struct{
        QString baudRate;
        QString dataBits;
        QString parity;
        QString stopBits;
        QString portName;
    };

    public slots:
    void initializePort();
    void readFromSerialPort();
    void writeFromSerialPort(const QByteArray &data);


private:
    QSerialPort *serialPort;
};

#endif // PHYSICAL_H
