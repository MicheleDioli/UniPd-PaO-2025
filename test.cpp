#include "text.h"
#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include "src/Articolo.h"
#include "src/Rivista.h"


text::text(QWidget *parent, Articolo* a) : QWidget(parent), a(a) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Pulsante Salva
    QPushButton *buttonSalva = new QPushButton("Salva");
    // Pulsante Importa
    QPushButton *buttonImporta = new QPushButton("Importa");

    layout->addWidget(buttonSalva);
    layout->addWidget(buttonImporta);

    // Connessioni
    connect(buttonSalva, &QPushButton::clicked, this, &text::salvaQT);
    connect(buttonImporta, &QPushButton::clicked, this, &text::importaQT);
}

Articolo* text::importaQT() {
    // Qui dovrebbe esserci la logica per importare il file JSON e restituire un Articolo
    // Supponiamo che tu abbia già una funzione json.importaJson() che restituisce un Articolo
    Articolo* articolo = json.importaJson();
    if (articolo) {
        a = articolo;  // Se l'importazione è riuscita, aggiorniamo l'oggetto a
    } else {
        std::cerr << "Errore durante l'importazione del JSON!" << std::endl;
    }
    return articolo;
}

void text::salvaQT() {
    if (a) {
        json.salvaJson(*a);  // Salva l'oggetto Articolo
    } else {
        std::cerr << "Errore: Articolo non valido!" << std::endl;
    }
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Rivista *a = new Rivista("codice", "descrizione", "genere", 2025, 10, "lingua", "editore", 100, "pubblicatore", 1, 1, 1);

    // Passiamo l'oggetto Articolo a `text`
    text *t= new text(nullptr, a);

    t->show();
    return app.exec();
}
