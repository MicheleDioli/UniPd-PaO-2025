#ifndef VISITORINTERFACE_H
#define VISITORINTERFACE_H

#include <iostream>

class Libro;
class Rivista;
class Film;

class VisitorInterface{
public:
    virtual ~VisitorInterface() = default;
    virtual void visitLibro(Libro& l) = 0;
    virtual void visitRivista(Rivista& r) = 0;
    virtual void visitFilm(Film& f) = 0;
};

#endif // VISITORINTERFACE_H