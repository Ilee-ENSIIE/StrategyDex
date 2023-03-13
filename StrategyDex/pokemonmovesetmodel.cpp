#include "pokemonmovesetmodel.h"
#include "filedownloader.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <iostream>

PokemonMovesetModel::PokemonMovesetModel(QString pokemon, QObject *parent)
    : QStandardItemModel{parent}
{
    QStandardItem* rootItem = invisibleRootItem();
    connect(this, &PokemonMovesetModel::gen9ouAvailable,[pokemon,rootItem](){
        //On ouvre le fichier en tant qu'objet QJsonDocument
        QFile file("datas/gen9ou.json");
        file.open(QIODevice::ReadOnly);
        QByteArray rawFile = file.readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(rawFile);
        //On le parse et on insère les données pertinentes dans un QString
        QJsonObject pokemonEntries = jsonDoc["dex"][pokemon].toObject();
        foreach(const QString& setName, pokemonEntries.keys()){
            QString set;
            set+="# "+setName+" OU #\n";
            set+=pokemon+"@"+pokemonEntries.value(setName).toObject()["item"].toString()+"\n\n";
            set+="Nature : "+pokemonEntries.value(setName).toObject()["nature"].toString()+"\n";
            set+="Ability : "+pokemonEntries.value(setName).toObject()["ability"].toString()+"\n";
            set+="Teracrystal type : "+pokemonEntries.value(setName).toObject()["teraType"].toString()+"\n";
            set+="EVs : ";
            QJsonObject evs = pokemonEntries.value(setName).toObject()["evs"].toObject();
            foreach(const QString& key, evs.keys()){
                QJsonValue value = evs.value(key);
                set+=QString::number(value.toInt())+" "+key+" ";
            }
            set+="\n";
            QJsonArray moves = pokemonEntries.value(setName).toObject()["moves"].toArray();
            for(auto move : moves){
                set+=" - "+move.toString()+"\n";
            }
            QStandardItem* newItem = new QStandardItem(set);
            rootItem->appendRow(newItem);
        }
    });
    connect(this, &PokemonMovesetModel::gen9ruAvailable,[pokemon,rootItem](){
        //add RU datas to model
        //On ouvre le fichier en tant qu'objet QJsonDocument
        QFile file("datas/gen9ru.json");
        file.open(QIODevice::ReadOnly);
        QByteArray rawFile = file.readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(rawFile);
        //On le parse et on insère les données pertinentes dans un QString
        QJsonObject pokemonEntries = jsonDoc["dex"][pokemon].toObject();
        foreach(const QString& setName, pokemonEntries.keys()){
            QString set;
            set+="# "+setName+" RU #\n";
            set+=pokemon+"@"+pokemonEntries.value(setName).toObject()["item"].toString()+"\n\n";
            set+="Nature : "+pokemonEntries.value(setName).toObject()["nature"].toString()+"\n";
            set+="Ability : "+pokemonEntries.value(setName).toObject()["ability"].toString()+"\n";
            set+="Teracrystal type : "+pokemonEntries.value(setName).toObject()["teraType"].toString()+"\n";
            set+="EVs : ";
            QJsonObject evs = pokemonEntries.value(setName).toObject()["evs"].toObject();
            foreach(const QString& key, evs.keys()){
                QJsonValue value = evs.value(key);
                set+=QString::number(value.toInt())+" "+key+" ";
            }
            set+="\n";
            QJsonArray moves = pokemonEntries.value(setName).toObject()["moves"].toArray();
            for(auto move : moves){
                set+=" - "+move.toString()+"\n";
            }
            QStandardItem* newItem = new QStandardItem(set);
            rootItem->appendRow(newItem);
        }
    });
    connect(this, &PokemonMovesetModel::gen9uuAvailable,[pokemon,rootItem](){
        //add UU datas to model
        //On ouvre le fichier en tant qu'objet QJsonDocument
        QFile file("datas/gen9uu.json");
        file.open(QIODevice::ReadOnly);
        QByteArray rawFile = file.readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(rawFile);
        //On le parse et on insère les données pertinentes dans un QString
        QJsonObject pokemonEntries = jsonDoc["dex"][pokemon].toObject();
        foreach(const QString& setName, pokemonEntries.keys()){
            QString set;
            set+="# "+setName+" UU #\n";
            set+=pokemon+"@"+pokemonEntries.value(setName).toObject()["item"].toString()+"\n\n";
            set+="Nature : "+pokemonEntries.value(setName).toObject()["nature"].toString()+"\n";
            set+="Ability : "+pokemonEntries.value(setName).toObject()["ability"].toString()+"\n";
            set+="Teracrystal type : "+pokemonEntries.value(setName).toObject()["teraType"].toString()+"\n";
            set+="EVs : ";
            QJsonObject evs = pokemonEntries.value(setName).toObject()["evs"].toObject();
            foreach(const QString& key, evs.keys()){
                QJsonValue value = evs.value(key);
                set+=QString::number(value.toInt())+" "+key+" ";
            }
            set+="\n";
            QJsonArray moves = pokemonEntries.value(setName).toObject()["moves"].toArray();
            for(auto move : moves){
                set+=" - "+move.toString()+"\n";
            }
            QStandardItem* newItem = new QStandardItem(set);
            rootItem->appendRow(newItem);
        }
    });
    connect(this, &PokemonMovesetModel::gen9nuAvailable,[pokemon,rootItem](){
        //add NU datas to model
        //On ouvre le fichier en tant qu'objet QJsonDocument
        QFile file("datas/gen9nu.json");
        file.open(QIODevice::ReadOnly);
        QByteArray rawFile = file.readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(rawFile);
        //On le parse et on insère les données pertinentes dans un QString
        QJsonObject pokemonEntries = jsonDoc["dex"][pokemon].toObject();
        foreach(const QString& setName, pokemonEntries.keys()){
            QString set;
            set+="# "+setName+" NU #\n";
            set+=pokemon+"@"+pokemonEntries.value(setName).toObject()["item"].toString()+"\n\n";
            set+="Nature : "+pokemonEntries.value(setName).toObject()["nature"].toString()+"\n";
            set+="Ability : "+pokemonEntries.value(setName).toObject()["ability"].toString()+"\n";
            set+="Teracrystal type : "+pokemonEntries.value(setName).toObject()["teraType"].toString()+"\n";
            set+="EVs : ";
            QJsonObject evs = pokemonEntries.value(setName).toObject()["evs"].toObject();
            foreach(const QString& key, evs.keys()){
                QJsonValue value = evs.value(key);
                set+=QString::number(value.toInt())+" "+key+" ";
            }
            set+="\n";
            QJsonArray moves = pokemonEntries.value(setName).toObject()["moves"].toArray();
            for(auto move : moves){
                set+=" - "+move.toString()+"\n";
            }
            QStandardItem* newItem = new QStandardItem(set);
            rootItem->appendRow(newItem);
        }
    });
    connect(this, &PokemonMovesetModel::gen9lcAvailable,[pokemon,rootItem](){
        //add LC datas to model
        //On ouvre le fichier en tant qu'objet QJsonDocument
        QFile file("datas/gen9lc.json");
        file.open(QIODevice::ReadOnly);
        QByteArray rawFile = file.readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(rawFile);
        //On le parse et on insère les données pertinentes dans un QString
        QJsonObject pokemonEntries = jsonDoc["dex"][pokemon].toObject();
        foreach(const QString& setName, pokemonEntries.keys()){
            QString set;
            set+="# "+setName+" LC #\n";
            set+=pokemon+"@"+pokemonEntries.value(setName).toObject()["item"].toString()+"\n\n";
            set+="Nature : "+pokemonEntries.value(setName).toObject()["nature"].toString()+"\n";
            set+="Ability : "+pokemonEntries.value(setName).toObject()["ability"].toString()+"\n";
            set+="Teracrystal type : "+pokemonEntries.value(setName).toObject()["teraType"].toString()+"\n";
            set+="EVs : ";
            QJsonObject evs = pokemonEntries.value(setName).toObject()["evs"].toObject();
            foreach(const QString& key, evs.keys()){
                QJsonValue value = evs.value(key);
                set+=QString::number(value.toInt())+" "+key+" ";
            }
            set+="\n";
            QJsonArray moves = pokemonEntries.value(setName).toObject()["moves"].toArray();
            for(auto move : moves){
                set+=" - "+move.toString()+"\n";
            }
            QStandardItem* newItem = new QStandardItem(set);
            rootItem->appendRow(newItem);
        }
    });
    connect(this, &PokemonMovesetModel::gen9ubersAvailable,[pokemon,rootItem](){
        //add Ubers datas to model
        //On ouvre le fichier en tant qu'objet QJsonDocument
        QFile file("datas/gen9ubers.json");
        file.open(QIODevice::ReadOnly);
        QByteArray rawFile = file.readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(rawFile);
        //On le parse et on insère les données pertinentes dans un QString
        QJsonObject pokemonEntries = jsonDoc["dex"][pokemon].toObject();
        foreach(const QString& setName, pokemonEntries.keys()){
            QString set;
            set+="# "+setName+" Ubers #\n";
            set+=pokemon+"@"+pokemonEntries.value(setName).toObject()["item"].toString()+"\n\n";
            set+="Nature : "+pokemonEntries.value(setName).toObject()["nature"].toString()+"\n";
            set+="Ability : "+pokemonEntries.value(setName).toObject()["ability"].toString()+"\n";
            set+="Teracrystal type : "+pokemonEntries.value(setName).toObject()["teraType"].toString()+"\n";
            set+="EVs : ";
            QJsonObject evs = pokemonEntries.value(setName).toObject()["evs"].toObject();
            foreach(const QString& key, evs.keys()){
                QJsonValue value = evs.value(key);
                set+=QString::number(value.toInt())+" "+key+" ";
            }
            set+="\n";
            QJsonArray moves = pokemonEntries.value(setName).toObject()["moves"].toArray();
            for(auto move : moves){
                set+=" - "+move.toString()+"\n";
            }
            QStandardItem* newItem = new QStandardItem(set);
            rootItem->appendRow(newItem);
        }
    });

    //On teste si chaque format est disponible dans "datas/" et sinon on le télécharge
    if(std::filesystem::exists("datas/gen9ou.json")){
        emit gen9ouAvailable();
    }
    else{
        QUrl url("http://play.pokemonshowdown.com/data/sets/gen9ou.json");
        auto downloader = new FileDownloader(url,this);
        connect(downloader,&FileDownloader::downloaded,[downloader,this](){
            std::cout<<"Raw OU 9G datas downloaded"<<std::endl;
            QFile file("datas/gen9ou.json");
            file.open(QIODevice::WriteOnly);
            file.write(downloader->downloadedData());
            file.close();
            emit gen9ouAvailable();
        });
    }
    if(std::filesystem::exists("datas/gen9uu.json")){
        emit gen9uuAvailable();
    }
    else{
        QUrl url("http://play.pokemonshowdown.com/data/sets/gen9uu.json");
        auto downloader = new FileDownloader(url,this);
        connect(downloader,&FileDownloader::downloaded,[downloader,this](){
            QFile file("datas/gen9uu.json");
            file.open(QIODevice::WriteOnly);
            file.write(downloader->downloadedData());
            file.close();
            emit gen9uuAvailable();
        });
    }
    if(std::filesystem::exists("datas/gen9ru.json")){
        emit gen9ruAvailable();
    }
    else{
        QUrl url("http://play.pokemonshowdown.com/data/sets/gen9ru.json");
        auto downloader = new FileDownloader(url,this);
        connect(downloader,&FileDownloader::downloaded,[downloader,this](){
            QFile file("datas/gen9ru.json");
            file.open(QIODevice::WriteOnly);
            file.write(downloader->downloadedData());
            file.close();
            emit gen9ruAvailable();
        });
    }
    if(std::filesystem::exists("datas/gen9nu.json")){
        emit gen9nuAvailable();
    }
    else{
        QUrl url("http://play.pokemonshowdown.com/data/sets/gen9nu.json");
        auto downloader = new FileDownloader(url,this);
        connect(downloader,&FileDownloader::downloaded,[downloader,this](){
            QFile file("datas/gen9nu.json");
            file.open(QIODevice::WriteOnly);
            file.write(downloader->downloadedData());
            file.close();
            emit gen9nuAvailable();
        });
    }
    if(std::filesystem::exists("datas/gen9lc.json")){
        emit gen9lcAvailable();
    }
    else{
        QUrl url("http://play.pokemonshowdown.com/data/sets/gen9lc.json");
        auto downloader = new FileDownloader(url,this);
        connect(downloader,&FileDownloader::downloaded,[downloader,this](){
            QFile file("datas/gen9lc.json");
            file.open(QIODevice::WriteOnly);
            file.write(downloader->downloadedData());
            file.close();
            emit gen9lcAvailable();
        });
    }
    if(std::filesystem::exists("datas/gen9ubers.json")){
        emit gen9ubersAvailable();
    }
    else{
        QUrl url("http://play.pokemonshowdown.com/data/sets/gen9ubers.json");
        auto downloader = new FileDownloader(url,this);
        connect(downloader,&FileDownloader::downloaded,[downloader,this](){
            QFile file("datas/gen9ubers.json");
            file.open(QIODevice::WriteOnly);
            file.write(downloader->downloadedData());
            file.close();
            emit gen9ubersAvailable();
        });
    }
}
