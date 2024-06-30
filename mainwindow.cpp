//主窗口
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <login.h>

//构造函数
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

//析构函数
MainWindow::~MainWindow()
{
    delete ui;
}
//退出
void MainWindow::on_exitButton_clicked()
{
    this->close();
}

//登录
void MainWindow::on_loginButton_clicked()
{
    this->hide();
    Login* loginWindow = new Login();
    loginWindow->show();
}

