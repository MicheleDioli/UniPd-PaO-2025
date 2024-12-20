//
// Created by Michele Dioli on 12/18/24.
//
#include "Rivista.h"

Rivista::Rivista(std::string codice, std::string descrizione, std::string genere, std::string breveDescrizione, int anno, std::string editore, int pagine, std::string pubblicatore, int intervalloPubblicazione, int edizione):
    Articolo(codice, descrizione, genere, breveDescrizione, anno), editore(editore), pagine(pagine), pubblicatore(pubblicatore), intervalloPubblicazione(intervalloPubblicazione), edizione(edizione){}

std::string Rivista::getEditore(){
    return editore;
}
