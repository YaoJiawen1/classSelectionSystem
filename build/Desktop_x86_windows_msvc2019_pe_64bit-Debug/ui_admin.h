/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

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

class Ui_Admin
{
public:
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QTableWidget *tableWidget;
    QPushButton *addCourse;
    QWidget *tab_4;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *confirmPassword;
    QPushButton *changePassword;
    QLabel *label;
    QLineEdit *newPassword;
    QLineEdit *prevPassword;

    void setupUi(QDialog *Admin)
    {
        if (Admin->objectName().isEmpty())
            Admin->setObjectName("Admin");
        Admin->resize(600, 400);
        tabWidget = new QTabWidget(Admin);
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
        tableWidget->setGeometry(QRect(0, 30, 591, 321));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setColumnCount(9);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(65);
        tableWidget->horizontalHeader()->setHighlightSections(true);
        addCourse = new QPushButton(tab_2);
        addCourse->setObjectName("addCourse");
        addCourse->setGeometry(QRect(0, 0, 151, 31));
        tabWidget->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        label_2 = new QLabel(tab_4);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(110, 130, 101, 31));
        label_3 = new QLabel(tab_4);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(110, 190, 101, 31));
        confirmPassword = new QLineEdit(tab_4);
        confirmPassword->setObjectName("confirmPassword");
        confirmPassword->setGeometry(QRect(230, 190, 221, 31));
        changePassword = new QPushButton(tab_4);
        changePassword->setObjectName("changePassword");
        changePassword->setGeometry(QRect(230, 270, 221, 31));
        label = new QLabel(tab_4);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 70, 101, 31));
        newPassword = new QLineEdit(tab_4);
        newPassword->setObjectName("newPassword");
        newPassword->setGeometry(QRect(230, 130, 221, 31));
        prevPassword = new QLineEdit(tab_4);
        prevPassword->setObjectName("prevPassword");
        prevPassword->setGeometry(QRect(230, 70, 221, 31));
        tabWidget->addTab(tab_4, QString());

        retranslateUi(Admin);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Admin);
    } // setupUi

    void retranslateUi(QDialog *Admin)
    {
        Admin->setWindowTitle(QCoreApplication::translate("Admin", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Admin", "\350\257\276\347\250\213\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Admin", "\350\257\276\347\250\213\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Admin", "\345\255\246\345\210\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Admin", "\346\216\210\350\257\276\346\225\231\345\270\210", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Admin", "\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Admin", "\345\234\260\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Admin", "\351\200\211\350\257\276\344\272\272\346\225\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Admin", "\344\277\256\346\224\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("Admin", "\345\210\240\351\231\244", nullptr));
        addCourse->setText(QCoreApplication::translate("Admin", "\346\267\273\345\212\240\350\257\276\347\250\213\345\210\260\351\200\211\350\257\276\345\210\227\350\241\250\344\270\255", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Admin", "\346\237\245\347\234\213\350\257\276\347\250\213", nullptr));
        label_2->setText(QCoreApplication::translate("Admin", "\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201", nullptr));
        label_3->setText(QCoreApplication::translate("Admin", "\345\206\215\346\254\241\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201", nullptr));
        changePassword->setText(QCoreApplication::translate("Admin", "\347\241\256\350\256\244", nullptr));
        label->setText(QCoreApplication::translate("Admin", "\350\276\223\345\205\245\345\216\237\345\257\206\347\240\201", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("Admin", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Admin: public Ui_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
