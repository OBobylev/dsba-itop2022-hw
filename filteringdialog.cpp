#include "filteringdialog.h"
#include "ui_filteringdialog.h"

FilteringDialog::FilteringDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FilteringDialog)
{
    ui->setupUi(this);
}

FilteringDialog::~FilteringDialog()
{
    delete ui;
}
