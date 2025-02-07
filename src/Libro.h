#ifndef LIBRO_H
#define LIBRO_H

#include<iostream>
#include "Articolo.h"

class Libro : public Articolo {
private:
    std::string casaEditrice;
    int capitoli;
    int pagine;
    std::string autore;

public:
    Libro(const std::string& titolo,const std::string& codice, const std::string& descrizione, const std::string& genere,int anno, int copie, const std::string& lingua, const std::string& casaEditrice, int capitoli,int pagine, const std::string& autore);

    std::string getCasaEditrice() const;
    int getCapitoli() const;
    int getPagine() const;
    std::string getAutore() const;

    std::string informazioniArticolo() const override;

    void setCasaEditrice(const std::string& casaEditrice);
    void setCapitoli(int capitoli);
    void setPagine(int pagine);
    void setAutore(const std::string& autore);

    virtual void accept(VisitorInterface& visitor);
    virtual void accept(ConstVisitorInterface& visitor) const;
};

#endif // LIBRO_H