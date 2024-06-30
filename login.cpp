//实现Login类，进入登录界面会打开该类的ui界面
#include "login.h"
#include "ui_login.h"
#include<QMessageBox>
#include<QFile>
#include<QTextStream>
#include<QDebug>
#include<QFileInfo>
#include "student.h"
#include "teacher.h"
#include "admin.h"

//构造函数
Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
}

//析构函数
Login::~Login()
{
    delete ui;
}

//返回
void Login::on_returnButton_clicked()
{
    this->hide();
    MainWindow *m = new MainWindow();
    m->show();
}

//记住密码
void Login::on_showPassword_stateChanged(int arg1)
{
    if(arg1)
        ui->password->setEchoMode(QLineEdit::Normal);
    else
        ui->password->setEchoMode(QLineEdit::Password);
}

//退出
void Login::on_exitButton_clicked()
{
    this->close();
}

//点击登录时，根据所选身份打开对应文件以核验
void Login::on_loginButton_clicked()
{
    QString account = ui->account->text();
    QString password = ui->password->text();
    if(ui->isStudent->isChecked())
    {
        QFile file("D:/CourseSelectionSystem/student.txt");
        if(!file.open(QIODevice::ReadOnly))
        {
            qDebug()<<"fail to open file";
        }
        else
        {
            bool flag = false;
            QTextStream in(&file);
            while (!in.atEnd())
            {
                QString line = in.readLine();
                QStringList parts = line.split(",");
                if (parts[1] == account && parts[2] == password)
                {
                    file.close();
                    this->hide();
                    Student* s = new Student(parts[0], parts[1], parts[2], parts[3], parts[4], parts[5]);
                    s->show();
                    flag = true;
                }
            }
            if(!flag)
            {
                file.close();
                QMessageBox::warning(this,"警告","账号或密码错误！");
            }
        }
    }
    else if(ui->isTeacher->isChecked())
    {
        QFile file("D:/CourseSelectionSystem/teacher.txt");
        if(!file.open(QIODevice::ReadOnly))
        {
            qDebug()<<"fail to open file";
        }
        else
        {
            bool flag = false;
            QTextStream in(&file);
            while (!in.atEnd())
            {
                QString line = in.readLine();
                QStringList parts = line.split(",");
                if (parts[1] == account && parts[2] == password)
                {
                    file.close();
                    this->hide();
                    Teacher* t = new Teacher(parts[0], parts[1], parts[2], parts[3], parts[4], parts[5]);
                    t->show();
                    flag = true;
                }
            }
            if(!flag)
            {
                file.close();
                QMessageBox::warning(this,"警告","账号或密码错误！");
            }
        }
    }
    else if(ui->isAdmin->isChecked())
    {
        QFile file("D:/CourseSelectionSystem/admin.txt");
        if(!file.open(QIODevice::ReadOnly))
        {
            qDebug()<<"fail to open file";
        }
        else
        {
            bool flag = false;
            QTextStream in(&file);
            while (!in.atEnd())
            {
                QString line = in.readLine();
                QStringList parts = line.split(",");
                if (parts[1] == account && parts[2] == password)
                {
                    file.close();
                    this->hide();
                    Admin* a = new Admin(parts[0], parts[1], parts[2], parts[3], parts[4], parts[5]);
                    a->show();
                    flag = true;
                }
            }
            if(!flag)
            {
                file.close();
                QMessageBox::warning(this,"警告","账号或密码错误！");
            }
        }
    }
    else
    {
        QMessageBox::warning(this,"警告","请选择您的身份");
    }
}

