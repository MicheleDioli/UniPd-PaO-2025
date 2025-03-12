#ifndef EDIT_H
#define EDIT_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include "../../Articolo.h"
#include "editVisitor.h"

class Edit : public QWidget {
    Q_OBJECT
public:
    explicit Edit(QWidget *parent = nullptr);
    void setArticolo(Articolo *articolo);

    signals:
        void modificheConfermate();
        void indietrosignal();

    private slots:
        void indietroclic();
        void salvaModifiche();

private:
    QVBoxLayout *layout;
    QPushButton *confermaButton;
    QPushButton *indietroButton;
    ModificaArticolo *currentEditor;
    Articolo *articoloCorrente;
};

#endif // EDIT_H