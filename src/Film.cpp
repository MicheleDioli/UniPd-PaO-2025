#include "Film.h"

Film::Film(const std::string& codice, const std::string& descrizione, const std::string& genere,
           const std::string& breveDescrizione, int anno, const std::string& regista, int durata,
           const std::string& attori, const std::string& produttore)
    : Articolo(codice, descrizione, genere, breveDescrizione, anno),
      regista(regista), durata(durata), attori(attori), produttore(produttore) {}

std::string Film::getRegista() const {return regista;}

int Film::getDurata() const {return durata;}

std::string Film::getAttori() const {return attori;}

std::string Film::getProduttore() const {return produttore;}

int Film::velocitaVisione() const {
    return durata / 60;
}

std::string Film::informazioniArticolo(const Articolo* art) const {
    if(art){
        return "Codice: " + art->getCodice() + "\nDescrizione: " + art->getDescrizione() + "\nGenere: " + art->getGenere() + "\nBreve Descrizione: " + art->getBreveDescrizione() + "\nAnno: " + std::to_string(art->getAnno()) +
               "\nRegista: " + regista + "\nDurata: " + std::to_string(durata) + "\nAttori: " + attori +
               "\nProduttore: " + produttore;
    } else {
        return "Articolo non trovato";
    }
}

void Film::setRegista(const std::string& regista) {this->regista = regista;}

void Film::setDurata(int durata) {this->durata = durata;}

void Film::setAttori(const std::string& attori) {this->attori = attori;}

void Film::setProduttore(const std::string& produttore) {this->produttore = produttore;}

