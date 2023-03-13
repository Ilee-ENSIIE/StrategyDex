#ifndef POKEDEXMODEL_H
#define POKEDEXMODEL_H

#include <QStandardItemModel>
#include <QObject>

class PokedexModel : public QStandardItemModel
{
    Q_OBJECT
public:
    explicit PokedexModel(QObject *parent = nullptr);


signals:
    void dexProcessed();

private:
    virtual ~PokedexModel() {}
};

#endif // POKEDEXMODEL_H
