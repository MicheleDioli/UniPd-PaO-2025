#ifndef FILM_H
#define FILM_H

#include "Articolo.h"

class Film : public Articolo {
private:
    std::string regista;
    int durata;
    std::string attori;
    std::string produttore;
public:
    Film(const std::string& codice, const std::string& descrizione, const std::string& genere,
         const std::string& breveDescrizione, int anno, const std::string& regista, int durata,
         const std::string& attori, const std::string& produttore);

    std::string getRegista() const;
    int getDurata() const;
    std::string getAttori() const;
    std::string getProduttore() const;
    int velocitaVisione() const;
    std::string informazioniArticolo(const Articolo* art) const;

    void setRegista(const std::string& regista);
    void setDurata(int durata);
    void setAttori(const std::string& attori);
    void setProduttore(const std::string& produttore);
};

#endif