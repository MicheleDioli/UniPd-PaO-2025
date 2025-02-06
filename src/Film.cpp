#include "Film.h"
#include "ConstVisitorInterface.h"

Film::Film(const std::string& titolo, const std::string& codice, const std::string& descrizione, const std::string& genere,
           int anno, int copie, const std::string& lingua, const std::string& regista, int durata,
           const std::string& attori, const std::string& produttore)
    : Articolo(titolo, codice, descrizione, genere, anno, copie, lingua), regista(regista), durata(durata),
      attori(attori), produttore(produttore) {}

std::string Film::getRegista() const {return regista;}

int Film::getDurata() const {return durata;}

std::string Film::getAttori() const {return attori;}

std::string Film::getProduttore() const {return produttore;}

int Film::velocitaVisione() const {
    return durata / 60;
}

std::string Film::informazioniArticolo() const {
      return "Codice: " + getCodice() + "\nDescrizione: " + getDescrizione() + "\nGenere: " + getGenere() + "\nAnno: " + std::to_string(getAnno()) +
             "\nRegista: " + regista + "\nDurata: " + std::to_string(durata) + "\nAttori: " + attori +
             "\nProduttore: " + produttore;
}

void Film::setRegista(const std::string& regista) {this->regista = regista;}

void Film::setDurata(int durata) {this->durata = durata;}

void Film::setAttori(const std::string& attori) {this->attori = attori;}

void Film::setProduttore(const std::string& produttore) {this->produttore = produttore;}

void Film::accept(VisitorInterface& visitor) {
    visitor.visitFilm(*this);
}

void Film::accept(ConstVisitorInterface& visitor) const {
    visitor.visitFilm(*this);
}