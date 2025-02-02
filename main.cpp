#include <QApplication>
#include <QVBoxLayout>
#include <QWidget>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QPushButton>
#include <QTextEdit>

#include "src/view/Modifica/editVisitor.h"
#include "src/Rivista.h"

class Test : public QWidget {
public:
    Test(QWidget* parent = nullptr) : QWidget(parent) {
        QVBoxLayout* layout = new QVBoxLayout(this);
        EditVisitor visitor;
        Rivista rivista("codice", "descrizione", "genere", 2021, 10, "lingua", "editore", 100, "pubblicatore", 1, 1, 1);
        rivista.accept(visitor);
        layout->addLayout(visitor.getLayout());
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Test window;
    window.show();
    return app.exec();
}