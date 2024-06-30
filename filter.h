#ifndef FILTER_H
#define FILTER_H

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTableWidget>
#include <QHeaderView>
#include <QSortFilterProxyModel>
#include <QLineEdit>
#include <QDialog>
#include <QFormLayout>

class FilterDialog : public QDialog {
    Q_OBJECT
public:
    FilterDialog(QTableWidget *table, QSortFilterProxyModel *proxyModel, QWidget *parent);
private:
    QTableWidget *tableWidget;
    QSortFilterProxyModel *proxyModel;
};

#endif // FILTER_H
