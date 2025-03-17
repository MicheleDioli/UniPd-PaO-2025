#include "MostraVisitor.h"

#include "../../Libro.h"
#include "../../Rivista.h"
#include "../../Film.h"

QVBoxLayout* MostraVisitor::getLayout() const {
    return layout;
}

void MostraVisitor::visitLibro(Libro& l) {

    layout = new QVBoxLayout();
    layout->setContentsMargins(20, 20, 20, 20);
    layout->setSpacing(15);

    QHBoxLayout* sopra = new QHBoxLayout();

    QLabel* codice_anno = new QLabel("Codice: <b>" + QString::fromStdString(l.getCodice()) + "</b><br>Anno: <b>" + QString::number(l.getAnno()) + "</b>" + "<br>Lingua: <b>" + QString::fromStdString(l.getLingua()) + "</b><br>Copie: <b>" + QString::number(l.getCopie()) + "</b>");
    codice_anno->setStyleSheet(
        "QLabel {"
        "   font-size: 14px;"
        "   padding: 8px;"
        "   border-radius: 8px;"
        "}"
    );
    codice_anno->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QPixmap image(":/asset/images/libro.png");
    image = image.scaled(120, 120, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QLabel* imageLabel = new QLabel();
    imageLabel->setPixmap(image);
    imageLabel->setAlignment(Qt::AlignCenter);

    sopra->addWidget(codice_anno);
    sopra->addWidget(imageLabel);
    //sopra->addWidget(lingua_copie);

    QLabel* titolo_autore = new QLabel("<h1 style='margin: 10px;'>" + QString::fromStdString(l.getTitolo()) + "</h1><h2>di " + QString::fromStdString(l.getAutore()) + "</h2>");
    titolo_autore->setStyleSheet(
        "QLabel {"
        "   font-family: 'Arial';"
        "   text-align: center;"
        "   padding: 10px;"
        "}"
    );
    titolo_autore->setAlignment(Qt::AlignCenter);

    QHBoxLayout* mezzo = new QHBoxLayout();
    mezzo->setSpacing(30);

    QVBoxLayout* mezzoLeft = new QVBoxLayout();
    QVBoxLayout* mezzoRight = new QVBoxLayout();

    QLabel* casaEditrice = new QLabel("<div style=' font-size: 13px;'>Prodotto e stampato da</div><div style='font-size: 15px; margin-top: 5px;'><b>" + QString::fromStdString(l.getCasaEditrice()) + "</b></div>");
    casaEditrice->setStyleSheet("QLabel { padding: 8px; }");

    QLabel* g_p_c = new QLabel(
        "<span style='font-weight: bold;'>" + QString::fromStdString(l.getGenere()) + "</span><br>" +
        QString::number(l.getCapitoli()) + " capitoli<br>" +
        QString::number(l.getPagine()) + " pagine"
    );
    g_p_c->setStyleSheet(
        "QLabel {"
        "   font-size: 14px;"
        "   padding: 8px;"
        "}"
    );

    mezzoLeft->addWidget(casaEditrice);
    mezzoRight->addWidget(g_p_c);

    mezzo->addLayout(mezzoLeft);
    mezzo->addLayout(mezzoRight);

    QLabel* descrizione = new QLabel(QString::fromStdString(l.getDescrizione()));
    descrizione->setStyleSheet(
        "QLabel {"
        "   border: 1px solid #dcdcdc;"
        "   border-radius: 8px;"
        "   padding: 15px;"
        "   margin: 10px 0;"
        "   font-size: 13px;"
        "   line-height: 1.4;"
        "}"
    );
    descrizione->setAlignment(Qt::AlignJustify);
    descrizione->setWordWrap(true);

    layout->addLayout(sopra);
    layout->addWidget(titolo_autore);
    layout->addLayout(mezzo);
    layout->addWidget(descrizione);
}

void MostraVisitor::visitRivista(Rivista& r) {

    layout = new QVBoxLayout();
    layout->setContentsMargins(20, 20, 20, 20);
    layout->setSpacing(15);

    QHBoxLayout* sopra = new QHBoxLayout();

    QLabel* codice_anno = new QLabel("Codice: <b>" + QString::fromStdString(r.getCodice()) + "</b><br>Anno: <b>" + QString::number(r.getAnno()) + "</b>" + "<br>Lingua: <b>" + QString::fromStdString(r.getLingua()) + "</b><br>Copie: <b>" + QString::number(r.getCopie()) + "</b>");
    codice_anno->setStyleSheet(
        "QLabel {"
        "   font-size: 14px;"
        "   padding: 8px;"
        "   border-radius: 8px;"
        "}"
    );
    codice_anno->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QPixmap image(":/asset/images/rivista.png");
    image = image.scaled(120, 120, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QLabel* imageLabel = new QLabel();
    imageLabel->setPixmap(image);
    imageLabel->setAlignment(Qt::AlignCenter);

    sopra->addWidget(codice_anno);
    sopra->addWidget(imageLabel);

    QLabel* titolo_autore = new QLabel("<h1 style='margin: 10px;'>" + QString::fromStdString(r.getTitolo()) + "</h1><h2>di " + QString::fromStdString(r.getEditore()) + "</h2>" + "<h3>" + QString::number(r.getEdizione()) + "° edizione</h3>");
    titolo_autore->setStyleSheet(
        "QLabel {"
        "font-family: 'Arial';"
        "text-align: center;"
        "padding: 10px;"
        "}"
    );
    titolo_autore->setAlignment(Qt::AlignCenter);

    QHBoxLayout* mezzo = new QHBoxLayout();
    mezzo->setSpacing(30);

    QVBoxLayout* mezzoLeft = new QVBoxLayout();
    QVBoxLayout* mezzoRight = new QVBoxLayout();

    QLabel* pubblicatore = new QLabel("<div style=' font-size: 13px;'>Pubblicata, stampata  da</div><div style='font-size: 15px; margin-top: 5px;'><b>" + QString::fromStdString(r.getPubblicatore()) + "</b></div>");
    pubblicatore->setStyleSheet("QLabel { padding: 8px; }");

    QLabel* p_i = new QLabel(
        "<span style='font-weight: bold;'>" + QString::fromStdString(r.getGenere()) + "</span><br>" +
        QString::number(r.getPagine()) + " pagine<br>" +
        "Intervallo di pubblicazione: " + QString::number(r.getIntervalloPubblicazione())
    );

    mezzoLeft->addWidget(pubblicatore);
    mezzoRight->addWidget(p_i);

    mezzo->addLayout(mezzoLeft);
    mezzo->addLayout(mezzoRight);

    int tmp1 = r.getDifficolta();
    QString tmp2 = "";
    for(int i = 0; i < tmp1; i++){
        tmp2 += "★";
    }

    QLabel* difficolta = new QLabel("Difficolta" + tmp2 + "<div class = num>" + QString::number(r.getDifficolta()) + "/5 </div>");
    difficolta->setStyleSheet(
        "QLabel {"
        "font-size: 14px;"
        "padding: 8px;"
        "}"
    );
    difficolta->setAlignment(Qt::AlignCenter);
    difficolta->setStyleSheet("num {margin-left: 10px;}");

    QLabel* velocita = new QLabel("Velocita di lettura: " + QString::number(r.velocitaLettura()) + " minuti stimati");
    velocita->setAlignment(Qt::AlignCenter);

    velocita->setStyleSheet(
        "QLabel {"
        "   font-size: 14px;"
        "   padding: 8px;"
        "}"
    );
    layout->addLayout(sopra);
    layout->addWidget(titolo_autore);
    layout->addLayout(mezzo);
    layout->addSpacing(10);
    layout->addWidget(difficolta);
    layout->addSpacing(10);
    layout->addWidget(velocita);
    QLabel* descrizione = new QLabel(QString::fromStdString(r.getDescrizione()));
    descrizione->setStyleSheet(
        "QLabel {"
        "border: 1px solid #dcdcdc;"
        "border-radius: 8px;"
        "padding: 15px;"
        "margin: 10px 0;"
        "font-size: 13px;"
        "line-height: 1.4;"
        "}"
    );
    descrizione->setAlignment(Qt::AlignJustify);
    layout->addWidget(descrizione);
}

void MostraVisitor::visitFilm(Film& f) {

layout = new QVBoxLayout();
layout->setContentsMargins(20, 20, 20, 20);
layout->setSpacing(15);

QHBoxLayout* sopra = new QHBoxLayout();
sopra->setContentsMargins(0, 0, 0, 0);


QPixmap image(":/asset/images/film.png");
image = image.scaled(120, 120, Qt::KeepAspectRatio, Qt::SmoothTransformation);
QLabel* imageLabel = new QLabel();
imageLabel->setPixmap(image);
imageLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
imageLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

QLabel* codice_anno = new QLabel("Codice: <b>" + QString::fromStdString(f.getCodice()) + "</b><br>Anno: <b>" + QString::number(f.getAnno()) + "</b><br>Lingua: <b>" + QString::fromStdString(f.getLingua()) + "</b><br>Copie: <b>" + QString::number(f.getCopie()) + "</b>");
codice_anno->setStyleSheet(
    "QLabel {"
    "   font-size: 14px;"
    "   padding: 8px;"
    "   border-radius: 8px;"
    "}"
);
codice_anno->setAlignment(Qt::AlignLeft | Qt::AlignTop);

sopra->addWidget(codice_anno, 1);
sopra->addWidget(imageLabel);

QLabel* titolo = new QLabel("<div style='margin: 15px 0;'>"
                            "<h1>" + QString::fromStdString(f.getTitolo()) + "</h1>"
                            "<h2>di " + QString::fromStdString(f.getRegista()) + "</h2></div>");
titolo->setAlignment(Qt::AlignCenter);
titolo->setStyleSheet(
    "QLabel {"
    "   font-family: 'Arial';"
    "   margin-top: 10px;"
    "   margin-bottom: 20px;"
    "}"
);

QHBoxLayout* mezzo = new QHBoxLayout();
mezzo->setSpacing(30);

QVBoxLayout* mezzoLeft = new QVBoxLayout();
QVBoxLayout* mezzoRight = new QVBoxLayout();

QLabel* attori_produttori = new QLabel(
    "<div style='font-size: 13px;'>Attore principale</div>"
    "<div style='font-size: 15px; margin: 5px 0 15px 0;'><b>" + QString::fromStdString(f.getAttori()) + "</b></div>"
    "<div style='font-size: 13px;'>Prodotto da</div>"
    "<div style='font-size: 15px; margin-top: 5px;'><b>" + QString::fromStdString(f.getProduttore()) + "</b></div>"
);

QLabel* durata = new QLabel(
    "<div style='font-size: 15px; margin-bottom: 8px;'><b>" + QString::fromStdString(f.getGenere()) + "</b></div>"
    "<div style='font-size: 14px;'>" + QString::number(f.getDurata()) + " minuti</div>"
);

mezzoLeft->addWidget(attori_produttori);
mezzoRight->addWidget(durata);
mezzo->addLayout(mezzoLeft);
mezzo->addLayout(mezzoRight);

QLabel* descrizione = new QLabel(QString::fromStdString(f.getDescrizione()));
descrizione->setStyleSheet(
"QLabel {"
"border: 1px solid #dcdcdc;"
"border-radius: 8px;"
"padding: 15px;"
"margin: 10px 0;"
"font-size: 13px;"
"line-height: 1.4;"
"}"
);
descrizione->setWordWrap(true);
descrizione->setAlignment(Qt::AlignJustify);

layout->addLayout(sopra);
layout->addWidget(titolo);
layout->addLayout(mezzo);
layout->addWidget(descrizione);
}
