//
// Created by Michele Dioli on 12/18/24.
//
#include <iostream>
#include <string>
#include <list>

#ifndef ARTICOLO_H
#define ARTICOLO_H

class Articolo{
private:
    std::string codice;
    std::string descrizione;
    std::string genere;
    std::string breveDescrizione;
    int anno;
public:
    Articolo(std::string codice, std::string descrizione, std::string genere, std::string breveDescrizione, int anno);
    virtual ~Articolo();
    std::string getCodice();
    std::string getDescrizione();
    std::string getGenere();
    std::string getBreveDescrizione();
    int getAnno();
};

#endif //ARTICOLO_H