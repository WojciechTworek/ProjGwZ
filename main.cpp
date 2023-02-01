#include "mainwindow.h"
#include "gra.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

void test(){
    Plansza pl(2,2);
    pl[0][0] = rand()%2;
    pl[0][1] = rand()%2;
    pl[1][0] = rand()%2;
    pl[1][1] = rand()%2;

    qDebug()<<pl[0][0];
    qDebug()<<pl[0][1];
    qDebug()<<pl[1][0];
    qDebug()<<pl[1][1];
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
    srand(time(NULL));
    MainWindow w;
    test();
    w.show();
    return a.exec();


}
