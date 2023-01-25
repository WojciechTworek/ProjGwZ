#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gra.h"
#include "qgraphicsscene.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void stworzplansze();

private slots:

    void on_Start_clicked();

    void on_wierszePlanszy_valueChanged(int value);

    void on_Reset_clicked();

    void on_kolumnyPlanszy_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scena;
    Gra gra;
    Plansza pl;
    QGraphicsRectItem *kwadrat;
    QString files;
};
#endif // MAINWINDOW_H
