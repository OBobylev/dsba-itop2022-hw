#ifndef SORTINGDIALOG_H
#define SORTINGDIALOG_H

#include <QDialog>
#include <QSortFilterProxyModel>

namespace Ui {
class SortingDialog;
}

class SortingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SortingDialog(QSortFilterProxyModel *baseModel, QWidget *parent = nullptr);
    ~SortingDialog();

private slots:
    void sortByPop();
    void sortByScore();

private:
    Ui::SortingDialog *ui;
    QSortFilterProxyModel *_proxyModel;
};

#endif // SORTINGDIALOG_H
