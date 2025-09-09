#include "ListaQT.h"

ListaQT::ListaQT(std::list<Articolo*> articoli) : articoli(articoli){
  	gruppo = new QGroupBox();
	tmp = new QVBoxLayout(gruppo);

    l = new QVBoxLayout();

    QHBoxLayout *b1l = new QHBoxLayout();
    QHBoxLayout *b2l = new QHBoxLayout();

    QLabel *b1Label = new QLabel();
    QLabel *b2Label = new QLabel();

    b1Label->setText("Crea un articolo nuovo");
    b1Label->setText("Importa una libreria");

    QPushButton* b1 = new QPushButton("CTRL + N");
    b1->setFlat(true);
    b1->setStyleSheet("color: blue; font-weight: bold; text-align: left;");

    QPushButton* b2 = new QPushButton("CTRL + 0");
    b2->setFlat(true);
    b2->setStyleSheet("color: blue; font-weight: bold; text-align: left;");

    b1l->addWidget(b1Label);
    b1l->addWidget(b1);

    b2l->addWidget(b2Label);
    b2l->addWidget(b2);

    l->addLayout(b1l);
    l->addLayout(b2l);

    tmp->addLayout(l);
    gruppo->setStyleSheet("QGroupBox {border: 1px solid grey; border-radius: 5px; margin-top: 1ex;}");
    layout->addWidget(gruppo);
}

void ListaQT::clicatoNuovo() {
    emit nuovoClicked();
}

void ListaQT::itemClicked(Articolo* articolo) {
    emit dettaglioClicked(articolo);
}

QHBoxLayout* ListaQT::getArticoli(std::list<Articolo*> articoli){

    pulisciLayout(layout);

    QScrollArea *scrollArea = new QScrollArea();
    QWidget *contentWidget = new QWidget();
    QGridLayout *gridLayout = new QGridLayout(contentWidget);
    gridLayout->setSpacing(10);
    scrollArea->setWidget(contentWidget);
    scrollArea->setWidgetResizable(true);

    QSlider *slider = new QSlider(Qt::Vertical);
    slider->setSingleStep(1);

    layout->addWidget(scrollArea);
    layout->addWidget(slider);

    int colonn = 3;
    int i = 0;
    for (auto a : articoli) {
        ListaVisitor visitor;
        a->accept(visitor);

        Cliccabile* c = new Cliccabile(a);
        c->minimumSize();
        c->setLayout(visitor.getLayout());
        c->minimumSizeHint();

        connect(c, &Cliccabile::clicked, this, &ListaQT::itemClicked);
        connect(c, &Cliccabile::salva, this, &ListaQT::salva);
        connect(c, &Cliccabile::cancella, this, &ListaQT::cancella);
        connect(c, &Cliccabile::dettagli, this, &ListaQT::dettaglio);
        connect(c, &Cliccabile::modifica, this, &ListaQT::modifica);

        gridLayout->addWidget(c, i / colonn, i % colonn);
        i++;
    }

    QVBoxLayout* tmp = new QVBoxLayout();
    QPixmap pixmap(":/asset/icon/nuovo.png");
    nuovo->setFixedSize(100, 100);
	QIcon icon(pixmap.scaled(500, 500, Qt::KeepAspectRatio));
	nuovo->setIcon(icon);
    //nuovo->setStyleSheet("QPushButton {background-color:;}");
    tmp->addWidget(nuovo,0,Qt::AlignCenter);
    QWidget* tmp2 = new QWidget();
    tmp2->setLayout(tmp);
    connect(nuovo, &QPushButton::clicked, this, &ListaQT::clicatoNuovo);

    gridLayout->addWidget(tmp2, i / colonn, i % colonn);

    QScrollBar *verticalScrollBar = scrollArea->verticalScrollBar();
    slider->setMinimum(verticalScrollBar->minimum());
    slider->setMaximum(verticalScrollBar->maximum());
    slider->setPageStep(verticalScrollBar->pageStep());

    connect(slider, &QSlider::valueChanged, verticalScrollBar, &QScrollBar::setValue);
    connect(verticalScrollBar, &QScrollBar::valueChanged, slider, &QSlider::setValue);

    //widgetGriglia->setStyleSheet("{border: 1px white; border-radius: 5px; margin-top: 1ex;}");
    //scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);<

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

        if (titolo.find(ricerca) == 0) {
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