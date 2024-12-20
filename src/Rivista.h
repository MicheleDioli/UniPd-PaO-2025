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
public:
    Rivista(std::string codice, std::string descrizione, std::string genere, std::string breveDescrizione, int anno, std::string editore, int pagine, std::string pubblicatore, int intervalloPubblicazione, int edizione);
    std::string getEditore();
};

#endif //RIVISTA_H