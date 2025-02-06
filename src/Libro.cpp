#include "Libro.h"
#include "ConstVisitorInterface.h"

Libro::Libro(const std::string titolo, const std::string &codice, const std::string &descrizione, const std::string &genere,
             int anno, int copie, const std::string &lingua, const std::string &casaEditrice, int capitoli,
             int pagine, const std::string &autore) : Articolo(titolo, codice, descrizione, genere, anno, copie, lingua),
                                                      casaEditrice(casaEditrice), capitoli(capitoli), pagine(pagine), autore(autore) {}

std::string Libro::getCasaEditrice() const {return casaEditrice;}

int Libro::getCapitoli() const {return capitoli;}

int Libro::getPagine() const {return pagine;}

std::string Libro::getAutore() const {return autore;}

std::string Libro::informazioniArticolo() const {
        return "Codice: " + getCodice() + "\nDescrizione: " + getDescrizione() + "\nGenere: " + getGenere() + "\nAnno: " + std::to_string(getAnno()) +
               "\nCasa Editrice: " + casaEditrice + "\nCapitoli: " + std::to_string(capitoli) + "\nPagine: " + std::to_string(pagine) +
               "\nAutore: " + autore;
}

void Libro::setCasaEditrice(const std::string& casaEditrice) {this->casaEditrice = casaEditrice;}

void Libro::setCapitoli(int capitoli) {this->capitoli = capitoli;}

void Libro::setPagine(int pagine) {this->pagine = pagine;}

void Libro::setAutore(const std::string& autore) {this->autore = autore;}
void Libro::accept(VisitorInterface& visitor) {
    visitor.visitLibro(*this);
}

void Libro::accept(ConstVisitorInterface& visitor) const {
    visitor.visitLibro(*this);
}