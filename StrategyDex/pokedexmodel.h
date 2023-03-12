#ifndef POKEDEXMODEL_H
#define POKEDEXMODEL_H

#include <QStandardItemModel>
#include <QObject>

class PokedexModel : public QStandardItemModel
{
    Q_OBJECT
public:
    explicit PokedexModel(QObject *parent = nullptr);
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value,int role);

signals:
    void dexProcessed();

private:
    virtual ~PokedexModel() {}
};

#endif // POKEDEXMODEL_H
