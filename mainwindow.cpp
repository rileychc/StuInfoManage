#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}
MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_stu_clapushButton_clicked() {
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "学号"
                                                             << "姓名"
                                                             << "性别"
                                                             << "班级编号"
                                                             << "院系编号"
                                                             << "生日"
                                                             << "籍贯");
}
