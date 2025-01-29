//
// Created by Michele Dioli on 1/29/25.
//
#ifndef SALVA_H
#define SALVA_H

#include <QVBoxLayout>
#include <QPushButton>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFileDialog>
#include <QHeaderView>
#include <QMessageBox>

#include "../Articolo.h"

class Json{
  private:
    QJsonObject salva(const Articolo&) const ;
    Articolo* importa();

public:
    void salvaJson(const Articolo&)const;
    Articolo* importaJson();
};

#endif //SALVA_H
