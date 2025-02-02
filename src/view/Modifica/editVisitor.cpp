#include "editVisitor.h"
#include "../../Film.h"
#include "../../Libro.h"
#include "../../Rivista.h"
#include "ModificaFilm.h"
#include "ModificaLibro.h"
#include "ModificaRivista.h"


QVBoxLayout* EditVisitor::getLayout() {
    return layout;
}

//layout->addWidget(new QLabel("Codice:"));
void EditVisitor::visitRivista(Rivista& rivista) {
    ModificaRivista* modificaRivista = new ModificaRivista(nullptr, &rivista);
    layout = modificaRivista->getLayout();
}


void EditVisitor::visitFilm(Film& film) {
    ModificaFilm* modificaFilm = new ModificaFilm(nullptr, &film);
    layout = modificaFilm->getLayout();
}

void EditVisitor::visitLibro(Libro& libro) {
  ModificaLibro* modificaLibro = new ModificaLibro(nullptr, &libro);
    layout = modificaLibro->getLayout();
}