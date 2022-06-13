#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "addrowdialog.h"
#include "fnmodel.h"
#include "aboutdialog.h"
#include "sortingdialog.h"
#include "descriptiondialog.h"
#include <QFileDialog>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->actionLoad_file, SIGNAL(triggered()), this, SLOT(loadFile()));
    QObject::connect(ui->actionSave_file, SIGNAL(triggered()), this, SLOT(saveFile()));
    QObject::connect(ui->addRowButton, SIGNAL(clicked()), this, SLOT(addRowSlot()));
    QObject::connect(ui->delButton, SIGNAL(clicked()), this, SLOT(deleteRowSlot()));
    QObject::connect(ui->actionStudent_ID, SIGNAL(triggered()), this, SLOT(showAbout()));
    QObject::connect(ui->descAction, SIGNAL(clicked()), this, SLOT(showDescription()));
    QObject::connect(ui->sortAction, SIGNAL(clicked()), this, SLOT(sortByScore()));

    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(_fnModel);

    ui->tableView->setModel(proxyModel);

    proxyModel->sort(0, Qt::AscendingOrder);



}

void MainWindow::sortByScore()
{
    SortingDialog a(proxyModel);
    a.exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showAbout()
{
    aboutDialog a;
    a.exec();
}

void MainWindow::showDescription()
{
    DescriptionDialog d(proxyModel);
    d.exec();
}

void MainWindow::deleteRowSlot()
{
    QModelIndex idx1 = ui->tableView->currentIndex();
    QModelIndex idx4 = proxyModel->mapToSource(idx1);
    _fnModel->removeRow(idx4.row());
}


void MainWindow::loadFile()
{
    delete _fnModel;

    _fnModel = new FnModel(this);
    QString fileName = QFileDialog::getOpenFileName(this, "Open File",
                                                    "../",
                                                    "Data (*.csv)");
    _fnModel->fillDataTableFromFile(fileName);

    proxyModel->setSourceModel(_fnModel);

}


void MainWindow::saveFile()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Open File",
                                                    "../",
                                                    "Data (*.csv)");
    _fnModel->saveDataTableToFile(fileName);

}

void MainWindow::addRowSlot()
{
    AddRowDialog d(this);
    if (d.exec() == QDialog::Accepted)
    {
        _fnModel->appendRow(d.getNewRow());
    }
}
