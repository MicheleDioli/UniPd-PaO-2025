//
// Created by Michele Dioli on 1/29/25.
//

#ifndef JSONVISITOR_H
#define JSONVISITOR_H

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

#include "../../ConstVisitorInterface.h"
#include "../../Libro.h"
#include "../../Rivista.h"
#include "../../Film.h"

class JsonVisitor : public ConstVisitorInterface{
private:
    QJsonObject object;
public:
    QJsonObject getObject() const;
    void visitLibro(const Libro&) override;
    void visitRivista(const Rivista&) override;
    void visitFilm(const Film&) override;
};


#endif //JSONVISITOR_H
