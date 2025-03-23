#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "sensoriqt/FiltroLayout.h"
#include "sensoriqt/ListaArticoli.h"
#include "sensoriqt/ListaQT.h"
#include "mostra/MostraVisitor.h"
#include "json/Json.h"
#include "modifica/Edit.h"
#include "modifica/ModificaArticolo.h"

#include <QMessageBox>
#include <QStackedLayout>
#include <QStatusBar>
#include <QDebug>

#include <iostream>
#include <list>

class MainWindow : public QWidget {
    Q_OBJECT
private:
    QPushButton* indietro;
    FiltroLayout* f;
    QStackedLayout* stack;
    QStatusBar* status;
    Nuovo* s;
    std::list<Articolo*> articoli;
    std::string messaggio;
    std::string pathLista;
    ListaArticoli* l;
    ListaQT* LQ;
    QToolBar* barra;
    QVBoxLayout* toll;
    QVBoxLayout* main;
    QWidget* widgetmain;
    QWidget* mostra;
    QWidget* modifica;
public:
    MainWindow(QWidget *parent = nullptr);
public slots:
    void nuovoClicked();
    void nuovoSalvato();
    void annullatoClicked();
    void mostaArticolo(Articolo*);
    void salvaListaSlot();
    void salvaSlot(Articolo*);
    void cancellaSlot(Articolo*);
    void infoSlot();
    void importaSlot();
    void modificaSlot(Articolo*);
    void confermaModifica();
signals:
    void modificaSignal(Articolo*);
public slots:
    void modificaMainSlot(Articolo*);
};

#endif //MAINWINDOW_H