#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Sensoriqt/FiltroLayout.h"
#include "Sensoriqt/ListaArticoli.h"
#include "Sensoriqt/ListaQT.h"
#include "Mostra/MostraVisitor.h"
#include "Json/Json.h"
#include "Modifica/edit.h"
#include "Modifica/ModificaArticolo.h"

#include <QMessageBox>
#include <QStackedLayout>
#include <QStatusBar>

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
    QWidget* mostra;
    QWidget* modifica;
public:
    MainWindow(QWidget *parent = nullptr);
    public slots:
        void nuovoClicked();
    void nuovoSalvato();
    void annullatoClicked();
    void mostaArticolo(Articolo*);

    void salvaSlot(Articolo*);
    void cancellaSlot(Articolo*);
    void infoSlot();
    void importaSlot();
    void modificaSlot(Articolo*);
    void confermaModifica();
};

#endif //MAINWINDOW_H