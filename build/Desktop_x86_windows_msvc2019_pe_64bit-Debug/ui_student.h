/********************************************************************************
** Form generated from reading UI file 'student.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENT_H
#define UI_STUDENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Student
{
public:
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QTableWidget *tableWidget;
    QWidget *tab_3;
    QTableWidget *tableWidget_2;
    QWidget *tab_4;
    QLineEdit *prevPassword;
    QLineEdit *newPassword;
    QLineEdit *confirmPassword;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *changePassword;

    void setupUi(QDialog *Student)
    {
        if (Student->objectName().isEmpty())
            Student->setObjectName("Student");
        Student->resize(600, 400);
        tabWidget = new QTabWidget(Student);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 601, 401));
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tableWidget = new QTableWidget(tab_2);
        if (tableWidget->columnCount() < 9)
            tableWidget->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(30, 20, 541, 340));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(59);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        tableWidget_2 = new QTableWidget(tab_3);
        if (tableWidget_2->columnCount() < 7)
            tableWidget_2->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(4, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(5, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(6, __qtablewidgetitem15);
        tableWidget_2->setObjectName("tableWidget_2");
        tableWidget_2->setGeometry(QRect(30, 20, 542, 340));
        tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_2->horizontalHeader()->setDefaultSectionSize(70);
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        prevPassword = new QLineEdit(tab_4);
        prevPassword->setObjectName("prevPassword");
        prevPassword->setGeometry(QRect(220, 80, 221, 31));
        newPassword = new QLineEdit(tab_4);
        newPassword->setObjectName("newPassword");
        newPassword->setGeometry(QRect(220, 140, 221, 31));
        confirmPassword = new QLineEdit(tab_4);
        confirmPassword->setObjectName("confirmPassword");
        confirmPassword->setGeometry(QRect(220, 200, 221, 31));
        label = new QLabel(tab_4);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 80, 101, 31));
        label_2 = new QLabel(tab_4);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(100, 140, 101, 31));
        label_3 = new QLabel(tab_4);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(100, 200, 101, 31));
        changePassword = new QPushButton(tab_4);
        changePassword->setObjectName("changePassword");
        changePassword->setGeometry(QRect(220, 280, 221, 31));
        tabWidget->addTab(tab_4, QString());

        retranslateUi(Student);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Student);
    } // setupUi

    void retranslateUi(QDialog *Student)
    {
        Student->setWindowTitle(QCoreApplication::translate("Student", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Student", "\350\257\276\347\250\213\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Student", "\350\257\276\347\250\213\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Student", "\345\255\246\345\210\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Student", "\346\216\210\350\257\276\346\225\231\345\270\210", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Student", "\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Student", "\345\234\260\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Student", "\351\200\211\350\257\276\344\272\272\346\225\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Student", "\351\200\211\350\257\276", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("Student", "\351\200\200\350\257\276", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Student", "\351\200\211\350\257\276", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("Student", "\350\257\276\347\250\213\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("Student", "\350\257\276\347\250\213\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("Student", "\345\255\246\345\210\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("Student", "\346\216\210\350\257\276\346\225\231\345\270\210", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_2->horizontalHeaderItem(4);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("Student", "\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_2->horizontalHeaderItem(5);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("Student", "\345\234\260\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_2->horizontalHeaderItem(6);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("Student", "\351\200\211\350\257\276\344\272\272\346\225\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("Student", "\346\237\245\347\234\213\351\200\211\350\257\276\347\273\223\346\236\234", nullptr));
        label->setText(QCoreApplication::translate("Student", "\350\276\223\345\205\245\345\216\237\345\257\206\347\240\201", nullptr));
        label_2->setText(QCoreApplication::translate("Student", "\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201", nullptr));
        label_3->setText(QCoreApplication::translate("Student", "\345\206\215\346\254\241\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201", nullptr));
        changePassword->setText(QCoreApplication::translate("Student", "\347\241\256\350\256\244", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("Student", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Student: public Ui_Student {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENT_H
