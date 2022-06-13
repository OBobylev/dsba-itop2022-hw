#include "descriptiondialog.h"
#include "ui_descriptiondialog.h"
#include "fnmodel.h"


DescriptionDialog::DescriptionDialog(QSortFilterProxyModel *baseModel, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DescriptionDialog)
{
    ui->setupUi(this);
    QObject::connect(ui->lineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(updateFilter( const QString &)));

    _proxyModel = baseModel;
    ui->tableView->setModel(_proxyModel);
    ui->tableView->hideColumn(0);
    ui->tableView->hideColumn(3);
    ui->tableView->hideColumn(4);
    ui->tableView->hideColumn(5);
    ui->tableView->hideColumn(6);
    ui->tableView->hideColumn(7);
    ui->tableView->hideColumn(8);
    ui->tableView->hideColumn(9);


}


void DescriptionDialog::updateFilter(const QString & text)
{
   _proxyModel->setFilterRegularExpression(QRegularExpression(text));
}

DescriptionDialog::~DescriptionDialog()
{
    _proxyModel->setFilterRegularExpression("");
    delete ui;
}
