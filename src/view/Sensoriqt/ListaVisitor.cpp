//
// Created by Michele Dioli on 2/3/25.
//
#include "ListaVisitor.h"

#include "../../Libro.h"
#include "../../Rivista.h"
#include "../../Film.h"



#include <iostream>

QVBoxLayout* ListaVisitor::getLayout() const {
    return layout;
}

void ListaVisitor::visitLibro(Libro& l) {
    QGroupBox* group = new QGroupBox();
    QHBoxLayout* mainLayout = new QHBoxLayout(group);

    QPixmap img(":/asset/images/libro.png");
    QLabel* imgLabel = new QLabel();
    imgLabel->setPixmap(img.scaledToHeight(50));

    QLabel* titolo = new QLabel(QString::fromStdString(l.getTitolo()));
    QLabel* codice = new QLabel(QString::fromStdString(l.getCodice()));
    QLabel* autore = new QLabel(QString::fromStdString(l.getAutore()));
    QLabel* lingua = new QLabel(QString::fromStdString(l.getLingua()));

    QVBoxLayout* info = new QVBoxLayout();
    info->addWidget(codice);
    info->addWidget(titolo);
    info->addWidget(autore);
    info->addWidget(lingua);

    mainLayout->addWidget(imgLabel);
    mainLayout->addLayout(info);
    group->setLayout(mainLayout);

    layout->addWidget(group);
}


void ListaVisitor::visitRivista(Rivista& r) {
    QGroupBox* group = new QGroupBox();

    QHBoxLayout* mainLayout = new QHBoxLayout(group);

    QVBoxLayout* info = new QVBoxLayout();

    QPixmap img(":/asset/images/rivista.png");
    QLabel* imgLabel = new QLabel();
    imgLabel->setPixmap(img.scaledToHeight(50));


    QLabel* titolo = new QLabel(QString::fromStdString(r.getTitolo()));
    QLabel* codice = new QLabel(QString::fromStdString(r.getCodice()));
    QLabel* editore = new QLabel(QString::fromStdString(r.getEditore()));
    QLabel* lingua = new QLabel(QString::fromStdString(r.getLingua()));

    info->addWidget(codice);
    info->addWidget(titolo);
    info->addWidget(editore);
    info->addWidget(lingua);

    mainLayout->addWidget(imgLabel);
    mainLayout->addLayout(info);

    group->setLayout(mainLayout);

    layout->addWidget(group);

}

void ListaVisitor::visitFilm(Film& f) {
    QGroupBox* group = new QGroupBox();

    QHBoxLayout* mainLayout = new QHBoxLayout(group);

    QVBoxLayout* info = new QVBoxLayout();

    QPixmap img(":/asset/images/film.png");
    QLabel* imgLabel = new QLabel();
    imgLabel->setPixmap(img.scaledToHeight(50));
    //art->addWidget(imgLabel);

    QLabel* titolo = new QLabel(QString::fromStdString(f.getTitolo()));
    QLabel* codice = new QLabel(QString::fromStdString(f.getCodice()));
    QLabel* autore = new QLabel(QString::fromStdString(f.getRegista()));
    QLabel* lingua = new QLabel(QString::fromStdString(f.getLingua()));

    info->addWidget(codice);
    info->addWidget(titolo);
    info->addWidget(autore);
    info->addWidget(lingua);

    mainLayout->addWidget(imgLabel);
    mainLayout->addLayout(info);

    group->setLayout(mainLayout);

    layout->addWidget(group);
}
