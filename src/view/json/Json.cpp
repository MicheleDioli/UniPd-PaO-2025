#include "Json.h"

void Json::setFileName(const QString& s){
    fileName = s;
}

QString Json::getFileName() const{
    return fileName;
}

QJsonObject Json::salva(const Articolo& a)const{
    JsonVisitor json_visitor;
    a.accept(json_visitor);
    return json_visitor.getObject();
}

QJsonObject Json::salvaLista(const ListaArticoli& l)const{
    QJsonObject obj;
    QJsonArray array;
    std::list<Articolo*> lista = l.getArticoli();
    for(auto it = lista.begin(); it != lista.end(); ++it){
        array.append(salva(**it));
    }
    obj["Articoli"] = array;
    return obj;
}

void Json::salvaJson(const Articolo& a){
    QJsonObject obj = salva(a);
    QJsonDocument doc(obj);
    QString fileName = QFileDialog::getSaveFileName(nullptr, "Save File", "", "JSON files (*.json)");
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(nullptr, "Unable to open file", file.errorString());
        return;
    }
    file.write(doc.toJson());
    file.close();
    setFileName(fileName);
}

void Json::salvaJsonLista(const ListaArticoli& l){
    QJsonObject obj = salvaLista(l);
    QJsonDocument doc(obj);
    QString fileName = QFileDialog::getSaveFileName(nullptr, "Save File", "", "JSON files (*.json)");
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(nullptr, "Unable to open file", file.errorString());
        return;
    }
    setFileName(fileName);
    file.write(doc.toJson());
    file.close();
}

void Json::importa(ListaArticoli* l){
    JsonImporter importer;
    importer.importa(l);

}

void Json::salvaSNLista(const ListaArticoli& l,QString fileNameInput){
    QString fileName = fileNameInput;
    if (fileName.isEmpty()) {
        QMessageBox::warning(nullptr, "File non selezionato", "Nessun file JSON selezionato per l'aggiornamento.");
        return;
    }

    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(nullptr, "Errore", "Impossibile aprire il file per la lettura: " + file.errorString());
        return;
    }

    QByteArray fileData = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(fileData);
    if (doc.isNull()) {
        QMessageBox::warning(nullptr, "Errore", "Formato JSON non valido.");
        return;
    }

    QJsonObject obj = doc.object();

    QJsonObject updatedObj = salvaLista(l);
    for (const QString& key : updatedObj.keys()) {
        obj[key] = updatedObj[key];
    }

    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(nullptr, "Errore", "Impossibile aprire il file per la scrittura: " + file.errorString());
        return;
    }
    QJsonDocument updatedDoc(obj);
    file.write(updatedDoc.toJson());
    file.close();
}

void Json::salvaSN(const Articolo& a,QString fileNameInput){
    QString fileName = fileNameInput;
    if (fileName.isEmpty()) {
        QMessageBox::warning(nullptr, "File non selezionato", "Nessun file JSON selezionato per l'aggiornamento.");
        return;
    }

    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(nullptr, "Errore", "Impossibile aprire il file per la lettura: " + file.errorString());
        return;
    }

    QByteArray fileData = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(fileData);
    if (doc.isNull()) {
        QMessageBox::warning(nullptr, "Errore", "Formato JSON non valido.");
        return;
    }

    QJsonObject obj = doc.object();

    QJsonObject updatedObj = salva(a);
    for (const QString& key : updatedObj.keys()) {
        obj[key] = updatedObj[key];
    }

    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(nullptr, "Errore", "Impossibile aprire il file per la scrittura: " + file.errorString());
        return;
    }
    QJsonDocument updatedDoc(obj);
    file.write(updatedDoc.toJson());
    file.close();
}