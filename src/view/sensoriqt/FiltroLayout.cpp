#include "FiltroLayout.h"


FiltroLayout::FiltroLayout(QWidget* parent, ListaArticoli* LA) : QWidget(parent), l1(LA) {

    main = new QVBoxLayout(this);

    std::list<Articolo*> art;

    layout = new QVBoxLayout();

    layout2 = new QHBoxLayout();

    gruppoFiltri = new QGroupBox();

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

    QLabel* label3 = new QLabel("Ordina per:");

    filtro2 = new QComboBox();
    filtro2->addItem("Nome Z-A");
    filtro2->addItem("Nome A-Z");

    fitriSpecificiCombo = new QGroupBox();
    filtroS = new filtroSpecifico(nullptr, l1);
    filtroS->backNormale();
    QVBoxLayout* layoutSpecifico = new QVBoxLayout();
    layoutSpecifico->addWidget(filtroS);
    fitriSpecificiCombo->setLayout(layoutSpecifico);

    filtri->addWidget(label2);
    filtri->addWidget(filtro);
    filtri->addWidget(label3);
    filtri->addWidget(filtro2);
    filtri->addWidget(fitriSpecificiCombo);

    gruppoFiltri->setLayout(filtri);
    layout2->addWidget(gruppoFiltri);

    gruppoFiltri->hide();

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
    connect(l, &ListaQT::importaClickedLista, this, &FiltroLayout::importa);

    connect(creazioneArticolo, &Nuovo::annullatoCliked, this, &FiltroLayout::nuovoSalvato);
    connect(creazioneArticolo, &Nuovo::salvaClicked, this, &FiltroLayout::nuovoSalvato);

    connect(l, &ListaQT::salvaclic, this, &FiltroLayout::salvaSlot);
    connect(l, &ListaQT::cancellaclic, this, &FiltroLayout::cancellaSlot);
    connect(l, &ListaQT::modificlic, this, &FiltroLayout::modificaSlot);

    connect(filtro2, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &FiltroLayout::filtraggio);

    connect(filtroS, &filtroSpecifico::annoValueChanged, this, &FiltroLayout::annoFiltrato);
    connect(filtroS, &filtroSpecifico::copieValueChanged, this, &FiltroLayout::copieFiltrato);
    connect(filtroS, &filtroSpecifico::linguaValueChanged, this, &FiltroLayout::linguaFiltrato);
    connect(filtroS, &filtroSpecifico::categoriaValueChanged, this, &FiltroLayout::categoriaFiltrato);

    connect(filtroS, &filtroSpecifico::minutaggioValueChanged, this, &FiltroLayout::minutaggioFiltrato);
    connect(filtroS, &filtroSpecifico::attoreValueChanged, this, &FiltroLayout::attoreFiltrato);
    connect(filtroS, &filtroSpecifico::produValueChanged, this, &FiltroLayout::produFiltrato);
    connect(filtroS, &filtroSpecifico::produValueChanged, this, &FiltroLayout::produFiltrato);

    connect(filtroS, &filtroSpecifico::pagineValueChanged, this, &FiltroLayout::pagineFiltrato);
    connect(filtroS, &filtroSpecifico::capitoliValueChanged, this, &FiltroLayout::capitoliFiltrato);
    connect(filtroS, &filtroSpecifico::autoreValueLibroChanged, this, &FiltroLayout::autoreiltrato);
    connect(filtroS, &filtroSpecifico::casaEditriceValueChanged, this, &FiltroLayout::casaFiltrato);
    connect(filtroS, &filtroSpecifico::pagineValueChanged, this, &FiltroLayout::allFil);

    connect(filtroS, &filtroSpecifico::pagineRivistaValueChanged, this, &FiltroLayout::pagineRivistaFiltrato);
    connect(filtroS, &filtroSpecifico::periodicoValueChanged, this, &FiltroLayout::periodicoFiltrato);
    connect(filtroS, &filtroSpecifico::difficoltaValueChanged, this, &FiltroLayout::difficoltaFiltrato);
}


void FiltroLayout::allFil(){

        filtroS->aggiorna();

      /*  std::list<Articolo*>tmp;

        std::list<Articolo*>tmpL = l->soloLibri(l1->getArticoli());
        std::list<Articolo*>tmpR = l->soloRiviste(l1->getArticoli());
        std::list<Articolo*>tmpF = l->soloFilm(l1->getArticoli());

        for(auto a : tmpL){
            Libro *l = dynamic_cast<Libro*>(a);
            
            if(l == nullptr){
                std::cout<<"Nullptre";
            }
            if(l){
                filtroS->setLayoutSpecifico(l);
                if(l->getCapitoli() >= capitoli || l->getAutore() == autore.toStdString() || l->getPagine() == pagineL)
                    tmp.push_back(l);
                 int a = 0;
            }
        }

        for(auto a : tmpR){
            Rivista *r = dynamic_cast<Rivista*>(a);
                        if(r == nullptr){
                std::cout<<"Nullptre";
            }
            if(r){
                filtroS->setLayoutSpecifico(r);
            int d = diff.toInt();
            if(r->getPagine() == pagineR || r->getIntervalloPubblicazione() ==perd.toStdString() || r->getDifficolta() == d)
                tmp.push_back(r);  
                int a = 0;
            }
        }

        for(auto a : tmpF){
            Film *f = dynamic_cast<Film*>(a);
                        if(f == nullptr){
                std::cout<<"Nullptre";
            }
            if(f){
                filtroS->setLayoutSpecifico(f);
            if(f->getAttori() == attore.toStdString() || f->getDurata() ==  minuti || f->getProduttore() == produ.toStdString())
              tmp.push_back(f);  
              int a = 0;
            }
        }
        filtra(tmp);*/

}

void FiltroLayout::allFiltri() {
    // Aggiorna i valori dei filtri dalla UI
    filtroS->aggiorna();

    // Lista che conterrà il risultato finale
    std::list<Articolo*> risultatoFiltrato;

    // Unico ciclo su tutti gli articoli originali
    for (auto articolo : l1->getArticoli()) {

        // --- FASE 1: CONTROLLO FILTRI GENERICI ---
        // Se anche solo uno di questi non corrisponde, salta al prossimo articolo
        
        bool linguaCorrisponde = (lang == "Tutti" || QString::fromStdString(articolo->getLingua()) == lang);
        if (!linguaCorrisponde) {
            continue; // Salta al prossimo articolo
        }

        bool categoriaCorrisponde = (cat == "Tutti" || QString::fromStdString(articolo->getGenere()) == cat);
        if (!categoriaCorrisponde) {
            continue;
        }

        // Per i numeri, il filtro si applica solo se il valore è > 0
        bool annoCorrisponde = (anno <= 0 || articolo->getAnno() >= anno);
        if (!annoCorrisponde) {
            continue;
        }

        bool copieCorrispondono = (copie <= 0 || articolo->getCopie() >= copie);
        if (!copieCorrispondono) {
            continue;
        }

        // Se siamo arrivati qui, l'articolo ha superato TUTTI i filtri generici.
        // Ora possiamo controllare i filtri specifici.

        // --- FASE 2: CONTROLLO FILTRI SPECIFICI ---
        
        bool corrispondenzaSpecifica = true; // Assumiamo che passi, a meno che non fallisca un test

        // Provo a fare il cast a Libro
        if (Libro* libro = dynamic_cast<Libro*>(articolo)) {
            // È un libro, applico i filtri per i libri
            // Nota: uso la logica AND. Un libro deve soddisfare TUTTI i filtri specifici attivi.
            
            // Se l'utente ha inserito un autore, controllalo
            if (!autore.isEmpty() && libro->getAutore() != autore.toStdString()) {
                corrispondenzaSpecifica = false;
            }
            // Se l'utente ha inserito un numero di capitoli, controllalo
            if (capitoli > 0 && libro->getCapitoli() < capitoli) {
                corrispondenzaSpecifica = false;
            }
            // Se l'utente ha inserito un numero di pagine, controllalo
            if (pagineL > 0 && libro->getPagine() < pagineL) {
                corrispondenzaSpecifica = false;
            }
        }
        // Altrimenti, provo a fare il cast a Rivista
        else if (Rivista* rivista = dynamic_cast<Rivista*>(articolo)) {
            // È una rivista, applico i filtri per le riviste
            int d = diff.toInt();

            if (!perd.isEmpty() && rivista->getIntervalloPubblicazione() != perd.toStdString()) {
                corrispondenzaSpecifica = false;
            }
            if (pagineR > 0 && rivista->getPagine() < pagineR) {
                corrispondenzaSpecifica = false;
            }
            if (d > 0 && rivista->getDifficolta() != d) {
                corrispondenzaSpecifica = false;
            }
        }
        // Altrimenti, provo a fare il cast a Film
        else if (Film* film = dynamic_cast<Film*>(articolo)) {
            // È un film, applico i filtri per i film

            if (!attore.isEmpty() && film->getAttori() != attore.toStdString()) {
                corrispondenzaSpecifica = false;
            }
            if (!produ.isEmpty() && film->getProduttore() != produ.toStdString()) {
                corrispondenzaSpecifica = false;
            }
            if (minuti > 0 && film->getDurata() < minuti) {
                corrispondenzaSpecifica = false;
            }
        }

        // --- FASE 3: AGGIUNTA ALLA LISTA FINALE ---
        // Se l'articolo ha superato sia i filtri generici (siamo ancora nel loop)
        // sia quelli specifici (corrispondenzaSpecifica è ancora true), lo aggiungo.
        if (corrispondenzaSpecifica) {
            risultatoFiltrato.push_back(articolo);
        }
    }

    // Ora che abbiamo la lista corretta, la passiamo alla funzione che aggiorna la vista
    filtra(risultatoFiltrato);
}
    



void FiltroLayout::periodicoFiltrato(const QString& text){
    perd = text;
    
}

void FiltroLayout::difficoltaFiltrato(const QString& v){
    diff = v;    
}

void FiltroLayout::pagineRivistaFiltrato(int value){
    pagineR = value;
    
}

void FiltroLayout::casaFiltrato(const QString& text){
    casa = text;
    
}

void FiltroLayout::autoreiltrato(const QString& text){
    autore = text;
}

void FiltroLayout::capitoliFiltrato(int value){
    capitoli = value;
    
}

void FiltroLayout::pagineFiltrato(int value) {
    pagineL = value;
}

void FiltroLayout::minutaggioFiltrato(int value) {
    minuti = value;
    
}

void FiltroLayout::attoreFiltrato(const QString& text) {
    attore = text;
    
}

void FiltroLayout::produFiltrato(const QString& text) {
    produ = text;
    
}

void FiltroLayout::annoFiltrato(int value) {
    anno = value;
    allFiltri();
}

void FiltroLayout::copieFiltrato(int value) {
    copie = value;
    allFiltri();
    filtroS->aggiorna();
}

void FiltroLayout::linguaFiltrato(const QString& text) {
    lang = text;
    allFiltri();
}

void FiltroLayout::categoriaFiltrato(const QString& text) {
    cat = text;
    allFiltri();
    
}

void FiltroLayout::ricercaScelta() {
    std::list<Articolo*> tmp = l->ricerca(l1->getArticoli(), ricerca->text().toStdString());
    filtra(tmp);
}

void FiltroLayout::importa(){
    emit importaClicked();
}

void FiltroLayout::filtraggio() {
    allFiltri();
}

void FiltroLayout::filtra(std::list<Articolo*> tmp) {

    if (filtro->currentText() == "Libri") {
        tmp = l->soloLibri(tmp);
    } else if (filtro->currentText() == "Riviste") {
        tmp = l->soloRiviste(tmp);
    } else if (filtro->currentText() == "Film") {
        tmp = l->soloFilm(tmp);
    }

    filtroS->setLayoutSpecifico(tmp.front());
    prev = filtro->currentIndex();
    lista = (l->getArticoli(tmp));
    layout2->addLayout(lista);
    layout->addLayout(layout2);

}

void FiltroLayout::nuovoClicked() {
    emit nuovo();
}

void FiltroLayout::nuovoSalvato(){
  emit listanuova();
}

void FiltroLayout::aggiorna() {

    if (l1->size() == 0) {
        gruppoFiltri->hide();
    } else {
        gruppoFiltri->show();
    }

    lista = (l->getArticoli(l1->getArticoli()));
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