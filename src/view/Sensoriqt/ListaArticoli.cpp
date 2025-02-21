#include "ListaArticoli.h"

ListaArticoli::ListaArticoli(std::list<Articolo*> articoli) : articoli(articoli) {}

void ListaArticoli::addArticolo(Articolo* a) {

    if (contralla(articoli, a) == 0) {
        articoli.push_back(a);
    } else {
        std::cerr << "Articolo già presente" << std::endl;
    }
}

void ListaArticoli::removeArticolo(Articolo* a) {

    for (auto it = articoli.begin(); it != articoli.end(); ++it) {
        if ((*it)->getCodice() == a->getCodice()) {
            articoli.erase(it);
            return;
        }
    }
}

std::list<Articolo*> ListaArticoli::getArticoli(){
    return articoli;
}

void ListaArticoli::clear() {
    articoli.clear();
}

ListaArticoli::~ListaArticoli() {
    for (auto a : articoli) {
        delete a;
    }
}

int ListaArticoli::contralla(std::list<Articolo*> articoli, Articolo* a) {
    for (auto it : articoli) {
        if (it->getCodice() == a->getCodice()) {
            std::cerr << "Codice già esistente" << std::endl;
            return -1;
        }
        if (it->getTitolo() == a->getTitolo() &&
            it->getAnno() == a->getAnno() &&
            it->getLingua() == a->getLingua()) {
            std::cerr << "Articolo già esistente" << std::endl;
            return -2;
        }
    }
    return 0;
}
