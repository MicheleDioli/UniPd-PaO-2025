#include "edit.h"

Edit::Edit(QWidget *parent)
    : QWidget(parent), currentEditor(nullptr), articoloCorrente(nullptr) {
    layout = new QVBoxLayout(this);
    
    confermaButton = new QPushButton("Salva Modifiche");
    indietroButton = new QPushButton();
    indietroButton->setIcon(QIcon(QPixmap(":/asset/icon/indietro.png")));
    indietroButton->adjustSize(); 

    layout->addWidget(indietroButton,0,Qt::AlignLeft);
    layout->addWidget(confermaButton);

    connect(confermaButton, &QPushButton::clicked,this, &Edit::salvaModifiche);
    connect(indietroButton, &QPushButton::clicked,this, &Edit::indietroclic);
}

void Edit::indietroclic(){
    emit indietrosignal();
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

        if(currentEditor) 
            layout->insertWidget(1, currentEditor); 
    }
}

void Edit::salvaModifiche(){
    if(currentEditor && articoloCorrente) {
        currentEditor->edit(articoloCorrente);
        emit modificheConfermate();
    }
}
