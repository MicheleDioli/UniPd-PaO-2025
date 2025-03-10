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
    file.write(doc.toJson());
    file.close();
}

void Json::importa(ListaArticoli* l){
    JsonImporter importer;
    importer.importa(l);
}

void Json::salvaSN(const Articolo& a){
    QJsonObject obj = salva(a);
    QJsonDocument doc(obj);
    QFile file(getFileName());
    file.write(doc.toJson());
    file.close();
}