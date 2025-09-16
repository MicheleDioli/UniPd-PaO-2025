#ifndef FILTROLAYOUT_H
#define FILTROLAYOUT_H

#include "../crea/Nuovo.h"
#include "filtroSpecifico.h"


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
    Cliccabile* cliccabile;
    int prev = 0;
    std::list<Articolo*> articoli;
    ListaArticoli *l1;
    filtroSpecifico* filtroS;

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
    QGroupBox* gruppoFiltri;
    QGroupBox *fitriSpecifici;
    QComboBox* filtro;
    QComboBox* filtro2;

    QHBoxLayout* lista;
    QLineEdit* ricerca;
    QSplitter* splitter;

    QPushButton* applicaBtn;

    QGroupBox* fitriSpecificiCombo;

    void applicaTuttiIFiltri();

     void aggiornaListaFiltrata();
     void gestisciVisibilitaFiltriSpecifici();

    int copie=0,anno=0,minuti=0,pagineL=0,capitoli=0,pagineR=0;
    QString cat= "Tutti",lang= "Tutti",produ,attore,autore,casa,diff,perd;
    
public:
    FiltroLayout(QWidget* parent = nullptr, ListaArticoli* LA = nullptr);
    void filtra(std::list<Articolo*>);

    void allFiltri();

    void annoFiltrato(int);
    void copieFiltrato(int);
    void linguaFiltrato(const QString&);
    void categoriaFiltrato(const QString&);

    void minutaggioFiltrato(int);
    void attoreFiltrato(const QString&);
    void produFiltrato(const QString&);

    void pagineFiltrato(int);
    void capitoliFiltrato(int);
    void autoreiltrato(const QString&);
    void casaFiltrato(const QString&);

    void pagineRivistaFiltrato(int);
    void periodicoFiltrato(const QString&);
    void difficoltaFiltrato(const QString&);
    void allFil();

public slots:
    void filtraggio();
    void ricercaScelta();
    void nuovoClicked();
    void nuovoSalvato();
    void aggiorna();
    void dettaglio(Articolo*);
    void importa();
    void salvaSlot(Articolo*);
    void cancellaSlot(Articolo*);
    void modificaSlot(Articolo*);

signals:
    void dettaglioClicked(Articolo*);
    void importaClicked();
    void nuovo();
    void listanuova();

    void salvaclic(Articolo*);
    void cancellaclic(Articolo*);
    void modificaclic(Articolo*);
};


#endif //FILTROLAYOUT_H
