#ifndef LISTAARTICOLI_H
#define LISTAARTICOLI_H

#include <list>
#include <map>

#include "../../Articolo.h"

class ListaArticoli {
private:
  std::list<Articolo*> articoliL;
  std::map< std::string, std::string> articoliS;
public:
  ListaArticoli(std::list<Articolo*> = std::list<Articolo*>());
  void addArticolo(Articolo*);
  void salvaMappa( std::string,  Articolo*);
  bool checkSalvato(Articolo*);
  void removeArticolo(Articolo*);
  std::list<Articolo*> getArticoli()const;
  int controlla(Articolo*);
  void clear();
  ~ListaArticoli();
};

#endif //LISTAARTICOLI_H
