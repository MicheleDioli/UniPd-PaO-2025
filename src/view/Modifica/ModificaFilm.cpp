#include "ModificaFilm.h"

ModificaFilm::ModificaFilm(QWidget* parent, Film* film)
    : ModificaArticolo(parent), film(film) {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(10, 10, 10, 10);
    mainLayout->setSpacing(15);

    if (!film) {
        qWarning() << "Film nullo in ModificaFilm!";
        return;
    }

    QGroupBox* generalGroup = new QGroupBox("Dettagli Generali", this);
    QFormLayout* formGeneral = new QFormLayout(generalGroup);
    formGeneral->setContentsMargins(10, 15, 10, 15);
    formGeneral->setSpacing(8);
    formGeneral->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);

    codiceInput = createLineEdit(QString::fromStdString(film->getCodice()), "Codice univoco identificativo");
    titoloInput = createLineEdit(QString::fromStdString(film->getTitolo()), "Titolo del film");
    descrizioneInput = createLineEdit(QString::fromStdString(film->getDescrizione()), "Descrizione sintetica");
    genereInput = createLineEdit(QString::fromStdString(film->getGenere()), "Genere cinematografico");

    annoInput = new QDateEdit();
    annoInput->setDate(QDate(film->getAnno(), 1, 1));
    annoInput->setDisplayFormat("yyyy");
    annoInput->setToolTip("Anno di produzione");

    copieInput = new QSpinBox();
    copieInput->setRange(0, 999);
    copieInput->setValue(film->getCopie());
    copieInput->setToolTip("Numero di copie disponibili");

    formGeneral->addRow("Codice:", codiceInput);
    formGeneral->addRow("Titolo:", titoloInput);
    formGeneral->addRow("Descrizione:", descrizioneInput);
    formGeneral->addRow("Genere:", genereInput);
    formGeneral->addRow("Anno:", annoInput);
    formGeneral->addRow("Copie:", copieInput);

    QGroupBox* detailsGroup = new QGroupBox("Dettagli Tecnici", this);
    QFormLayout* formDetails = new QFormLayout(detailsGroup);
    formDetails->setContentsMargins(10, 15, 10, 15);
    formDetails->setSpacing(8);

    linguaInput = createLineEdit(QString::fromStdString(film->getLingua()), "Lingua originale");
    registaInput = createLineEdit(QString::fromStdString(film->getRegista()), "Regista principale");

    durataInput = new QSpinBox();
    durataInput->setRange(1, 999);
    durataInput->setValue(film->getDurata());
    durataInput->setSuffix(" min");
    durataInput->setToolTip("Durata in minuti");

    attoriInput = createLineEdit(QString::fromStdString(film->getAttori()), "Attore principale");
    produttoreInput = createLineEdit(QString::fromStdString(film->getProduttore()), "Casa di produzione");

    formDetails->addRow("Lingua:", linguaInput);
    formDetails->addRow("Regista:", registaInput);
    formDetails->addRow("Durata:", durataInput);
    formDetails->addRow("Attori:", attoriInput);
    formDetails->addRow("Produttore:", produttoreInput);

    mainLayout->addWidget(generalGroup);
    mainLayout->addWidget(detailsGroup);
    mainLayout->addStretch();
}

QLineEdit* ModificaFilm::createLineEdit(const QString& text, const QString& tooltip) {
    QLineEdit* edit = new QLineEdit(text);
    edit->setPlaceholderText("...");
    edit->setToolTip(tooltip);
    edit->setMinimumWidth(250);
    return edit;
}

void ModificaFilm::edit(Articolo* a) {

    Film* film = dynamic_cast<Film*>(a);

    film->setCodice(codiceInput->text().toStdString());
    film->setTitolo(titoloInput->text().toStdString());
    film->setDescrizione(descrizioneInput->text().toStdString());
    film->setGenere(genereInput->text().toStdString());
    film->setAnno(annoInput->date().year());
    film->setCopie(copieInput->value());
    film->setLingua(linguaInput->text().toStdString());
    film->setRegista(registaInput->text().toStdString());
    film->setDurata(durataInput->value());
    film->setAttori(attoriInput->text().toStdString());
    film->setProduttore(produttoreInput->text().toStdString());

    int check = lista.controlla(film);

    if(check == 0) {
        return;
    } else if(check == -1) {
        codiceInput->clear();
        codiceInput->setFocus();
    
    } else if(check == -2) {
        titoloInput->clear();
        titoloInput->setFocus();
    
    }

}

QVBoxLayout* ModificaFilm::getLayout() const {
    return layout;
}
