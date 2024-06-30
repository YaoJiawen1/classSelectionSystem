#include "filter.h"
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
using namespace Qt;

FilterDialog::FilterDialog(QTableWidget *table, QSortFilterProxyModel *proxyModel, QWidget *parent = nullptr){
    QVBoxLayout *layout = new QVBoxLayout();
    QFormLayout *formLayout = new QFormLayout();

    for (int i = 0; i < tableWidget->columnCount(); ++i) {
        QLineEdit *lineEdit = new QLineEdit(this);
        formLayout->addRow(tableWidget->horizontalHeaderItem(i)->text(), lineEdit);
        connect(lineEdit, &QLineEdit::textChanged, [&proxyModel, i](const QString &text) {
            proxyModel->setFilterKeyColumn(i);
            //proxyModel->setFilterRegExp(QRegExp(text, Qt::CaseInsensitive, QRegExp::FixedString));
        });
    }

    layout->addLayout(formLayout);
    setLayout(layout);
    setWindowTitle("Filter Dialog");
}
