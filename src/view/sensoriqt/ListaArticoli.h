#ifndef LISTAARTICOLI_H
#define LISTAARTICOLI_H

#include <list>
#include <map>

#include "../../Articolo.h"

class ListaArticoli {
private:
  std::list<Articolo*> articoliL;
  std::map< std::string, std::string> articoliS;
  std::string listaPath;
public:
  std::string getListaPath()const;
  void setListaPath(std::string);
  ListaArticoli(std::list<Articolo*> = std::list<Articolo*>());
  void addArticolo(Articolo*);
  void salvaMappa( std::string,  Articolo*);
  bool checkSalvato(Articolo*);
  void removeArticolo(Articolo*);
  std::list<Articolo*> getArticoli()const;
  std::string getPath(Articolo*);
  int controlla(Articolo*);
  void clear();
  std::list<Articolo*> ordinaLista(std::list<Articolo*>,char);
  ~ListaArticoli();
  int size()const{
    return articoliL.size();
  }
};

#endif //LISTAARTICOLI_H
