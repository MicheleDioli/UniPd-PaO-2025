//
// Created by Michele Dioli on 12/18/24.
//
#include "Rivista.h"

Rivista::Rivista(std::string codice, std::string descrizione, std::string genere, std::string breveDescrizione, int anno, std::string editore, int pagine, std::string pubblicatore, int intervalloPubblicazione, int edizione, int difficolta):
    Articolo(codice, descrizione, genere, breveDescrizione, anno), editore(editore), pagine(pagine), pubblicatore(pubblicatore), intervalloPubblicazione(intervalloPubblicazione), edizione(edizione), difficolta(difficolta) {}

std::string Rivista::getEditore(){
    return editore;
}
int Rivista::getPagine(){
  return pagine;
}

std::string Rivista::getPubblicatore(){
  return pubblicatore;
}

int Rivista::getIntervalloPubblicazione(){
	return intervalloPubblicazione;
}
int Rivista::getEdizione(){
	return edizione;
}

int Rivista::getDifficolta(){
    return difficolta;
}

int Rivista::velocitaLettura(){
  int indice = 1 + ( difficolta/5);
  int minutoxpag = 5 * indice;
  return minutoxpag * pagine;
}