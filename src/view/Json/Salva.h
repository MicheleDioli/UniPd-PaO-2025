//
// Created by Michele Dioli on 1/29/25.
//
#ifndef SALVA_H
#define SALVA_H

#include "JsonVisitor.h"
#include "JsonImporter.h"


#include "../../Articolo.h"

class Json{
  private:
    QJsonObject salva(const Articolo&) const ;
    Articolo* importa();

public:
    void salvaJson(const Articolo&);
    Articolo* importaJson();
};

#endif //SALVA_H
