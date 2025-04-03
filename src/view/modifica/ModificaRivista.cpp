#include "ModificaRivista.h"

ModificaRivista::ModificaRivista(QWidget* parent, Rivista* rivista)
    : ModificaArticolo(parent), rivista(rivista) {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(10, 10, 10, 10);
    mainLayout->setSpacing(15);

    if (!rivista) {
        return;
    }

    // Dettagli Generali
    QGroupBox* generalGroup = new QGroupBox("Dettagli Generali", this);
    QFormLayout* formGeneral = new QFormLayout(generalGroup);
    formGeneral->setContentsMargins(10, 15, 10, 15);
    formGeneral->setSpacing(8);
    formGeneral->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);

    codiceInput = createLineEdit(QString::fromStdString(rivista->getCodice()), "Codice univoco identificativo");
    titoloInput = createLineEdit(QString::fromStdString(rivista->getTitolo()), "Titolo della rivista");
    descrizioneInput = createLineEdit(QString::fromStdString(rivista->getDescrizione()), "Descrizione sintetica");
    genereInput = new QComboBox();
    genereInput->addItems({"Fantascenza", "Giallo", "Horror", "Scienza", "Storico", "Thriller"});
    genereInput->setCurrentText(QString::fromStdString(rivista->getGenere()));

    annoInput = new QDateEdit();
    annoInput->setDate(QDate(rivista->getAnno(), 1, 1));
    annoInput->setDisplayFormat("yyyy");
    annoInput->setToolTip("Anno di pubblicazione");

    copieInput = new QSpinBox();
    copieInput->setRange(0, 999);
    copieInput->setValue(rivista->getCopie());
    copieInput->setToolTip("Numero di copie disponibili");

    formGeneral->addRow("Codice:", codiceInput);
    formGeneral->addRow("Titolo:", titoloInput);
    formGeneral->addRow("Descrizione:", descrizioneInput);
    formGeneral->addRow("Genere:", genereInput);
    formGeneral->addRow("Anno:", annoInput);
    formGeneral->addRow("Copie:", copieInput);

    // Dettagli Specifici Rivista
    QGroupBox* detailsGroup = new QGroupBox("Dettagli Rivista", this);
    QFormLayout* formDetails = new QFormLayout(detailsGroup);
    formDetails->setContentsMargins(10, 15, 10, 15);
    formDetails->setSpacing(8);

    linguaInput = new QComboBox();
    linguaInput->addItems({"Italiano", "Inglese", "Spagnolo", "Francese", "Tedesco"});
    linguaInput->setCurrentText(QString::fromStdString(rivista->getLingua()));
    periodicitaInput = new QSpinBox();
    periodicitaInput->setRange(1, 31);
    QString intervalloStr = QString::fromStdString(rivista->getIntervalloPubblicazione());

    bool ok;
    int intervallo = intervalloStr.toInt(&ok);
    if (ok) 
        periodicitaInput->setValue(intervallo);

    periodicitaInput->setToolTip("Giorni tra le pubblicazioni");
    periodicitaInput->setSuffix(" giorni");

    numeroInput = new QSpinBox();
    numeroInput->setRange(1, 99);
    numeroInput->setValue(rivista->getEdizione());
    numeroInput->setToolTip("Numero edizione corrente");

    editoreRivistaInput = createLineEdit(QString::fromStdString(rivista->getEditore()), "Editore responsabile");
    pagineRivistaInput = new QSpinBox();
    pagineRivistaInput->setRange(1, 1999);
    pagineRivistaInput->setValue(rivista->getPagine());
    pagineRivistaInput->setSuffix(" pagine");
    pagineRivistaInput->setToolTip("Numero totale di pagine");

    difficoltaInput = new QSpinBox();
    difficoltaInput->setRange(1, 5);
    difficoltaInput->setValue(rivista->getDifficolta());
    difficoltaInput->setToolTip("Livello complessitá (1=base, 5=avanzato)");

    pubblicatoreInput = createLineEdit(QString::fromStdString(rivista->getPubblicatore()), "Ente pubblicatore");

    formDetails->addRow("Lingua:", linguaInput);
    formDetails->addRow("Periodicità:", periodicitaInput);
    formDetails->addRow("Edizione:", numeroInput);
    formDetails->addRow("Editore:", editoreRivistaInput);
    formDetails->addRow("Pagine:", pagineRivistaInput);
    formDetails->addRow("Difficoltà:", difficoltaInput);
    formDetails->addRow("Pubblicatore:", pubblicatoreInput);

    mainLayout->addWidget(generalGroup);
    mainLayout->addWidget(detailsGroup);
    mainLayout->addStretch();
}

QLineEdit* ModificaRivista::createLineEdit(const QString& text, const QString& tooltip) {
    QLineEdit* edit = new QLineEdit(text);
    edit->setPlaceholderText("...");
    edit->setToolTip(tooltip);
    edit->setMinimumWidth(250);
    return edit;
}

void ModificaRivista::edit(Articolo* a) {
    Rivista* rivista = dynamic_cast<Rivista*>(a);
    rivista->setCodice(codiceInput->text().toStdString());
    rivista->setTitolo(titoloInput->text().toStdString());
    rivista->setDescrizione(descrizioneInput->text().toStdString());
    rivista->setGenere(genereInput->currentText().toStdString());
    rivista->setLingua(linguaInput->currentText().toStdString());
    rivista->setAnno(annoInput->date().year());
    rivista->setCopie(copieInput->value());
    rivista->setIntervalloPubblicazione(std::to_string(periodicitaInput->value()));
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