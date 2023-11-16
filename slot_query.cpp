#include "mainwindow.h"

void MainWindow::base_query(BaseCtl *p) {
    ui->tableWidget->setRowCount(0);
    auto res = p->select(p->tb_name); // 获取查询结果集
    int fields = mysql_num_fields(res);
    ui->tableWidget->setColumnCount(fields);
    // fetch
    MYSQL_ROW row; // 定义一行的数据
    int j = 0;
    while ((row = mysql_fetch_row(res)) != NULL) {
        this->ui->tableWidget->insertRow(j);
        for (int i = 0; i < fields; i++) {
            QTableWidgetItem *item = new QTableWidgetItem(
                row[i] ? QString::fromUtf8(row[i]) : QString("NULL"));
            ui->tableWidget->setItem(j, i, item);
        }
        j++;
    }
    mysql_free_result(res);
}

void MainWindow::on_stu_query_Button_clicked() {
    Student stu(&sqlObj);
    tb_select = 0;
    ui->tableWidget->clear();
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "学号"
                                                             << "姓名"
                                                             << "性别"
                                                             << "班级编号"
                                                             << "院系编号"
                                                             << "生日"
                                                             << "籍贯");

    base_query(&stu);
}

void MainWindow::on_chg_query_p_clicked() {
    Change chg(&sqlObj);
    tb_select = 1;
    ui->tableWidget->clear();
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "记录号"
                                                             << "学号"
                                                             << "变更代码"
                                                             << "记录时间"
                                                             << "描述");
    base_query(&chg);
}

void MainWindow::on_rw_query_p_clicked() {
    Reward rw(&sqlObj);
    tb_select = 2;
    ui->tableWidget->clear();
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "记录号"
                                                             << "学号"
                                                             << "级别代码"
                                                             << "记录时间"
                                                             << "描述");
    base_query(&rw);
}

void MainWindow::on_pns__query_p_clicked() {
    Punishment pns(&sqlObj);
    tb_select = 3;
    ui->tableWidget->clear();
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "记录号"
                                                             << "学号"
                                                             << "级别代码"
                                                             << "记录时间"
                                                             << "是否生效"
                                                             << "描述");
    base_query(&pns);
}

void MainWindow::on_depa__query_p_clicked() {
    Department dep(&sqlObj);
    tb_select = 4;
    string tg = "department";
    ui->tableWidget->clear();
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "编号"
                                                             << "全称");
    base_query(&dep);
}

void MainWindow::on_cls__query_p_clicked() {
    C_class cls(&sqlObj);
    tb_select = 5;
    ui->tableWidget->clear();
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "编号"
                                                             << "全称"
                                                             << "班长学号");
    base_query(&cls);
}