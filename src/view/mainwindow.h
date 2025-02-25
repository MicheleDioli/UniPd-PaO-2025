//
// Created by Michele Dioli on 2/21/25.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLoggingCategory>



#include "Sensoriqt/FiltroLayout.h"
#include "Sensoriqt/ListaArticoli.h"
#include "Sensoriqt/ListaQT.h"
#include "Modifica/editVisitor.h"
#include "Mostra/MostraVisitor.h"

#include <QStackedLayout>

class MainWindow : public QWidget {
    Q_OBJECT
private:
    QPushButton* indietro;
    FiltroLayout* f;
    QStackedLayout* stack;
    Nuovo* s;
    std::list<Articolo*> articoli;
    ListaArticoli* l;
    ListaQT* LQ;
    QToolBar* barra;
    QVBoxLayout* toll;
    QVBoxLayout* main;
    QWidget* widgetmain;
    QWidget* modifica;
public:
    MainWindow(QWidget *parent = nullptr);
public slots:
    void dettagli(Articolo*);
    void nuovoClicked();
    void nuovoSalvato();
    void annullatoClicked();
    void modificaArticolo();
    void mostaArticolo(Articolo*);
};

#endif //MAINWINDOW_H
