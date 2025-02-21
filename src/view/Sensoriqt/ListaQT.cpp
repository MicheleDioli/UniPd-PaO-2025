#include "ListaQT.h"


#include "../../Rivista.h"
#include "../../Libro.h"
#include "../../Film.h"

ListaQT::ListaQT(std::list<Articolo*> articoli) : articoli(articoli){

    pulisciLayout(layout);

    int size = articoli.size() + 2;
    int colonne = sqrt(size);
    int righe = colonne;
    if (colonne * colonne < articoli.size()) righe++;

    layout->setSpacing(15);

    int i = 0;
    for (auto a : articoli) {
        ListaVisitor visitor;
        a->accept(visitor);

        Cliccabile* c = new Cliccabile(a);
        c->setLayout(visitor.getLayout());
        connect(c, &Cliccabile::clicked, this, &ListaQT::itemClicked);
        layout->addWidget(c, i / righe, i % righe);
        i++;
    }

    QVBoxLayout* tmp = new QVBoxLayout();

    nuovo->setIcon(QIcon(":/asset/icon/nuovo.png"));

    tmp->addWidget(nuovo);
    QWidget* tmp2 = new QWidget();
    tmp2->setLayout(tmp);

    connect(nuovo, &QPushButton::clicked, this, &ListaQT::clicatoNuovo);
    layout->addWidget(tmp2, i / righe, i % righe);

}

void ListaQT::clicatoNuovo() {
    emit nuovoClicked();
}

void ListaQT::itemClicked(Articolo* articolo) {
    emit dettaglioClicked(articolo);
}

QGridLayout* ListaQT::getArticoli(std::list<Articolo*> articoli){

    pulisciLayout(layout);

    int size = articoli.size() + 2;
    int colonne = sqrt(size);
    int righe = colonne;
    if (colonne * colonne < articoli.size()) righe++;

    layout->setSpacing(15);

    int i = 0;
    for (auto a : articoli) {
        ListaVisitor visitor;
        a->accept(visitor);

        Cliccabile* c = new Cliccabile(a);
        c->setLayout(visitor.getLayout());
        connect(c, &Cliccabile::clicked, this, &ListaQT::itemClicked);
        layout->addWidget(c, i / righe, i % righe);
        i++;
    }

    QVBoxLayout* tmp = new QVBoxLayout();

    nuovo->setIcon(QIcon(":/asset/icon/nuovo.png"));

    tmp->addWidget(nuovo);
    QWidget* tmp2 = new QWidget();
    tmp2->setLayout(tmp);

    layout->addWidget(tmp2, i / righe, i % righe);

    return layout;
}

std::list<Articolo*> ListaQT::soloLibri(std::list<Articolo*> articoli) {
    std::list<Articolo*> libri;
    for (auto a : articoli) {
        if (dynamic_cast<Libro*>(a)) {
            libri.push_back(a);
        }
    }
    return libri;
}

std::list<Articolo*> ListaQT::soloRiviste(std::list<Articolo*> articoli) {
    std::list<Articolo*> riviste;
    for (auto a : articoli) {
        if (dynamic_cast<Rivista*>(a)) {
            riviste.push_back(a);
        }
    }
    return riviste;
}

std::list<Articolo*> ListaQT::soloFilm(std::list<Articolo*> articoli) {
    std::list<Articolo*> film;
    for (auto a : articoli) {
        if (dynamic_cast<Film*>(a)) {
            film.push_back(a);
        }
    }
    return film;
}

void ListaQT::pulisciLayout(QLayout* layout) {
    if (!layout) return;
    while (QLayoutItem* item = layout->takeAt(0)) {
        if (QWidget* widget = item->widget()) {
            widget->deleteLater();
        }
        if (QLayout* childLayout = item->layout()) {
            pulisciLayout(childLayout);
            delete childLayout;
        }
        delete item;
    }
}


std::list<Articolo*> ListaQT::ricerca(std::list<Articolo*> articoli, std::string ricerca) {
    std::list<Articolo*> tmp;

    std::transform(ricerca.begin(), ricerca.end(), ricerca.begin(), ::tolower);

    for (auto a : articoli) {
        std::string titolo = a->getTitolo();
        std::transform(titolo.begin(), titolo.end(), titolo.begin(), ::tolower);

        if (titolo.find(ricerca) != std::string::npos) {
            tmp.push_back(a);
        }
    }

    return tmp;
}