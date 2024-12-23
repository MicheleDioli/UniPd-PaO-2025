//
// Created by Michele Dioli on 12/18/24.
//
#include "src/Rivista.h"
#include <QApplication>
#include <QLabel>
#include <QString>
#include <QPixmap>
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Rivista *r = new Rivista("abc", "desc", "gen", "brev", 2024, "cacone", 100, "pubb", 30, 1);
    std::string stg= r->getEditore();
    QPixmap pixmap(":asset/icon/save.svg");

    QLabel label;
    label.setPixmap(pixmap);
    label.show();
    return app.exec();
}