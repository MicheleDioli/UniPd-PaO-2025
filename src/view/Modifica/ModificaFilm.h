#ifndef MODIFICAFILM_H
#define MODIFICAFILM_H

#include "ModificaArticolo.h"

class ModificaFilm : public ModificaArticolo {
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

    //film
    QLineEdit *registaInput;
    QSpinBox *durataInput;
    QLineEdit *attoriInput;
    QLineEdit *produttoreInput;

    Film* film;

    QPushButton *confermaButton;

public:
    ModificaFilm() = default;
    explicit ModificaFilm(QWidget* parent = nullptr, Film* film = nullptr);
    void edit(Articolo*) override;
    virtual QVBoxLayout* getLayout() const;
};

#endif //MODIFICAFILM_H
