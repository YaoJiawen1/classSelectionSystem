//实现Student类，该类继承自User类，当学生登录时打开该类的ui界面
#include "student.h"
#include "ui_student.h"
#include "course.h"
#include <QMessageBox>

//构造函数
Student::Student(QString _name, QString _account, QString _password, QString _phone, QString _id, QString _school, QWidget *parent)
    : User(_name, _account, _password, _phone, _id, _school, parent)
    , ui(new Ui::Student)
{
    ui->setupUi(this);

    //设置窗口标题
    setWindowTitle(QString("你好，%1！").arg(name));

    //默认打开时在帮助界面(即tab的index为0)
    ui->tabWidget->setCurrentIndex(0);

    //设置table的表头宽度固定(用户不可调整)
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    //打开course.txt，将课程信息输入“选课”tab下的表格中
    QFile file("D:/CourseSelectionSystem/course.txt");
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        int row = 0;
        while(!in.atEnd())
        {
            ui->tableWidget->setRowCount(row+1);
            QString line = in.readLine().trimmed();
            if(!line.isEmpty())
            {
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
                QPushButton* selection = new QPushButton("选课");
                QPushButton* withdraw = new QPushButton("退课");
                connect(selection, &QPushButton::clicked, this, &Student::on_selection_clicked);
                connect(withdraw, &QPushButton::clicked, this, &Student::on_withdraw_clicked);
                selection->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
                selection->setProperty("row", row);
                withdraw->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
                withdraw->setProperty("row", row);
                ui->tableWidget->setCellWidget(row, 7, selection);
                ui->tableWidget->setCellWidget(row, 8, withdraw);
                ++row;
            }
        }
    }
    file.close();

    QFile file_2("D:/CourseSelectionSystem/course-student.txt");
    if(file_2.open(QIODevice::ReadOnly))
    {
        QTextStream in_2(&file_2);
        int row_2 = 0;
        while(!in_2.atEnd())
        {
            QString line = in_2.readLine().trimmed();
            if(!line.isEmpty())
            {
                QStringList parts = line.split(':');
                QStringList stu = parts[1].split(',');
                bool select = false;
                for(int i = 0; i < stu.size(); ++i)
                {
                    if(stu[i] == _account)
                    {
                        ui->tableWidget_2->setRowCount(row_2 + 1);
                        select = true;
                        Course* tmp = new Course(parts[0]);
                        QTableWidgetItem *_id = new QTableWidgetItem(tmp->id);
                        QTableWidgetItem *_name = new QTableWidgetItem(tmp->name);
                        QTableWidgetItem *_credit = new QTableWidgetItem(QString::number(tmp->credit));
                        QTableWidgetItem *_teacher = new QTableWidgetItem(tmp->teacher);
                        QTableWidgetItem *_time = new QTableWidgetItem(tmp->time);
                        QTableWidgetItem *_address = new QTableWidgetItem(tmp->address);
                        QString _tmp = QString::number(tmp->currNum);
                        QTableWidgetItem *_num = new QTableWidgetItem(QString("%1/%2").arg(_tmp, QString::number(tmp->num)));
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
                if(!select)
                    continue;
            }
        }
    }
    file_2.close();
}

Student::~Student()
{
    delete ui;
}

bool containsTextInFile(const QString &fileName, const QString &searchText) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false; // 无法打开文件
    }

    QTextStream in(&file);
    QString line;
    while (!in.atEnd()) {
        line = in.readLine();
        if (line.contains(searchText)) {
            file.close();
            return true; // 找到文本
        }
    }

    file.close();
    return false; // 未找到文本
}

// 选课功能
void Student::on_selection_clicked() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button) {
        int row = button->property("row").toInt();
        QTableWidgetItem* item0 = ui->tableWidget->item(row, 0);
        if (item0) {
            QString id_ = item0->text();

            // 读取文件内容
            QFile file("D:/CourseSelectionSystem/course-student.txt");
            if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
                qDebug() << "无法打开文件";
                return;
            }

            QTextStream in(&file);
            QStringList lines;
            bool idFound = false;
            while (!in.atEnd()) {
                QString line = in.readLine();
                if (line.startsWith(id_ + ":")) {
                    // ID 已存在，添加新的 account
                    line += "," + account;
                    idFound = true;
                }
                lines << line;
            }

            if (!idFound) {
                // ID 不存在，添加新行
                lines << id_ + ":" + account;
            }

            // 清空文件并重新写入
            file.resize(0);
            file.seek(0);
            QTextStream out(&file);
            for (const QString &line : lines) {
                out << line << Qt::endl;
            }

            file.close();

            // 更新已选课程表格
            updateSelectedCoursesTable(id_, row);
        }
    }
}

//退课功能
void Student::on_withdraw_clicked() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button) {
        int row = button->property("row").toInt();
        QTableWidgetItem* item0 = ui->tableWidget->item(row, 0);
        if (item0) {
            QString id_ = item0->text();

            // 读取文件内容
            QFile file("D:/CourseSelectionSystem/course-student.txt");
            if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
                qDebug() << "无法打开文件";
                return;
            }

            QTextStream in(&file);
            QStringList lines;
            bool courseRemoved = false;
            while (!in.atEnd()) {
                QString line = in.readLine();
                if (line.startsWith(id_ + ":")) {
                    QStringList parts = line.split(":");
                    QStringList accounts = parts[1].split(",");
                    accounts.removeAll(account);
                    if (!accounts.isEmpty()) {
                        line = parts[0] + ":" + accounts.join(",");
                        lines << line;
                    } else {
                        courseRemoved = true;
                    }
                } else {
                    lines << line;
                }
            }

            // 清空文件并重新写入
            file.resize(0);
            file.seek(0);
            QTextStream out(&file);
            for (const QString &line : lines) {
                out << line << Qt::endl;
            }

            file.close();

            // 更新 TableWidget 中的课程人数
            QTableWidgetItem* numItem = ui->tableWidget->item(row, 6);
            if (numItem) {
                QString numText = numItem->text();
                QStringList numParts = numText.split("/");
                if (numParts.size() == 2) {
                    int currNum = numParts[0].toInt();
                    int maxNum = numParts[1].toInt();
                    currNum = qMax(0, currNum - 1); // 确保不会小于0
                    numItem->setText(QString("%1/%2").arg(currNum).arg(maxNum));
                }
            }

            removeFromSelectedCoursesTable(id_);
        }
    }
}



// 辅助函数：从已选课程表格中移除课程
void Student::removeFromSelectedCoursesTable(const QString& id_) {
    for (int i = 0; i < ui->tableWidget_2->rowCount(); ++i) {
        if (ui->tableWidget_2->item(i, 0)->text() == id_) {
            ui->tableWidget_2->removeRow(i);
            break;
        }
    }
}

// 辅助函数：更新已选课程表格
void Student::updateSelectedCoursesTable(const QString& id_, int r) {
    QFile _file("D:/CourseSelectionSystem/course.txt");
    if (_file.open(QIODevice::ReadOnly)) {
        QTextStream in(&_file);
        int row_2 = ui->tableWidget_2->rowCount();
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split(',');
            if (id_ == parts[0]) {
                ui->tableWidget_2->setRowCount(row_2 + 1);
                for (int i = 0; i < 6; ++i) {
                    QTableWidgetItem *item = new QTableWidgetItem(parts[i]);
                    ui->tableWidget_2->setItem(row_2, i, item);
                }
                Course *tmp = new Course(parts[0]);
                QString _tmp = QString::number(tmp->currNum);
                QTableWidgetItem *_num = new QTableWidgetItem(QString("%1/%2").arg(_tmp, parts[6]));
                QTableWidgetItem *_num_2 = new QTableWidgetItem(QString("%1/%2").arg(_tmp, parts[6]));
                ui->tableWidget_2->setItem(row_2, 6, _num);
                ui->tableWidget->setItem(r, 6, _num_2);
                delete tmp;
                break;
            }
        }
    }
    _file.close();
}

void Student::on_changePassword_clicked()
{
    QString prevPassword = ui->prevPassword->text();
    QString newPassword = ui->newPassword->text();
    QString confirmPassword = ui->confirmPassword->text();
    if (prevPassword==password&&newPassword==confirmPassword){
        modifyTextFileContent("D:/CourseSelectionSystem/student.txt",prevPassword, newPassword);
        QMessageBox::information(this,"提示","修改密码成功！");
    }
    else if(prevPassword != password){
        QMessageBox::warning(this,"警告","原密码不正确！");
    }
    else if(newPassword != confirmPassword){
        QMessageBox::warning(this,"警告","新密码与确认密码不符！");
    }
}

