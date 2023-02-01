#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<fstream>
#include<QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    gra.setAll(4,4);
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

    int il_wie=490/gra.get_ilosc_wierszy();
    int il_kol=500/gra.get_ilosc_kolumn();
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

void MainWindow::on_Losuj_clicked()
{
    gra.inicjalizacjaStartowa();
    stworzplansze();
}

void MainWindow::on_wierszePlanszy_valueChanged(int value)
{
    gra.setAll(value,gra.get_ilosc_kolumn());
    ui->spinBox->setValue(value);
    stworzplansze();
}

void MainWindow::on_Reset_clicked()
{
    //pl.clear();
    stworzplansze();
}

void MainWindow::on_kolumnyPlanszy_valueChanged(int value)
{
    gra.setAll(gra.get_ilosc_wierszy(),value);
    ui->spinBox_2->setValue(value);
    stworzplansze();
}

void MainWindow::on_Iteracja_clicked()
{
    gra.przetrwanie();
    stworzplansze();
}

void MainWindow::windowFilePath(){
    QString file = QFileDialog::getOpenFileName(this,"Zapis","","Zapis (*.txt)");
    if(!file.isEmpty()) files = file;
}

void MainWindow::on_Ladowanie_clicked()
{
    windowFilePath();
    gra.odczyt(files);
    stworzplansze();
    files = nullptr;
}


void MainWindow::on_Zapis_clicked()
{
    windowFilePath2();
    gra.zapis(files);
}



void MainWindow::windowFilePath2(){
    QString file = QFileDialog::getOpenFileName(this,"Zapis","","Zapis (*.txt)");
    if(!file.isEmpty()) files = file;
}
