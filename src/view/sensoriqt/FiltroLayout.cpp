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
    applicaBtn = new QPushButton("Applica Filtri Specifici");
    

    filtri->addWidget(label2);
    filtri->addWidget(filtro);
    filtri->addWidget(label3);
    filtri->addWidget(filtro2);
    filtri->addWidget(fitriSpecificiCombo);
    filtri->addWidget(applicaBtn);

    gruppoFiltri->setLayout(filtri);
    layout2->addWidget(gruppoFiltri);

    gruppoFiltri->hide();

    l = new ListaQT(l1->getArticoli());

    layout2->addWidget(l);

    QSpacerItem* spacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding);

    filtri->addItem(spacer);

    layout->addLayout(layout2);

    main->addLayout(layout);
    filtroS->aggiorna();

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

 

    connect(applicaBtn, &QPushButton::clicked, this, &FiltroLayout::allFiltri);

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

    connect(filtroS, &filtroSpecifico::pagineRivistaValueChanged, this, &FiltroLayout::pagineRivistaFiltrato);
    connect(filtroS, &filtroSpecifico::periodicoValueChanged, this, &FiltroLayout::periodicoFiltrato);
    connect(filtroS, &filtroSpecifico::difficoltaValueChanged, this, &FiltroLayout::difficoltaFiltrato);
}


void FiltroLayout::allFil(){

        filtroS->aggiorna();
}

void FiltroLayout::allFiltri() {
    filtroS->aggiorna();
    std::list<Articolo*> risultatoFiltrato;

    for (auto articolo : l1->getArticoli()) {
        if (!(lang == "Tutti" || QString::fromStdString(articolo->getLingua()) == lang)) continue;
        if (!(cat == "Tutti" || QString::fromStdString(articolo->getGenere()) == cat)) continue;
        if (!(anno <= 0 || articolo->getAnno() >= anno)) continue;
        if (!(copie <= 0 || articolo->getCopie() >= copie)) continue;
        
        bool filtriSpecificiAttiviPerQuestoTipo = false;
        bool corrispondenzaSpecificaTrovata = false;

        if (Libro* libro = dynamic_cast<Libro*>(articolo)) {

            if (!autore.isEmpty() || capitoli > 0 || pagineL > 0) {
                filtriSpecificiAttiviPerQuestoTipo = true;
                qDebug() << "  -> Filtri Libro ATTIVI. Autore:" << autore << "Capitoli >=" << capitoli << "Pagine >=" << pagineL;
                
                if (!autore.isEmpty() && libro->getAutore() == autore.toStdString()) corrispondenzaSpecificaTrovata = true;
                if (!corrispondenzaSpecificaTrovata && capitoli > 0 && libro->getCapitoli() >= capitoli) corrispondenzaSpecificaTrovata = true;
                if (!corrispondenzaSpecificaTrovata && pagineL > 0 && libro->getPagine() >= pagineL) corrispondenzaSpecificaTrovata = true;
            }
        }
        else if (Rivista* rivista = dynamic_cast<Rivista*>(articolo)) {
            qDebug() << "Trovata una Rivista:" << QString::fromStdString(rivista->getTitolo());
            int d = diff.toInt();

            if (!perd.isEmpty() || pagineR > 0 || d > 0) {
                filtriSpecificiAttiviPerQuestoTipo = true;
                qDebug() << "  -> Filtri Rivista ATTIVI. Periodo:" << perd << "Pagine >=" << pagineR << "Difficolta ==" << d;
                
                if (!perd.isEmpty() && rivista->getIntervalloPubblicazione() == perd.toStdString()) corrispondenzaSpecificaTrovata = true;
               
                if (!corrispondenzaSpecificaTrovata && d > 0 && rivista->getDifficolta() == d) corrispondenzaSpecificaTrovata = true;
                if (!corrispondenzaSpecificaTrovata && pagineR > 0 && rivista->getPagine() >= pagineR) corrispondenzaSpecificaTrovata = true;
            }
        }
    
        else if (Film* film = dynamic_cast<Film*>(articolo)) {
            qDebug() << "Trovato un Film:" << QString::fromStdString(film->getTitolo());

    
            if (!attore.isEmpty() || !produ.isEmpty() || minuti > 0) {
                filtriSpecificiAttiviPerQuestoTipo = true;
                 qDebug() << "  -> Filtri Film ATTIVI. Attore:" << attore << "Produttore:" << produ << "Minuti >=" << minuti;

    
                if (!attore.isEmpty() && film->getAttori() == attore.toStdString()) corrispondenzaSpecificaTrovata = true;
                if (!corrispondenzaSpecificaTrovata && !produ.isEmpty() && film->getProduttore() == produ.toStdString()) corrispondenzaSpecificaTrovata = true;
                if (!corrispondenzaSpecificaTrovata && minuti > 0 && film->getDurata() >= minuti) corrispondenzaSpecificaTrovata = true;
            }
        }
        if (!filtriSpecificiAttiviPerQuestoTipo || corrispondenzaSpecificaTrovata) {
            risultatoFiltrato.push_back(articolo);
        }
    }

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

    filtroS->aggiorna();

    if (filtro->currentText() == "Libri") {
        tmp = l->soloLibri(tmp);
    } else if (filtro->currentText() == "Riviste") {
        tmp = l->soloRiviste(tmp);
    } else if (filtro->currentText() == "Film") {
        tmp = l->soloFilm(tmp);
    } else if (filtro->currentText() == "Tutti"){
        filtroS->backNormale();
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