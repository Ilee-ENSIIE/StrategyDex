#include "widget.h"
#include "./ui_widget.h"
#include "pokedexmodel.h"

#include <QLineEdit>
#include <QSortFilterProxyModel>
#include <QListView>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //Mise en place du layout de l'application

    //Partie gauche
    QLineEdit* searchBar = new QLineEdit;
    searchBar->setMaximumWidth(200);
    QListView* pokedexView = new QListView;
    pokedexView->setMaximumWidth(200);
    QVBoxLayout* leftPanel = new QVBoxLayout;
    leftPanel->addWidget(searchBar);
    leftPanel->addWidget(pokedexView);
    //Partie droite
    QLabel* pokemon = new QLabel;
    QListView* movesetView = new QListView;
    QVBoxLayout* rightPanel = new QVBoxLayout;
    rightPanel->addWidget(pokemon);
    rightPanel->addWidget(movesetView);
    //Layout global
    QHBoxLayout* applicationLayout = new QHBoxLayout;
    applicationLayout->addLayout(leftPanel);
    applicationLayout->addLayout(rightPanel);
    setLayout(applicationLayout);

    //On télécharge le pokédex
    PokedexModel* pokedexModel = new PokedexModel;

    //On met en place la search bar et la vue sur le résultat de la recherche
    QSortFilterProxyModel *proxy = new QSortFilterProxyModel(this);
    proxy->setSourceModel(pokedexModel);
    pokedexView->setModel(proxy);
    pokedexView->setRootIndex(proxy->mapFromSource(pokedexModel->index(0,0)));
    connect(searchBar, SIGNAL(textChanged(QString)),proxy,SLOT(setFilterFixedString(QString)));

    //On connecte le changement d'index sur la vue à un changement des informations sur le panel de droite


}

Widget::~Widget()
{
    delete ui;
}

