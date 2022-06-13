#ifndef DESCRIPTIONDIALOG_H
#define DESCRIPTIONDIALOG_H

#include <QDialog>
#include "fnmodel.h"
#include <QSortFilterProxyModel>

namespace Ui {
class DescriptionDialog;
}

class DescriptionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DescriptionDialog(QSortFilterProxyModel *baseModel = nullptr, QWidget *parent = nullptr);

    ~DescriptionDialog();
    FnModel decModel;
private slots:
    void updateFilter(const QString & text);

private:

    Ui::DescriptionDialog *ui;
    QSortFilterProxyModel *_proxyModel;

};

#endif // DESCRIPTIONDIALOG_H
