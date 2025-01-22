#ifndef ARTICOLO_H
#define ARTICOLO_H

#include <string>
#include <iostream>
#include <list>

class Articolo {
private:
    std::string codice;
    std::string descrizione;
    std::string genere;
    std::string breveDescrizione;
    int anno;

public:
    Articolo(const std::string& codice, const std::string& descrizione, const std::string& genere, const std::string& breveDescrizione, int anno);
    Articolo() = default;
    virtual ~Articolo();

    std::string getCodice() const;
    std::string getDescrizione() const;
    std::string getGenere() const;
    std::string getBreveDescrizione() const;
    int getAnno() const;

    virtual std::string informazioniArticolo(const Articolo* art) const;
    int numeroArticoli(const std::list<Articolo*>& articoli) const;
    Articolo* getArticoloPrecendete(const Articolo* art, const std::list<Articolo*>& articoli) const;
    Articolo* getArticoloSuccessivo(const Articolo* art, const std::list<Articolo*>& articoli) const;
    int getNumeroSerie(const Articolo* art, const std::list<Articolo*>& articoli) const;
};

#endif // ARTICOLO_H