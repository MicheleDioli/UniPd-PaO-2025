#include "FiltroLayout.h"

FiltroLayout::FiltroLayout(QWidget* parent, ListaArticoli* LA) : QWidget(parent), l1(LA) {
    main = new QVBoxLayout(this);

    std::list<Articolo*> art;
/*
    l1->addArticolo(new Rivista("Rivista ah","codice", "descrizione", "genere", 2021, 10, "lingua", "editore", 100, "pubblicatore", 1, 1, 1));
    l1->addArticolo(new Rivista("Rivista a","codice1", "descrizione", "genere", 2021, 10, "lingua", "editore", 100, "pubblicatore", 1, 1, 1));
    l1->addArticolo(new Rivista("Rivista","codice2", "descrizione", "genere", 2021, 10, "lingua", "editore", 100, "pubblicatore", 1, 1, 1));
    l1->addArticolo(new Rivista("Rivist","codice3", "descrizione", "genere", 2021, 10, "lingua", "editore", 100, "pubblicatore", 1, 1, 1));
    l1->addArticolo(new Rivista("Rivis","codice4", "descrizione", "genere", 2021, 10, "lingua", "editore", 100, "pubblicatore", 1, 1, 1));
    l1->addArticolo(new Rivista("Rivi","codice5", "descrizione", "genere", 2021, 10, "lingua", "editore", 100, "pubblicatore", 1, 1, 1));
    l1->addArticolo(new Rivista("Ri","codice6", "descrizione", "genere", 2021, 10, "lingua", "editore", 100, "pubblicatore", 1, 1, 1));
    l1->addArticolo(new Rivista("Rta ah","codice7", "descrizione", "genere", 2021, 10, "lingua", "editore", 100, "pubblicatore", 1, 1, 1));
    l1->addArticolo(new Rivista("R ah","codice8", "descrizione", "genere", 2021, 10, "lingua", "editore", 100, "pubblicatore", 1, 1, 1));
    l1->addArticolo(new Rivista("ivista ah","codice9", "descrizione", "genere", 2021, 10, "lingua", "editore", 100, "pubblicatore", 1, 1, 1));
*/
    layout = new QVBoxLayout();

    layout2 = new QHBoxLayout();

    QGroupBox* gruppoFiltri = new QGroupBox();

    splitter = new QSplitter(Qt::Vertical);

    filtri = new QVBoxLayout();
    filtro = new QComboBox();
    salva = new QPushButton("Salva");
    ricerca = new QLineEdit();

    QLabel* label = new QLabel("Ricerca per nome:");
    QLabel* label2 = new QLabel("Filtra per tipo:");

    gruppoFiltri->setStyleSheet("QGroupBox { border: 1px solid gray; border-radius: 5px; margin-top: 1ex;}");
    gruppoFiltri->setFixedWidth(200);

    filtri->addWidget(label);
    filtri->addWidget(ricerca);

    filtro->addItem("Tutti");
    filtro->addItem("Libri");
    filtro->addItem("Riviste");
    filtro->addItem("Film");

    filtri->addWidget(label2);
    filtri->addWidget(filtro);

    gruppoFiltri->setLayout(filtri);
    layout2->addWidget(gruppoFiltri);

    l = new ListaQT(l1->getArticoli());

    layout2->addWidget(l);

    QSpacerItem* spacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding);

    filtri->addItem(spacer);


    layout->addLayout(layout2);

    main->addLayout(layout);

    creazioneArticolo = new Nuovo(nullptr,l1);

    connect(filtro, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &FiltroLayout::ricercaScelta);
    connect(ricerca, &QLineEdit::textChanged, this, &FiltroLayout::ricercaScelta);

    connect(l, &ListaQT::nuovoClicked, this, &FiltroLayout::nuovoClicked);
    connect(l, &ListaQT::dettaglioClicked, this, &FiltroLayout::dettaglio);

    connect(creazioneArticolo, &Nuovo::annullatoCliked, this, &FiltroLayout::nuovoSalvato);
    connect(creazioneArticolo, &Nuovo::salvaClicked, this, &FiltroLayout::nuovoSalvato);

    connect(l, &ListaQT::salvaclic, this, &FiltroLayout::salvaSlot);
    connect(l, &ListaQT::cancellaclic, this, &FiltroLayout::cancellaSlot);
    connect(l, &ListaQT::modificlic, this, &FiltroLayout::modificaSlot);


}

void FiltroLayout::ricercaScelta() {
    std::list<Articolo*> tmp = l->ricerca(l1->getArticoli(), ricerca->text().toStdString());
    filtra(tmp);
}

void FiltroLayout::filtra(std::list<Articolo*> tmp) {

	std::cout<<"Filtro"<<std::endl;
    if (filtro->currentText() == "Libri") {
        tmp = l->soloLibri(tmp);
    } else if (filtro->currentText() == "Riviste") {
        tmp = l->soloRiviste(tmp);
    } else if (filtro->currentText() == "Film") {
        tmp = l->soloFilm(tmp);
    }

    if (!tmp.empty()) {
        prev = filtro->currentIndex();
        lista = l->getArticoli(tmp);
        layout2->addLayout(lista);
        layout->addLayout(layout2);

    } else {
		QErrorMessage* error = new QErrorMessage();
        error->showMessage("Nessun articolo trovato");
        filtro->setCurrentIndex(prev);

    }
}

void FiltroLayout::nuovoClicked() {
    emit nuovo();
}

void FiltroLayout::nuovoSalvato(){
  emit listanuova();
}

void FiltroLayout::aggiorna() {
    lista = l->getArticoli(l1->getArticoli());
    layout2->addLayout(lista);
    layout->addLayout(layout2);
}

void FiltroLayout::dettaglio(Articolo* a) {
    emit dettaglioClicked(a);
}

void FiltroLayout::salvaSlot(Articolo* a) {
   emit salvaclic(a);
}

void FiltroLayout::cancellaSlot(Articolo* a) {
    emit cancellaclic(a);
}

void FiltroLayout::modificaSlot(Articolo* a) {
    emit modificaclic(a);
}