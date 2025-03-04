//
// Created by Michele Dioli on 2/2/25.
//
#ifndef MODIFICALIBRO_H
#define MODIFICALIBRO_H

#include "ModificaArticolo.h"

class ModificaLibro : public ModificaArticolo {
    Q_OBJECT
private:
    QVBoxLayout* layout = new QVBoxLayout();

    //asstratta
    QLineEdit *codiceInput;
    QLineEdit *titoloInput;
    QLineEdit *descrizioneInput;
    QLineEdit *genereInput;
    QLineEdit *linguaInput;
    QDateEdit *annoInput;
    QSpinBox *copieInput;

    //libro
    QLineEdit *autoreInput;
	QLineEdit *casaEditriceInput;
    QSpinBox *pagineInput;
    QSpinBox *capitoliInput;

    Libro* libro;

    QPushButton *confermaButton;

public:
    ModificaLibro(QWidget* parent = nullptr, Libro* libro = nullptr);
    void edit(Articolo*) override;
    virtual QVBoxLayout* getLayout() const;
};

#endif //MODIFICALIBRO_H
