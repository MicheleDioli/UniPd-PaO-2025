#include "edit.h"

Edit::Edit(QWidget *parent)
    : QWidget(parent), currentEditor(nullptr), articoloCorrente(nullptr) {
    layout = new QVBoxLayout(this);

    // Pulsante di conferma
    confermaButton = new QPushButton("Salva Modifiche", this);
    layout->addWidget(confermaButton);

    connect(confermaButton, &QPushButton::clicked,
            this, &Edit::salvaModifiche);
}

void Edit::setArticolo(Articolo *articolo) {

    if(currentEditor) {
        layout->removeWidget(currentEditor);
       // delete currentEditor;
    }

    articoloCorrente = articolo;

    if(articolo) {
        editVisitor visitor;
        articolo->accept(visitor);
        currentEditor = visitor.getEditor();

        if(currentEditor) {
            layout->insertWidget(0, currentEditor);
        }
    }
}

void Edit::salvaModifiche() {
    if(currentEditor && articoloCorrente) {
        currentEditor->edit(articoloCorrente);
        emit modificheConfermate();
    }
}