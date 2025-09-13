#include "MostraListaVisitor.h"

QVBoxLayout* MostraListaVisitor::getLayout() const {
    return layout;
}

void MostraListaVisitor::visitLibro(Libro& l) {
    layout = new QVBoxLayout();

    QPixmap image(":/asset/images/libro.png");
    image = image.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QLabel* imageLabel = new QLabel();
    imageLabel->setPixmap(image);
    imageLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(imageLabel);

    QLabel* titolo = new QLabel(QString::fromStdString(l.getTitolo()));
    QLabel* autore = new QLabel(QString::fromStdString(l.getAutore()));
    QLabel* casaEditrice = new QLabel(QString::fromStdString(l.getCasaEditrice()));
    QLabel* pagine = new QLabel(QString::number(l.getPagine()) + " pagine");
    QLabel* codice = new QLabel(QString::fromStdString(l.getCodice()));
    QLabel* anno = new QLabel(QString::number(l.getAnno()));
    QVBoxLayout* vLayout = new QVBoxLayout();
    QVBoxLayout* vLayout2 = new QVBoxLayout();
    QVBoxLayout* vLayout3 = new QVBoxLayout();

    vLayout->addWidget(titolo);
    vLayout->addWidget(autore);
    vLayout2->addWidget(casaEditrice);
    vLayout2->addWidget(pagine);
    vLayout3->addWidget(codice);
    vLayout3->addWidget(anno);
    layout->addLayout(vLayout);
    layout->addLayout(vLayout2);
    layout->addLayout(vLayout3);
}

void MostraListaVisitor::visitRivista(Rivista& r) {
    layout = new QVBoxLayout();

    QPixmap image(":/asset/images/rivista.png");
    image = image.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QLabel* imageLabel = new QLabel();
    imageLabel->setPixmap(image);
    imageLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(imageLabel);

    QLabel* titolo = new QLabel(QString::fromStdString(r.getTitolo()));
    QLabel* periodicita = new QLabel(QString::fromStdString(r.getIntervalloPubblicazione()));
    QLabel* codice = new QLabel(QString::fromStdString(r.getCodice()));
    QLabel* anno = new QLabel(QString::number(r.getAnno()));
    QVBoxLayout* vLayout = new QVBoxLayout();
    QVBoxLayout* vLayout2 = new QVBoxLayout();

    vLayout->addWidget(titolo);
    vLayout->addWidget(periodicita);
    vLayout2->addWidget(codice);
    vLayout2->addWidget(anno);
    layout->addLayout(vLayout);
    layout->addLayout(vLayout2);
}

void MostraListaVisitor::visitFilm(Film& f) {
    layout = new QVBoxLayout();
    QPixmap image(":/asset/images/film.png");
    image = image.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QLabel* imageLabel = new QLabel();
    imageLabel->setPixmap(image);
    imageLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(imageLabel);

    QLabel* titolo = new QLabel(QString::fromStdString(f.getTitolo()));
    QLabel* regista = new QLabel(QString::fromStdString(f.getRegista()));
    QLabel* durata = new QLabel(QString::number(f.getDurata()) + " min");
    QLabel* codice = new QLabel(QString::fromStdString(f.getCodice()));
    QLabel* anno = new QLabel(QString::number(f.getAnno()));
    QVBoxLayout* vLayout = new QVBoxLayout();
    QVBoxLayout* vLayout2 = new QVBoxLayout();
    QVBoxLayout* vLayout3 = new QVBoxLayout();

    vLayout->addWidget(titolo);
    vLayout->addWidget(regista);
    vLayout2->addWidget(durata);
    vLayout3->addWidget(codice);
    vLayout3->addWidget(anno);
    layout->addLayout(vLayout);
    layout->addLayout(vLayout2);
    layout->addLayout(vLayout3);
}
