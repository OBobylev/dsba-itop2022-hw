#include "addrowdialog.h"
#include "ui_addrowdialog.h"
#include <QMessageBox>

AddRowDialog::AddRowDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRowDialog)
{
    ui->setupUi(this);

    ui->comboBox->addItem("SHOW", 1);
    ui->comboBox->addItem("MOVIE", 2);

    QObject::connect(ui->okButton, SIGNAL(clicked()), this, SLOT(saveAddedRow()));
    QObject::connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
}

void AddRowDialog::saveAddedRow()
{
    newRow.push_back(ui->titleEdit->text());
    newRow.push_back(ui->desEdit->text());
    newRow.push_back(ui->comboBox->currentText().toInt());
    newRow.push_back(ui->runtBox->value());
    newRow.push_back(ui->yearBox->value());
    newRow.push_back(ui->genEdit->text());
    newRow.push_back(ui->imdbsSpinBox->value());
    newRow.push_back(ui->imdbvBox->value());
    newRow.push_back(ui->tmdbpSpinBox->value());
    newRow.push_back(ui->tmdbsSpinBox->value());


    QMessageBox::warning(this, "Title", "Looooonger Text");

    accept();
}

const QList<QVariant>& AddRowDialog::getNewRow()
{
    return newRow;
}


AddRowDialog::~AddRowDialog()
{
    delete ui;
}
