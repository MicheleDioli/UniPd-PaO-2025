//
// Created by Michele Dioli on 2/2/25.
//

#ifndef MODIFICAFILM_H
#define MODIFICAFILM_H

#include "ModificaArticolo.h"

class ModificaFilm : public ModificaArticolo {
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

    //film
    QLineEdit *registaInput;
    QSpinBox *durataInput;
    QLineEdit *attoriInput;
    QLineEdit *produttoreInput;

public:
    explicit ModificaFilm(QWidget* parent = nullptr, Film* film = nullptr);
    Film* New() override;
    virtual QVBoxLayout* getLayout() const;
};

#endif //MODIFICAFILM_H
