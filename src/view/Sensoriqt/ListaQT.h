#ifndef LISTAQT_H
#define LISTAQT_H

#include <QWidget>
#include <QTableWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QIcon>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <QSpacerItem>

#include "ListaVisitor.h"
#include "Cliccabile.h"
#include "../../Articolo.h"

class ListaQT : public QWidget {
    Q_OBJECT
private:
   QGridLayout* layout = new QGridLayout(this);
    QPushButton* nuovo = new QPushButton();
    std::list<Articolo*> articoli;
public:
    ListaQT(std::list<Articolo*> articoli = {});
    ListaQT () = default;

    QGridLayout* getArticoli(std::list<Articolo*>);

    std::list<Articolo*> soloLibri(std::list<Articolo*>);
    std::list<Articolo*> soloRiviste(std::list<Articolo*>);
    std::list<Articolo*> soloFilm(std::list<Articolo*>);
    std::list<Articolo*> ricerca(std::list<Articolo*>, std::string);

    void pulisciLayout(QLayout* layout);
public slots:
    void clicatoNuovo();
    void itemClicked(Articolo* articolo);

    void salva(Articolo* articolo);
    void cancella(Articolo* articolo);
    void dettaglio(Articolo* articolo);
    void modifica(Articolo* articolo);

signals:

    void dettaglioClicked(Articolo* articolo);
    void salvaclic(Articolo* articolo);
    void cancellaclic(Articolo* articolo);
    void modificlic(Articolo* articolo);

    void nuovoClicked();

};

#endif // LISTAQT_H

