#ifndef LIBRO_H
#define LIBRO_H

#include "Articolo.h"

class Libro : public Articolo {
private:
  std::string casaEditrice;
  int capitoli;
  int pagine;
  std::string autore;
public:
  Libro(const std::string& codice, const std::string& descrizione, const std::string& genere,
            const std::string& breveDescrizione, int anno, const std::string& editore, int pagine,
            const std::string& autore, int capitoli);
    std::string getCasaEditrice() const;
    int getCapitoli() const;
    int getPagine() const;
    std::string getAutore() const;
    std::string informazioniArticolo(const Articolo* art) const override;

    void setCasaEditrice(const std::string& casaEditrice);
    void setCapitoli(int capitoli);
    void setPagine(int pagine);
    void setAutore(const std::string& autore);
};

#endif // LIBRO_H