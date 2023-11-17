#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}
MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_stu_clapushButton_clicked() {
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
}

void MainWindow::on_tabWidget_destroyed() { mysql_close(&sqlObj); }
