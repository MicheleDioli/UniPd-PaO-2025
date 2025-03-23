#include "Edit.h"

Edit::Edit(QWidget *parent, ListaArticoli *l)
    : QWidget(parent) ,l(l), currentEditor(nullptr), articoloCorrente(nullptr) {
    layout = new QVBoxLayout(this);
    
    confermaButton = new QPushButton("Salva Modifiche");
    indietroButton = new QPushButton();
    indietroButton->setIcon(QIcon(QPixmap(":/asset/icon/indietro.png")));
    indietroButton->adjustSize();

    errori = new QLabel();

    layout->addWidget(indietroButton,0,Qt::AlignLeft);
    layout->addWidget(confermaButton);
    layout->addWidget(errori);
    errori->setVisible(false);

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
			for (auto it : l->getArticoli()) {
            	if(articoloCorrente->getCodice() == it->getCodice() && articoloCorrente != it) {
					errori->setText("Codice già esistente");
                    errori->setVisible(true);
                    return;
            	}

                if(articoloCorrente->getTitolo() == it->getTitolo() &&
                    articoloCorrente->getAnno() == it->getAnno() &&
                    articoloCorrente->getLingua() == it->getLingua() && articoloCorrente != it) {
                    errori->setText("Articolo già esistente");
                    errori->setVisible(true);
                    return;
                }

			}

        emit modificheConfermate();
    }
}
