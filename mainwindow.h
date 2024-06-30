//主窗口类，即程序运行最开始的界面
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //点击退出按钮
    void on_exitButton_clicked();

    //点击登录按钮
    void on_loginButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
