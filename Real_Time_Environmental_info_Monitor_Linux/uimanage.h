#ifndef UIMANAGE_H
#define UIMANAGE_H

#include <QObject>
#include "mainwindow.h"
#include "ui/cloudconfigdlg.h"
#include "ui/maindlg.h"
#include "ui/systemconfigdlg.h"
#include "ui/warningconfigdlg.h"
#include "ui/manageaccountdlg.h"
#include "keyboard/keyboard.h"

class UIManage : public QObject
{
    Q_OBJECT
public:
    explicit UIManage(QObject *parent = 0);

    void mainwinshow();

signals:

public slots:


private:
    MainWindow mainwin;

    MainDlg maindlg;

    CloudConfigDlg cloudconfig;
    SystemConfigDlg systemconfig;
    WarningConfigDlg warningconfig;
    ManageAccountDlg manegeaccount;

    KeyBoard keyboard;

};

#endif // UIMANAGE_H

