#include <QApplication>
#include <QVBoxLayout>
#include <QWidget>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QPushButton>
#include <QTextEdit>

#include "src/view/mainwindow.h"
#include "src/view/Sensoriqt/ListaVisitor.h"
#include "src/view/Modifica/editVisitor.h"
#include "src/view/Sensoriqt/FiltroLayout.h"
#include "src/view/Mostra/MostraVisitor.h"
#include "src/Rivista.h"
#include "src/Libro.h"
#include "src/Film.h"
/*
class test : public QWidget {
  public:
  test(QWidget* parent = nullptr) : QWidget(parent) {
    QVBoxLayout* layout = new QVBoxLayout(this);
    MostraVisitor visitor;
    Rivista rivista("titolo","codice", "descrizione", "genere", 2021, 10, "lingua", "editore", 100, "pubblicatore", 1, 1, 1);
    Libro libro("titolo","codice", "descrizione", "genere", 2021, 10, "lingua","monda",3, 100, "autore");
    rivista.accept(visitor);
    layout->addLayout(visitor.getLayout());
  }
};

*/
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
	app.setWindowIcon(QIcon(":/asset/images/biblioteca.png"));
	MainWindow w;
    w.setWindowTitle("Biblioteca");
    w.show();
    return app.exec();
}