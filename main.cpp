#include <QApplication>
#include <QVBoxLayout>
#include <QWidget>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QPushButton>
#include <QTextEdit>

#include "src/view/Sensoriqt/ListaVisitor.h"
#include "src/view/Modifica/editVisitor.h"
#include "src/view/Sensoriqt/FiltroLayout.h"
#include "src/view/Mostra/MostraVisitor.h"
#include "src/Rivista.h"
#include "src/Libro.h"
#include "src/Film.h"
/*
class test : public QWidget {
  public:
  test(QWidget* parent = nullptr) : QWidget(parent) {
    QVBoxLayout* layout = new QVBoxLayout(this);
    MostraVisitor visitor;
    Rivista rivista("titolo","codice", "descrizione", "genere", 2021, 10, "lingua", "editore", 100, "pubblicatore", 1, 1, 1);
    Libro libro("titolo","codice", "descrizione", "genere", 2021, 10, "lingua","monda",3, 100, "autore");
    rivista.accept(visitor);
    layout->addLayout(visitor.getLayout());
  }
};

*/
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Rivista rivista("titolo","codice", "descrizione", "genere", 2021, 10, "lingua", "editore", 100, "pubblicatore", 1, 1, 1);
    Rivista rivista2("titolo","codice", "descrizione", "genere", 2021, 10, "lingua", "editore", 100, "pubblicatore", 1, 1, 1);
    Libro libro("titolo","codice", "descrizione", "genere", 2021, 10, "lingua","monda",3, 100, "autore");
    Film film("titolo","codice", "descrizione", "genere", 2021, 10, "lingua","regista", 100, "attori", "produttore");
    Film film2("titolo","codice", "descrizione", "genere", 2021, 10, "lingua","regista", 100, "attori", "produttore");
        Film film3("titolo","codice", "descrizione", "genere", 2021, 10, "lingua","regista", 100, "attori", "produttore");
        Film film4("titolo","codice", "descrizione", "genere", 2021, 10, "lingua","regista", 100, "attori", "produttore");
        std::list<Articolo*> articoli;
        articoli.push_back(&rivista);
        articoli.push_back(&libro);
        articoli.push_back(&film);
        articoli.push_back(&rivista2);
        articoli.push_back(&film2);
        articoli.push_back(&film3);
        articoli.push_back(&film4);

        FiltroLayout filtro(nullptr, articoli);
    filtro.show();
         /*
        test t;
        t.show();*/
    return app.exec();
}