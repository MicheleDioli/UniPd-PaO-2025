#ifndef EDIT_H
#define EDIT_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include "../../Articolo.h"
#include "editVisitor.h"
#include "../Sensoriqt/ListaArticoli.h"

class Edit : public QWidget {
    Q_OBJECT
public:
    explicit Edit(QWidget *parent = nullptr, ListaArticoli *l = nullptr);
    void setArticolo(Articolo *articolo);

    signals:
        void modificheConfermate();
        void indietrosignal();

    private slots:
        void indietroclic();
        void salvaModifiche();
private:
    ListaArticoli *l;
    QVBoxLayout *layout;
    QPushButton *confermaButton;
    QPushButton *indietroButton;
    QLabel *errori;
    ModificaArticolo *currentEditor;
    Articolo *articoloCorrente;
};

#endif // EDIT_H