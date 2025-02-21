#include "FiltroLayout.h"

FiltroLayout::FiltroLayout(QWidget* parent, std::list<Articolo*> articoli) : QWidget(parent), l(new ListaQT(articoli)), articoli(articoli) {
    stack = new QStackedLayout(this);
    widgetmain = new QWidget();
    main = new QVBoxLayout();

    std::list<Articolo*> art;;

    l1 = new ListaArticoli(art);
    l1->addArticolo(new Rivista("genocidio di ebrei","codice", "descrizione", "genere", 2021, 10, "lingua", "editore", 100, "pubblicatore", 1, 1, 1));

    layout = new QVBoxLayout();

    layout2 = new QHBoxLayout();

    QGroupBox* gruppoFiltri = new QGroupBox();

    barra = new QToolBar();

    barra->setOrientation(Qt::Vertical);
    //barra(Qt::LeftToolBarArea, barra);
    barra->setOrientation(Qt::Horizontal);

    QAction *nuovo = new QAction(QIcon(QPixmap((":/asset/icon/creanuovo.png"))),"CreaNuovo");
    QAction *importa = new QAction(QIcon(QPixmap((":/asset/icon/apri.png"))),"Importa");
    QAction *salvan = new QAction(QIcon(QPixmap((":/asset/icon/salvaJson.png"))),"salva con nome");
    QAction *info = new QAction(QIcon(QPixmap((":/asset/icon/info.png"))),"Info");

    barra->addAction(nuovo);
    barra->addAction(importa);
    barra->addAction(salvan);
    barra->addAction(info);

    layout->addWidget(barra);

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
    //filtri->addWidget(salva);

    gruppoFiltri->setLayout(filtri);
    layout2->addWidget(gruppoFiltri);

    //lista = l->getArticoli(articoli);

    l = new ListaQT(l1->getArticoli());

    layout2->addWidget(l);

    QSpacerItem* spacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding);

    filtri->addItem(spacer);


    layout->addLayout(layout2);

    main->addLayout(layout);

    widgetmain->setLayout(main);

    stack->addWidget(widgetmain);
    creazioneArticolo = new Nuovo(nullptr,l1);
    stack->addWidget(creazioneArticolo);

    connect(filtro, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &FiltroLayout::ricercaScelta);
    connect(ricerca, &QLineEdit::textChanged, this, &FiltroLayout::ricercaScelta);
    connect(nuovo, &QAction::triggered, this, &FiltroLayout::nuovoClicked);

    //connect(ListaQT::nuovo, &QPushButton::clicked, this, &FiltroLayout::nuovoClicked);
        connect(l, &ListaQT::nuovoClicked, this, &FiltroLayout::nuovoClicked);
    connect(l, &ListaQT::dettaglioClicked, this, &FiltroLayout::dettagli);

    connect(creazioneArticolo, &Nuovo::annullatoCliked, this, &FiltroLayout::nuovoSalvato);
    connect(creazioneArticolo, &Nuovo::salvaClicked, this, &FiltroLayout::nuovoSalvato);
}



void FiltroLayout::ricercaScelta() {
    std::list<Articolo*> tmp = l->ricerca(l1->getArticoli(), ricerca->text().toStdString());
    filtra(tmp);
}

void FiltroLayout::filtra(std::list<Articolo*> tmp) {

    if (filtro->currentText() == "Libri") {
        tmp = l->soloLibri(tmp);
    } else if (filtro->currentText() == "Riviste") {
        tmp = l->soloRiviste(tmp);
    } else if (filtro->currentText() == "Film") {
        tmp = l->soloFilm(tmp);
    }

    if (!tmp.empty()) {
        lista = l->getArticoli(tmp);
        layout2->addLayout(lista);
        layout->addLayout(layout2);

    } else {
        QLabel* noRecord = new QLabel("No record found");
        lista = l->getArticoli(tmp);
        layout2->addWidget(noRecord);
        layout->addLayout(layout2);
    }

}

void FiltroLayout::nuovoClicked() {
    stack->setCurrentIndex(1);
}

void FiltroLayout::nuovoSalvato() {
    stack->setCurrentIndex(0);
    lista = l->getArticoli(l1->getArticoli());
    layout2->addLayout(lista);
    layout->addLayout(layout2);
}

void FiltroLayout::dettagli(Articolo* a) {
std::cout<<a->getTitolo()<<std::endl;
}