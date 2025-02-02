//
// Created by Michele Dioli on 2/2/25.
//

#ifndef MODIFICAARTICOLO_H
#define MODIFICAARTICOLO_H

#include <QWidget>
#include <QSpinBox>
#include <QLineEdit>
#include <QDateEdit>
#include <QLabel>
#include <QVBoxLayout>

#include "../../Articolo.h"
#include "../../Film.h"
#include "../../Libro.h"
#include "../../Rivista.h"


class ModificaArticolo : public QWidget {
    Q_OBJECT
public:
  ModificaArticolo(QWidget* parent = nullptr);
  ~ModificaArticolo();
  virtual Articolo* New() = 0;
    virtual QVBoxLayout* getLayout() const = 0;
};

#endif //MODIFICAARTICOLO_H
