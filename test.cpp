#include "text.h"



text::text(QWidget *parent, Articolo* a) : QWidget(parent), a(a) {
    layout = new QVBoxLayout(this);


    QPushButton *buttonSalva = new QPushButton("Salva");
    QPushButton *buttonImporta = new QPushButton("Importa");

    layout->addWidget(buttonSalva);
    layout->addWidget(buttonImporta);

    connect(buttonSalva, &QPushButton::clicked, this, &text::salvaQT);
    connect(buttonImporta, &QPushButton::clicked, this, &text::importaQT);
}

void text::importaQT() {

    salva= json.importaJson();

    if (!salva) {
        std::cerr << "Errore durante l'importazione del JSON!" << std::endl;
        return;
    }

    std::cout << a->informazioniArticolo() << std::endl;
}

void text::salvaQT() {
    if (a) {
        json.salvaJson(*a);
    } else {
        std::cerr << "Errore: Articolo non valido!" << std::endl;
    }
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Rivista *a = new Rivista("codice", "banana", "genere", 2025, 10, "lingua", "editore", 100, "pubblicatore", 1, 1, 1);
    text *t= new text(nullptr,a);

    t->show();
    return app.exec();
}
