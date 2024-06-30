//Login类的头文件，进入登录界面会打开该类的ui界面
#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <mainwindow.h>
#include<QButtonGroup>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    //声明构造函数
    explicit Login(QWidget *parent = nullptr);

    //声明析构函数
    ~Login();

private slots:
    //点击返回按钮
    void on_returnButton_clicked();

    //显示密码按钮状态改变(即被选中与否)
    void on_showPassword_stateChanged(int arg1);

    //点击退出按钮
    void on_exitButton_clicked();

    //点击登录按钮
    void on_loginButton_clicked();


private:
    Ui::Login *ui;
};

#endif // LOGIN_H
