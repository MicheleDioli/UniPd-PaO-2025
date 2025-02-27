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
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
	app.setWindowIcon(QIcon(":/asset/images/biblioteca.png"));
	MainWindow w;
    w.setWindowTitle("Biblioteca");
    w.show();
    return app.exec();
}