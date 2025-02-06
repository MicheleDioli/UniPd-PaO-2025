#include "ModificaLibro.h"

ModificaLibro::ModificaLibro(QWidget* parent, Libro* libro) : ModificaArticolo(parent){
	layout->addWidget(new QLabel("Codice:"));
    codiceInput = new QLineEdit();
    codiceInput->setText(QString::fromStdString(libro->getCodice()));
    layout->addWidget(codiceInput);

    layout->addWidget(new QLabel("Titolo:"));
    titoloInput = new QLineEdit();
    titoloInput->setText(QString::fromStdString(libro->getTitolo()));
    layout->addWidget(titoloInput);

    layout->addWidget(new QLabel("Descrizione:"));
    descrizioneInput = new QLineEdit();
    descrizioneInput->setText(QString::fromStdString(libro->getDescrizione()));
    layout->addWidget(descrizioneInput);

    layout->addWidget(new QLabel("Genere:"));
    genereInput = new QLineEdit();
    genereInput->setText(QString::fromStdString(libro->getGenere()));
    layout->addWidget(genereInput);

    layout->addWidget(new QLabel("Anno:"));
    annoInput = new QDateEdit();
    annoInput->setDate(QDate(libro->getAnno(),1,1));
    annoInput->setDisplayFormat("yyyy");
    layout->addWidget(annoInput);

    layout->addWidget(new QLabel("Copie:"));
    copieInput = new QSpinBox();
    copieInput->setValue(libro->getCopie());
    layout->addWidget(copieInput);

    layout->addWidget(new QLabel("Lingua:"));
    linguaInput = new QLineEdit();
    linguaInput->setText(QString::fromStdString(libro->getLingua()));
    layout->addWidget(linguaInput);

    layout->addWidget(new QLabel("Autore:"));
    autoreInput = new QLineEdit();
    autoreInput->setText(QString::fromStdString(libro->getAutore()));
    layout->addWidget(autoreInput);

    layout->addWidget(new QLabel("Casa Editrice:"));
    casaEditriceInput = new QLineEdit();
    casaEditriceInput->setText(QString::fromStdString(libro->getCasaEditrice()));
    layout->addWidget(casaEditriceInput);

    layout->addWidget(new QLabel("Pagine:"));
    pagineInput = new QSpinBox();
    pagineInput->setRange(1, 1999);
    pagineInput->setValue(libro->getPagine());
    layout->addWidget(pagineInput);

    layout->addWidget(new QLabel("Capitoli:"));
    capitoliInput = new QSpinBox();
    capitoliInput->setRange(1, 1999);
    capitoliInput->setValue(libro->getCapitoli());
    layout->addWidget(capitoliInput);
}

void ModificaLibro::edit(Articolo* a) {
    Libro* libro = dynamic_cast<Libro*>(a);
    libro->setCodice(codiceInput->text().toStdString());
    libro->setTitolo(titoloInput->text().toStdString());
    libro->setDescrizione(descrizioneInput->text().toStdString());
    libro->setGenere(genereInput->text().toStdString());
    libro->setAnno(annoInput->date().year());
    libro->setCopie(copieInput->value());
    libro->setLingua(linguaInput->text().toStdString());
    libro->setAutore(autoreInput->text().toStdString());
    libro->setCasaEditrice(casaEditriceInput->text().toStdString());
    libro->setPagine(pagineInput->value());
    libro->setCapitoli(capitoliInput->value());
}

QVBoxLayout* ModificaLibro::getLayout() const {
    return layout;
}