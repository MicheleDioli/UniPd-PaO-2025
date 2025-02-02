#include "Rivista.h"
#include "ConstVisitorInterface.h"

Rivista::Rivista(const std::string& codice, const std::string& descrizione, const std::string& genere,
        int anno, int copie, const::std::string&lingua, const std::string& editore, int pagine,
        const std::string& pubblicatore, int intervalloPubblicazione, int edizione, int difficolta)
    : Articolo(codice, descrizione, genere, anno, copie, lingua), editore(editore), pagine(pagine),
      pubblicatore(pubblicatore), intervalloPubblicazione(intervalloPubblicazione), edizione(edizione),
      difficolta(difficolta) {}

Rivista::Rivista(){}

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

std::string Rivista::informazioniArticolo() const {
    return "Codice: " + getCodice() + "\nDescrizione: " + getDescrizione() + "\nGenere: " +
           getGenere() + "\nAnno: " +
           std::to_string(getAnno()) + "\nEditore: " + editore + "\nPagine: " + std::to_string(pagine) +
           "\nPubblicatore: " + pubblicatore + "\nIntervallo Pubblicazione: " +
           std::to_string(intervalloPubblicazione) + "\nEdizione: " + std::to_string(edizione) +
           "\nDifficolta: " + std::to_string(difficolta);
}

void Rivista::setEditore(const std::string& editore) { this->editore = editore; }

void Rivista::setPagine(int pagine) { this->pagine = pagine; }

void Rivista::setPubblicatore(const std::string& pubblicatore) { this->pubblicatore = pubblicatore; }

void Rivista::setIntervalloPubblicazione(int intervallo) { this->intervalloPubblicazione = intervallo; }

void Rivista::setEdizione(int edizione) { this->edizione = edizione; }

void Rivista::setDifficolta(int difficolta) { this->difficolta = difficolta; }

void Rivista::accept(VisitorInterface& visitor) {
    visitor.visitRivista(*this);
}

void Rivista::accept(ConstVisitorInterface& visitor) const {
    visitor.visitRivista(*this);
}


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