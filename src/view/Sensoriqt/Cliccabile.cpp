//
// Created by Michele Dioli on 2/4/25.
//

#include "Cliccabile.h"

void Cliccabile::mousePressEvent(QMouseEvent* event){
    if (event->button() == Qt::LeftButton) {
        std::cout << "Cliccato (spero)" << std::endl;
        emit clicked(articolo);
    }
    if (event->button() == Qt::RightButton) {
        emit rightClicked(articolo);
        MostraMenu(event->globalPos());
    }
    QWidget::mousePressEvent(event);
}

void Cliccabile::MostraMenu(const QPoint& pos) {
    QMenu menu;

    QAction* salva = new QAction(QIcon(QPixmap((":/asset/icon/creanuovo.png"))), "Salva", this);
    menu.addAction(salva);
    QAction* cancella = menu.addAction("Cancella ");
    QAction* dettagli = menu.addAction("Mostra dettagli ");
    QAction* modifica = menu.addAction("Modifica ");

/*
    connect(action1, &QAction::triggered, this, &Cliccabile::onAction1);
    connect(action2, &QAction::triggered, this, &Cliccabile::onAction2);
    connect(action3, &QAction::triggered, this, &Cliccabile::onAction3);
*/
    menu.exec(pos);
}