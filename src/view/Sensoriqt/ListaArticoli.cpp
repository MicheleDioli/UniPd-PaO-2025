#include "ListaArticoli.h"

void ListaArticoli::addArticolo(Articolo* a) {
    if(contralla(articoli,a)){
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

int ListaArticoli::contralla(std::list<Articolo*> articoli, Articolo* a) {
    for(auto it : articoli) {
        if(it->getCodice() == a->getCodice()) {
            std::cerr << "Codice già esistente" << std::endl;
            return -1;
        }
        if(it->getTitolo() == a->getTitolo() && it->getAnno() == a->getAnno() && it->getLingua() == a->getLingua()) {
            std::cerr << "Articolo già esistente" << std::endl;
            return -2;
        }
    }
    return 0;
}
