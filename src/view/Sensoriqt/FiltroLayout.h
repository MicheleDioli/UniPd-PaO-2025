//
// Created by Michele Dioli on 2/4/25.
//

#ifndef FILTROLAYOUT_H
#define FILTROLAYOUT_H

#include "../Crea/Nuovo.h"
#include <QComboBox>
#include <QLineEdit>
#include <QSpacerItem>
#include <QGroupBox>
#include <QSplitter>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStackedLayout>
#include <QToolBar>

class FiltroLayout : public QWidget {
    Q_OBJECT
private:
    std::list<Articolo*> articoli;

    Nuovo* creazioneArticolo;
    ListaQT *l;

    QStackedLayout* lll;

    QWidget* salvaWidger;
    QWidget* widgetmain;

    QVBoxLayout *main;
    QVBoxLayout* mostraSalva;
    QVBoxLayout* filtri;
    QVBoxLayout* layout;
    QHBoxLayout* layout2;
    QVBoxLayout* v;

    QPushButton* salva;
    QComboBox* filtro;

    QGridLayout* lista;
    QLineEdit* ricerca;
    QSplitter* splitter;
    QToolBar*  barra;

public:
    FiltroLayout(QWidget* parent = nullptr, std::list<Articolo*> articoli = std::list<Articolo*>());
    void filtra(std::list<Articolo*>);
public slots:
    void ricercaScelta();
    void nuovoClicked();
    void nuovoSalvato();
};


#endif //FILTROLAYOUT_H
