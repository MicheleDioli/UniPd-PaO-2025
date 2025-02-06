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
  void addArticolo(Articolo*);
  void removeArticolo(Articolo*);
  std::list<Articolo*> getArticoli() const;
  bool contralla(std::list<Articolo*>, std::string);
  void clear();
  ~ListaArticoli();
};

#endif //LISTAARTICOLI_H
