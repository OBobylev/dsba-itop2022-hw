#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "fnmodel.h"
#include <QSortFilterProxyModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void loadFile();
    void saveFile();
    void addRowSlot();
    void deleteRowSlot();
    void showAbout();
    void showDescription();
    void sortByScore();

private:
    size_t _shownDetailsColumn;
    FnModel *_fnModel;
    QSortFilterProxyModel *proxyModel;
    QSortFilterProxyModel *proxyModel2;
    //CustomProxyModel *proxyModelFare;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
