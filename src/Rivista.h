#ifndef RIVISTA_H
#define RIVISTA_H

#include <string>
#include "Articolo.h"

class Rivista : public Articolo {
private:
    std::string editore;
    int pagine;
    std::string pubblicatore;
    int intervalloPubblicazione;
    int edizione;
    int difficolta;

public:
    Rivista(const std::string& codice, const std::string& descrizione, const std::string& genere,
            int anno, int copie, const::std::string&lingua, const std::string& editore, int pagine,
            const std::string& pubblicatore, int intervalloPubblicazione, int edizione, int difficolta);
    std::string getEditore() const;
    int getPagine() const;
    std::string getPubblicatore() const;
    int getIntervalloPubblicazione() const;
    int getEdizione() const;
    int getDifficolta() const;
    int velocitaLettura() const;
    std::string informazioniArticolo() const override;

     void setEditore(const std::string& editore);
     void setPagine(int pagine);
     void setPubblicatore(const std::string& pubblicatore);
     void setIntervalloPubblicazione(int intervallo);
     void setEdizione(int edizione);
     void setDifficolta(int difficolta);

    virtual void accept(VisitorInterface& visitor);
    virtual void accept(ConstVisitorInterface& visitor) const;
};
/*
class Builder {
private:

    std::string codice;
    std::string descrizione;
    std::string genere;
    std::string breveDescrizione;
    int anno;


    std::string editore = "N/A";
    int pagine = 0;
    std::string pubblicatore = "N/A";
    int intervalloPubblicazione = 0;
    int edizione = 1;
    int difficolta = 1;

public:
    Builder(const std::string& codice, const std::string& descrizione, const std::string& genere,
            const std::string& breveDescrizione, int anno);

    Rivista build() const;
};
*/

#endif