//
// Created by Michele Dioli on 12/18/24.
//
#include "Articolo.h"

Articolo::Articolo(std::string codice, std::string descrizione, std::string genere, std::string breveDescrizione, int anno):
    codice(codice), descrizione(descrizione), genere(genere), breveDescrizione(breveDescrizione), anno(anno){}

Articolo::~Articolo() {}

std::string Articolo::getCodice(){
    return codice;
}

std::string Articolo::getDescrizione(){
    return descrizione;
}

std::string Articolo::getGenere(){
    return genere;
}

std::string Articolo::getBreveDescrizione(){
    return breveDescrizione;
}

int Articolo::getAnno(){
    return anno;
}
