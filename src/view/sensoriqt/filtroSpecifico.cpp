#include "filtroSpecifico.h"

filtroSpecifico::filtroSpecifico(QWidget* parent, ListaArticoli* LA) : QWidget(parent), l1(LA) {

    mainFiltroSpecifico = new QVBoxLayout(this);

    annoSplitter = new QSlider(Qt::Horizontal, this);
    copieSplitter = new QSlider(Qt::Horizontal, this);

    linguaCombo = new QComboBox();

    annoSplitter->setRange(0, l1->maxAnni());

    int maxCopie = LA->maxCopie();
    copieSplitter->setValue(0);
    copieSplitter->setRange(0, maxCopie);

    linguaCombo->addItems({"Tutti","Italiano", "Inglese", "Spagnolo", "Francese", "Tedesco"});

    categoria = new QComboBox();
    categoria->addItems({"Tutti","Fantascienza", "Giallo", "Horror", "Scienza", "Storico", "Thriller"});

    QLabel* annoLabel = new QLabel(QString("Anno: %1").arg(annoSplitter->value()));
    QLabel* copieLabel = new QLabel(QString("Copie: %1").arg(copieSplitter->value()));

    connect(annoSplitter, &QSlider::valueChanged, [annoLabel](int value) {
        annoLabel->setText(QString("Anno: %1").arg(value));
    });

    connect(copieSplitter, &QSlider::valueChanged, [copieLabel](int value) {
        copieLabel->setText(QString("Copie: %1").arg(value));
    });


    filtroFilm(LA);
    filtroLibro(LA);
    filtroRivista(LA);

    mainFiltroSpecifico->addWidget(annoLabel);
    mainFiltroSpecifico->addWidget(annoSplitter);
    mainFiltroSpecifico->addWidget(copieLabel);
    mainFiltroSpecifico->addWidget(copieSplitter);
    mainFiltroSpecifico->addWidget(linguaCombo);
    mainFiltroSpecifico->addWidget(categoria);

    if(layoutSpecifico)
        mainFiltroSpecifico->addLayout(layoutSpecifico);

}

void filtroSpecifico::filtroFilm(ListaArticoli* LA){

    layoutFilm = new QVBoxLayout();
    

    minutaggioDial = new QDial();
    int max = LA->maxMinutaggio();
    minutaggioDial->setRange(0,max);
    QLabel* minutaggioLabel = new QLabel(QString("Minutaggio: %1").arg(minutaggioDial->value()));

    attoreCombo = new QComboBox();
    produCombo = new QComboBox();

    std::list<std::string*> attoriLista;
    attoriLista = LA->allAttori();
    std::list<std::string*> produLista;
    produLista = LA->allProdu();

    for(auto a : attoriLista){
        attoreCombo->addItem(QString::fromStdString(*a));
    }

    for(auto p : produLista){
        produCombo->addItem(QString::fromStdString(*p));
    }
    QLabel* labelFilm = new QLabel("FILM");
    labelFilm->setAlignment(Qt::AlignCenter);
    layoutFilm->addWidget(labelFilm);
    layoutFilm->addWidget(minutaggioLabel);
    layoutFilm->addWidget(minutaggioDial);
    layoutFilm->addWidget(new QLabel("Attore:"));
    layoutFilm->addWidget(attoreCombo);
    layoutFilm->addWidget(new QLabel("Produttore:"));
    layoutFilm->addWidget(produCombo);

    connect(minutaggioDial, &QDial::valueChanged, [minutaggioLabel](int value) {
        minutaggioLabel->setText(QString("Minutaggio: %1").arg(value));
    });

}

void filtroSpecifico::aggiorna() {
    if (!l1) return;

    annoSplitter->setRange(0, l1->maxAnni());

    copieSplitter->setRange(0, l1->maxCopie());
    copieSplitter->setValue(0);


    if (attoreCombo) {
        attoreCombo->clear();
        for (auto a : l1->allAttori()) {
            attoreCombo->addItem(QString::fromStdString(*a));
        }
    }

    if (produCombo) {
        produCombo->clear();
        for (auto p : l1->allProdu()) {
            produCombo->addItem(QString::fromStdString(*p));
        }
    }

    if (minutaggioDial) {
        minutaggioDial->setRange(0, l1->maxMinutaggio());
        minutaggioDial->setValue(0);
    }

    if (pagineDial) {
        pagineDial->setRange(0, l1->maxPagine());
        pagineDial->setValue(0);
    }

    if (capitoliDial) {
        capitoliDial->setRange(0, l1->maxCapitoli());
        capitoliDial->setValue(0);
    }

    if (autoreCombo) {
        autoreCombo->clear();
        for (auto a : l1->allAutoriLibri()) {
            autoreCombo->addItem(QString::fromStdString(*a));
        }
    }

    if (casaEditriceCombo) {
        casaEditriceCombo->clear();
        for (auto c : l1->allCaseEditrici()) {
            casaEditriceCombo->addItem(QString::fromStdString(*c));
        }
    }

    if (pagineRivistaSlider) {
        pagineRivistaSlider->setRange(0, l1->maxPagineRivista());
        pagineRivistaSlider->setValue(0);
    }

    if (periodicoCombo) {
        periodicoCombo->clear();
        for (auto p : l1->allPeriodici()) {
            periodicoCombo->addItem(QString::fromStdString(*p));
        }
    }

    if (difficoltaCombo) {
        difficoltaCombo->setCurrentIndex(0);
    }

   
}



void filtroSpecifico::filtroLibro(ListaArticoli* LA) {

    layoutLibro = new QVBoxLayout();

    pagineDial = new QDial();
    int maxPagine = LA->maxPagine();
    pagineDial->setRange(0, maxPagine);
    QLabel* pagineLabel = new QLabel(QString("Pagine: %1").arg(pagineDial->value()));

    capitoliDial = new QDial();
    int maxCapitoli = LA->maxCapitoli();
    capitoliDial->setRange(0, maxCapitoli);
    QLabel* capitoliLabel = new QLabel(QString("Capitoli: %1").arg(capitoliDial->value()));

    autoreCombo = new QComboBox();
    casaEditriceCombo = new QComboBox();

    std::list<std::string*> autoriLista = LA->allAutoriLibri();
    std::list<std::string*> caseEditriciLista = LA->allCaseEditrici();

    for (auto a : autoriLista) {
        autoreCombo->addItem(QString::fromStdString(*a));
    }

    for (auto c : caseEditriciLista) {
        casaEditriceCombo->addItem(QString::fromStdString(*c));
    }

    QLabel* labelLibro = new QLabel("LIBRI");
    labelLibro->setAlignment(Qt::AlignCenter);
    layoutLibro->addWidget(labelLibro);
    layoutLibro->addWidget(pagineLabel);
    layoutLibro->addWidget(pagineDial);
    layoutLibro->addWidget(capitoliLabel);
    layoutLibro->addWidget(capitoliDial);
    layoutLibro->addWidget(new QLabel("Autore:"));
    layoutLibro->addWidget(autoreCombo);
    layoutLibro->addWidget(new QLabel("Casa Editrice:"));
    layoutLibro->addWidget(casaEditriceCombo);

    connect(pagineDial, &QDial::valueChanged, [pagineLabel](int value) {
        pagineLabel->setText(QString("Pagine: %1").arg(value));
    });

    connect(capitoliDial, &QDial::valueChanged, [capitoliLabel](int value) {
        capitoliLabel->setText(QString("Capitoli: %1").arg(value));
    });
}

void filtroSpecifico::filtroRivista(ListaArticoli* LA) {
    layoutRivista = new QVBoxLayout();
    pagineRivistaSlider = new QSlider(Qt::Horizontal, this);
    int maxPagineRivista = LA->maxPagineRivista();
    pagineRivistaSlider->setRange(0, maxPagineRivista);
    QLabel* pagineRivistaLabel = new QLabel(QString("Pagine Rivista: %1").arg(pagineRivistaSlider->value()));
    difficoltaCombo = new QComboBox();
    difficoltaCombo->addItems({"Tutti","1","2", "3", "4", "5"});
    periodicoCombo = new QComboBox();
    std::list<std::string*> periodiciLista = LA->allPeriodici();
    for (auto p : periodiciLista) {
        if (p && !p->empty()) {
            periodicoCombo->addItem(QString::fromStdString(*p));
        }
    }

    connect(pagineRivistaSlider, &QSlider::valueChanged, [pagineRivistaLabel](int value) {
        pagineRivistaLabel->setText(QString("Pagine Rivista: %1").arg(value));
    });



    QLabel* labelRivista = new QLabel("RIVISTE");
    labelRivista->setAlignment(Qt::AlignCenter);
    layoutRivista->addWidget(labelRivista);
    layoutRivista->addWidget(pagineRivistaLabel);
    layoutRivista->addWidget(pagineRivistaSlider);
    layoutRivista->addWidget(new QLabel("Periodico:"));
    layoutRivista->addWidget(periodicoCombo);
    layoutRivista->addWidget(new QLabel("Difficoltà:"));
    layoutRivista->addWidget(difficoltaCombo);
}

void setLayoutSpecifico(Articolo* a) {

    QVBoxLayout *layoutSpecifico = new QVBoxLayout();


}