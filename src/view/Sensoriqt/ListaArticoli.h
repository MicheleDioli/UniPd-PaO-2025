//
// Created by Michele Dioli on 2/3/25.
//

#ifndef LISTAARTICOLI_H
#define LISTAARTICOLI_H

#include <list>

#include "../../Articolo.h"


class ListaArticoli {
private:
  std::list<Articolo*> articoli;
public:
  ListaArticoli(std::list<Articolo*> = std::list<Articolo*>());
  void addArticolo(Articolo*);
  void removeArticolo(Articolo*);
  std::list<Articolo*> getArticoli();
  int contralla(std::list<Articolo*>, Articolo*);
  void clear();
  ~ListaArticoli();
};

#endif //LISTAARTICOLI_H
