//Admin类的头文件，该类继承自User类，当管理员登录时打开该类的ui界面
#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include <QSortFilterProxyModel>
#include "user.h"

namespace Ui {
class Admin;
}

class Admin : public User
{
    Q_OBJECT

public:
    //声明构造函数
    explicit Admin(QString name, QString account, QString password, QString phone, QString id, QString school, QWidget *parent = nullptr);
    void updateTable(QFile &file);
    //声明析构函数
    ~Admin();

private slots:
    //修改课程信息的按钮
    void on_editButton_clicked();

    //增加课程的按钮
    void on_addCourseButton_clicked();

    //删除课程的按钮
    void on_removeCourseBotton_clicked();

    //筛选课程的按钮
    void on_filtterCourseBotton_clicked();

    void on_changePassword_clicked();

private:
    Ui::Admin *ui;
    QSortFilterProxyModel *proxyModel;
};

#endif // ADMIN_H
