#ifndef JSON_H
#define JSON_H

#include "JsonVisitor.h"
#include "JsonImporter.h"

#include "../../Articolo.h"
#include "../sensoriqt/ListaArticoli.h"

class Json{
private:
    QJsonObject salva(const Articolo&) const ;
    QJsonObject salvaLista(const ListaArticoli&) const;
    QString fileName;

public:
    QString getFileName() const;
    void setFileName(const QString&);
    void importa(ListaArticoli*);
    void salvaJson(const Articolo&, ListaArticoli*);
    void salvaJsonLista(const ListaArticoli&);
    Articolo* importaJson();
    ListaArticoli importaLista(const QString&);
    void salvaSN(const Articolo&, QString);
    void salvaSNLista(const ListaArticoli&, QString);
};

#endif
