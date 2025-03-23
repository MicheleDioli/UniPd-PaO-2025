#include "JsonVisitor.h"

QJsonObject JsonVisitor::getObject() const {
    return object;
}

void JsonVisitor::visitLibro(const Libro& libro) {
    QJsonObject libro_object;
    libro_object.insert("type", QJsonValue::fromVariant("libro"));
    libro_object.insert("titolo", QJsonValue::fromVariant(libro.getTitolo().c_str()));
    libro_object.insert("codice", QJsonValue::fromVariant(libro.getCodice().c_str()));
    libro_object.insert("descrizione", QJsonValue::fromVariant(libro.getDescrizione().c_str()));
    libro_object.insert("genere", QJsonValue::fromVariant(libro.getGenere().c_str()));
    libro_object.insert("anno", QJsonValue::fromVariant(libro.getAnno()));
    libro_object.insert("copie", QJsonValue::fromVariant(libro.getCopie()));
    libro_object.insert("lingua", QJsonValue::fromVariant(libro.getLingua().c_str()));
    libro_object.insert("casaEditrice", QJsonValue::fromVariant(libro.getCasaEditrice().c_str()));
    libro_object.insert("capitoli", QJsonValue::fromVariant(libro.getCapitoli()));
    libro_object.insert("pagine", QJsonValue::fromVariant(libro.getPagine()));
    libro_object.insert("autore", QJsonValue::fromVariant(libro.getAutore().c_str()));

    object = libro_object;
}

void JsonVisitor::visitRivista(const Rivista& rivista){
    QJsonObject rivista_object;
    rivista_object.insert("type", QJsonValue::fromVariant("rivista"));
    rivista_object.insert("titolo", QJsonValue::fromVariant(rivista.getTitolo().c_str()));
    rivista_object.insert("codice", QJsonValue::fromVariant(rivista.getCodice().c_str()));
    rivista_object.insert("descrizione", QJsonValue::fromVariant(rivista.getDescrizione().c_str()));
    rivista_object.insert("genere", QJsonValue::fromVariant(rivista.getGenere().c_str()));
    rivista_object.insert("anno", QJsonValue::fromVariant(rivista.getAnno()));
    rivista_object.insert("copie", QJsonValue::fromVariant(rivista.getCopie()));
    rivista_object.insert("lingua", QJsonValue::fromVariant(rivista.getLingua().c_str()));
    rivista_object.insert("editore", QJsonValue::fromVariant(rivista.getEditore().c_str()));
    rivista_object.insert("pagine", QJsonValue::fromVariant(rivista.getPagine()));
    rivista_object.insert("pubblicatore", QJsonValue::fromVariant(rivista.getPubblicatore().c_str()));
    rivista_object.insert("intervalloPubblicazione", QJsonValue::fromVariant(rivista.getIntervalloPubblicazione()));
    rivista_object.insert("edizione", QJsonValue::fromVariant(rivista.getEdizione()));
    rivista_object.insert("difficolta", QJsonValue::fromVariant(rivista.getDifficolta()));

    object = rivista_object;
}

void JsonVisitor::visitFilm(const Film& film){
    QJsonObject film_object;
    film_object.insert("type", QJsonValue::fromVariant("film"));
    film_object.insert("titolo", QJsonValue::fromVariant(film.getTitolo().c_str()));
    film_object.insert("codice", QJsonValue::fromVariant(film.getCodice().c_str()));
    film_object.insert("descrizione", QJsonValue::fromVariant(film.getDescrizione().c_str()));
    film_object.insert("genere", QJsonValue::fromVariant(film.getGenere().c_str()));
    film_object.insert("anno", QJsonValue::fromVariant(film.getAnno()));
    film_object.insert("copie", QJsonValue::fromVariant(film.getCopie()));
    film_object.insert("lingua", QJsonValue::fromVariant(film.getLingua().c_str()));
    film_object.insert("regista", QJsonValue::fromVariant(film.getRegista().c_str()));
    film_object.insert("durata", QJsonValue::fromVariant(film.getDurata()));
    film_object.insert("attori", QJsonValue::fromVariant(film.getAttori().c_str()));
    film_object.insert("produttore", QJsonValue::fromVariant(film.getProduttore().c_str()));

    object = film_object;
}