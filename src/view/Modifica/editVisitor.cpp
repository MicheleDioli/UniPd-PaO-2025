#include "editVisitor.h"
#include "../../Film.h"
#include "../../Libro.h"
#include "../../Rivista.h"

#include "ModificaFilm.h"
#include "ModificaLibro.h"
#include "ModificaRivista.h"

void editVisitor::visitFilm(Film& film) {
    editor = new ModificaFilm(nullptr, &film);
}

void editVisitor::visitLibro(Libro& libro) {
    editor = new ModificaLibro(nullptr, &libro);
}

void editVisitor::visitRivista(Rivista& rivista) {
    editor = new ModificaRivista(nullptr, &rivista);
}

ModificaArticolo* editVisitor::getEditor() const {
    return editor;
}

