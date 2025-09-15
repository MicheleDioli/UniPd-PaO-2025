#include "filtroSpecifico.h"

filtroSpecifico::filtroSpecifico(QWidget* parent, ListaArticoli* LA) : QWidget(parent), l1(LA){
    mainFiltroSpecifico = new QVBoxLayout(this);
    stackedWidget = new QStackedWidget(this);
    
    setupPaginaFilm();
    setupPaginaLibro();
    setupPaginaRivista();

    QWidget* spacer = new QWidget();

    stackedWidget->addWidget(paginaFilm);   
    stackedWidget->addWidget(paginaLibro);  
    stackedWidget->addWidget(paginaRivista);
    stackedWidget->addWidget(spacer);       

    stackedWidget->setCurrentWidget(nullptr);

    // widget comuni
    annoSplitter = new QSlider(Qt::Horizontal, this);
    copieSplitter = new QSlider(Qt::Horizontal, this);
    linguaCombo = new QComboBox();
    categoria = new QComboBox();

    annoSplitter->setRange(l1->minAnni(), l1->maxAnni());
    copieSplitter->setRange(0, l1->maxCopie());
    copieSplitter->setValue(0);

    linguaCombo->addItems({"Tutti","Italiano","Inglese","Spagnolo","Francese","Tedesco"});
    categoria->addItems({"Tutti","Fantascienza","Giallo","Horror","Scienza","Storico","Thriller"});

    QLabel* annoLabel = new QLabel(QString("Anno: %1").arg(annoSplitter->value()));
    QLabel* copieLabel = new QLabel(QString("Copie: %1").arg(copieSplitter->value()));

    connect(annoSplitter, &QSlider::valueChanged, [annoLabel](int value){
        annoLabel->setText(QString("Anno: %1").arg(value));
    });

    connect(copieSplitter, &QSlider::valueChanged, [copieLabel](int value){
        copieLabel->setText(QString("Copie: %1").arg(value));
    });

    mainFiltroSpecifico->addWidget(annoLabel);
    mainFiltroSpecifico->addWidget(annoSplitter);
    mainFiltroSpecifico->addWidget(copieLabel);
    mainFiltroSpecifico->addWidget(copieSplitter);
    mainFiltroSpecifico->addWidget(linguaCombo);
    mainFiltroSpecifico->addWidget(categoria);
    mainFiltroSpecifico->addWidget(stackedWidget);
        
    connect(annoSplitter, &QSlider::valueChanged, this, [this](int value){
        emit annoValueChanged(value);
    });

    connect(copieSplitter, &QSlider::valueChanged, this, [this](int value){
        emit copieValueChanged(value);
    });

    connect(linguaCombo, &QComboBox::currentTextChanged, this, [this](const QString &text){
        emit linguaValueChanged(text);
    });

    connect(categoria, &QComboBox::currentTextChanged, this, [this](const QString &text){
        emit categoriaValueChanged(text);
    });


}

void filtroSpecifico::setupPaginaFilm() {
    paginaFilm = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(paginaFilm);

    QLabel* labelFilm = new QLabel("FILM");
    labelFilm->setAlignment(Qt::AlignCenter);

    minutaggioDial = new QDial();
    minutaggioDial->setRange(0, l1->maxMinutaggio());
    QLabel* minutaggioLabel = new QLabel(QString("Minutaggio: %1").arg(minutaggioDial->value()));

    attoreCombo = new QComboBox();
    for(auto a : l1->allAttori()) attoreCombo->addItem(QString::fromStdString(*a));

    produCombo = new QComboBox();
    for(auto p : l1->allProdu()) produCombo->addItem(QString::fromStdString(*p));

    layout->addWidget(labelFilm);
    layout->addWidget(minutaggioLabel);
    layout->addWidget(minutaggioDial);
    layout->addWidget(new QLabel("Attore:"));
    layout->addWidget(attoreCombo);
    layout->addWidget(new QLabel("Produttore:"));
    layout->addWidget(produCombo);

    connect(minutaggioDial, &QDial::valueChanged, [minutaggioLabel](int value){
        minutaggioLabel->setText(QString("Minutaggio: %1").arg(value));
    });

    connect(minutaggioDial, &QDial::valueChanged, this, [this](int value){
    emit minutaggioValueChanged(value);
    });

    connect(attoreCombo, &QComboBox::currentTextChanged, this, [this](const QString &text){
        emit attoreValueChanged(text);
    });

    connect(produCombo, &QComboBox::currentTextChanged, this, [this](const QString &text){
        emit produValueChanged(text);
    });

}

void filtroSpecifico::setupPaginaLibro() {
    paginaLibro = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(paginaLibro);

    pagineDial = new QDial();
    pagineDial->setRange(0, l1->maxPagine());
    QLabel* pagineLabel = new QLabel(QString("Pagine: %1").arg(pagineDial->value()));

    capitoliDial = new QDial();
    capitoliDial->setRange(0, l1->maxCapitoli());
    QLabel* capitoliLabel = new QLabel(QString("Capitoli: %1").arg(capitoliDial->value()));

    autoreCombo = new QComboBox();
    casaEditriceCombo = new QComboBox();
    for(auto a : l1->allAutoriLibri()) autoreCombo->addItem(QString::fromStdString(*a));
    for(auto c : l1->allCaseEditrici()) casaEditriceCombo->addItem(QString::fromStdString(*c));

    QLabel* labelLibro = new QLabel("LIBRI");
    labelLibro->setAlignment(Qt::AlignCenter);

    layout->addWidget(labelLibro);
    layout->addWidget(pagineLabel);
    layout->addWidget(pagineDial);
    layout->addWidget(capitoliLabel);
    layout->addWidget(capitoliDial);
    layout->addWidget(new QLabel("Autore:"));
    layout->addWidget(autoreCombo);
    layout->addWidget(new QLabel("Casa Editrice:"));
    layout->addWidget(casaEditriceCombo);

    connect(pagineDial, &QDial::valueChanged, [pagineLabel](int value){
        pagineLabel->setText(QString("Pagine: %1").arg(value));
    });
    connect(capitoliDial, &QDial::valueChanged, [capitoliLabel](int value){
        capitoliLabel->setText(QString("Capitoli: %1").arg(value));
    });

    connect(pagineDial, &QDial::valueChanged, this, [this](int value){
        emit pagineValueChanged(value);
    });

    connect(capitoliDial, &QDial::valueChanged, this, [this](int value){
        emit capitoliValueChanged(value);
    });

    connect(autoreCombo, &QComboBox::currentTextChanged, this, [this](const QString &text){
        emit autoreValueLibroChanged(text);
    });

    connect(casaEditriceCombo, &QComboBox::currentTextChanged, this, [this](const QString &text){
        emit casaEditriceValueChanged(text);
    });

}

void filtroSpecifico::setupPaginaRivista() {
    paginaRivista = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(paginaRivista);

    pagineRivistaSlider = new QDial();
    pagineRivistaSlider->setRange(0, l1->maxPagineRivista());
    QLabel* pagineLabel = new QLabel(QString("Pg. Rivista: %1").arg(pagineRivistaSlider->value()));

    difficoltaCombo = new QComboBox();
    difficoltaCombo->addItems({"Tutti","1","2","3","4","5"});

    periodicoCombo = new QComboBox();
    for(auto p : l1->allPeriodici()) if(p && !p->empty()) periodicoCombo->addItem(QString::fromStdString(*p));

    QLabel* labelRivista = new QLabel("RIVISTE");
    labelRivista->setAlignment(Qt::AlignCenter);

    layout->addWidget(labelRivista);
    layout->addWidget(pagineLabel);
    layout->addWidget(pagineRivistaSlider);
    layout->addWidget(new QLabel("Periodico:"));
    layout->addWidget(periodicoCombo);
    layout->addWidget(new QLabel("Difficoltà:"));
    layout->addWidget(difficoltaCombo);

    connect(pagineRivistaSlider, &QSlider::valueChanged, [pagineLabel](int value){
        pagineLabel->setText(QString("Pg. Rivista: %1").arg(value));
    });

    connect(pagineRivistaSlider, &QSlider::valueChanged, this, [this](int value){
    emit pagineRivistaValueChanged(value);
    });

    connect(periodicoCombo, &QComboBox::currentTextChanged, this, [this](const QString &text){
        emit periodicoValueChanged(text);
    });

    connect(difficoltaCombo, &QComboBox::currentTextChanged, this, [this](const QString &text){
        emit difficoltaValueChanged(text);
    });

}

void filtroSpecifico::setLayoutSpecifico(Articolo* a) {
    if(dynamic_cast<Film*>(a)) {
        stackedWidget->setCurrentWidget(paginaFilm);
    } else if(dynamic_cast<Libro*>(a)) {
        stackedWidget->setCurrentWidget(paginaLibro);
    } else if(dynamic_cast<Rivista*>(a)) {
        stackedWidget->setCurrentWidget(paginaRivista);
    }
}

void filtroSpecifico::backNormale() {
    stackedWidget->setCurrentIndex(3);
}

void filtroSpecifico::aggiorna() {
    if (!l1) return;

    annoSplitter->setRange(l1->minAnni(), l1->maxAnni());
    copieSplitter->setRange(0, l1->maxCopie());
    copieSplitter->setValue(0);

    if(attoreCombo) { attoreCombo->clear(); for(auto a: l1->allAttori()) attoreCombo->addItem(QString::fromStdString(*a)); }
    if(produCombo) { produCombo->clear(); for(auto p: l1->allProdu()) produCombo->addItem(QString::fromStdString(*p)); }
    if(minutaggioDial) { minutaggioDial->setRange(0, l1->maxMinutaggio()); minutaggioDial->setValue(0); }

    if(pagineDial) { pagineDial->setRange(0, l1->maxPagine()); pagineDial->setValue(0); }
    if(capitoliDial) { capitoliDial->setRange(0, l1->maxCapitoli()); capitoliDial->setValue(0); }
    if(autoreCombo) { autoreCombo->clear(); for(auto a: l1->allAutoriLibri()) autoreCombo->addItem(QString::fromStdString(*a)); }
    if(casaEditriceCombo) { casaEditriceCombo->clear(); for(auto c: l1->allCaseEditrici()) casaEditriceCombo->addItem(QString::fromStdString(*c)); }

    if(pagineRivistaSlider) { pagineRivistaSlider->setRange(0, l1->maxPagineRivista()); pagineRivistaSlider->setValue(0); }
    if(periodicoCombo) { periodicoCombo->clear(); for(auto p: l1->allPeriodici()) periodicoCombo->addItem(QString::fromStdString(*p)); }
    if(difficoltaCombo) difficoltaCombo->setCurrentIndex(0);
}

