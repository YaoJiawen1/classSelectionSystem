//Course类的头文件，记录了课程的信息
#ifndef COURSE_H
#define COURSE_H

#include <QString>
#include <QFile>
#include <QTextStream>

class Course
{
public:
    //声明构造函数
    Course(QString _id);

    //下面是Course拥有的属性
    QString id;
    QString name;
    int credit;
    QString teacher;
    QString time;
    QString address;
    int num;//限选人数
    int currNum;//已选人数
    QStringList students;//选课学生
};

#endif // COURSE_H
