#include "MostraVisitor.h"

#include "../../Libro.h"
#include "../../Rivista.h"
#include "../../Film.h"

QVBoxLayout* MostraVisitor::getLayout() const {
    return layout;
}

void MostraVisitor::visitLibro(Libro& l) {
    layout = new QVBoxLayout();

    QHBoxLayout* sopra = new QHBoxLayout();

    QLabel* codice_anno = new QLabel("Codice: " + QString::fromStdString(l.getCodice())+ "\n Anno: " + QString::number(l.getAnno()));
    codice_anno->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    QLabel* lingua_copie = new QLabel("Lingua: " + QString::fromStdString(l.getLingua()) + "\n Copie: " + QString::number(l.getCopie()));
    lingua_copie->setAlignment(Qt::AlignRight | Qt::AlignTop);

    QPixmap image(":/asset/images/libro.png");
    QLabel* imageLabel = new QLabel();
    imageLabel->setAlignment(Qt::AlignCenter);
    imageLabel->setPixmap(image);

    sopra->addWidget(codice_anno);
    //sopra->addStretch();
    sopra->addWidget(imageLabel);
    //sopra->addStretch();
    sopra->addWidget(lingua_copie);

    QLabel* titolo_autore = new QLabel(QString::fromStdString(l.getTitolo())+" by "+ QString::fromStdString(l.getAutore()));
    titolo_autore->setAlignment(Qt::AlignCenter);

    //QLabel* titolo = new QLabel("Titolo: " + QString::fromStdString(l.getTitolo()));

    QHBoxLayout* mezzo = new QHBoxLayout();

    QVBoxLayout* mezzoLeft = new QVBoxLayout();
    QVBoxLayout* mezzoRight = new QVBoxLayout();

    QLabel* casaEditrice = new QLabel("Prodotto, stampato\n    da\n " + QString::fromStdString(l.getCasaEditrice()));
    casaEditrice->setAlignment(Qt::AlignLeft);
    QLabel* g_p_c = new QLabel(QString::fromStdString(l.getGenere()) + "\n" + QString::number(l.getCapitoli()) + " capitoli\n" + QString::number(l.getPagine()) + " pagine");
    g_p_c->setAlignment(Qt::AlignRight);

    mezzoLeft->addWidget(casaEditrice);
    mezzoRight->addWidget(g_p_c);

    mezzo->addLayout(mezzoLeft);
    mezzo->addLayout(mezzoRight);

    QLabel* descrizione = new QLabel(QString::fromStdString(l.getDescrizione()));
    descrizione->setAlignment(Qt::AlignCenter);

    layout->addLayout(sopra);
    layout->addWidget(titolo_autore);
    layout->addLayout(mezzo);
    layout->addWidget(descrizione);

}

void MostraVisitor::visitRivista(Rivista& r) {
    layout = new QVBoxLayout();

    QPixmap image(":/asset/images/rivista.png");
    QLabel* imageLabel = new QLabel();
    imageLabel->setPixmap(image);

    QVBoxLayout* InfoArticolo = new QVBoxLayout();
    QHBoxLayout* InfoArticoloLeft = new QHBoxLayout();
    QHBoxLayout* InfoArticoloRight = new QHBoxLayout();

    QLabel* titolo = new QLabel("Titolo: " + QString::fromStdString(r.getTitolo()));
    QLabel* codice = new QLabel("Codice: " + QString::fromStdString(r.getCodice()));
    QLabel* genere = new QLabel("Generi: " + QString::fromStdString(r.getGenere()));

    QLabel* lingua = new QLabel("Lingua: " + QString::fromStdString(r.getLingua()));
    QLabel* anno = new QLabel("Anno: " + QString::number(r.getAnno()));
    QLabel* copie = new QLabel("Copie: " + QString::number(r.getCopie()));

    InfoArticoloLeft->addWidget(titolo);
    InfoArticoloLeft->addWidget(codice);
    InfoArticoloLeft->addWidget(genere);

    InfoArticoloRight->addWidget(lingua);
    InfoArticoloRight->addWidget(anno);
    InfoArticoloRight->addWidget(copie);

    InfoArticolo->addLayout(InfoArticoloLeft);
    InfoArticolo->addLayout(InfoArticoloRight);

    QGroupBox* InfoArticoloGroup = new QGroupBox();

    InfoArticoloGroup->setLayout(InfoArticolo);

    QHBoxLayout* alto = new QHBoxLayout();

    alto->addWidget(imageLabel);
    alto->addWidget(InfoArticoloGroup);

    layout->addLayout(alto);

    QVBoxLayout* descizione = new QVBoxLayout();
    QLabel* descrizioneLabel = new QLabel(QString::fromStdString(r.getDescrizione()));

    descizione->addWidget(descrizioneLabel);

    // secondo

    QGroupBox* DescrizioneGroup = new QGroupBox("Descrizione");
    DescrizioneGroup->setLayout(descizione);

    layout->addWidget(DescrizioneGroup);

    //terzo

    QVBoxLayout* InfoSpecifiche = new QVBoxLayout();

    QHBoxLayout* InfoSpecificheRight = new QHBoxLayout();
    QHBoxLayout* InfoSpecificheLeft = new QHBoxLayout();

    QLabel* editore = new QLabel("Editore: " + QString::fromStdString(r.getEditore()));
    QLabel* pagine = new QLabel("Pagine; " + QString::number(r.getPagine()));
    QLabel* pubblicatore = new QLabel("Pubblicatore: " + QString::fromStdString(r.getPubblicatore()));
    QLabel* intervalloPubblicazione = new QLabel("Intervallo Pubblicazione: " + QString::number(r.getIntervalloPubblicazione()));
    QLabel* edizione = new QLabel("Edizione: " + QString::number(r.getEdizione()));
    QLabel* difficolta = new QLabel("Difficolta: " + QString::number(r.getDifficolta()));

    InfoSpecificheLeft->addWidget(editore);
    InfoSpecificheLeft->addWidget(pagine);
    InfoSpecificheLeft->addWidget(edizione);

    InfoSpecificheRight->addWidget(pubblicatore);
    InfoSpecificheRight->addWidget(intervalloPubblicazione);
    InfoSpecificheRight->addWidget(difficolta);

    InfoSpecifiche->addLayout(InfoSpecificheLeft);
    InfoSpecifiche->addLayout(InfoSpecificheRight);

    QGroupBox * InfoSpecificheGroup = new QGroupBox;

    InfoSpecificheGroup->setLayout(InfoSpecifiche);

    layout->addWidget(InfoSpecificheGroup);
}

void MostraVisitor::visitFilm(Film& f) {
    layout = new QVBoxLayout();

    QPixmap image(":/asset/images/film.png");
    QLabel* imageLabel = new QLabel();
    imageLabel->setPixmap(image);

    QVBoxLayout* InfoArticolo = new QVBoxLayout();
    QHBoxLayout* InfoArticoloLeft = new QHBoxLayout();
    QHBoxLayout* InfoArticoloRight = new QHBoxLayout();

    QLabel* titolo = new QLabel("Titolo: " + QString::fromStdString(f.getTitolo()));
    QLabel* codice = new QLabel("Codice: " + QString::fromStdString(f.getCodice()));
    QLabel* genere = new QLabel("Generi: " + QString::fromStdString(f.getGenere()));

    QLabel* lingua = new QLabel("Lingua : " + QString::fromStdString(f.getLingua()));
    QLabel* anno = new QLabel("Anno " + QString::number(f.getAnno()));
    QLabel* copie = new QLabel("Copie: " + QString::number(f.getCopie()));

    InfoArticoloLeft->addWidget(titolo);
    InfoArticoloLeft->addWidget(codice);
    InfoArticoloLeft->addWidget(genere);

    InfoArticoloRight->addWidget(lingua);
    InfoArticoloRight->addWidget(anno);
    InfoArticoloRight->addWidget(copie);

    InfoArticolo->addLayout(InfoArticoloLeft);
    InfoArticolo->addLayout(InfoArticoloRight);

    layout->addWidget(imageLabel);
    imageLabel->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    QGroupBox* InfoArticoloGroup = new QGroupBox();
    InfoArticoloGroup->setLayout(InfoArticolo);

    layout->addWidget(InfoArticoloGroup);

    QVBoxLayout* descizione = new QVBoxLayout();
    QLabel* descrizioneLabel = new QLabel("Descrizione: " + QString::fromStdString(f.getDescrizione()));

    descizione->addWidget(descrizioneLabel);

    // secondo

    QGroupBox* DescrizioneGroup = new QGroupBox();
    DescrizioneGroup->setLayout(descizione);

    layout->addWidget(DescrizioneGroup);

    //terzo

    QVBoxLayout* InfoSpecifiche = new QVBoxLayout();

    QHBoxLayout* InfoSpecificheRight = new QHBoxLayout();
    QHBoxLayout* InfoSpecificheLeft = new QHBoxLayout();

    QLabel* regista = new QLabel("Regista :" + QString::fromStdString(f.getRegista()));
    QLabel* durata = new QLabel("Durata :" + QString::number(f.getDurata()));
    QLabel* attori = new QLabel("Attori :" + QString::fromStdString(f.getAttori()));
    QLabel* produttore = new QLabel("Produttore :" + QString::fromStdString(f.getProduttore()));

    InfoSpecificheLeft->addWidget(regista);
    InfoSpecificheLeft->addWidget(durata);

    InfoSpecificheRight->addWidget(attori);
    InfoSpecificheRight->addWidget(produttore);

    InfoSpecifiche->addLayout(InfoSpecificheLeft);

    QGroupBox* InfoSpecificheGroup = new QGroupBox();

    InfoSpecificheGroup->setLayout(InfoSpecifiche);

    layout->addWidget(InfoSpecificheGroup);
}
