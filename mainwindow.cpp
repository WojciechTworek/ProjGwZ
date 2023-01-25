#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::stworzplansze(){
    scena = new QGraphicsScene(ui->board);
    ui->board->setScene(scena);
    QBrush szczotka(QColor(90,208,184,150));
    QPen pioro(Qt::black);

    int il_wie=400/pl.getIlwierszy();
    int il_kol=400/pl.getIlkolumn();

    for(int i=0;i<ui->wierszePlanszy->value();i++){
        for(int j=0;j<ui->kolumnyPlanszy->value();j++){

            if(0){
                kwadrat = scena->addRect(il_wie*i,il_kol*j,il_wie,il_kol,pioro,szczotka);
            }
            else{
                kwadrat = scena->addRect(il_wie*i,il_kol*j,il_wie,il_kol,pioro);
            }
        }
    }
}

void MainWindow::on_Start_clicked()
{
    stworzplansze();
}


void MainWindow::on_wierszePlanszy_valueChanged(int value)
{
    pl.setIlwierszy(value);
    stworzplansze();
}



void MainWindow::on_Reset_clicked()
{
    gra.inicjalizacjaStartowa();
    stworzplansze();
}





void MainWindow::on_kolumnyPlanszy_valueChanged(int value)
{
    pl.setIlkolumn(value);
    stworzplansze();
}

