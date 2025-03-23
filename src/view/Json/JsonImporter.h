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
#include <QErrorMessage>
#include <QMessageBox>


#include "../../Articolo.h"
#include "../../Libro.h"
#include "../../Rivista.h"
#include "../../Film.h"
#include "../sensoriqt/ListaArticoli.h"

class JsonImporter{
public:
    Articolo* createArticolo(const QString&, const QJsonObject&);
    void importa(ListaArticoli*);
};

#endif //JSONIMPORTER_H