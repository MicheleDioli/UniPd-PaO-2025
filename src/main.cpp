#include <QApplication>

#include "view/MainWindow.h"

void padriefigli(QtMsgType, const QMessageLogContext &, const QString &) {}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
	app.setWindowIcon(QIcon(":/asset/images/biblioteca.png"));
	MainWindow w;
//	qInstallMessageHandler(padriefigli); //da togliere
    w.setWindowTitle("Biblioteca");
    w.show();
    w.resize(800,600);
    return app.exec();
}
