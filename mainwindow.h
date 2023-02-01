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

    void on_Losuj_clicked();

    void on_wierszePlanszy_valueChanged(int value);

    void on_Reset_clicked();

    void on_kolumnyPlanszy_valueChanged(int value);

    void on_Iteracja_clicked();
    void windowFilePath();
    void windowFilePath2();

    void on_Ladowanie_clicked();

    void on_Zapis_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scena;
    Gra gra;
    QGraphicsRectItem *kwadrat;
    QString files;
};
#endif // MAINWINDOW_H
