#ifndef FILTERINGDIALOG_H
#define FILTERINGDIALOG_H

#include <QDialog>

namespace Ui {
class FilteringDialog;
}

class FilteringDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FilteringDialog(QWidget *parent = nullptr);
    ~FilteringDialog();

private:
    Ui::FilteringDialog *ui;
};

#endif // FILTERINGDIALOG_H
