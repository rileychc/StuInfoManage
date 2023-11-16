#include "mainwindow.h"
#include "sql.h"
#include <QApplication>

C_mysql mysql;
int main(int argc, char *argv[]) {
    mysql.connect();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
