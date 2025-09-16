#include "ListaArticoli.h"
#include <algorithm>
#include <iostream>

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
            articoliS.erase(a->getCodice());

            return;
        }
    }
}

std::list<Articolo*> ListaArticoli::ordinaLista(std::list<Articolo*> articoliL, char c){

  std::list<Articolo*> temp = articoliL;

    if (c == 't') {
        temp.sort([](Articolo* a, Articolo* b) {
            return a->getTitolo() < b->getTitolo();
        });
    } else if (c == 'T') {
        temp.sort([](Articolo* a, Articolo* b) {
            return a->getTitolo() > b->getTitolo();
        });}

    return temp;
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
            return -1;
        }
        if (it->getTitolo() == a->getTitolo() &&
            it->getAnno() == a->getAnno() &&
            it->getLingua() == a->getLingua()) {
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

std::string ListaArticoli::getPath(Articolo* a) {
    return articoliS[a->getCodice()];
}

std::string ListaArticoli::getListaPath()const{
    return listaPath;
}

void ListaArticoli::setListaPath(std::string s){
    listaPath = s;
}

int ListaArticoli::maxAnni() const {
    if (articoliL.empty())  
        return 0;

    int max = 0;
    for(auto a : articoliL){
        if (a->getAnno()>max)   max = a->getAnno();
    }
    return max;
}

int ListaArticoli::minAnni() const {
    if (articoliL.empty())  
        return 0;
    int min = 9999;
    for(auto a : articoliL){
        if (a->getAnno()<min)   min = a->getAnno();
    }
    return min;
}

int ListaArticoli::maxCopie()const{
    if (articoliL.empty())  
        return 0;
    int max = 0;
    for(auto a : articoliL){
        if (a->getCopie()>max)   max = a->getCopie();
    }
    return max;
}

int ListaArticoli::maxMinutaggio()const{

    if (articoliL.empty())  
        return 0;

    int max = 0;

    for(auto a : articoliL){
        if(Film* f = dynamic_cast<Film*>(a)) {
            if (f->getDurata() > max) {
                max = f->getDurata();
            }
        }
    }
    std::cout << "Max minutaggio: " << max << std::endl;

    return max;

}

std::list<std::string *> ListaArticoli::allAttori()const{

    std::list<std::string*> filmAttori;

    if (articoliL.empty())  
        return filmAttori;

    for(auto a : articoliL){
        if(Film* f = dynamic_cast<Film*>(a)) {
            std::string* push = new std::string(f->getAttori());
            filmAttori.push_back(push); 
        }
    }


    return filmAttori;
}

std::list<std::string *> ListaArticoli::allProdu()const{
    std::list<std::string*> filmProdu;

    if (articoliL.empty())  
        return filmProdu;

    for(auto a : articoliL){
        if(Film* f = dynamic_cast<Film*>(a)) {
            std::string* push = new std::string(f->getProduttore());
            filmProdu.push_back(push); 
        }
    }
    return filmProdu;
}

int ListaArticoli::maxPagine()const{
    if (articoliL.empty())  
        return 0;
    int max = 0;
    std::list<Libro*> libroPagine;
    
    for(auto a : articoliL){
        if(Libro* l = dynamic_cast<Libro*>(a)) {
            libroPagine.push_back(l); 
        }
    }

    for(auto a : libroPagine){
        if (a->getPagine()>max)   max = a->getPagine();
    }

    return max;
}

int ListaArticoli::maxCapitoli()const{
    if (articoliL.empty())  
        return 0;
    int max = 0;
    std::list<Libro*> libroCapitoli;
    
    for(auto a : articoliL){
        if(Libro* l = dynamic_cast<Libro*>(a)) {
            libroCapitoli.push_back(l); 
        }
    }

    for(auto a : libroCapitoli){
        if (a->getCapitoli()>max)   max = a->getCapitoli();
    }

    return max;
}

std::list<std::string *> ListaArticoli::allAutoriLibri()const{
    std::list<std::string*> autoriLista;

    if (articoliL.empty())  
        return autoriLista;

    for(auto a : articoliL){
        if(Libro* l = dynamic_cast<Libro*>(a)) {
            std::string* push = new std::string(l->getAutore());
            autoriLista.push_back(push); 
        }
    }
    return autoriLista;
}

std::list<std::string *> ListaArticoli::allCaseEditrici()const{
    std::list<std::string*> caseLista;

    if (articoliL.empty())  
        return caseLista;

    for(auto a : articoliL){
        if(Libro* l = dynamic_cast<Libro*>(a)) {
            std::string* push = new std::string(l->getCasaEditrice());
            caseLista.push_back(push); 
        }
    }
    return caseLista;
}

int ListaArticoli::maxPagineRivista()const{
    if (articoliL.empty())  
        return 0;
    int max = 0;

    for(auto a : articoliL){
        if(Rivista* r = dynamic_cast<Rivista*>(a)) {
            if (r->getPagine() > max) {
                max = r->getPagine();
            }
        }
    }

    return max;
}

std::list<std::string*> ListaArticoli::allPeriodici()const{
    std::list<std::string*> periodiciLista;

    if (articoliL.empty()) {
        return periodiciLista;
    }
    for(auto a : articoliL){
        if(Rivista* r = dynamic_cast<Rivista*>(a)) {
            std::string* push = new std::string(r->getIntervalloPubblicazione());
            periodiciLista.push_back(push);
        }
    }
    return periodiciLista;
}
