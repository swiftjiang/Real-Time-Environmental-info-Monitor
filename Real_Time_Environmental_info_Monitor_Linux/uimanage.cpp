#include "uimanage.h"

UIManage::UIManage(QObject *parent) : QObject(parent)
{
    //页面跳转信号关联
    connect(&mainwin,SIGNAL(login()),&maindlg,SLOT(show()));//登录
    connect(&maindlg,SIGNAL(logout()),&mainwin,SLOT(show()));//登出

    connect(&maindlg,SIGNAL(syscfg()),&systemconfig,SLOT(show()));//系统配置
    connect(&maindlg,SIGNAL(warningcfg()),&warningconfig,SLOT(show()));//警报配置
    connect(&maindlg,SIGNAL(cloudcfg()),&cloudconfig,SLOT(show()));//云端配置
    connect(&maindlg,SIGNAL(manageaccount()),&manegeaccount,SLOT(show()));//帐户管理

    connect(&systemconfig,SIGNAL(save()),&maindlg,SLOT(show()));//系统配置保存
    connect(&warningconfig,SIGNAL(save()),&maindlg,SLOT(show()));//警报配置保存
    connect(&cloudconfig,SIGNAL(save()),&maindlg,SLOT(show()));//云端配置保存

    connect(&systemconfig,SIGNAL(cancle()),&maindlg,SLOT(show()));//系统配置界面取消
    connect(&warningconfig,SIGNAL(cancle()),&maindlg,SLOT(show()));//警报配置界面取消
    connect(&cloudconfig,SIGNAL(cancle()),&maindlg,SLOT(show()));//云端配置界面取消
    connect(&manegeaccount,SIGNAL(cancle()),&maindlg,SLOT(show()));//云端配置界面取消



    //键盘
    //登录页面输入
    connect(&mainwin,SIGNAL(keyboard_signal()),&keyboard,SLOT(keyboard_slot()));
    connect(&keyboard,SIGNAL(setData_signal(QString&)),&mainwin,SLOT(getData_slot(QString&)));
    //主页面输入
    connect(&maindlg,SIGNAL(keyboard_signal()),&keyboard,SLOT(keyboard_slot()));
    connect(&keyboard,SIGNAL(setData_signal(QString&)),&maindlg,SLOT(getData_slot(QString&)));
    //系统配置页面
    connect(&systemconfig,SIGNAL(keyboard_signal()),&keyboard,SLOT(keyboard_slot()));
    connect(&keyboard,SIGNAL(setData_signal(QString&)),&systemconfig,SLOT(getData_slot(QString&)));

    //账户管理页面
    connect(&manegeaccount,SIGNAL(keyboard_signal()),&keyboard,SLOT(keyboard_slot()));
    connect(&keyboard,SIGNAL(setData_signal(QString&)),&manegeaccount,SLOT(getData_slot(QString&)));



}

void UIManage::mainwinshow()
{
    this->mainwin.show();
}
