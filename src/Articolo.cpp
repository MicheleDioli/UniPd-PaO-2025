// Articolo.cpp
#include "Articolo.h"

Articolo::Articolo() {}

Articolo::Articolo(const std::string& titolo, const std::string& codice, const std::string& descrizione, const std::string& genere, int anno, int copie, const std::string& lingua)
    : titolo(titolo), codice(codice), descrizione(descrizione), genere(genere), anno(anno), copie(copie), lingua(lingua){}

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

std::string Articolo::getTitolo() const {
    return titolo;
}

void Articolo::setTitolo(const std::string& titolo) {
    this->titolo = titolo;
}