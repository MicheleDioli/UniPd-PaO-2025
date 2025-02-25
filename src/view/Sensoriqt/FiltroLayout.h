//
// Created by Michele Dioli on 2/4/25.
//

#ifndef FILTROLAYOUT_H
#define FILTROLAYOUT_H

#include "../Crea/Nuovo.h"
#include "../Sensoriqt/ListaArticoli.h"


#include <QComboBox>
#include <QLineEdit>
#include <QSpacerItem>
#include <QGroupBox>
#include <QSplitter>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStackedLayout>
#include <QToolBar>
#include <QErrorMessage>

class FiltroLayout : public QWidget {
    Q_OBJECT
private:
    int prev = 0;
    std::list<Articolo*> articoli;
    ListaArticoli *l1;

    Nuovo* creazioneArticolo;
    ListaQT *l;

    std::list<Articolo*> vera;

    QStackedLayout* stack;

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

public:
    FiltroLayout(QWidget* parent = nullptr, ListaArticoli* LA = nullptr);
    void filtra(std::list<Articolo*>);

public slots:
    void ricercaScelta();
    void nuovoClicked();
    void nuovoSalvato();
    void nuovoSalvato12();

signals:
    void nuovo();
    void listanuova();
};


#endif //FILTROLAYOUT_H
