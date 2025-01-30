//
// Created by Michele Dioli on 1/29/25.
//
#ifndef JSONIMPORTER_H
#define JSONIMPORTER_H

#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QTextStream>
#include <QTextStream>
#include <QFileDialog>
#include <QString>
#include <QMessageBox>

#include <list>
#include <iostream>

#include "../../Articolo.h"
#include "../../Libro.h"
#include "../../Film.h"
#include "../../Rivista.h"

class JsonImporter{
public:
    Articolo* importJson();
};

#endif //JSONIMPORTER_H
