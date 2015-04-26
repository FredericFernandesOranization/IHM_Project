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

#include "Headers/mainwindow.h"
#include "Headers/database.h"
#include "item.h"
//#include "Headers/ui_mainwindow.h"
#include "Headers/mainwindow.h"
#include "Headers/database.h"
#include "Headers/leftzone.h"
#include "Headers/rightzone.h"

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
