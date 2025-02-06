//
// Created by Michele Dioli on 2/4/25.
//

#ifndef FILTROLAYOUT_H
#define FILTROLAYOUT_H

#include "ListaQT.h"
#include <QComboBox>
#include <QLineEdit>
#include <QSpacerItem>
#include <QGroupBox>
#include <QSplitter>
#include <QVBoxLayout>

#include <QToolBar>

class FiltroLayout : public QWidget {
    Q_OBJECT
private:
    QVBoxLayout* filtri;
    QVBoxLayout* layout;
    QHBoxLayout* layout2;
    ListaQT l;
    QPushButton* salva;
    QComboBox* filtro;
    std::list<Articolo*> articoli;
    QGridLayout* lista;
    QLineEdit* ricerca;
    QSplitter* splitter;
    QToolBar*  barra;
public:
    FiltroLayout(QWidget* parent = nullptr, std::list<Articolo*> articoli = std::list<Articolo*>());
    void filtra(std::list<Articolo*>);
public slots:
    void ricercaScelta();
};


#endif //FILTROLAYOUT_H
