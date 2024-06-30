//Student类的头文件，该类继承自User类，当学生登录时打开该类的ui界面
#ifndef STUDENT_H
#define STUDENT_H

#include <QDialog>
#include "user.h"
#include <QFile>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class Student;
}

class Student : public User
{
    Q_OBJECT

public:
    //声明构造函数
    explicit Student(QString name, QString account, QString password, QString phone, QString id, QString school, QWidget *parent = nullptr);

    //声明析构函数
    ~Student();

    //Student类(除继承的属性之外)的属性
    QStringList courses;

    void updateSelectedCoursesTable(const QString& id_, int r);

    void removeFromSelectedCoursesTable(const QString& id_);

private slots:
    //点击更改密码按钮
    void on_changePassword_clicked();
    //点击选课
    void on_selection_clicked();
    //点击退课
    void on_withdraw_clicked();
private:
    Ui::Student *ui;
};

#endif // STUDENT_H
