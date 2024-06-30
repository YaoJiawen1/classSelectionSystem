//实现User类，它是其他三个类的基类
#include "user.h"
#include "ui_user.h"

//构造函数
User::User(QString _name, QString _account, QString _password, QString _phone, QString _id, QString _school, QWidget *parent)
    : QDialog(parent), name(_name), account(_account), password(_password), phone(_phone), id(_id), school(_school)
    , ui(new Ui::User)
{
    ui->setupUi(this);
}
void modifyTextFileContent(const QString &filePath, const QString &oldContent, const QString &newContent) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        // 处理文件打开失败的情况
        qDebug() << "Failed to open file:" << filePath;
        return;
    }

    // 读取文件的全部内容
    QTextStream in(&file);
    QString originalContent = in.readAll();

    // 替换特定内容
    QString modifiedContent = originalContent.replace(oldContent, newContent);

    // 将文件指针重置到文件开头以便重新写入
    file.seek(0);

    // 写入修改后的内容
    QTextStream out(&file);
    out << modifiedContent;

    file.close();
}
User::~User()
{
    delete ui;
}
