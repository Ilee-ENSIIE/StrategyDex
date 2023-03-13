#ifndef POKEMONMOVESETMODEL_H
#define POKEMONMOVESETMODEL_H

#include <QStandardItemModel>
#include "pokedexmodel.h"

class PokemonMovesetModel : public QStandardItemModel
{
    Q_OBJECT
public:
    explicit PokemonMovesetModel(QString Pokemon, QObject *parent = nullptr);
signals:
    gen9ouAvailable();
    gen9ubersAvailable();
    gen9uuAvailable();
    gen9ruAvailable();
    gen9nuAvailable();
    gen9lcAvailable();
};

#endif // POKEMONMOVESETMODEL_H
