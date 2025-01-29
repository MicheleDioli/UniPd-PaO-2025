//
// Created by Michele Dioli on 1/29/25.
//

#ifndef TEXT_H
#define TEXT_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include "src/view/Salva.h"
#include "src/Articolo.h"

class text : public QWidget {
    Q_OBJECT
private:
    Articolo* a;
    QVBoxLayout *layout;
    Articolo* salva;
    Json json;
public:
    explicit text(QWidget *parent = nullptr, Articolo* a = nullptr);

    public slots:
        void salvaQT();
        void importaQT();
};

#endif // TEXT_H
