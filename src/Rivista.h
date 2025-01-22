#ifndef RIVISTA_H
#define RIVISTA_H

#include <string>
#include "Articolo.h" // Dipende dalla struttura del progetto

class Rivista : public Articolo {
private:
    std::string editore;
    int pagine;
    std::string pubblicatore;
    int intervalloPubblicazione;
    int edizione;
    int difficolta;

    // Costruttore privato, chiamato solo dal Builder
    Rivista(const std::string& codice, const std::string& descrizione, const std::string& genere,
            const std::string& breveDescrizione, int anno, const std::string& editore, int pagine,
            const std::string& pubblicatore, int intervalloPubblicazione, int edizione, int difficolta);

public:

    std::string getEditore() const;
    int getPagine() const;
    std::string getPubblicatore() const;
    int getIntervalloPubblicazione() const;
    int getEdizione() const;
    int getDifficolta() const;
    int velocitaLettura() const;
    std::string informazioniArticolo(const Articolo* art) const override;


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

        Builder& setEditore(const std::string& editore);
        Builder& setPagine(int pagine);
        Builder& setPubblicatore(const std::string& pubblicatore);
        Builder& setIntervalloPubblicazione(int intervallo);
        Builder& setEdizione(int edizione);
        Builder& setDifficolta(int difficolta);

        Rivista build() const;
    };
};

#endif