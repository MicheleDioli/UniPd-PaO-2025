#ifndef EDITVISITOR_H
#define EDITVISITOR_H

#include "../../VisitorInterface.h"
#include "editVisitor.h"

class Film;
class Libro;
class Rivista;

#include <QVBoxLayout>
#include <QLineEdit>
#include <QSpinBox>
#include <QLabel>
#include <QDateEdit>

class EditVisitor : public VisitorInterface{
private:
    QVBoxLayout* layout = new QVBoxLayout();

public:
    QVBoxLayout* getLayout();
    void visitFilm(Film& film) override;
    void visitLibro(Libro& libro) override;
    void visitRivista(Rivista& rivista) override;
};

#endif