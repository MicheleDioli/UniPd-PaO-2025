#include "JsonImporter.h"


Articolo* JsonImporter::importJson() {
    QString fileName = QFileDialog::getOpenFileName(nullptr, "Open File", "", "Json files (*.json)");
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
        }

    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);

    if (doc.isNull()) {
        std::cerr << "Errore nel parsing del file JSON!" << std::endl;
        return nullptr;
    }

    QJsonObject json = doc.object();

    QString tipo = json["type"].toString();

    if( tipo == "Libro" || tipo == "libro"){
        return  new Libro(json["codice"].toString().toStdString(), json["descrizione"].toString().toStdString(), json["genere"].toString().toStdString(), json["anno"].toInt(), json["copie"].toInt(), json["lingua"].toString().toStdString(), json["casaEditrice"].toString().toStdString(), json["capitoli"].toInt(), json["pagine"].toInt(), json["autore"].toString().toStdString());
    }
    else if( tipo == "Rivista" || tipo == "rivista"){
        return new Rivista(json["codice"].toString().toStdString(), json["descrizione"].toString().toStdString(), json["genere"].toString().toStdString(), json["anno"].toInt(), json["copie"].toInt(), json["lingua"].toString().toStdString(), json["editore"].toString().toStdString(), json["pagine"].toInt(), json["pubblicatore"].toString().toStdString(), json["intervalloPubblicazione"].toInt(), json["edizione"].toInt(), json["difficolta"].toInt());
    }
    else if( tipo == "Film" || tipo == "film"){
        return new Film(json["codice"].toString().toStdString(), json["descrizione"].toString().toStdString(), json["genere"].toString().toStdString(), json["anno"].toInt(), json["copie"].toInt(), json["lingua"].toString().toStdString(), json["regista"].toString().toStdString(), json["durata"].toInt(), json["attori"].toString().toStdString(), json["produttore"].toString().toStdString());
    }

    std::cerr << "Tipo non riconosciuto!" << std::endl;
    return nullptr;
}