#include <QWidget>
#include <list>
#include <iostream>
#include <QLabel>
#include <QLineEdit>
#include <QRadioButton>
#include<QPixmap>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QGroupBox>
#include <QComboBox>
#include <QSpinBox>
#include <QFormLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QSpacerItem>

#include "../Sensoriqt/ListaQT.h"

class Articolo;

class Nuovo : public QWidget {
    Q_OBJECT
private:

    ListaQT l;

    QVBoxLayout *layout = new QVBoxLayout(this);
    QVBoxLayout *mezzo = new QVBoxLayout();

    QGroupBox *infoArticolo;
    QTextEdit *descrizione;
    QLabel *icona = new QLabel();

    QRadioButton *radioButton;
    QRadioButton *radioButton2;
    QRadioButton *radioButton3;

    QGroupBox *tipo = new QGroupBox("Tipo");

    QHBoxLayout *lay = new QHBoxLayout();

public:
    Nuovo(QWidget *parent = nullptr, std::list<Articolo*> articoli = {});
    void pulisciLayout(QLayout* layout) {
        if (!layout) return;

        // Per evitare problemi, rimuoviamo il layout dal suo genitore prima di procedere
        layout->setParent(nullptr);

        while (QLayoutItem* item = layout->takeAt(0)) {
            if (QWidget* widget = item->widget()) {
                widget->deleteLater();  // Cancella i widget in modo sicuro
            }
            if (QLayout* childLayout = item->layout()) {
                pulisciLayout(childLayout);  // Rimuove ricorsivamente i child layout
                delete childLayout;  // Elimina il child layout
            }
            delete item;  // Elimina l'item di layout
        }
    }

protected:
    QHBoxLayout* creaFilm();
    QHBoxLayout* creaLibro();
    QHBoxLayout* creaRivista();

public slots:
    void cambiaIcona();
};