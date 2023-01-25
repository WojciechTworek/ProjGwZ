#include "mainwindow.h"
#include "gra.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

void test(){
    Gra gra(5,5);

    gra.inicjalizacjaStartowa();

    if(gra.ZliczSasiadow(2,3) == 0){
        qDebug() << "Działa";
    }
    else{
        qDebug() << "Nie działa";
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Grawzycie_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.show();
    test();
    return a.exec();


}
