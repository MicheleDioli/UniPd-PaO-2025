#ifndef MOSTRALISTAVISITOR_H
#define MOSTRALISTAVISITOR_H

#include "../../VisitorInterface.h"

#include "../../Libro.h"
#include "../../Rivista.h"
#include "../../Film.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QPixmap>
#include <QString>
#include <QPushButton>


class MostraListaVisitor : public VisitorInterface {
private:
    QVBoxLayout* layout;
public:
    QVBoxLayout* getLayout() const;
    void visitLibro(Libro& l);
    void visitRivista(Rivista& r);
    void visitFilm(Film& f);
};

#endif // MOSTRALISTAVISITOR_H