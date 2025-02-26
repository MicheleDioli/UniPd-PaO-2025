#include "ListaQT.h"


#include "../../Rivista.h"
#include "../../Libro.h"
#include "../../Film.h"

ListaQT::ListaQT(std::list<Articolo*> articoli) : articoli(articoli){

    pulisciLayout(layout);

    int colonn = 3;
    layout->setSpacing(15);
    int i = 0;
    for (auto a : articoli) {
        ListaVisitor visitor;
        a->accept(visitor);

        Cliccabile* c = new Cliccabile(a);
        c->setLayout(visitor.getLayout());

        connect(c, &Cliccabile::clicked, this, &ListaQT::itemClicked);
    	connect(c, &Cliccabile::salva, this, &ListaQT::salva);
    	connect(c, &Cliccabile::cancella, this, &ListaQT::cancella);
    	connect(c, &Cliccabile::dettagli, this, &ListaQT::dettaglio);
    	connect(c, &Cliccabile::modifica, this, &ListaQT::modifica);

        layout->addWidget(c, i / colonn, i % colonn);
        i++;
    }

    for (int j = 0; j < (9 - static_cast<int>(articoli.size())) - 1; ++j) {
        QPixmap image(":/asset/icon/vuoto.png");
        QLabel* imageLabel = new QLabel();
        imageLabel->setPixmap(image);
        layout->addWidget(imageLabel, i / colonn, i % colonn);
        i++;
    }

    QVBoxLayout* tmp = new QVBoxLayout();

    nuovo->setIcon(QIcon(":/asset/icon/nuovo.png"));
    nuovo->setFixedSize(80, 80);

    tmp->addWidget(nuovo);
    QWidget* tmp2 = new QWidget();
    tmp2->setLayout(tmp);

    connect(nuovo, &QPushButton::clicked, this, &ListaQT::clicatoNuovo);
    layout->addWidget(tmp2, i / colonn, i % colonn);




}

void ListaQT::clicatoNuovo() {
    emit nuovoClicked();
}

void ListaQT::itemClicked(Articolo* articolo) {
    emit dettaglioClicked(articolo);
}

QGridLayout* ListaQT::getArticoli(std::list<Articolo*> articoli){

    pulisciLayout(layout);

    int colonn = 3;

    layout->setSpacing(15);

    int i = 0;
    for (auto a : articoli) {
        ListaVisitor visitor;
        a->accept(visitor);

        Cliccabile* c = new Cliccabile(a);
        c->setLayout(visitor.getLayout());
        connect(c, &Cliccabile::clicked, this, &ListaQT::itemClicked);
        connect(c, &Cliccabile::clicked, this, &ListaQT::itemClicked);
    	connect(c, &Cliccabile::salva, this, &ListaQT::salva);
    	connect(c, &Cliccabile::cancella, this, &ListaQT::cancella);
    	connect(c, &Cliccabile::dettagli, this, &ListaQT::dettaglio);
    	connect(c, &Cliccabile::modifica, this, &ListaQT::modifica);
        layout->addWidget(c, i / colonn, i % colonn);
        i++;
    }

    for (int j = 0; j < (9 - static_cast<int>(articoli.size())) - 1; ++j) {
        QPixmap image(":/asset/icon/vuoto.png");
        QLabel* imageLabel = new QLabel();
        imageLabel->setPixmap(image.scaled(80, 80));
        layout->addWidget(imageLabel, i / colonn, i % colonn);
        i++;
    }

    QVBoxLayout* tmp = new QVBoxLayout();

    nuovo->setIcon(QIcon(":/asset/icon/nuovo.png"));
    nuovo->setFixedSize(80, 80);

    tmp->addWidget(nuovo);
    QWidget* tmp2 = new QWidget();
    tmp2->setLayout(tmp);

    layout->addWidget(tmp2, i / colonn, i % colonn);

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

void ListaQT::salva(Articolo* articolo) {
        emit salvaclic(articolo);
}

void ListaQT::cancella(Articolo* articolo) {
        emit cancellaclic(articolo);
}

void ListaQT::dettaglio(Articolo* articolo) {
        emit dettaglioClicked(articolo);
}

void ListaQT::modifica(Articolo* articolo) {
        emit modificlic(articolo);
}