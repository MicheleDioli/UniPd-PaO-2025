#ifndef EDITVISITOR_H
#define EDITVISITOR_H

#include "../../VisitorInterface.h"
#include "../../Film.h"
#include "../../Libro.h"
#include "../../Rivista.h"

#include "ModificaArticolo.h"

#include <QVBoxLayout>
#include <QLineEdit>
#include <QSpinBox>
#include <QLabel>
#include <QDateEdit>
#include <QPushButton>
#include <QWidget>

class editVisitor : public VisitorInterface {
private:
    ModificaArticolo* editor;
public:
    // Implementazione di TUTTI i metodi dell'interfaccia
     void visitLibro(Libro&);
     void visitRivista(Rivista&);
     void visitFilm(Film&);

    ModificaArticolo* getEditor() const;
};

#endif