#ifndef CONSTVISITORINTERFACE_H
#define CONSTVISITORINTERFACE_H

#include <iostream>

class Libro;
class Rivista;
class Film;

class ConstVisitorInterface{
public:
    virtual ~ConstVisitorInterface() = default;
    virtual void visitLibro(const Libro& l) = 0;
    virtual void visitRivista(const Rivista& r) = 0;
    virtual void visitFilm(const Film& f) = 0;
};

#endif //CONSTVISITORINTERFACE_H
