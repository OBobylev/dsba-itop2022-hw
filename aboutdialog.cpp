#include "aboutdialog.h"
#include "ui_aboutdialog.h"

aboutDialog::aboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aboutDialog)
{
    ui->setupUi(this);
}

void aboutDialog::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen;
    pen.setWidth(20);
    pen.setColor(Qt::red);
    painter.setPen(pen);
    painter.setBrush(Qt::green);
    painter.drawEllipse(50,50, 125, 125);
    QWidget::paintEvent(event);
}

aboutDialog::~aboutDialog()
{
    delete ui;
}
