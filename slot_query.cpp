#include "mainwindow.h"

void MainWindow::on_stu_query_Button_clicked() {
    tb_select = 0;
    on_stu_clapushButton_clicked();
    Student stu(&sqlObj);
    string tg = "student";
    auto res = stu.select(tg);
    // rows/fields  行/列
    // printf("rows:%d\n", rows);
    int fields = mysql_num_fields(res);
    // printf("fields:%d\n", fields);
    // fetch
    MYSQL_ROW row; // 定义一行的数据
    int j = 0;
    while ((row = mysql_fetch_row(res)) != NULL) {
        this->ui->tableWidget->insertRow(j);
        for (int i = 0; i < fields; i++) {
            QTableWidgetItem *item = new QTableWidgetItem(
                row[i] ? QString::fromUtf8(row[i]) : QString("NULL"));
            // QTableWidgetItem *demo = new QTableWidgetItem(row[i]);
            // printf("%s ", row[i]);
            ui->tableWidget->setItem(j, i, item);
        }
        // printf("\n");
        j++;
    }
    mysql_free_result(res);
}

void MainWindow::on_chg_query_p_clicked() {
    Change chg(&sqlObj);
    tb_select = 1;
    string tg = "`change`";
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    auto res = chg.select(tg);
    int fields = mysql_num_fields(res);
    ui->tableWidget->setColumnCount(fields); // rows/fields  行/列
    // printf("rows:%d\n", rows);
    // printf("fields:%d\n", fields);
    // fetch
    MYSQL_ROW row; // 定义一行的数据
    int j = 0;
    while ((row = mysql_fetch_row(res)) != NULL) {
        this->ui->tableWidget->insertRow(j);
        for (int i = 0; i < fields; i++) {
            QTableWidgetItem *item = new QTableWidgetItem(
                row[i] ? QString::fromUtf8(row[i]) : QString("NULL"));
            // QTableWidgetItem *demo = new QTableWidgetItem(row[i]);
            // printf("%s ", row[i]);
            ui->tableWidget->setItem(j, i, item);
        }
        // printf("\n");
        j++;
    }
    mysql_free_result(res);
}

void MainWindow::on_rw_query_p_clicked() {
    Reward rw(&sqlObj);
    tb_select = 2;
    string tg = "reward";
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    auto res = rw.select(tg);
    int fields = mysql_num_fields(res);
    ui->tableWidget->setColumnCount(fields);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "记录号"
                                                             << "学号"
                                                             << "级别代码"
                                                             << "记录时间"
                                                             << "描述");
    // rows/fields  行/列
    // printf("rows:%d\n", rows);
    // printf("fields:%d\n", fields);
    // fetch
    MYSQL_ROW row; // 定义一行的数据
    int j = 0;
    while ((row = mysql_fetch_row(res)) != NULL) {
        this->ui->tableWidget->insertRow(j);
        for (int i = 0; i < fields; i++) {
            QTableWidgetItem *item = new QTableWidgetItem(
                row[i] ? QString::fromUtf8(row[i]) : QString("NULL"));
            // QTableWidgetItem *demo = new QTableWidgetItem(row[i]);
            // printf("%s ", row[i]);
            ui->tableWidget->setItem(j, i, item);
        }
        // printf("\n");
        j++;
    }
    mysql_free_result(res);
}

void MainWindow::on_pns__query_p_clicked() {
    Punishment pns(&sqlObj);
    tb_select = 3;
    string tg = "punishment";
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    auto res = pns.select(tg);
    int fields = mysql_num_fields(res);
    ui->tableWidget->setColumnCount(fields);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "记录号"
                                                             << "学号"
                                                             << "级别代码"
                                                             << "记录时间"
                                                             << "是否生效"
                                                             << "描述");
    // rows/fields  行/列
    // printf("rows:%d\n", rows);
    // printf("fields:%d\n", fields);
    // fetch
    MYSQL_ROW row; // 定义一行的数据
    int j = 0;
    while ((row = mysql_fetch_row(res)) != NULL) {
        this->ui->tableWidget->insertRow(j);
        for (int i = 0; i < fields; i++) {
            QTableWidgetItem *item = new QTableWidgetItem(
                row[i] ? QString::fromUtf8(row[i]) : QString("NULL"));
            // QTableWidgetItem *demo = new QTableWidgetItem(row[i]);
            // printf("%s ", row[i]);
            ui->tableWidget->setItem(j, i, item);
        }
        // printf("\n");
        j++;
    }
    mysql_free_result(res);
}

void MainWindow::on_depa__query_p_clicked() {
    Department dep(&sqlObj);
    tb_select = 4;
    string tg = "department";
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    auto res = dep.select(tg);
    int fields = mysql_num_fields(res);
    ui->tableWidget->setColumnCount(fields);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "编号"
                                                             << "全称");
    // rows/fields  行/列
    // printf("rows:%d\n", rows);
    // printf("fields:%d\n", fields);
    // fetch
    MYSQL_ROW row; // 定义一行的数据
    int j = 0;
    while ((row = mysql_fetch_row(res)) != NULL) {
        this->ui->tableWidget->insertRow(j);
        for (int i = 0; i < fields; i++) {
            QTableWidgetItem *item = new QTableWidgetItem(
                row[i] ? QString::fromUtf8(row[i]) : QString("NULL"));
            // QTableWidgetItem *demo = new QTableWidgetItem(row[i]);
            // printf("%s ", row[i]);
            ui->tableWidget->setItem(j, i, item);
        }
        // printf("\n");
        j++;
    }
    mysql_free_result(res);
}

void MainWindow::on_cls__query_p_clicked() {
    C_class cls(&sqlObj);
    tb_select = 5;
    string tg = "class";
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    auto res = cls.select(tg);
    int fields = mysql_num_fields(res);
    ui->tableWidget->setColumnCount(fields);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "编号"
                                                             << "全称"
                                                             << "班长学号");
    // rows/fields  行/列
    // printf("rows:%d\n", rows);
    // printf("fields:%d\n", fields);
    // fetch
    MYSQL_ROW row; // 定义一行的数据
    int j = 0;
    while ((row = mysql_fetch_row(res)) != NULL) {
        this->ui->tableWidget->insertRow(j);
        for (int i = 0; i < fields; i++) {
            QTableWidgetItem *item = new QTableWidgetItem(
                row[i] ? QString::fromUtf8(row[i]) : QString("NULL"));
            // QTableWidgetItem *demo = new QTableWidgetItem(row[i]);
            // printf("%s ", row[i]);
            ui->tableWidget->setItem(j, i, item);
        }
        // printf("\n");
        j++;
    }
    mysql_free_result(res);
}
