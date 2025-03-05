//
// Created by Michele Dioli on 2/2/25.
//
#include "ModificaRivista.h"

ModificaRivista::ModificaRivista(QWidget* parent, Rivista* rivista) : ModificaArticolo(parent), rivista(rivista) {
    layout = new QVBoxLayout(this);

	layout->addWidget(new QLabel("Codice:"));
    codiceInput = new QLineEdit();
    codiceInput->setText(QString::fromStdString(rivista->getCodice()));
    layout->addWidget(codiceInput);

    layout->addWidget(new QLabel("Titolo:"));
    titoloInput = new QLineEdit();
    titoloInput->setText(QString::fromStdString(rivista->getTitolo()));
    layout->addWidget(titoloInput);

    layout->addWidget(new QLabel("Descrizione:"));
    descrizioneInput = new QLineEdit();
    descrizioneInput->setText(QString::fromStdString(rivista->getDescrizione()));
    layout->addWidget(descrizioneInput);

    layout->addWidget(new QLabel("Genere:"));
    genereInput = new QLineEdit();
    genereInput->setText(QString::fromStdString(rivista->getGenere()));
    layout->addWidget(genereInput);

    layout->addWidget(new QLabel("Anno:"));
    annoInput = new QDateEdit();
    annoInput->setDate(QDate(rivista->getAnno(),1,1));
    annoInput->setDisplayFormat("yyyy");
    layout->addWidget(annoInput);

    layout->addWidget(new QLabel("Copie:"));
    copieInput = new QSpinBox();
    copieInput->setValue(rivista->getCopie());
    layout->addWidget(copieInput);

    layout->addWidget(new QLabel("Lingua:"));
    linguaInput = new QLineEdit();
    linguaInput->setText(QString::fromStdString(rivista->getLingua()));
    layout->addWidget(linguaInput);

    layout->addWidget(new QLabel("Periodicita:"));
    periodicitaInput = new QSpinBox();
    periodicitaInput->setRange(1, 31);
    periodicitaInput->setValue(rivista->getIntervalloPubblicazione());
    layout->addWidget(periodicitaInput);

    layout->addWidget(new QLabel("Edizione:"));
    numeroInput = new QSpinBox();
    numeroInput->setRange(1, 99);
    numeroInput->setValue(rivista->getEdizione());
    layout->addWidget(numeroInput);

    layout->addWidget(new QLabel("Editore Rivista:"));
    editoreRivistaInput = new QLineEdit();
    editoreRivistaInput->setText(QString::fromStdString(rivista->getEditore()));
    layout->addWidget(editoreRivistaInput);

    layout->addWidget(new QLabel("Pagine Rivista:"));
    pagineRivistaInput = new QSpinBox();
    pagineRivistaInput->setRange(1, 1999);
    pagineRivistaInput->setValue(rivista->getPagine());
    layout->addWidget(pagineRivistaInput);

    layout->addWidget(new QLabel("Difficolta:"));
    difficoltaInput = new QSpinBox();
    difficoltaInput->setValue(rivista->getDifficolta());
    difficoltaInput->setRange(1, 5);

    layout->addWidget(difficoltaInput);

    layout->addWidget(new QLabel("Pubblicatore:"));
    pubblicatoreInput = new QLineEdit();
    pubblicatoreInput->setText(QString::fromStdString(rivista->getPubblicatore()));
    layout->addWidget(pubblicatoreInput);

}

void ModificaRivista::edit(Articolo* a) {
    Rivista* rivista = dynamic_cast<Rivista*>(a);
    rivista->setCodice(codiceInput->text().toStdString());
    rivista->setTitolo(titoloInput->text().toStdString());
    rivista->setDescrizione(descrizioneInput->text().toStdString());
    rivista->setGenere(genereInput->text().toStdString());
    rivista->setLingua(linguaInput->text().toStdString());
    rivista->setAnno(annoInput->date().year());
    rivista->setCopie(copieInput->value());
    rivista->setIntervalloPubblicazione(periodicitaInput->value());
    rivista->setEdizione(numeroInput->value());
    rivista->setEditore(editoreRivistaInput->text().toStdString());
    rivista->setPagine(pagineRivistaInput->value());
    rivista->setDifficolta(difficoltaInput->value());
    rivista->setPubblicatore(pubblicatoreInput->text().toStdString());
    std::cout << rivista->getTitolo() << std::endl;
}

QVBoxLayout* ModificaRivista::getLayout() const {
    return layout;
}