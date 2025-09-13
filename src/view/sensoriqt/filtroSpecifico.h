#ifndef FILTROSPECIFICO_H
#define FILTROSPECIFICO_H

#include "../../Articolo.h"
#include "../../Rivista.h"
#include "../../Libro.h"
#include "../../Film.h"

#include "../sensoriqt/ListaArticoli.h"

#include<QDial>
#include<QSlider>
#include<QComboBox>
#include<QVBoxLayout>
#include<QWidget>
#include<QLabel>
#include<QLineEdit>
#include<QHBoxLayout>
#include<QGroupBox>



class filtroSpecifico : public QWidget {
    Q_OBJECT
private:

    ListaArticoli *l1;

    QVBoxLayout *mainFiltroSpecifico;
    QVBoxLayout *layoutFilm;
    QVBoxLayout *layoutLibro;
    QVBoxLayout *layoutRivista;
    QVBoxLayout *layoutSpecifico;

    QSlider *annoSplitter;
    QSlider *copieSplitter;
    QComboBox *linguaCombo;
    QComboBox *categoria;
    
    QDial *minutaggioDial;
    QComboBox *attoreCombo;
    QComboBox *produCombo;

    QDial *pagineDial;
    QDial *capitoliDial;
    QComboBox *autoreCombo;
    QComboBox *casaEditriceCombo;

    QSlider *pagineRivistaSlider;
    QComboBox *periodicoCombo;
    QComboBox *difficoltaCombo;



public:

    filtroSpecifico(QWidget* parent = nullptr, ListaArticoli* LA = nullptr);
    void filtroFilm(ListaArticoli* LA);
    void filtroLibro(ListaArticoli* LA);
    void filtroRivista(ListaArticoli* LA);
    void setLayoutSpecifico(Articolo* a);
    void aggiorna();
};

#endif // LISTAQT_H

