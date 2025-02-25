//
// Created by Michele Dioli on 2/3/25.
//
#ifndef CLICCABILE_H
#define CLICCABILE_H
#include <QWidget>
#include <QGridLayout>
#include <QMouseEvent>
#include <list>
#include <cmath>
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QMenu>
#include <QAction>
#include <iostream>
#include <QIcon>
#include <QPixmap>

#include "../../Articolo.h"
#include "ListaVisitor.h"

class Cliccabile : public QWidget {
    Q_OBJECT
public:
    explicit Cliccabile(Articolo* articolo, QWidget* parent = nullptr)
        : QWidget(parent), articolo(articolo) {}
protected:
    void mousePressEvent(QMouseEvent* event) override;
public slots:
    void salvaclic();
    void cancellaclic();
    void dettagliclic();
    void modificaclic();
private:
    QAction* Asalva;
    QAction* Acancella;
    QAction* Adettagli;
    QAction* Amodifica;
    void MostraMenu(const QPoint& pos);

    Articolo* articolo;
signals:
    void clicked(Articolo*);
    void salva(Articolo*);
    void cancella(Articolo*);
    void dettagli(Articolo*);
    void modifica(Articolo*);
};

#endif //CLICCABILE_H
