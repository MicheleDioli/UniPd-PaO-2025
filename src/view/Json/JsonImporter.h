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

#include "../../Articolo.h"
#include "../../Libro.h"
#include "../../Rivista.h"
#include "../../Film.h"


class JsonImporter{
public:
    Articolo* importJson();
    Articolo* createArticolo(const QString&, const QJsonObject&);
};

#endif //JSONIMPORTER_H
