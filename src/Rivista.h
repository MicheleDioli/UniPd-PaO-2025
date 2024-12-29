//
// Created by Michele Dioli on 12/18/24.
#include "Articolo.h"

#ifndef RIVISTA_H
#define RIVISTA_H

class Rivista : public Articolo{
private:
    std::string editore;
    int pagine;
    std::string pubblicatore;
    int intervalloPubblicazione;
    int edizione;
    int difficolta;
public:
    Rivista(std::string codice, std::string descrizione, std::string genere, std::string breveDescrizione, int anno, std::string editore, int pagine, std::string pubblicatore, int intervalloPubblicazione, int edizione, int diffi);
    std::string getEditore();
    int getPagine();
    std::string getPubblicatore();
    int getIntervalloPubblicazione();
    int getEdizione();
    int getDifficolta();
    int velocitaLettura();
};

#endif //RIVISTA_H