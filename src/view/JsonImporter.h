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
#include <list>
#include "../Articolo.h"

class JsonImporter {
public:

    Articolo* importJson(const QString& filePath);
};

#endif //JSONIMPORTER_H
