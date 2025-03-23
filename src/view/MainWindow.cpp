#include "MainWindow.h"

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

    barra->setStyleSheet("QToolBar {margin:1px; border: 1px solid black; border-radius: 5px;}");

    QAction *nuovo = new QAction(QIcon(QPixmap((":/asset/icon/creanuovo.png"))),"CreaNuovo");
    QAction *importa = new QAction(QIcon(QPixmap((":/asset/icon/apri.png"))),"Importa");
    QAction *salvan = new QAction(QIcon(QPixmap((":/asset/icon/salva.png"))),"salva con nome");
    QAction *info = new QAction(QIcon(QPixmap((":/asset/icon/info.png"))),"Info");

    nuovo->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_N));
    importa->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_O));
    salvan->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_S));
    info->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_H));

    barra->addAction(nuovo);
    barra->addAction(importa);
    barra->addAction(salvan);
    barra->addAction(info);

    toll->addWidget(barra);

    main->addLayout(toll);
    main->addWidget(f);

    status = new QStatusBar();
    status->showMessage("Status bar: ...");
    status->setStyleSheet("QStatusBar {border: 1px solid black; border-radius: 5px;}");
    main->addWidget(status);

    widgetmain = new QWidget();

    widgetmain->setLayout(main);

    stack->addWidget(widgetmain);
    stack->addWidget(s);
    stack->setSizeConstraint(QLayout::SetMinimumSize);
	adjustSize();

    connect(salvan, &QAction::triggered, this, &MainWindow::salvaListaSlot);
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

void MainWindow::salvaListaSlot() {
    Json json;
    pathLista = l->getListaPath();
    if (pathLista == ""){
        json.salvaJsonLista(*l);
        messaggio = "Lista salvata";
        status->showMessage(messaggio.c_str());
        pathLista = json.getFileName().toStdString();
        std::cout << pathLista << std::endl;
    } else {
        json.salvaSNLista(*l, QString::fromStdString(pathLista));
        }
}

void MainWindow::nuovoClicked() {
    stack->setCurrentWidget(s);
}

void MainWindow::nuovoSalvato() {
  	stack->setCurrentWidget(widgetmain);
  	f->aggiorna();
    messaggio = "Articolo creato con successo";
    status->showMessage(messaggio.c_str());
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
    //layoutButtons->addStretch();
    QPushButton* indietro = new QPushButton();
    indietro->setIcon(QIcon(QPixmap(":/asset/icon/indietro.png")));
    layoutButtons->addWidget(indietro,0,Qt::AlignLeft);
    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addLayout(layoutButtons);
    mainLayout->addLayout(layout);

    mostra->setLayout(mainLayout);

    stack->addWidget(mostra);
    stack->setCurrentWidget(mostra);

    connect(indietro, &QPushButton::clicked, this, &MainWindow::annullatoClicked);
}

void MainWindow::modificaMainSlot(Articolo* a) {
    emit modificaSignal(a);
}

void MainWindow::salvaSlot(Articolo* a) {
    Json json;
    if(a && !(l->checkSalvato(a))){
        json.salvaJson(*a);
        l->salvaMappa(json.getFileName().toStdString(), a);
        std::cout << json.getFileName().toStdString() << std::endl;
    }

    if(l->checkSalvato(a)){
        json.salvaSN(*a, QString::fromStdString(l->getPath(a)));
    }

    messaggio = "Articolo salvato";
    status->showMessage(messaggio.c_str());
}

void MainWindow::cancellaSlot(Articolo* a) {

	QMessageBox msgBox;
	msgBox.setText("Sei sicuro di voler cancellare l'articolo?");
	msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	msgBox.setDefaultButton(QMessageBox::Yes);

	int ret = msgBox.exec();

	if (ret == QMessageBox::Yes && a) {
    	l->removeArticolo(a);
    	f->aggiorna();
    	delete a;
        messaggio = "Articolo cancellato";
    	status->showMessage(messaggio.c_str());
	}
}

void MainWindow::importaSlot() {
    Json j;
    j.importa(l);
    f->aggiorna();
    messaggio = "Importata effettuato con successo";
    status->showMessage(messaggio.c_str());
}

void MainWindow::infoSlot() {
    QMessageBox *msg = new QMessageBox();
    msg->setText("Per creare un nuovo articolo\n -> CTRL + N\nPer importare un articolo o lista\n -> CTRL + O\nPer salvare una lista\n -> CTRL + S\nOgni articolo può essere cliccato con il tasto destro per visualizzarne i dettagli \n o con il tasto sinistro per aprire il menu");
    QPixmap image(":/asset/icon/info.png");
    msg->setIconPixmap(image);
    msg->show();
}

void MainWindow::modificaSlot(Articolo* a) {
    Edit* edit = new Edit(this,l);
    edit->setArticolo(a);
    connect(edit, &Edit::modificheConfermate, this, &MainWindow::confermaModifica);
    connect(edit, &Edit::indietrosignal, this, &MainWindow::annullatoClicked);
    stack->addWidget(edit);
    stack->setCurrentWidget(edit);
}

void MainWindow::confermaModifica() {
    std::cout << "confermaModifica" << std::endl;
    stack->setCurrentWidget(widgetmain);
    f->aggiorna();
    messaggio = "Modifica effettuata con successo";
    status->showMessage(messaggio.c_str());
}
