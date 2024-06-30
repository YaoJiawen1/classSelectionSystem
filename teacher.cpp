//实现Teacher类，该类继承自User类，当教师登录时打开该类的ui界面
#include "teacher.h"
#include "ui_teacher.h"
#include "course.h"
#include <QMessageBox>

//构造函数
Teacher::Teacher(QString _name, QString _account, QString _password, QString _phone, QString _id, QString _school, QWidget *parent)
    : User(_name, _account, _password, _phone, _id, _school, parent)
    , ui(new Ui::Teacher)
{
    ui->setupUi(this);

    //设置窗口标题
    setWindowTitle(QString("你好，%1！").arg(name));

    //默认打开时在帮助界面(即tab的index为0)
    ui->tabWidget->setCurrentIndex(0);

    //设置table的表头宽度固定(用户不可调整)
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    //打开course.txt，将课程信息输入“查看课程”“查看所教课程”tab下的表格中
    QFile file("D:/CourseSelectionSystem/course.txt");
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        int row = 0;
        int row_2 = 0;
        while(!in.atEnd())
        {
            ui->tableWidget->setRowCount(row+1);
            QString line = in.readLine();
            QStringList parts = line.split(',');
            QTableWidgetItem *_id = new QTableWidgetItem(parts[0]);
            QTableWidgetItem *_name = new QTableWidgetItem(parts[1]);
            QTableWidgetItem *_credit = new QTableWidgetItem(parts[2]);
            QTableWidgetItem *_teacher = new QTableWidgetItem(parts[3]);
            QTableWidgetItem *_time = new QTableWidgetItem(parts[4]);
            QTableWidgetItem *_address = new QTableWidgetItem(parts[5]);
            Course *tmp = new Course(parts[0]);
            QString _tmp = QString::number(tmp->currNum);
            QTableWidgetItem *_num = new QTableWidgetItem(QString("%1/%2").arg(_tmp, parts[6]));
            ui->tableWidget->setItem(row,0,_id);
            ui->tableWidget->setItem(row,1,_name);
            ui->tableWidget->setItem(row,2,_credit);
            ui->tableWidget->setItem(row,3,_teacher);
            ui->tableWidget->setItem(row,4,_time);
            ui->tableWidget->setItem(row,5,_address);
            ui->tableWidget->setItem(row,6,_num);
            ++row;

            //如果名字是自己，则加入所教课程的table中
            if(parts[3] == name)
            {
                QTableWidgetItem *_id = new QTableWidgetItem(parts[0]);
                QTableWidgetItem *_name = new QTableWidgetItem(parts[1]);
                QTableWidgetItem *_credit = new QTableWidgetItem(parts[2]);
                QTableWidgetItem *_teacher = new QTableWidgetItem(parts[3]);
                QTableWidgetItem *_time = new QTableWidgetItem(parts[4]);
                QTableWidgetItem *_address = new QTableWidgetItem(parts[5]);
                Course *tmp = new Course(parts[0]);
                QString _tmp = QString::number(tmp->currNum);
                QTableWidgetItem *_num = new QTableWidgetItem(QString("%1/%2").arg(_tmp, parts[6]));

                ui->tableWidget_2->setRowCount(row_2+1);
                ui->tableWidget_2->setItem(row_2,0,_id);
                ui->tableWidget_2->setItem(row_2,1,_name);
                ui->tableWidget_2->setItem(row_2,2,_credit);
                ui->tableWidget_2->setItem(row_2,3,_teacher);
                ui->tableWidget_2->setItem(row_2,4,_time);
                ui->tableWidget_2->setItem(row_2,5,_address);
                ui->tableWidget_2->setItem(row_2,6,_num);
                ++row_2;
            }
        }
    }
    file.close();
}

Teacher::~Teacher()
{
    delete ui;
}

void Teacher::on_changePassword_clicked()
{
    QString prevPassword = ui->prevPassword->text();
    QString newPassword = ui->newPassword->text();
    QString confirmPassword = ui->confirmPassword->text();
    if (prevPassword==password&&newPassword==confirmPassword){
        modifyTextFileContent("D:/CourseSelectionSystem/teacher.txt",prevPassword, newPassword);
        QMessageBox::information(this,"提示","修改密码成功！");
    }
    else if(prevPassword != password){
        QMessageBox::warning(this,"警告","原密码不正确！");
    }
    else if(newPassword != confirmPassword){
        QMessageBox::warning(this,"警告","新密码与确认密码不符！");
    }
}
