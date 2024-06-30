//Teacher类的头文件，该类继承自User类，当教师登录时打开该类的ui界面
#ifndef TEACHER_H
#define TEACHER_H

#include <QDialog>
#include "user.h"
#include <QMessageBox>

namespace Ui {
class Teacher;
}

class Teacher : public User
{
    Q_OBJECT

public:
    //声明构造函数
    explicit Teacher(QString name, QString account, QString password, QString phone, QString id, QString school, QWidget *parent = nullptr);

    //声明析构函数
    ~Teacher();

    //Teacher类(除继承的属性之外)的属性
    QStringList courses;

private slots:
    void on_changePassword_clicked();

private:
    Ui::Teacher *ui;
};
#endif // TEACHER_H
