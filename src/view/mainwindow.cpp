#include "mainwindow.h"
#include <iostream>
#include <list>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    QLoggingCategory::setFilterRules("*.debug=false");
    stack = new QStackedLayout(this);

    main = new QVBoxLayout();

    //LQ = new ListaQT(articoli);

    l = new ListaArticoli(articoli);
    f = new FiltroLayout(this, l);
    s = new Nuovo(this, l);


    barra = new QToolBar();
    toll = new QVBoxLayout();

    barra->setOrientation(Qt::Vertical);
    barra->setOrientation(Qt::Horizontal);

    QAction *nuovo = new QAction(QIcon(QPixmap((":/asset/icon/creanuovo.png"))),"CreaNuovo");
    QAction *importa = new QAction(QIcon(QPixmap((":/asset/icon/apri.png"))),"Importa");
    QAction *salvan = new QAction(QIcon(QPixmap((":/asset/icon/salvaJson.png"))),"salva con nome");
    QAction *info = new QAction(QIcon(QPixmap((":/asset/icon/info.png"))),"Info");

    barra->addAction(nuovo);
    barra->addAction(importa);
    barra->addAction(salvan);
    barra->addAction(info);

    toll->addWidget(barra);

    main->addLayout(toll);
    main->addWidget(f);

    widgetmain = new QWidget();

    widgetmain->setLayout(main);

    stack->addWidget(widgetmain);
    stack->addWidget(s);
    stack->setSizeConstraint(QLayout::SetMinimumSize);
	adjustSize();
    connect(f,  &FiltroLayout::nuovo, this, &MainWindow::nuovoClicked);
    //connect(l, &ListaArticoli::dettaglioClicked, this, &MainWindow::dettagli);
	connect(nuovo, &QAction::triggered, this, &MainWindow::nuovoClicked);
    connect(s, &Nuovo::annullatoCliked, this, &MainWindow::annullatoClicked);
    //connect(f, &FiltroLayout::listanuova, this, &MainWindow::nuovoSalvato);
    connect(s, &Nuovo::salvaClicked, this, &MainWindow::nuovoSalvato);
    connect(f, &FiltroLayout::dettaglioClicked, this, &MainWindow::mostaArticolo);
}

void MainWindow::dettagli(Articolo* a) {
    if (a) {
        std::cout << a->getTitolo() << std::endl;
    }
}

void MainWindow::nuovoClicked() {
 	std::cout<<"nuovoClicked"<<std::endl;
	stack->setCurrentIndex(1);

}

void MainWindow::nuovoSalvato() {
  	stack->setCurrentIndex(0);
  	f->nuovoSalvato12();
}

void MainWindow::annullatoClicked() {
    stack->setCurrentIndex(0);
}

void MainWindow::mostaArticolo(Articolo* articolo) {

    //std::cout << articolo->getTitolo() << std::endl;

    MostraVisitor visitor;
    articolo->accept(visitor);

    if (modifica) {
        stack->removeWidget(modifica);
        delete modifica;
        modifica = nullptr;
    }

    modifica = new QWidget();

    QVBoxLayout* layout = visitor.getLayout();

    QHBoxLayout* layoutButtons = new QHBoxLayout();
    layoutButtons->addStretch();  // Per allineare a destra il pulsante
    indietro = new QPushButton("Indietro");
    layoutButtons->addWidget(indietro);

    layout->addLayout(layoutButtons);

    modifica->setLayout(layout);

    stack->addWidget(modifica);
    stack->setCurrentWidget(modifica);

    connect(indietro, &QPushButton::clicked, this, &MainWindow::annullatoClicked);
}


void MainWindow::modificaArticolo() {
    //editVisitor visitor;
    //stack->setCurrentIndex(1);
}