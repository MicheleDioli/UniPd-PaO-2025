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

void EditVisitor::visitRivista(Rivista& rivista) {
    layout = new QVBoxLayout();
    ModificaRivista* modificaRivista = new ModificaRivista(nullptr, &rivista);
    layout = modificaRivista->getLayout();
}


void EditVisitor::visitFilm(Film& film) {
    layout = new QVBoxLayout();
    ModificaFilm* modificaFilm = new ModificaFilm(nullptr, &film);
    layout = modificaFilm->getLayout();
}

void EditVisitor::visitLibro(Libro& libro) {
    layout = new QVBoxLayout();
    ModificaLibro* modificaLibro = new ModificaLibro(nullptr, &libro);
    layout = modificaLibro->getLayout();
}