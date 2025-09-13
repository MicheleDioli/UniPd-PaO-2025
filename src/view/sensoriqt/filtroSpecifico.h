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
#include <QDial>
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
    QDial* minutaggioDial;
    QComboBox* attoreCombo;
    QComboBox* produCombo;

    // Libro
    QDial* pagineDial;
    QDial* capitoliDial;
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
/*
    public slots:
    void annoChanged(int);
    void copieChanged(int);
    void linguaChanged(const QString&);
    void categoriaChanged(const QString&);

    void minutaggioChanged(int);
    void attoreChanged(const QString&);
    void produChanged(const QString&);

    void pagineChanged(int);
    void capitoliChanged(int);
    void autoreChanged(const QString&);
    void casaEditriceChanged(const QString&);

    void pagineRivistaChanged(int);
    void periodicoChanged(const QString&);
    void difficoltaChanged(const QString&);
    
    signals:
    int annoValueChanged(int);
    int copieValueChanged(int);
    QString linguaValueChanged(const QString&);
    QString categoriaValueChanged(const QString&);

    int minutaggioValueChanged(int);
    QString attoreValueChanged(const QString&);
    QString produValueChanged(const QString&);

    int pagineValueChanged(int);
    int capitoliValueChanged(int);
    QString autoreValueLibroChanged(const QString&);
    QString casaEditriceValueChanged(const QString&);

    int pagineRivistaValueChanged(int);
    QString periodicoValueChanged(const QString&);
    QString difficoltaValueChanged(const QString&);*/
};

#endif // FILTROSPECIFICO_H