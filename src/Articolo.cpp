// Articolo.cpp
#include "Articolo.h"

Articolo::Articolo(const std::string& codice, const std::string& descrizione, const std::string& genere, const std::string& breveDescrizione, int anno)
    : codice(codice), descrizione(descrizione), genere(genere), breveDescrizione(breveDescrizione), anno(anno) {}

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

std::string Articolo::getBreveDescrizione() const {
    return breveDescrizione;
}

int Articolo::getAnno() const {
    return anno;
}

std::string Articolo::informazioniArticolo(const Articolo* art) const {
	if(art){
	    return "Codice: " + art->getCodice() + "\nDescrizione: " + art->getDescrizione() + "\nGenere: " + art->getGenere() + "\nBreve Descrizione: " + art->getBreveDescrizione() + "\nAnno: " + std::to_string(art->getAnno());
    }
    else{
    	return "Articolo non trovato";
    }
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