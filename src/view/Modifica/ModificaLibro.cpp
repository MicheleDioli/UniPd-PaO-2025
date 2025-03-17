#include "ModificaLibro.h"

ModificaLibro::ModificaLibro(QWidget* parent, Libro* libro)
    : ModificaArticolo(parent), libro(libro) {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(10, 10, 10, 10);
    mainLayout->setSpacing(15);

    if (!libro) {
        qWarning() << "Libro nullo in ModificaLibro!";
        return;
    }

    // Dettagli Generali
    QGroupBox* generalGroup = new QGroupBox("Dettagli Generali", this);
    QFormLayout* formGeneral = new QFormLayout(generalGroup);
    formGeneral->setContentsMargins(10, 15, 10, 15);
    formGeneral->setSpacing(8);
    formGeneral->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);

    codiceInput = createLineEdit(QString::fromStdString(libro->getCodice()), "Codice univoco identificativo");
    titoloInput = createLineEdit(QString::fromStdString(libro->getTitolo()), "Titolo del libro");
    descrizioneInput = createLineEdit(QString::fromStdString(libro->getDescrizione()), "Descrizione sintetica");
    genereInput = new QComboBox();
    genereInput->addItems({"Fantascenza", "Giallo", "Horror", "Scienza", "Storico", "Thriller"});
    genereInput->setCurrentText(QString::fromStdString(libro->getGenere()));
    annoInput = new QDateEdit();
    annoInput->setDate(QDate(libro->getAnno(), 1, 1));
    annoInput->setDisplayFormat("yyyy");
    annoInput->setToolTip("Anno di pubblicazione");

    copieInput = new QSpinBox();
    copieInput->setRange(0, 999);
    copieInput->setValue(libro->getCopie());
    copieInput->setToolTip("Numero di copie disponibili");

    linguaInput = new QComboBox();
    linguaInput->addItems({"Italiano", "Inglese", "Spagnolo", "Francese", "Tedesco"});
    linguaInput->setCurrentText(QString::fromStdString(libro->getLingua()));

    formGeneral->addRow("Codice:", codiceInput);
    formGeneral->addRow("Titolo:", titoloInput);
    formGeneral->addRow("Descrizione:", descrizioneInput);
    formGeneral->addRow("Genere:", genereInput);
    formGeneral->addRow("Anno:", annoInput);
    formGeneral->addRow("Copie:", copieInput);
    formGeneral->addRow("Lingua:", linguaInput);

    // Dettagli Specifici Libro
    QGroupBox* detailsGroup = new QGroupBox("Dettagli Libro", this);
    QFormLayout* formDetails = new QFormLayout(detailsGroup);
    formDetails->setContentsMargins(10, 15, 10, 15);
    formDetails->setSpacing(8);

    autoreInput = createLineEdit(QString::fromStdString(libro->getAutore()), "Autore principale");
    casaEditriceInput = createLineEdit(QString::fromStdString(libro->getCasaEditrice()), "Casa editrice");

    pagineInput = new QSpinBox();
    pagineInput->setRange(1, 1999);
    pagineInput->setValue(libro->getPagine());
    pagineInput->setSuffix(" pagine");
    pagineInput->setToolTip("Numero totale di pagine");

    capitoliInput = new QSpinBox();
    capitoliInput->setRange(1, 1999);
    capitoliInput->setValue(libro->getCapitoli());
    capitoliInput->setSuffix(" capitoli");
    capitoliInput->setToolTip("Numero totale di capitoli");

    formDetails->addRow("Autore:", autoreInput);
    formDetails->addRow("Casa Editrice:", casaEditriceInput);
    formDetails->addRow("Pagine:", pagineInput);
    formDetails->addRow("Capitoli:", capitoliInput);

    mainLayout->addWidget(generalGroup);
    mainLayout->addWidget(detailsGroup);
    mainLayout->addStretch();
}

QLineEdit* ModificaLibro::createLineEdit(const QString& text, const QString& tooltip) {
    QLineEdit* edit = new QLineEdit(text);
    edit->setPlaceholderText("...");
    edit->setToolTip(tooltip);
    edit->setMinimumWidth(250);
    return edit;
}

void ModificaLibro::edit(Articolo* a) {
    Libro* libro = dynamic_cast<Libro*>(a);
    libro->setCodice(codiceInput->text().toStdString());
    libro->setTitolo(titoloInput->text().toStdString());
    libro->setDescrizione(descrizioneInput->text().toStdString());
    libro->setGenere(genereInput->currentText().toStdString());
    libro->setAnno(annoInput->date().year());
    libro->setCopie(copieInput->value());
    libro->setLingua(linguaInput->currentText().toStdString());
    libro->setAutore(autoreInput->text().toStdString());
    libro->setCasaEditrice(casaEditriceInput->text().toStdString());
    libro->setPagine(pagineInput->value());
    libro->setCapitoli(capitoliInput->value());

    l.controlla(libro);

}

QVBoxLayout* ModificaLibro::getLayout() const {
    return layout;
}
