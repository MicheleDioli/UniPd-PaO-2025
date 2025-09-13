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
#include <QSlider>
#include <QScrollBar>
#include <QScrollArea>
#include <QGroupBox>


#include "ListaVisitor.h"
#include "Cliccabile.h"
#include "../../Articolo.h"
#include "../../Rivista.h"
#include "../../Libro.h"
#include "../../Film.h"

class ListaQT : public QWidget {
    Q_OBJECT
private:
   QHBoxLayout* layout = new QHBoxLayout(this);
    QPushButton* nuovo = new QPushButton();
    QVBoxLayout *l;
    QVBoxLayout *tmp;
    QGroupBox *gruppo;

    QPushButton* b1, *b2;
    
    std::list<Articolo*> articoli;
public:
    ListaQT(std::list<Articolo*> articoli = {});
    ListaQT () = default;

    QHBoxLayout* getArticoli(std::list<Articolo*>);

    std::list<Articolo*> soloLibri(std::list<Articolo*>);
    std::list<Articolo*> soloRiviste(std::list<Articolo*>);
    std::list<Articolo*> soloFilm(std::list<Articolo*>);
    std::list<Articolo*> ricerca(std::list<Articolo*>, std::string);

    void pulisciLayout(QLayout* layout);
public slots:
    void clicatoNuovo();
    void importaNuovo();
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
    void importaClickedLista();
    void nuovoClicked();

};

#endif // LISTAQT_H

