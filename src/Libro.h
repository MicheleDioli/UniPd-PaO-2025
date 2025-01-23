#ifndef LIBRO_H
#define LIBRO_H

#include "Articolo.h"

class Libro : public Articolo {
private:
  std::string casaEditrice;
  int capitoli;
  int pagine;


public:
  Libro() = default;
};

#endif // LIBRO_H