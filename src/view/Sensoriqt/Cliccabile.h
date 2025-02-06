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
    signals:
        void clicked(Articolo* articolo);
        void rightClicked(Articolo* articolo);
protected:
    void mousePressEvent(QMouseEvent* event) override;
private:
    void MostraMenu(const QPoint& pos);
    Articolo* articolo;
};

#endif //CLICCABILE_H
