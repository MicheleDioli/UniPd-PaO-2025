#ifndef MODIFICALIBRO_H
#define MODIFICALIBRO_H

#include "ModificaArticolo.h"
#include <QFormLayout>

#include"../sensoriqt/ListaArticoli.h"

class ModificaLibro : public ModificaArticolo {
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

    //libro
    QLineEdit *autoreInput;
	QLineEdit *casaEditriceInput;
    QSpinBox *pagineInput;
    QSpinBox *capitoliInput;

    Libro* libro;
    ListaArticoli l;

    QPushButton *confermaButton;

public:
    ModificaLibro(QWidget* parent = nullptr, Libro* libro = nullptr);
    void edit(Articolo*) override;
    virtual QVBoxLayout* getLayout() const;
};

#endif //MODIFICALIBRO_H
