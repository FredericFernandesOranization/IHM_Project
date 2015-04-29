#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QPushButton>
#include <QGraphicsView>

#include <qdebug.h>

#include "mainwindow.h"
#include "database.h"
#include "item.h"
//#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "database.h"
#include "leftzone.h"
#include "rightzone.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
