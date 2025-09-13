#ifndef LISTAARTICOLI_H
#define LISTAARTICOLI_H

#include <list>
#include <map>

#include "../../Articolo.h"

#include "../../Film.h"
#include "../../Libro.h"
#include "../../Rivista.h"

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

  int maxAnni()const;
  int minAnni() const;
  int maxCopie()const;
  std::list<std::string*> allAttori()const;
  std::list<std::string*> allProdu()const;

  int maxPagine()const;
  int maxCapitoli()const;
  std::list<std::string*> allAutoriLibri()const;
  std::list<std::string*> allCaseEditrici()const;

  int maxPagineRivista()const;
  std::list<std::string*> allPeriodici()const;

  int maxMinutaggio()const;

  std::list<Articolo*> ordinaLista(std::list<Articolo*>,char);
  ~ListaArticoli();
  int size()const{
    return articoliL.size();
  }
};

#endif //LISTAARTICOLI_H
