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
    QBrush szczotka(QColor(230,45,26,150));
    QPen pioro(Qt::black);

    int k[2] ={pl.getIlwierszy(),pl.getIlkolumn()};

    int il_wie=400/5;
    int il_kol=400/5;

    for(int i=0;i<ui->WielkoscPlanszy->value();i++){
        k[0]=i;
        for(int j=0;j<ui->WielkoscPlanszy->value();j++){
            k[1]=j;
            if(gra.ZliczSasiadow(il_wie,il_kol)){
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


void MainWindow::on_WielkoscPlanszy_valueChanged(int value)
{
    pl.setWielkosc(value,value);
}


void MainWindow::on_Reset_clicked()
{
    pl.clear();
    gra.getCzy_losowac();
    stworzplansze();
}



