#include "FiltroLayout.h"

FiltroLayout::FiltroLayout(QWidget* parent, std::list<Articolo*> articoli) : QWidget(parent), l(new ListaQT(articoli)), articoli(articoli) {
    lll = new QStackedLayout(this);
    widgetmain = new QWidget();
    main = new QVBoxLayout();

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
    l = new ListaQT(articoli);

    layout2->addWidget(l);

    QSpacerItem* spacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding);

    filtri->addItem(spacer);


    layout->addLayout(layout2);

    main->addLayout(layout);

    widgetmain->setLayout(main);

    lll->addWidget(widgetmain);
    creazioneArticolo = new Nuovo();
    lll->addWidget(creazioneArticolo);

    connect(filtro, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &FiltroLayout::ricercaScelta);
    connect(ricerca, &QLineEdit::textChanged, this, &FiltroLayout::ricercaScelta);
    connect(nuovo, &QAction::triggered, this, &FiltroLayout::nuovoClicked);

    //connect(ListaQT::nuovo, &QPushButton::clicked, this, &FiltroLayout::nuovoClicked);
}



void FiltroLayout::ricercaScelta() {
    std::list<Articolo*> tmp = l->ricerca(articoli, ricerca->text().toStdString());
    filtra(tmp);
}

void FiltroLayout::filtra(std::list<Articolo*> tmp) {

   /*
    if (!ricerca->text().isEmpty()) {
        tmp = l.ricerca(articoli, ricerca->text().toStdString());
    } else {
        tmp = articoli;
    }*/
    if (filtro->currentText() == "Libri") {
        tmp = l->soloLibri(tmp);
    } else if (filtro->currentText() == "Riviste") {
        tmp = l->soloRiviste(tmp);
    } else if (filtro->currentText() == "Film") {
        tmp = l->soloFilm(tmp);
    }

    l = new ListaQT(tmp);
    mostraSalva->addWidget(l);

    QWidget *container = new QWidget();
    container->setLayout(mostraSalva);

}

void FiltroLayout::nuovoClicked() {
    lll->setCurrentIndex(1);
}

void FiltroLayout::nuovoSalvato() {
    lll->setCurrentIndex(0);
}