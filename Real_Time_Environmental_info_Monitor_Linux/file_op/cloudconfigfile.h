#ifndef CLOUDCONFIGFILE_H
#define CLOUDCONFIGFILE_H

#include <QObject>

class CloudConfigFile : public QObject
{
    Q_OBJECT
public:
    explicit CloudConfigFile(QObject *parent = 0);

signals:

public slots:
};

#endif // CLOUDCONFIGFILE_H