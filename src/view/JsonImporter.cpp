#include "JsonImporter.h"

Articolo* JsonImporter::importJson(const QString& filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        std::cerr << "Impossibile aprire il file JSON!" << std::endl;
        return nullptr;
    }

    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);

    if (doc.isNull()) {
        std::cerr << "Errore nel parsing del file JSON!" << std::endl;
        return nullptr;
    }

    QJsonObject json = doc.object();

    QString tipo = json["tipo"].toString();

    if (tipo == "Libro") {

        QString codice = json["codice"].toString();
        QString descrizione = json["descrizione"].toString();
        QString autore = json["autore"].toString();
        int anno = json["anno"].toInt();
        QString genere = json["genere"].toString();
        int pagine = json["pagine"].toInt();
        QString casaEditrice = json["casaEditrice"].toString();

        return new Libro(codice.toStdString(), descrizione.toStdString(), 0.0, autore.toStdString(), genere.toStdString());
    } else if (tipo == "Film") {

        QString codice = json["codice"].toString();
        QString descrizione = json["descrizione"].toString();
        QString regista = json["regista"].toString();
        int durata = json["durata"].toInt();
        int valutazioneCritica = json["valutazioneCritica"].toInt();
        int valutazionePubblico = json["valutazionePubblico"].toInt();
        QString genere = json["genere"].toString();

        QJsonArray attoriArray = json["attori"].toArray();
        std::list<std::string> attori;
        for (auto& actor : attoriArray) {
            attori.push_back(actor.toString().toStdString());
        }

        return new Film(codice.toStdString(), descrizione.toStdString(), 0.0, regista.toStdString(), genere.toStdString(), durata, attori);
    } else if (tipo == "Rivista") {
        // Creare oggetto Rivista
        QString codice = json["codice"].toString();
        QString descrizione = json["descrizione"].toString();
        QString editore = json["editore"].toString();
        QString pubblicatore = json["pubblicatore"].toString();
        int pagine = json["pagine"].toInt();
        int intervalloPubblicazione = json["intervalloPubblicazione"].toInt();
        int edizione = json["edizione"].toInt();
        QString genere = json["genere"].toString();

        return new Rivista(codice.toStdString(), descrizione.toStdString(), 0.0, editore.toStdString(), genere.toStdString(), pagine);
    }

    std::cerr << "Tipo di articolo non riconosciuto!" << std::endl;
    return nullptr;
}
