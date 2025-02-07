//
// Created by Michele Dioli on 2/4/25.
//

#ifndef FILTROLAYOUT_H
#define FILTROLAYOUT_H

#include "../Crea/Nuovo.h"
#include <QComboBox>
#include <QLineEdit>
#include <QSpacerItem>
#include <QGroupBox>
#include <QSplitter>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStackedWidget>
#include <QToolBar>

class FiltroLayout : public QWidget {
    Q_OBJECT
private:
    QVBoxLayout *main;
    Nuovo* creazioneArticolo;
    ListaQT *l;
    QVBoxLayout* filtri;
    QVBoxLayout* layout;
    QHBoxLayout* layout2;
    QPushButton* salva;
    QComboBox* filtro;
    std::list<Articolo*> articoli;
    QGridLayout* lista;
    QLineEdit* ricerca;
    QSplitter* splitter;
    QToolBar*  barra;
    QVBoxLayout* mostraSalva;

    QVBoxLayout* v;
public:
    FiltroLayout(QWidget* parent = nullptr, std::list<Articolo*> articoli = std::list<Articolo*>());
    void filtra(std::list<Articolo*>);
    void rimuoviLayout(QLayout* layout, QLayout* layoutToRemove);
    void switchLayout(QVBoxLayout *mainLayout, QLayout *oldLayout, QLayout *newLayout) {
        // 1. Rimuovi il vecchio layout
        while (QLayoutItem* item = oldLayout->takeAt(0)) {
            if (QWidget* widget = item->widget()) {
                widget->hide();  // Nasconde il widget
                widget->setParent(nullptr);  // Rimuove il parent
            }
            delete item;  // Elimina l'elemento del layout
        }

        mainLayout->removeItem(oldLayout); // Rimuove il layout stesso

        // 2. Aggiungi il nuovo layout
        mainLayout->addLayout(newLayout);
    }


public slots:
    void ricercaScelta();
    void nuovoClicked();
};


#endif //FILTROLAYOUT_H
