#ifndef LISTAVISITOR_H
#define LISTAVISITOR_H

#include <QGroupBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>

#include "../../VisitorInterface.h"

class ListaVisitor :public VisitorInterface{
private:
    QVBoxLayout* layout = new QVBoxLayout();
public:
    QVBoxLayout* getLayout() const;
    void visitLibro(Libro&) override;
    void visitRivista(Rivista&) override;
    void visitFilm(Film&) override;

};

#endif //LISTAVISITOR_H
