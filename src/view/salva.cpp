#include "Salva.h"
#include "JsonVisitor.h"
#include "JsonImporter.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFileDialog>
#include <QHeaderView>
#include <QMessageBox>

QJsonObject Json::salva(const Articolo& a)const{
    JsonVisitor json_visitor;
    a.accept(json_visitor);
    return json_visitor.getObject();
}

void Json::salvaJson(const Articolo& a)const {
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
}

Articolo* Json::importa(){
    JsonImporter importer;
    return importer.importJson();
}

Articolo* Json::importaJson(){
    return importa();
}