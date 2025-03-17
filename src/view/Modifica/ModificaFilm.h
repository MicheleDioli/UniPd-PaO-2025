#ifndef MODIFICAFILM_H
#define MODIFICAFILM_H

#include "ModificaArticolo.h"
#include "../Sensoriqt/ListaArticoli.h"

#include <QDebug>
#include <QFormLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QComboBox>


class ModificaFilm : public ModificaArticolo {
    Q_OBJECT
private:
  	QVBoxLayout* layout = new QVBoxLayout();

    //asstratta
    QLineEdit *codiceInput;
    QLineEdit *titoloInput;
    QLineEdit *descrizioneInput;
    QComboBox *genereInput;
    QComboBox *linguaInput;
    QDateEdit *annoInput;
    QSpinBox *copieInput;

    //film
    QLineEdit *registaInput;
    QSpinBox *durataInput;
    QLineEdit *attoriInput;
    QLineEdit *produttoreInput;

    Film* film;
    ListaArticoli lista;

    QPushButton *confermaButton;

public:
    QLineEdit* createLineEdit(const QString& text, const QString& tooltip);
    ModificaFilm() = default;
    explicit ModificaFilm(QWidget* parent = nullptr, Film* film = nullptr);
    void edit(Articolo*) override;
    virtual QVBoxLayout* getLayout() const;
};

#endif //MODIFICAFILM_H
