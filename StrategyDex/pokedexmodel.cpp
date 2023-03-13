#include "pokedexmodel.h"
#include "filedownloader.h"
#include <QDebug>
#include <QVariant>
#include <QColor>
#include <QIcon>
#include <QFile>
#include <QStandardItem>
#include <iostream>
#include <filesystem>

PokedexModel::PokedexModel(QObject *parent)
    : QStandardItemModel{parent}
{
    //Root item pour le model
    QStandardItem* parentItem = invisibleRootItem();

    //Url nécessaire pour télécharger le fichier pokédex
    QUrl url(QString("https://le-gal.iiens.net/paldean.txt"));
    auto dexDownloader = new FileDownloader(url, this);

    //On définit le comportement lorsque les données brutes ont été téléchargées
    connect(dexDownloader,&FileDownloader::downloaded,[dexDownloader,parentItem,this](){
        //On peuple les entrées avec le fichier téléchargé
        QStringList pokedex = QString(dexDownloader->downloadedData()).split("\r\n");
        for(auto pokemon : pokedex) {
            QStandardItem* newEntry = new QStandardItem(pokemon);
            parentItem->appendRow(newEntry);
        }
        emit dexProcessed();
    });

    //On ajoute les icones pour chaque entrée
    connect(this,&PokedexModel::dexProcessed,[this](){
        QStandardItem* parentItem = invisibleRootItem();
        for(int i=0;i<parentItem->rowCount();i++){
            auto currentItem = parentItem->child(i);
            QString pokemon = currentItem->data(Qt::DisplayRole).toString();
            QString trimmedPokemon = pokemon.toLower().remove(" ").remove("'").remove(".").remove(":").remove("-");
            //Si on trouve une Icone dans nos fichiers on l'utilise
            if(std::filesystem::exists("datas/"+trimmedPokemon.toStdString()+".png")) {
                std::string name="datas/"+trimmedPokemon.toStdString()+".png";
                QImage img;
                img.load(QString(name.c_str()));
                currentItem->setData(QIcon(name.c_str()),Qt::DecorationRole);
            }
            //Sinon on télécharge ladite icone puis on l'utilise
            else{
                QUrl url = "https://play.pokemonshowdown.com/sprites/dex/"+trimmedPokemon+".png";
                auto iconDownloader = new FileDownloader(url, this);
                connect(iconDownloader,&FileDownloader::downloaded,[=,&url](){
                    QPixmap pixmap;
                    if(!iconDownloader->downloadedData().isEmpty()){
                        QFile file("datas/"+trimmedPokemon+".png");
                        file.open(QIODevice::WriteOnly);
                        file.write(iconDownloader->downloadedData());
                        file.close();
                        pixmap.loadFromData(iconDownloader->downloadedData());
                        currentItem->setData(QIcon(pixmap),Qt::DecorationRole);
                    }
                });
            }
        }
    });
}

