#ifndef FILM_H
#define FILM_H

#include "Articolo.h"
#include <iostream>

class Film : public Articolo {
private:
    std::string regista;
    int durata;
    std::string attori;
    std::string produttore;
public:
    Film(const std::string& titolo, const std::string& codice, const std::string& descrizione, const std::string& genere,
         int anno, int copie, const std::string& lingua, const std::string& regista, int durata,
         const std::string& attori, const std::string& produttore);
    std::string getRegista() const;
    int getDurata() const;
    std::string getAttori() const;
    std::string getProduttore() const;
    int velocitaVisione() const;
    std::string informazioniArticolo() const;

    void setRegista(const std::string& regista);
    void setDurata(int durata);
    void setAttori(const std::string& attori);
    void setProduttore(const std::string& produttore);

    virtual void accept(VisitorInterface& visitor);
    virtual void accept(ConstVisitorInterface& visitor) const;
};

#endif