//实现了Course类，记录课程信息
#include "course.h"

//构造函数，先在course.txt中找到id对应的课程，然后在course-student.txt中找到该课程，统计选课学生数量(即currNum)
Course::Course(QString _id)
{
    currNum = 0;
    QFile file("D:/CourseSelectionSystem/course.txt");
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString line = in.readLine().trimmed();
            QStringList parts = line.split(",");
            if (parts[0] == _id)
            {
                id=_id; name=parts[1]; credit=parts[2].toInt(); teacher=parts[3]; time=parts[4]; address=parts[5]; num=parts[6].toInt();
                QFile _file("D:/CourseSelectionSystem/course-student.txt");
                if(_file.open(QIODevice::ReadOnly))
                {
                    QTextStream _in(&_file);
                    while(!_in.atEnd())
                    {
                        QString _line = _in.readLine().trimmed();
                        QStringList _parts = _line.split(":");
                        if (_parts[0] == _id)
                        {
                            students = _parts[1].split(",");
                            for (QString student : students)
                            {
                                currNum++;
                            }
                        }
                    }
                }
                _file.close();
                break;
            }
        }
    }
    file.close();
}
