// Articolo.cpp
#include "Articolo.h"

Articolo::Articolo() {}

Articolo::Articolo(const std::string& codice, const std::string& descrizione, const std::string& genere, int anno, int copie, const std::string& lingua)
    : codice(codice), descrizione(descrizione), genere(genere), anno(anno), copie(copie), lingua(lingua){}

Articolo::~Articolo() {
}

std::string Articolo::getCodice() const {
    return codice;
}

std::string Articolo::getDescrizione() const {
    return descrizione;
}

std::string Articolo::getGenere() const {
    return genere;
}

int Articolo::getAnno() const {
    return anno;
}

std::string Articolo::getLingua() const {
    return lingua;
}

int Articolo::getCopie() const {
    return copie;
}

std::string Articolo::informazioniArticolo() const {
	    return "Codice: " + getCodice() + "\nDescrizione: " + getDescrizione() + "\nGenere: " + getGenere() + "\nAnno: " + std::to_string(getAnno());
}

int Articolo::numeroArticoli(const std::list<Articolo*>& articoli) const {
    return articoli.size();
}

Articolo* Articolo::getArticoloPrecendete(const Articolo* art, const std::list<Articolo*>& articoli) const {
    auto it = articoli.begin();
    auto prev = articoli.end();

    if(art != *it){
   		while (it != articoli.end()) {
        	if ((*it)->getCodice() == art->getCodice()) {
            	if (prev != articoli.end()) {
                	return *prev;
            	}
            	return nullptr;
        	}
        	prev = it;
        	++it;
    	}
    }
    return nullptr;
}

Articolo* Articolo::getArticoloSuccessivo(const Articolo* art, const std::list<Articolo*>& articoli) const {
    auto it = articoli.begin();
    if(!(it == articoli.end())){
    	while (it != articoli.end()) {
        	if ((*it)->getCodice() == art->getCodice()) {
            	++it;
            	if (it != articoli.end()) {
                	return *it;
            	}
            	return nullptr;
        	}
        	++it;
    	}
    }
    return nullptr;
}

int Articolo::getNumeroSerie(const Articolo* art, const std::list<Articolo*>& articoli) const {
    auto it = articoli.begin();
    int i = 0;
    while (it != articoli.end()) {
        if ((*it)->getCodice() == art->getCodice()) {
            return i+1;
        }
        ++i;
        ++it;
    }
    return -1;
}

void Articolo::setCodice(const std::string& codice) {
    this->codice = codice;
}

void Articolo::setDescrizione(const std::string& descrizione) {
    this->descrizione = descrizione;
}

void Articolo::setGenere(const std::string& genere) {
    this->genere = genere;
}

void Articolo::setAnno(int anno) {
    this->anno = anno;
}

void Articolo::setLingua(const std::string& lingua) {
    this->lingua = lingua;
}

void Articolo::setCopie(int copie) {
    this->copie = copie;
}