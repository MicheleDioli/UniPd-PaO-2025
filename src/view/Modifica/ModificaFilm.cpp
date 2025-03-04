#include "ModificaFilm.h"
#include <QDebug>

ModificaFilm::ModificaFilm(QWidget* parent, Film* film)
    : ModificaArticolo(parent), film(film) {
    layout = new QVBoxLayout(this);

    if (!film) {
        qWarning() << "Film nullo in ModificaFilm!";
        return;
    }

    codiceInput = new QLineEdit();
    codiceInput->setText(QString::fromStdString(film->getCodice()));

    titoloInput = new QLineEdit();
    titoloInput->setText(QString::fromStdString(film->getTitolo()));

    descrizioneInput = new QLineEdit();
    descrizioneInput->setText(QString::fromStdString(film->getDescrizione()));

    genereInput = new QLineEdit();
    genereInput->setText(QString::fromStdString(film->getGenere()));

    annoInput = new QDateEdit();
    annoInput->setDate(QDate(film->getAnno(), 1, 1));
    annoInput->setDisplayFormat("yyyy");

    copieInput = new QSpinBox();
    copieInput->setValue(film->getCopie());

    linguaInput = new QLineEdit();
    linguaInput->setText(QString::fromStdString(film->getLingua()));

    registaInput = new QLineEdit();
    registaInput->setText(QString::fromStdString(film->getRegista()));

    durataInput = new QSpinBox();
    durataInput->setRange(1, 999);
    durataInput->setValue(film->getDurata());

    attoriInput = new QLineEdit();
    attoriInput->setText(QString::fromStdString(film->getAttori()));

    produttoreInput = new QLineEdit();
    produttoreInput->setText(QString::fromStdString(film->getProduttore()));

    layout->addWidget(new QLabel("Codice:"));
    layout->addWidget(codiceInput);

    layout->addWidget(new QLabel("Titolo:"));
    layout->addWidget(titoloInput);

    layout->addWidget(new QLabel("Descrizione:"));
    layout->addWidget(descrizioneInput);

    layout->addWidget(new QLabel("Genere:"));
    layout->addWidget(genereInput);

    layout->addWidget(new QLabel("Anno:"));
    layout->addWidget(annoInput);

    layout->addWidget(new QLabel("Copie:"));
    layout->addWidget(copieInput);

    layout->addWidget(new QLabel("Lingua:"));
    layout->addWidget(linguaInput);

    layout->addWidget(new QLabel("Regista:"));
    layout->addWidget(registaInput);

    layout->addWidget(new QLabel("Durata:"));
    layout->addWidget(durataInput);

    layout->addWidget(new QLabel("Attori:"));
    layout->addWidget(attoriInput);

    layout->addWidget(new QLabel("Produttore:"));
    layout->addWidget(produttoreInput);


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
}

QVBoxLayout* ModificaFilm::getLayout() const {
    return layout;
}
