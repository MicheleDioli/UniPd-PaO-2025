//
// Created by Michele Dioli on 2/2/25.
//

#ifndef MODIFICARIVISTA_H
#define MODIFICARIVISTA_H

#include "ModificaArticolo.h"

class ModificaRivista : public ModificaArticolo {
    Q_OBJECT
private:
    QVBoxLayout* layout = new QVBoxLayout();

    //asstratta
    QLineEdit *codiceInput;
    QLineEdit *descrizioneInput;
    QLineEdit *genereInput;
    QLineEdit *linguaInput;
    QDateEdit *annoInput;
    QSpinBox *copieInput;

    //rivista
    QSpinBox *periodicitaInput;
    QSpinBox *numeroInput;
    QLineEdit *editoreRivistaInput;
    QSpinBox *pagineRivistaInput;
    QSpinBox *difficoltaInput;
    QLineEdit *pubblicatoreInput;

    Rivista* rivista;

public:
    ModificaRivista(QWidget* parent = nullptr, Rivista* rivista = nullptr);
    Rivista* New() override;
    virtual QVBoxLayout* getLayout() const;
};

#endif //MODIFICARIVISTA_H
