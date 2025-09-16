#ifndef FILTROSPECIFICO_H
#define FILTROSPECIFICO_H

#include "../../Articolo.h"
#include "../../Rivista.h"
#include "../../Libro.h"
#include "../../Film.h"
#include "../sensoriqt/ListaArticoli.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>

#include <QSlider>

class filtroSpecifico : public QWidget {
    Q_OBJECT

private:
    ListaArticoli* l1;

    QVBoxLayout* mainFiltroSpecifico;

    QStackedWidget* stackedWidget;
    QWidget* paginaFilm;
    QWidget* paginaLibro;
    QWidget* paginaRivista;

    // widget generici
    QSlider* annoSplitter;
    QSlider* copieSplitter;
    QComboBox* linguaCombo;
    QComboBox* categoria;

    // Film
    QSlider* minutaggioDial;
    QComboBox* attoreCombo;
    QComboBox* produCombo;

    // Libro
    QSlider* pagineDial;
    QSlider* capitoliDial;
    QComboBox* autoreCombo;
    QComboBox* casaEditriceCombo;

    // Rivista
    QSlider* pagineRivistaSlider;
    QComboBox* periodicoCombo;
    QComboBox* difficoltaCombo;

    void setupPaginaFilm();
    void setupPaginaLibro();
    void setupPaginaRivista();

public:
    filtroSpecifico(QWidget* parent = nullptr, ListaArticoli* LA = nullptr);
    void setLayoutSpecifico(Articolo* a);
    void backNormale();
    void aggiorna();

signals:
    void annoValueChanged(int value);
    void copieValueChanged(int value);
    void linguaValueChanged(const QString& text);
    void categoriaValueChanged(const QString& text);

    void minutaggioValueChanged(int value);
    void attoreValueChanged(const QString& text);
    void produValueChanged(const QString& text);

    void pagineValueChanged(int value);
    void capitoliValueChanged(int value);
    void autoreValueLibroChanged(const QString& text);
    void casaEditriceValueChanged(const QString& text);

    void pagineRivistaValueChanged(int value);
    void periodicoValueChanged(const QString& text);
    void difficoltaValueChanged(const QString& text);


};

#endif // FILTROSPECIFICO_H