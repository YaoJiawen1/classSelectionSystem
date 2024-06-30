//实现了Admin类，该类继承自User类，当管理员登录时打开该类的ui界面
#include "admin.h"
#include "ui_admin.h"
#include "course.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QVBoxLayout>

//构造函数
Admin::Admin(QString _name, QString _account, QString _password, QString _phone, QString _id, QString _school, QWidget *parent)
    : User(_name, _account, _password, _phone, _id, _school, parent)
    , ui(new Ui::Admin)
{
    ui->setupUi(this);

    //设置窗口标题
    setWindowTitle(QString("你好，%1！").arg(name));

    //默认打开时在帮助界面(即tab的index为0)
    ui->tabWidget->setCurrentIndex(0);

    //设置table的表头宽度固定(用户不可调整)
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    //打开course.txt，将课程信息输入“查看课程”tab下的表格中
    QFile file("D:/CourseSelectionSystem/course.txt");
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        int row = 0;
        //添加课程
        connect(ui->addCourse, &QPushButton::clicked, this, &Admin::on_addCourseButton_clicked);
        //读入course.txt
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
            QPushButton* selection = new QPushButton("修改");
            connect(selection, &QPushButton::clicked, this, &Admin::on_editButton_clicked);
            selection->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
            ui->tableWidget->setCellWidget(row,7,selection);
            QPushButton* deletion = new QPushButton("删除");
            connect(deletion, &QPushButton::clicked, this, &Admin::on_removeCourseBotton_clicked);
            deletion->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
            ui->tableWidget->setCellWidget(row,8,deletion);
            ++row;
        }
    }
    file.close();

}

void Admin::on_editButton_clicked()
{
    // 获取发送信号的按钮
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button) return;

    // 获取按钮所在的行
    int row = ui->tableWidget->indexAt(button->pos()).row();

    // 获取当前行的课程信息
    QString id = ui->tableWidget->item(row, 0)->text();
    QString name = ui->tableWidget->item(row, 1)->text();
    QString credit = ui->tableWidget->item(row, 2)->text();
    QString teacher = ui->tableWidget->item(row, 3)->text();
    QString time = ui->tableWidget->item(row, 4)->text();
    QString address = ui->tableWidget->item(row, 5)->text();
    QString num = ui->tableWidget->item(row, 6)->text();
    QStringList parts = num.split('/');
    QString _tmp = parts[0];
    QString part = parts[1];
    // 弹出对话框供用户修改课程信息
    bool ok;
    id = QInputDialog::getText(this, tr("修改课程号"), tr("课程号:"), QLineEdit::Normal, id, &ok);

    name = QInputDialog::getText(this, tr("修改课程名"), tr("课程名:"), QLineEdit::Normal, name, &ok);

    credit = QInputDialog::getText(this, tr("修改学分"), tr("学分:"), QLineEdit::Normal, credit, &ok);

    teacher = QInputDialog::getText(this, tr("修改教师"), tr("教师:"), QLineEdit::Normal, teacher, &ok);

    time = QInputDialog::getText(this, tr("修改时间"), tr("时间:"), QLineEdit::Normal, time, &ok);

    address = QInputDialog::getText(this, tr("修改地点"), tr("地点:"), QLineEdit::Normal, address, &ok);

    part = QInputDialog::getText(this, tr("修改限选人数"), tr("限选人数:"), QLineEdit::Normal, part, &ok);

    // 更新表格中的课程信息
    ui->tableWidget->item(row, 0)->setText(id);
    ui->tableWidget->item(row, 1)->setText(name);
    ui->tableWidget->item(row, 2)->setText(credit);
    ui->tableWidget->item(row, 3)->setText(teacher);
    ui->tableWidget->item(row, 4)->setText(time);
    ui->tableWidget->item(row, 5)->setText(address);
    ui->tableWidget->item(row, 6)->setText(QString("%1/%2").arg(_tmp, part));

    // 更新文件内容
    QFile file("D:/CourseSelectionSystem/course.txt");
    if(file.open(QIODevice::WriteOnly)){
        Admin::updateTable(file);
    }
    else{
        qDebug() << "file no found";
    }
}

void Admin::on_removeCourseBotton_clicked()
{
    // 获取当前选中的行号
    int row = ui->tableWidget->currentRow();
    if (row >= 0) {
        // 弹出确认对话框
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "确认删除", "确认删除该课程信息？", QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            // 用户确认删除，执行删除操作
            qDebug() << "Delete confirmed for row" << row;

            // 直接删除整行
            ui->tableWidget->removeRow(row);

            QMessageBox::information(this, "删除成功", "课程信息已成功删除！");
        } else {
            // 用户取消删除，不执行任何操作
            qDebug() << "Delete canceled.";
        }
    } else {
        QMessageBox::warning(this, "未选择行", "请先选择要删除的课程信息行！");
    }
}

void Admin::on_addCourseButton_clicked(){
    int rowCount = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(rowCount+1);
    bool ok;
    QString id;
    id = QInputDialog::getText(this, tr("添加课程号"), tr("课程号:"), QLineEdit::Normal, id, &ok);
    ui->tableWidget->setItem(rowCount,0,new QTableWidgetItem(id));
    QString name;
    name = QInputDialog::getText(this, tr("添加课程名"), tr("课程名:"), QLineEdit::Normal, name, &ok);
    ui->tableWidget->setItem(rowCount,1,new QTableWidgetItem(name));
    QString credit;
    credit = QInputDialog::getText(this, tr("添加学分"), tr("学分:"), QLineEdit::Normal, credit, &ok);
    ui->tableWidget->setItem(rowCount,2,new QTableWidgetItem(credit));
    QString teacher;
    teacher = QInputDialog::getText(this, tr("添加教师"), tr("教师:"), QLineEdit::Normal, teacher, &ok);
    ui->tableWidget->setItem(rowCount,3,new QTableWidgetItem(teacher));
    QString time;
    time = QInputDialog::getText(this, tr("添加时间"), tr("时间:"), QLineEdit::Normal, time, &ok);
    ui->tableWidget->setItem(rowCount,4,new QTableWidgetItem(time));
    QString address;
    address = QInputDialog::getText(this, tr("添加地点"), tr("地点:"), QLineEdit::Normal, address, &ok);
    ui->tableWidget->setItem(rowCount,5,new QTableWidgetItem(address));
    QString part;
    part = QInputDialog::getText(this, tr("添加限选人数"), tr("限选人数:"), QLineEdit::Normal, part, &ok);
    ui->tableWidget->setItem(rowCount,6,new QTableWidgetItem(QString("%1/%2").arg("0", part)));

    QPushButton* selection = new QPushButton("修改");
    connect(selection, &QPushButton::clicked, this, &Admin::on_editButton_clicked);
    selection->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    ui->tableWidget->setCellWidget(rowCount,7,selection);
    QPushButton* deletion = new QPushButton("删除");
    connect(deletion, &QPushButton::clicked, this, &Admin::on_removeCourseBotton_clicked);
    deletion->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    ui->tableWidget->setCellWidget(rowCount,8,deletion);
    // 更新文件内容
    QFile file("D:/CourseSelectionSystem/course.txt");
    if(file.open(QIODevice::WriteOnly)){
        Admin::updateTable(file);
    }
    else{
        qDebug() << "file no found";
    }
}
void Admin::on_filtterCourseBotton_clicked(){
    // 创建代理模型
    //proxyModel = new QSortFilterProxyModel(this);
    //proxyModel->setSourceModel(ui->tableWidget->model());

    // 创建过滤输入框
    //QLineEdit *filterEdit = new QLineEdit(this);
    //filterEdit->setPlaceholderText("Enter text to filter");

    //QVBoxLayout *layout = new QVBoxLayout(this);
    //layout->addWidget(filterEdit);
    //layout->addWidget(ui->tableWidget);

    // 连接过滤输入框的信号和槽
    //connect(filterEdit, &QLineEdit::textChanged, this, &Admin::filterChanged);

    // 设置默认过滤列
    //proxyModel->setFilterKeyColumn(0); // 默认按第一列过滤

    // 初始更新表格显示数据
    QFile file("D:/CourseSelectionSystem/course.txt");
    if(file.open(QIODevice::WriteOnly)){
        Admin::updateTable(file);
    }
    else{
        qDebug() << "file no found";
    }
}

void Admin::updateTable(QFile &file){
    QTextStream out(&file);
    file.resize(0);

    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        QStringList rowContents;
        for (int col = 0; col < 6; ++col) {
            QTableWidgetItem *item = ui->tableWidget->item(row, col);
            if (item) {
                rowContents << item->text();
            } else {
                rowContents << "";
            }
        }
        QString num = ui->tableWidget->item(row, 6)->text();
        QStringList parts = num.split('/');
        if (parts.size() == 2) {
            rowContents<<parts[1];
        } else {
            qDebug() << "Invalid encoded string format.";
        }
        out << rowContents.join(",") << "\n";
    }

    QMessageBox::information(nullptr, "Success", "File saved successfully");
}
//析构函数
Admin::~Admin()
{
    delete ui;
}

void Admin::on_changePassword_clicked()
{
    QString prevPassword = ui->prevPassword->text();
    QString newPassword = ui->newPassword->text();
    QString confirmPassword = ui->confirmPassword->text();
    if (prevPassword==password&&newPassword==confirmPassword){
        modifyTextFileContent("D:/CourseSelectionSystem/admin.txt",prevPassword, newPassword);
        QMessageBox::information(this,"提示","修改密码成功！");
    }
    else if(prevPassword != password){
        QMessageBox::warning(this,"警告","原密码不正确！");
    }
    else if(newPassword != confirmPassword){
        QMessageBox::warning(this,"警告","新密码与确认密码不符！");
    }
}

