//
// Created by Michele Dioli on 2/21/25.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Sensoriqt/FiltroLayout.h"

class MainWindow : public QWidget {
  private:
    FiltroLayout* f;
    QVBoxLayout* layout;
  public:
    MainWindow(QWidget *parent = nullptr);
};

#endif //MAINWINDOW_H
