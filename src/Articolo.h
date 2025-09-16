#ifndef ARTICOLO_H
#define ARTICOLO_H

#include "VisitorInterface.h"
#include "ConstVisitorInterface.h"

#include <string>
#include <iostream>
#include <list>

class Articolo {
private:
    std::string titolo;
    std::string codice;
    std::string descrizione;
    std::string genere;
    int anno;
    int copie;
    std::string lingua;
    std::string image;
public:
    Articolo(const std::string& titolo, const std::string& codice, const std::string& descrizione, const std::string& genere, int anno, int copie, const std::string& lingua);
    virtual ~Articolo();
    Articolo();

    std::string getCodice() const;
    std::string getDescrizione() const;
    std::string getGenere() const;
    int getAnno() const;
    std::string getLingua() const;
    int getCopie() const;
    std::string getTitolo() const;
    std::string getImg() const;

    void setCodice(const std::string& codice);
    void setDescrizione(const std::string& descrizione);
    void setGenere(const std::string& genere);
    void setAnno(int anno);
    void setLingua(const std::string& lingua);
    void setCopie(int copie);
    void setTitolo(const std::string& titolo);

    virtual void accept(VisitorInterface& visitor) = 0;
    virtual void accept(ConstVisitorInterface& visitor) const = 0;
};

#endif // ARTICOLO_H