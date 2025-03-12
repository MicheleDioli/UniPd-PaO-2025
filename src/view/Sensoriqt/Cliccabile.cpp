#include "Cliccabile.h"

void Cliccabile::mousePressEvent(QMouseEvent* event){
    if (event->button() == Qt::LeftButton) {
        emit clicked(articolo);
    }
    if (event->button() == Qt::RightButton) {
        MostraMenu(event->globalPosition().toPoint());
    }
}

void Cliccabile::MostraMenu(const QPoint& pos) {
    QMenu menu;

    Asalva = new QAction(QIcon(QPixmap((":/asset/icon/creanuovo.png"))), "Salva", this);
    menu.addAction(Asalva);
    AsalvaCN = new QAction(QIcon(QPixmap((":/asset/icon/creanuovo.png"))), "Salva con salva", this);
    menu.addAction(AsalvaCN);
    Acancella = new QAction(QIcon(QPixmap((":/asset/icon/creanuovo.png"))), "Cancella", this);
    menu.addAction(Acancella);
    Adettagli = new QAction(QIcon(QPixmap((":/asset/icon/creanuovo.png"))), "Mostra dettagli", this);
    menu.addAction(Adettagli);
    Amodifica = new QAction(QIcon(QPixmap((":/asset/icon/creanuovo.png"))), "Modifica", this);
    menu.addAction(Amodifica);

    connect(Asalva, &QAction::triggered, this, &Cliccabile::salvaclic);
    connect(AsalvaCN, &QAction::triggered, this, &Cliccabile::salvaCNclic);
    connect(Acancella, &QAction::triggered, this, &Cliccabile::cancellaclic);
    connect(Adettagli, &QAction::triggered, this, &Cliccabile::dettagliclic);
    connect(Amodifica, &QAction::triggered, this, &Cliccabile::modificaclic);

    menu.exec(pos);
}

void Cliccabile::salvaclic() {
    emit salva(articolo);
}

void Cliccabile::salvaCNclic() {
    emit salvaCN(articolo);
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
