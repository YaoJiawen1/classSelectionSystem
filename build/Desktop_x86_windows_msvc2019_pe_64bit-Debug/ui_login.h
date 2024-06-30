/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QRadioButton *isStudent;
    QRadioButton *isTeacher;
    QRadioButton *isAdmin;
    QLineEdit *account;
    QLineEdit *password;
    QLabel *label;
    QLabel *label_2;
    QPushButton *returnButton;
    QCheckBox *showPassword;
    QPushButton *loginButton;
    QPushButton *exitButton;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(640, 480);
        QFont font;
        font.setPointSize(16);
        Login->setFont(font);
        isStudent = new QRadioButton(Login);
        isStudent->setObjectName("isStudent");
        isStudent->setGeometry(QRect(140, 110, 91, 18));
        QFont font1;
        font1.setPointSize(12);
        isStudent->setFont(font1);
        isTeacher = new QRadioButton(Login);
        isTeacher->setObjectName("isTeacher");
        isTeacher->setGeometry(QRect(250, 110, 91, 18));
        isTeacher->setFont(font1);
        isAdmin = new QRadioButton(Login);
        isAdmin->setObjectName("isAdmin");
        isAdmin->setGeometry(QRect(360, 110, 111, 18));
        isAdmin->setFont(font1);
        account = new QLineEdit(Login);
        account->setObjectName("account");
        account->setGeometry(QRect(190, 170, 311, 41));
        account->setInputMethodHints(Qt::ImhHiddenText);
        password = new QLineEdit(Login);
        password->setObjectName("password");
        password->setGeometry(QRect(190, 240, 311, 41));
        password->setMaxLength(20);
        password->setEchoMode(QLineEdit::Password);
        password->setClearButtonEnabled(false);
        label = new QLabel(Login);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 170, 81, 41));
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(Login);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(110, 240, 81, 41));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);
        returnButton = new QPushButton(Login);
        returnButton->setObjectName("returnButton");
        returnButton->setGeometry(QRect(0, 0, 81, 41));
        returnButton->setFont(font1);
        showPassword = new QCheckBox(Login);
        showPassword->setObjectName("showPassword");
        showPassword->setGeometry(QRect(510, 250, 71, 20));
        QFont font2;
        font2.setPointSize(8);
        showPassword->setFont(font2);
        loginButton = new QPushButton(Login);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(190, 340, 311, 51));
        exitButton = new QPushButton(Login);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(80, 0, 81, 41));
        exitButton->setFont(font1);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
        isStudent->setText(QCoreApplication::translate("Login", "\346\210\221\346\230\257\345\255\246\347\224\237", nullptr));
        isTeacher->setText(QCoreApplication::translate("Login", "\346\210\221\346\230\257\350\200\201\345\270\210", nullptr));
        isAdmin->setText(QCoreApplication::translate("Login", "\346\210\221\346\230\257\347\256\241\347\220\206\345\221\230", nullptr));
        account->setPlaceholderText(QCoreApplication::translate("Login", "\350\257\267\350\276\223\345\205\245\345\255\246\345\217\267/\350\264\246\345\217\267", nullptr));
        password->setPlaceholderText(QCoreApplication::translate("Login", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        label->setText(QCoreApplication::translate("Login", "\345\255\246\345\217\267/\350\264\246\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "\345\257\206\347\240\201", nullptr));
        returnButton->setText(QCoreApplication::translate("Login", "\350\277\224\345\233\236", nullptr));
        showPassword->setText(QCoreApplication::translate("Login", "\346\230\276\347\244\272\345\257\206\347\240\201", nullptr));
        loginButton->setText(QCoreApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
        exitButton->setText(QCoreApplication::translate("Login", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
