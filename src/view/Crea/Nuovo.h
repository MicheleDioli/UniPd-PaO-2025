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
#include <QSizePolicy>


#include "../../Rivista.h"
#include "../../Libro.h"
#include "../../Film.h"

#include "../Sensoriqt/ListaQT.h"

#include "../Sensoriqt/ListaArticoli.h"

class Articolo;

class Nuovo : public QWidget {
    Q_OBJECT
private:
   //QT
    ListaQT *l;
    ListaArticoli *l1;
    ListaArticoli *articoli;

    QLabel *erroreCodice;
    QLabel *erroreTitolo;

    QVBoxLayout *layout;
    QVBoxLayout *mezzo = new QVBoxLayout();

    QGroupBox *infoArticolo;
    QTextEdit *descrizione;
    QLabel *icona = new QLabel();

    QRadioButton *radioButton;
    QRadioButton *radioButton2;
    QRadioButton *radioButton3;

    QPushButton *salva;

    QGroupBox *tipo = new QGroupBox("Tipo");

    QHBoxLayout *lay = new QHBoxLayout();

    QLabel *label = new QLabel;

    //Articol0

    QLineEdit *titolo = new QLineEdit();
    QLineEdit *codice = new QLineEdit();
    QComboBox *genere = new QComboBox();
    QComboBox *lingua = new QComboBox();
    QSpinBox *copie = new QSpinBox();
    QSpinBox *anno = new QSpinBox();

    //Film
    QLineEdit *regista;
    QLineEdit* attore;
    QLineEdit* produttore;
    QSpinBox* durata;

    //Libro
    QLineEdit *casaEditrice;
    QLineEdit *autore;
    QSpinBox *capitoli;
    QSpinBox *pagine;

    //Rivista
    QLineEdit *editore;
    QLineEdit *pubblicatore;
    QSpinBox *edizione;
    QComboBox *intervalloPubblicazione;
    QSpinBox *difficolta;
public:
    explicit Nuovo(QWidget *parent = nullptr, std::list<Articolo*> articoli = std::list<Articolo*>());

protected:
    QHBoxLayout* creaFilm();
    QHBoxLayout* creaLibro();
    QHBoxLayout* creaRivista();
    bool checkCampi();

public slots:
    void cambiaIcona();
    void salvataggio();
    void annulla();
signals:
    void salvaClicked();
    void annullatoCliked();
};