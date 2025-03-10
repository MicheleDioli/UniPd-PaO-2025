#include "ListaArticoli.h"

ListaArticoli::ListaArticoli(std::list<Articolo*> articoli) : articoliL(articoli) {}

void ListaArticoli::addArticolo(Articolo* a) {

    if (controlla(a) == 0) {
        articoliL.push_back(a);
    } else {
        std::cerr << "Articolo già presente" << std::endl;
    }
}

void ListaArticoli::removeArticolo(Articolo* a) {

    for (auto it = articoliL.begin(); it != articoliL.end(); ++it) {
        if ((*it)->getCodice() == a->getCodice()) {
            articoliL.erase(it);
            return;
        }
    }
}

std::list<Articolo*> ListaArticoli::getArticoli()const{
    return articoliL;
}

void ListaArticoli::clear() {
    articoliL.clear();
}

ListaArticoli::~ListaArticoli() {
    for (auto a : articoliL) {
        delete a;
    }
}

int ListaArticoli::controlla(Articolo* a) {
    for (auto it : articoliL) {
        if (it->getCodice() == a->getCodice()) {
            //std::cerr << "Codice già esistente" << std::endl;
            return -1;
        }
        if (it->getTitolo() == a->getTitolo() &&
            it->getAnno() == a->getAnno() &&
            it->getLingua() == a->getLingua()) {
            //std::cerr << "Articolo già esistente" << std::endl;
            return -2;
        }
    }
    return 0;
}

void ListaArticoli::salvaMappa(std::string path,  Articolo* a) {
        articoliS[a->getCodice()] = path;
}

bool ListaArticoli::checkSalvato(Articolo* a) {
    if(articoliS.find(a->getCodice()) != articoliS.end())
        return true;
    return false;
}
