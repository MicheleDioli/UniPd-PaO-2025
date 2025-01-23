#include "Rivista.h"

Rivista::Rivista(const std::string& codice, const std::string& descrizione, const std::string& genere,
                 const std::string& breveDescrizione, int anno, const std::string& editore, int pagine,
                 const std::string& pubblicatore, int intervalloPubblicazione, int edizione, int difficolta)
    : Articolo(codice, descrizione, genere, breveDescrizione, anno),
      editore(editore), pagine(pagine), pubblicatore(pubblicatore),
      intervalloPubblicazione(intervalloPubblicazione), edizione(edizione), difficolta(difficolta) {}

std::string Rivista::getEditore() const { return editore; }

int Rivista::getPagine() const { return pagine; }

std::string Rivista::getPubblicatore() const { return pubblicatore; }

int Rivista::getIntervalloPubblicazione() const { return intervalloPubblicazione; }

int Rivista::getEdizione() const { return edizione; }

int Rivista::getDifficolta() const { return difficolta; }

int Rivista::velocitaLettura() const {
    int indice = 1 + (difficolta / 5);
    int minutoxpag = 5 * indice;
    return minutoxpag * pagine;
}

std::string Rivista::informazioniArticolo(const Articolo* art) const {
    if (art) {
        return "Codice: " + art->getCodice() + "\nDescrizione: " + art->getDescrizione() + "\nGenere: " +
               art->getGenere() + "\nBreve Descrizione: " + art->getBreveDescrizione() + "\nAnno: " +
               std::to_string(art->getAnno()) + "\nEditore: " + editore + "\nPagine: " + std::to_string(pagine) +
               "\nPubblicatore: " + pubblicatore + "\nIntervallo Pubblicazione: " +
               std::to_string(intervalloPubblicazione) + "\nEdizione: " + std::to_string(edizione) +
               "\nDifficolta: " + std::to_string(difficolta);
    } else {
        return "Articolo non trovato";
    }
}

void Rivista::setEditore(const std::string& editore) { this->editore = editore; }

void Rivista::setPagine(int pagine) { this->pagine = pagine; }

void Rivista::setPubblicatore(const std::string& pubblicatore) { this->pubblicatore = pubblicatore; }

void Rivista::setIntervalloPubblicazione(int intervallo) { this->intervalloPubblicazione = intervallo; }

void Rivista::setEdizione(int edizione) { this->edizione = edizione; }

void Rivista::setDifficolta(int difficolta) { this->difficolta = difficolta; }

/*
Rivista::Builder::Builder(const std::string& codice, const std::string& descrizione,
                          const std::string& genere, const std::string& breveDescrizione, int anno)
    : codice(codice), descrizione(descrizione), genere(genere),
      breveDescrizione(breveDescrizione), anno(anno) {}

Rivista::Builder& Rivista::Builder::setEditore(const std::string& editore) {
    this->editore = editore;
    return *this;
}

Rivista::Builder& Rivista::Builder::setPagine(int pagine) {
    this->pagine = pagine;
    return *this;
}

Rivista::Builder& Rivista::Builder::setPubblicatore(const std::string& pubblicatore) {
    this->pubblicatore = pubblicatore;
    return *this;
}

Rivista::Builder& Rivista::Builder::setIntervalloPubblicazione(int intervallo) {
    this->intervalloPubblicazione = intervallo;
    return *this;
}

Rivista::Builder& Rivista::Builder::setEdizione(int edizione) {
    this->edizione = edizione;
    return *this;
}

Rivista::Builder& Rivista::Builder::setDifficolta(int difficolta) {
    this->difficolta = difficolta;
    return *this;
}

Rivista Rivista::Builder::build() const {
    return Rivista(codice, descrizione, genere, breveDescrizione, anno, editore, pagine, pubblicatore,
                   intervalloPubblicazione, edizione, difficolta);
}
*/