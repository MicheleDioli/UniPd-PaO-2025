//
// Created by Michele Dioli on 2/2/25.
//
#include "ModificaRivista.h"

ModificaRivista::ModificaRivista(QWidget* parent, Rivista* rivista) : ModificaArticolo(parent), rivista(rivista) {
	layout->addWidget(new QLabel("Codice:"));
    codiceInput = new QLineEdit();
    codiceInput->setText(QString::fromStdString(rivista->getCodice()));
    layout->addWidget(codiceInput);

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
}

Rivista* ModificaRivista::New(){
    return new Rivista(codiceInput->text().toStdString(),
                       descrizioneInput->text().toStdString(),
                       genereInput->text().toStdString(),
                       annoInput->date().year(),
                       copieInput->value(),
                       linguaInput->text().toStdString(),
                        editoreRivistaInput->text().toStdString(),
                        pagineRivistaInput->value(),
                        pubblicatoreInput->text().toStdString(),
                        periodicitaInput->value(),
                        numeroInput->value(),
                        difficoltaInput->value());
}

QVBoxLayout* ModificaRivista::getLayout() const {
    return layout;
}