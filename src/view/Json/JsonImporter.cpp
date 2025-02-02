#include "JsonImporter.h"

Articolo* JsonImporter::createArticolo(const QString& type, const QJsonObject& json) {
        if (type.compare("Libro", Qt::CaseInsensitive) == 0) {
            return new Libro(
                json["codice"].toString().toStdString(),
                json["descrizione"].toString().toStdString(),
                json["genere"].toString().toStdString(),
                json["anno"].toInt(),
                json["copie"].toInt(),
                json["lingua"].toString().toStdString(),
                json["casaEditrice"].toString().toStdString(),
                json["capitoli"].toInt(),
                json["pagine"].toInt(),
                json["autore"].toString().toStdString()
            );
        } else if (type.compare("Rivista", Qt::CaseInsensitive) == 0) {
            return new Rivista(
                json["codice"].toString().toStdString(),
                json["descrizione"].toString().toStdString(),
                json["genere"].toString().toStdString(),
                json["anno"].toInt(),
                json["copie"].toInt(),
                json["lingua"].toString().toStdString(),
                json["editore"].toString().toStdString(),
                json["pagine"].toInt(),
                json["pubblicatore"].toString().toStdString(),
                json["intervalloPubblicazione"].toInt(),
                json["edizione"].toInt(),
                json["difficolta"].toInt()
            );
        } else if (type.compare("Film", Qt::CaseInsensitive) == 0) {
            return new Film(
                json["codice"].toString().toStdString(),
                json["descrizione"].toString().toStdString(),
                json["genere"].toString().toStdString(),
                json["anno"].toInt(),
                json["copie"].toInt(),
                json["lingua"].toString().toStdString(),
                json["regista"].toString().toStdString(),
                json["durata"].toInt(),
                json["attori"].toString().toStdString(),
                json["produttore"].toString().toStdString()
            );
        }
        return nullptr;
    }

Articolo* JsonImporter::importJson() {

    QString fileName = QFileDialog::getOpenFileName(nullptr, "Open File", "", "Json files (*.json)");
    if (fileName.isEmpty()) {
        QMessageBox::warning(nullptr, "Errore", "Nessun file selezionato.");
        return nullptr;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(nullptr, "Errore", "Impossibile aprire: " + file.errorString());
        return nullptr;
    }

    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (doc.isNull() || !doc.isObject()) {
        QMessageBox::warning(nullptr, "Errore", "Formato Json non valido.");
        return nullptr;
    }

    QJsonObject json = doc.object();
    QString type = json["type"].toString();

    Articolo* articolo = createArticolo(type, json);
    if (!articolo) {
        QMessageBox::warning(nullptr, "Errore", "Tipo non supportato: " + type);
        return nullptr;
    }

    return articolo;
}