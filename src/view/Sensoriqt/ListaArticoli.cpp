//
// Created by Michele Dioli on 2/3/25.
//

#include "ListaArticoli.h"

void ListaArticoli::addArticolo(Articolo* a) {
    if(contralla(articoli,a->getCodice())){
        articoli.push_back(a);
    } else {
        std::cerr << "Articolo già presente" << std::endl;
        return;
    }

}

void ListaArticoli::removeArticolo(Articolo* a) {
    articoli.remove(a);
}

std::list<Articolo*> ListaArticoli::getArticoli() const {
    return articoli;
}

void ListaArticoli::clear() {
    articoli.clear();
}

ListaArticoli::~ListaArticoli() {
    for(auto a : articoli) {
        delete a;
    }
}

bool ListaArticoli::contralla(std::list<Articolo*> articoli, std::string codice) {
    for(auto a : articoli) {
        if(a->getCodice() == codice) {
            return false;
        }
    }
    return true;
}
