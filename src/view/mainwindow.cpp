#include "mainwindow.h"
#include <iostream>
#include <list>
MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    stack = new QStackedLayout(this);

    main = new QVBoxLayout();

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

    nuovo->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_N));
    importa->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
    salvan->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));
    info->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_H));

    barra->addAction(nuovo);
    barra->addAction(importa);
    barra->addAction(salvan);
    barra->addAction(info);

    toll->addWidget(barra);

    main->addLayout(toll);
    main->addWidget(f);

    QStatusBar* status = new QStatusBar();
    status->showMessage("halo");
    main->addWidget(status);

    widgetmain = new QWidget();

    widgetmain->setLayout(main);

    stack->addWidget(widgetmain);
    stack->addWidget(s);
    stack->setSizeConstraint(QLayout::SetMinimumSize);
	adjustSize();

    connect(importa, &QAction::triggered, this, &MainWindow::importaSlot);

    connect(f,  &FiltroLayout::nuovo, this, &MainWindow::nuovoClicked);

	connect(nuovo, &QAction::triggered, this, &MainWindow::nuovoClicked);
    connect(s, &Nuovo::annullatoCliked, this, &MainWindow::annullatoClicked);

    connect(s, &Nuovo::salvaClicked, this, &MainWindow::nuovoSalvato);
    connect(info, &QAction::triggered, this, &MainWindow::infoSlot);

    connect(f, &FiltroLayout::dettaglioClicked, this, &MainWindow::mostaArticolo);
    connect(f, &FiltroLayout::salvaclic, this, &MainWindow::salvaSlot);
    connect(f, &FiltroLayout::cancellaclic, this, &MainWindow::cancellaSlot);
    connect(f, &FiltroLayout::modificaclic, this, &MainWindow::modificaSlot);
}

void MainWindow::nuovoClicked() {
    stack->setCurrentWidget(s);
}

void MainWindow::nuovoSalvato() {
  	stack->setCurrentWidget(widgetmain);
  	f->aggiorna();
}

void MainWindow::annullatoClicked() {
    stack->setCurrentWidget(widgetmain);
}

void MainWindow::mostaArticolo(Articolo* articolo) {

   if (mostra) {
        stack->removeWidget(mostra);
        mostra = nullptr;
    }

    MostraVisitor visitor;
    articolo->accept(visitor);

    mostra = new QWidget();

    QVBoxLayout* layout = visitor.getLayout();

    QHBoxLayout* layoutButtons = new QHBoxLayout();
    layoutButtons->addStretch();
    QPushButton* indietro = new QPushButton("Indietro");
    layoutButtons->addWidget(indietro);

    layout->addLayout(layoutButtons);

    mostra->setLayout(layout);

    stack->addWidget(mostra);
    stack->setCurrentWidget(mostra);

    connect(indietro, &QPushButton::clicked, this, &MainWindow::annullatoClicked);
    connect(indietro, &QPushButton::clicked, this, &MainWindow::annullatoClicked);
}

void MainWindow::salvaSlot(Articolo* a) {
    Json json;
    json.salvaJson(*a);
}

void MainWindow::cancellaSlot(Articolo* a) {
  	if (a){
    l->removeArticolo(a);
    f->aggiorna();
    delete a;
    }
}

void MainWindow::importaSlot() {
    Json j;
    Articolo* a = j.importaJson();
    if(a){
    	l->addArticolo(a);
    	f->aggiorna();
    }
}

void MainWindow::infoSlot() {
    QMessageBox *msg = new QMessageBox();
    msg->setText("Per creare un nuovo articolo\n -> CTRL + N\nPer importare un articolo\n -> CTRL + O\nPer salvare un articolo\n -> CTRL + S\n");
    QPixmap image(":/asset/icon/info.png");
    msg->setIconPixmap(image);
    msg->show();
}

void MainWindow::modificaSlot(Articolo* a) {
    Edit* edit = new Edit(this);
    edit->setArticolo(a);
    connect(edit, &Edit::modificheConfermate, this, &MainWindow::confermaModifica);
    stack->addWidget(edit);
    stack->setCurrentWidget(edit);
}

void MainWindow::confermaModifica() {
    std::cout << "confermaModifica" << std::endl;
    stack->setCurrentWidget(widgetmain);
    f->aggiorna();
}
