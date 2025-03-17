#ifndef MODIFICARIVISTA_H
#define MODIFICARIVISTA_H

#include "ModificaArticolo.h"
#include <QFormLayout>

class ModificaRivista : public ModificaArticolo {
    Q_OBJECT
private:
    QLineEdit* createLineEdit(const QString& text, const QString& tooltip);
    QVBoxLayout* layout = new QVBoxLayout();

    //asstratta
    QLineEdit *codiceInput;
    QLineEdit *titoloInput;
    QLineEdit *descrizioneInput;
    QComboBox *genereInput;
    QComboBox *linguaInput;
    QDateEdit *annoInput;
    QSpinBox *copieInput;

    //rivista
    QSpinBox *periodicitaInput;
    QSpinBox *numeroInput;
    QLineEdit *editoreRivistaInput;
    QSpinBox *pagineRivistaInput;
    QSpinBox *difficoltaInput;
    QLineEdit *pubblicatoreInput;

    QPushButton* salvaButton;

    Rivista* rivista;

public:
    ModificaRivista(QWidget* parent = nullptr, Rivista* rivista = nullptr);
    virtual void edit(Articolo*) override;
    virtual QVBoxLayout* getLayout() const;
};

#endif //MODIFICARIVISTA_H
