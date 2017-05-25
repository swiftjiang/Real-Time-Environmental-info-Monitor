#ifndef SYSTEMCONFIGFILE_H
#define SYSTEMCONFIGFILE_H

#include <QObject>
#include <QString>
#include <QFile>


class SystemConfigFile : public QObject
{
    Q_OBJECT
public:
    explicit SystemConfigFile(QObject *parent = 0);

signals:

public slots:

private:
    //tcp
    QString ip;
    QString port;

    //串口
    QString baudRate;
    QString devName;
    QString readTimeout;
    QString dataBits;
    QString flowControl;
    //

};

#endif // SYSTEMCONFIGFILE_H
