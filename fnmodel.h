#ifndef FNMODEL_H
#define FNMODEL_H
#include <QVariant>
#include <QAbstractTableModel>


class FnModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit FnModel(QObject *parent = nullptr);


    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;
    void fillDataTableFromFile(QString path);
    void saveDataTableToFile(QString path);
    void appendRow(const QList<QVariant> &row);
    void removeRow(int idx);

    QList<QList<QVariant>> dataTable;
    QList<QString> headerList;
};

#endif // FNMODEL_H
