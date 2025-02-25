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
        //emit rightClicked(articolo);
        MostraMenu(event->globalPos());
    }
    QWidget::mousePressEvent(event);
}

void Cliccabile::MostraMenu(const QPoint& pos) {
    QMenu menu;

    Asalva = new QAction(QIcon(QPixmap((":/asset/icon/creanuovo.png"))), "Salva", this);
    menu.addAction(Asalva);
    Acancella = menu.addAction("Cancella ");
    Adettagli = menu.addAction("Mostra dettagli ");
    Amodifica = menu.addAction("Modifica ");

    connect(Asalva, &QAction::triggered, this, &Cliccabile::salvaclic);
    connect(Acancella, &QAction::triggered, this, &Cliccabile::cancellaclic);
    connect(Adettagli, &QAction::triggered, this, &Cliccabile::dettagliclic);
    connect(Amodifica, &QAction::triggered, this, &Cliccabile::modificaclic);

    menu.exec(pos);
}

void Cliccabile::salvaclic() {
    emit salva(articolo);
}

void Cliccabile::cancellaclic() {
    emit cancella(articolo);
}

void Cliccabile::dettagliclic() {
    emit dettagli(articolo);
}

void Cliccabile::modificaclic() {
    emit modifica(articolo);
}
