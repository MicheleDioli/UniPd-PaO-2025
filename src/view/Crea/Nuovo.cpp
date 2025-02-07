#include "Nuovo.h"


Nuovo::Nuovo(QWidget *parent, std::list<Articolo*> articoli) : QWidget(parent), articoli(articoli){

    layout = new QVBoxLayout(this);

    QHBoxLayout *sopra = new QHBoxLayout();



    QGroupBox *box = new QGroupBox("Seleziona il tipo di articolo");

    radioButton = new QRadioButton("Film");
    radioButton2 = new QRadioButton("Libro");
    radioButton3 = new QRadioButton("Rivista");

    icona = new QLabel();
    QPixmap *pixmap = new QPixmap(":/asset/images/film.png");
    icona->setPixmap(*pixmap);
    icona->setAlignment(Qt::AlignTop | Qt::AlignRight);
    //radioButton->setChecked(true);

    connect(radioButton,&QRadioButton::clicked,this,&Nuovo::cambiaIcona);
    connect(radioButton2,&QRadioButton::clicked,this,&Nuovo::cambiaIcona);
    connect(radioButton3,&QRadioButton::clicked,this,&Nuovo::cambiaIcona);

    //QSpacerItem *spacer = new QSpacerItem();

    sopra->addWidget(radioButton);
    sopra->addWidget(radioButton2);
    sopra->addWidget(radioButton3);
    //sopra->addStretch();
    //sopra->addWidget(icona);

    infoArticolo = new QGroupBox("Inserisci i dati dell'articolo");
    QHBoxLayout *layoutInfo = new QHBoxLayout();
    QFormLayout *infoA1 = new QFormLayout();
    QFormLayout *infoA2 = new QFormLayout();
/*
    QLineEdit *titolo = new QLineEdit();
    QLineEdit *codice = new QLineEdit();
    QComboBox *genere = new QComboBox();
    QComboBox *lingua = new QComboBox();
    QSpinBox *copie = new QSpinBox();
    QSpinBox *anno = new QSpinBox();
*/

    genere->addItems({"Fantascenza", "Giallo", "Horror", "Scienza", "Storico", "Thriller"});
    lingua->addItems({"Italiano", "Inglese", "Spagnolo", "Francese", "Tedesco"});

    anno->setRange(0, 2025);
    copie->setRange(0, 1000);

    infoA1->addRow("Titolo:", titolo);
    infoA1->addRow("Codice:", codice);
    infoA1->addRow("Genere:", genere);

    infoA2->addRow("Copie:", copie);
    infoA2->addRow("Anno:", anno);
    infoA2->addRow("Lingua:", lingua);

    layoutInfo->addLayout(infoA1);
    layoutInfo->addLayout(infoA2);

    infoArticolo->setLayout(layoutInfo);

    box->setLayout(sopra);
    QHBoxLayout *tipo = new QHBoxLayout();
    tipo->addWidget(box);
    tipo->addWidget(icona);

    descrizione = new QTextEdit();
    QGroupBox *desc = new QGroupBox("Descrizione");
    QVBoxLayout *descLayout = new QVBoxLayout();
    descLayout->addWidget(descrizione);
    desc->setLayout(descLayout);

    layout->addLayout(tipo);
    layout->addWidget(infoArticolo);
    layout->addWidget(desc);
    layout->addLayout(mezzo);

    QHBoxLayout *basso = new QHBoxLayout();
    salva = new QPushButton("Salva");
    QPushButton *annulla = new QPushButton("Annulla");

    QSpacerItem *spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    basso->addItem(spacer);
    basso->addWidget(annulla);
    basso->addWidget(salva);

    layout->addLayout(basso);

    salva->setEnabled(false);

    connect(salva, &QPushButton::clicked, this, &Nuovo::salvataggio);

}

void Nuovo::cambiaIcona() {

    l->pulisciLayout(mezzo);

    QGroupBox *crea = new QGroupBox("Crea");

	salva->setEnabled(true);

    if (radioButton->isChecked()) {
        QPixmap pixmap(":/asset/images/film.png");
        icona->setPixmap(pixmap);
        crea->setLayout(creaFilm());

    } else if (radioButton2->isChecked()) {
        QPixmap pixmap(":/asset/images/libro.png");
        icona->setPixmap(pixmap);
        crea->setLayout(creaLibro());

    } else if (radioButton3->isChecked()) {
        QPixmap pixmap(":/asset/images/rivista.png");
        icona->setPixmap(pixmap);
        crea->setLayout(creaRivista());
    }

    mezzo->addWidget(crea);
}

QHBoxLayout* Nuovo::creaFilm() {
    QHBoxLayout *creaLayout = new QHBoxLayout();
    QFormLayout *infoF1 = new QFormLayout();
    QFormLayout *infoF2 = new QFormLayout();

    regista = new QLineEdit();
    attore = new QLineEdit();
    produttore = new QLineEdit();
    durata = new QSpinBox();
    durata->setRange(0, 999);

    infoF1->addRow("Regista:", regista);
    infoF2->addRow("Attore:", attore);
    infoF1->addRow("Produttore:", produttore);
    infoF2->addRow("Durata:", durata);

    creaLayout->addLayout(infoF1);
    creaLayout->addLayout(infoF2);

    return creaLayout;
}

QHBoxLayout* Nuovo::creaLibro() {
    QHBoxLayout *creaLayout = new QHBoxLayout();
    QFormLayout *infoL1 = new QFormLayout();
    QFormLayout *infoL2 = new QFormLayout();

    QLineEdit *casaEditrice = new QLineEdit();
    QLineEdit *autore = new QLineEdit();
    QSpinBox *capitoli = new QSpinBox();
    QSpinBox *pagine = new QSpinBox();

    capitoli->setRange(0, 999);
    pagine->setRange(0, 9999);

    infoL1->addRow("Casa Editrice:", casaEditrice);
    infoL1->addRow("Autore:", autore);
    infoL2->addRow("Capitoli:", capitoli);
    infoL2->addRow("Pagine:", pagine);

    creaLayout->addLayout(infoL1);
    creaLayout->addLayout(infoL2);

    return creaLayout;
}

QHBoxLayout* Nuovo::creaRivista() {
    QHBoxLayout *creaLayout = new QHBoxLayout();
    QFormLayout *infoR1 = new QFormLayout();
    QFormLayout *infoR2 = new QFormLayout();

    editore = new QLineEdit();
    pubblicatore = new QLineEdit();
    edizione = new QSpinBox();
    intervalloPubblicazione = new QComboBox();
    difficolta = new QSpinBox();
    pagine = new QSpinBox();


    pagine->setRange(0,9999);
    difficolta->setRange(1,5);
    edizione->setRange(0, 999);
    intervalloPubblicazione->addItems({"Mensile", "Bimestrale", "Trimestrale", "Semestrale", "Annuale"});

    infoR1->addRow("Editore:", editore);
    infoR2->addRow("Pubblicatore:", pubblicatore);
    infoR1->addRow("Edizione:", edizione);
    infoR2->addRow("Intervallo Pubblicazione:", intervalloPubblicazione);

    creaLayout->addLayout(infoR1);
    creaLayout->addLayout(infoR2);

    return creaLayout;
}

void Nuovo::salvataggio() {
    if (radioButton->isChecked()) {
        Film *f = new Film(titolo->text().toStdString(), codice->text().toStdString(), descrizione->toPlainText().toStdString(), genere->currentText().toStdString(), anno->value(), copie->value(), lingua->currentText().toStdString(), regista->text().toStdString(), durata->value(), attore->text().toStdString(), produttore->text().toStdString());
        articoli.push_back(f);
        std::cout<<f->getTitolo()<<std::endl;
        this->close();
        return;

    } else if (radioButton2->isChecked()) {
        Libro *l = new Libro(titolo->text().toStdString(), codice->text().toStdString(), descrizione->toPlainText().toStdString(), genere->currentText().toStdString(), anno->value(), copie->value(), lingua->currentText().toStdString(), casaEditrice->text().toStdString(), capitoli->value(), pagine->value(), autore->text().toStdString());
        articoli.push_back(l);
        std::cout<<l->getTitolo()<<std::endl;
        this->close();
        return;

    } else if (radioButton3->isChecked()) {
      	std::string edizioneStr = std::to_string(edizione->value());
        Rivista* r = new Rivista(titolo->text().toStdString(), codice->text().toStdString(), descrizione->toPlainText().toStdString(), genere->currentText().toStdString(), anno->value(), copie->value(), lingua->currentText().toStdString(), editore->text().toStdString(), pagine->value(), pubblicatore->text().toStdString(), intervalloPubblicazione->currentText().toInt(), edizione->value(), difficolta->value());
        articoli.push_back(r);
        std::cout<<r->getTitolo()<<std::endl;
        this->close();
   }
   }

void Nuovo::annulla() {
    this->close();
}
