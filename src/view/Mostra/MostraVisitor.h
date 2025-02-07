#ifndef MOSTRAVISITOR_H
#define MOSTRAVISITOR_H

#include "../../VisitorInterface.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QPixmap>
#include <QString>

class MostraVisitor : public VisitorInterface {
private:
    QVBoxLayout* layout;
public:
    QVBoxLayout* getLayout() const;
    void visitLibro(Libro& l);
    void visitRivista(Rivista& r);
    void visitFilm(Film& f);
};

#endif //MOSTRAVISITOR_H
