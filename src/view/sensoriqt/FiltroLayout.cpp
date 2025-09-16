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
    connect(filtro, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &FiltroLayout::allFiltri);
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

    connect(filtroS, &filtroSpecifico::pagineValueChanged, this, &FiltroLayout::pagineFiltrato);
    connect(filtroS, &filtroSpecifico::capitoliValueChanged, this, &FiltroLayout::capitoliFiltrato);
    connect(filtroS, &filtroSpecifico::autoreValueLibroChanged, this, &FiltroLayout::autoreiltrato);
    connect(filtroS, &filtroSpecifico::casaEditriceValueChanged, this, &FiltroLayout::casaFiltrato);

    connect(filtroS, &filtroSpecifico::pagineRivistaValueChanged, this, &FiltroLayout::pagineRivistaFiltrato);
    connect(filtroS, &filtroSpecifico::periodicoValueChanged, this, &FiltroLayout::periodicoFiltrato);
    connect(filtroS, &filtroSpecifico::difficoltaValueChanged, this, &FiltroLayout::difficoltaFiltrato);
}

void FiltroLayout::allFiltri() {

    filtroS->aggiorna();

    std::list<Articolo*> tmp;

    if (filtro->currentText() == "Film") {
        for (auto a : l1->getArticoli()) {
            if (Film* f = dynamic_cast<Film*>(a)) {
                if (f->getAttori() == attore.toStdString() ||
                    f->getProduttore() == produ.toStdString() ||
                    f->getDurata() >= minuti) 
                {
                    tmp.push_back(a);
                }
            }
        }
    } else if (filtro->currentText() == "Libri") {
        for (auto a : l1->getArticoli()) {
            if (Libro* f = dynamic_cast<Libro*>(a)) {
                if (f->getPagine() >= pagineL ||
                    f->getCapitoli() >= capitoli ||
                    f->getAutore() == autore.toStdString() ||
                    f->getCasaEditrice() == casa.toStdString()) 
                {
                    tmp.push_back(a);
                }
            }
        }
    } else if (filtro->currentText() == "Riviste") {
        int di = diff.toInt();
        for (auto a : l1->getArticoli()) {
            if (Rivista* f = dynamic_cast<Rivista*>(a)) {
                if (f->getIntervalloPubblicazione() == perd.toStdString() ||
                    f->getDifficolta() == di ||
                    f->getPagine() >= pagineR) 
                {
                    tmp.push_back(a);
                }
            }
        }
    } else if (filtro->currentText() == "Tutti") {
       

    for(auto a : tmp){
        if (a->getAnno() >= anno ||
                    a->getCopie() >= copie ||
                    a->getGenere() == cat.toStdString() ||
                    a->getLingua() == lang.toStdString())
                {
                    tmp.push_back(a);
                }
    }
        
    filtroS->backNormale();
    tmp = l1->getArticoli();
    }

    if (!tmp.empty()) 
        filtroS->setLayoutSpecifico(tmp.front());

    lista = l->getArticoli(tmp);
    layout2->addLayout(lista);
    layout->addLayout(layout2);

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
    copie=value;
    
    
}

void FiltroLayout::linguaFiltrato(const QString& text) {
    lang = text;
   
    
}

void FiltroLayout::categoriaFiltrato(const QString& text) {
    cat = text;
   
    
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