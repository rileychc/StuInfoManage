#include "mainwindow.h"
#include <Department.h>
#include <string>
using namespace std;

bool MainWindow::single_query(BaseCtl *p, QTableWidgetItem *it) {
    string seleTg = "name"; // 默认为查询name
    string key_vlu = it->text().toStdString();
    auto sg_res = mysql_fetch_row(p->select(seleTg, key_vlu)); // 查询到的结果
    it->setText(QString::fromStdString(sg_res[0]));
    return true;
}
void MainWindow::base_query(BaseCtl *p) { // 父类指针指向子类对象，多态性
    ui->tableWidget->setRowCount(0);
    auto res = p->select(); // 获取查询结果集
    if (nullptr == res)
        ui->statusbar->showMessage("查询失败!", 2000);

    int fields = mysql_num_fields(res);
    // fetch
    MYSQL_ROW row; // 定义一行的数据
    int j = 0;
    switch (tb_select) {
    case 0:
        ui->tableWidget->setColumnCount(fields);
        while ((row = mysql_fetch_row(res)) != NULL) {
            this->ui->tableWidget->insertRow(j);
            for (int i = 0; i < fields; i++) {
                QTableWidgetItem *item = new QTableWidgetItem(
                    row[i] ? QString::fromUtf8(row[i]) : QString("NULL"));
                if (2 == i) {
                    if ("F" == item->text().toStdString())
                        item->setText("女");
                    else if ("M" == item->text().toStdString())
                        item->setText("男");
                } else if (3 == i) {
                    single_query(new C_class(&sqlObj), item);
                } else if (4 == i) {
                    single_query(new Department(&sqlObj), item);
                }
                item->setTextAlignment(Qt::AlignCenter);
                ui->tableWidget->setItem(j, i, item);
            }
            j++;
        }

        break;
    case 3: {
        int i;
        string code = "";
        ui->tableWidget->setColumnCount(fields + 1);
        QTableWidgetItem *last_item;
        while ((row = mysql_fetch_row(res)) != NULL) {
            this->ui->tableWidget->insertRow(j);
            for (i = 0; i < fields; i++) {
                QTableWidgetItem *item =
                    new QTableWidgetItem(QString::fromUtf8(row[i]));
                if (4 == i && "F" == item->text().toStdString())
                    item->setText("否");
                else if (4 == i && "T" == item->text().toStdString())
                    item->setText("是");
                else if (2 == i) {
                    last_item = new QTableWidgetItem(item->text());
                }
                item->setTextAlignment(Qt::AlignCenter);
                ui->tableWidget->setItem(j, i, item);
            }
            BaseCtl *addLast = new BaseCtl(&sqlObj);
            addLast->tb_name = "punish_levels"; // 选择代码表
            single_query(addLast, last_item);
            last_item->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->setItem(j, i, last_item);
            j++;
        }
        break;
    }
    case 1:
    case 2: {
        QTableWidgetItem *last_item;
        ui->tableWidget->setColumnCount(fields + 1);
        while ((row = mysql_fetch_row(res)) != NULL) {
            int i;
            this->ui->tableWidget->insertRow(j);
            for (i = 0; i < fields; i++) {
                QTableWidgetItem *item = new QTableWidgetItem(
                    row[i] ? QString::fromUtf8(row[i]) : QString("NULL"));
                if (2 == i) {
                    last_item = new QTableWidgetItem(item->text());
                }
                item->setTextAlignment(Qt::AlignCenter);
                ui->tableWidget->setItem(j, i, item);
            }
            BaseCtl *addLast = new BaseCtl(&sqlObj);
            addLast->tb_name = (1 == tb_select) ? "change_code"
                                                : "reward_levels"; // 选择代码表
            single_query(addLast, last_item);
            last_item->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->setItem(j, i, last_item);
            j++;
        }
        break;
    }

    default: {
        ui->tableWidget->setColumnCount(fields);
        while ((row = mysql_fetch_row(res)) != NULL) {
            this->ui->tableWidget->insertRow(j);
            for (int i = 0; i < fields; i++) {
                QTableWidgetItem *item = new QTableWidgetItem(
                    row[i] ? QString::fromUtf8(row[i]) : QString("NULL"));
                item->setTextAlignment(Qt::AlignCenter);
                ui->tableWidget->setItem(j, i, item);
            }
            j++;
        }
        break;
    }
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
                                                             << "班级名称"
                                                             << "院系名称"
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
                                                             << "描述"
                                                             << "变更名称");
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
                                                             << "描述"
                                                             << "奖励名称");
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
                                                             << "描述"
                                                             << "处罚名称");
    base_query(&pns);
}

void MainWindow::on_depa__query_p_clicked() {
    Department dep(&sqlObj);
    tb_select = 4;
    string tg = "department";
    ui->tableWidget->clear();
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "编号"
                                                             << "院系全称");
    base_query(&dep);
}

void MainWindow::on_cls__query_p_clicked() {
    C_class cls(&sqlObj);
    tb_select = 5;
    ui->tableWidget->clear();
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "编号"
                                                             << "班级全称"
                                                             << "班长学号");
    base_query(&cls);
}
