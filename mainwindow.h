#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include<QLabel>
#include"button.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *);

private:
    Ui::MainWindow *ui;
};

class Button1 : public QPushButton
{
    Q_OBJECT
public:
   Button1(QString x);
signals:

public slots:

};

#endif // MAINWINDOW_H
