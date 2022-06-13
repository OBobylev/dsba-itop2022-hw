#include "sortingdialog.h"
#include "ui_sortingdialog.h"

SortingDialog::SortingDialog(QSortFilterProxyModel *baseModel, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SortingDialog)
{
    ui->setupUi(this);
    _proxyModel = baseModel;
    QObject::connect(ui->scoreButton, SIGNAL(clicked()), this, SLOT(sortByScore()));
    QObject::connect(ui->popButton, SIGNAL(clicked()), this, SLOT(sortByPop()));
}

void SortingDialog::sortByPop()
{
    _proxyModel->sort(8, Qt::AscendingOrder);
}

void SortingDialog::sortByScore()
{
    _proxyModel->sort(6, Qt::DescendingOrder);
}

SortingDialog::~SortingDialog()
{
    _proxyModel->setFilterKeyColumn(0);
    delete ui;
}
