#include "Libro.h"

Libro::Libro(const std::string& codice, const std::string& descrizione, const std::string& genere,
             const std::string& breveDescrizione, int anno, const std::string& casaEditrice, int pagine,
             const std::string& autore, int capitoli)
    : Articolo(codice, descrizione, genere, breveDescrizione, anno),
      casaEditrice(casaEditrice), pagine(pagine), autore(autore), capitoli(capitoli) {}

std::string Libro::getCasaEditrice() const {return casaEditrice;}

int Libro::getCapitoli() const {return capitoli;}

int Libro::getPagine() const {return pagine;}

std::string Libro::getAutore() const {return autore;}

std::string Libro::informazioniArticolo(const Articolo* art) const {
    if(art){
        return "Codice: " + art->getCodice() + "\nDescrizione: " + art->getDescrizione() + "\nGenere: " + art->getGenere() + "\nBreve Descrizione: " + art->getBreveDescrizione() + "\nAnno: " + std::to_string(art->getAnno()) +
               "\nCasa Editrice: " + casaEditrice + "\nCapitoli: " + std::to_string(capitoli) + "\nPagine: " + std::to_string(pagine) +
               "\nAutore: " + autore;
    } else {
        return "Articolo non trovato";
    }
}

void Libro::setCasaEditrice(const std::string& casaEditrice) {this->casaEditrice = casaEditrice;}

void Libro::setCapitoli(int capitoli) {this->capitoli = capitoli;}

void Libro::setPagine(int pagine) {this->pagine = pagine;}

void Libro::setAutore(const std::string& autore) {this->autore = autore;}