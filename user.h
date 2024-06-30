//定义了User类，是其他三个用户类的基类
#ifndef USER_H
#define USER_H

#include <QDialog>
#include <QFile>

namespace Ui {
class User;
}

class User : public QDialog
{
    Q_OBJECT

public:
    //声明构造函数
    explicit User(QString name, QString account, QString password, QString phone, QString id, QString school, QWidget *parent = nullptr);

    //声明析构函数
    ~User();

    //User类的属性
    QString name;
    QString account;
    QString password;
    QString phone;
    QString id;
    QString school;

private:
    Ui::User *ui;
};
void modifyTextFileContent(const QString &filePath, const QString &oldContent, const QString &newContent);
#endif // USER_H
