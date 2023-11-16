#include "mainwindow.h"
// #include "./ui_mainwindow.h"
#include "/Users/riley/Project/build-rileySQL-Desktop-Debug/StuInfoManage_autogen/include/ui_mainwindow.h"
#include "Change.h"
#include "Class.h"
#include "Department.h"
#include "Punishment.h"
#include "Reward.h"
#include "Student.h"
#include <QString>
#include <QStringList>
#include <QVBoxLayout>
#include <Qdebug>
#include <qlogging.h>
#include <stdio.h>
#include <string>
using namespace std;

extern C_mysql mysql;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}
MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_cls_ar_accepted() {

    C_class cls(&mysql);
    cls.id = this->ui->t_cla_id->text().toStdString();
    cls.name = this->ui->t_cla_name->text().toStdString();
    cls.monitor = this->ui->t_cla_monitor->text().toStdString();
    cls.insert();
}

void MainWindow::on_cla_ar_rejected() {
    this->ui->t_cla_id->clear();
    this->ui->t_cla_name->clear();
    this->ui->t_cla_monitor->clear();
}

void MainWindow::on_depa_ar_accepted() {
    Department dep(&mysql);
    dep.id = this->ui->t_depa_id->text().toStdString();
    dep.name = this->ui->t_depa_name->text().toStdString();
    dep.insert();
}

void MainWindow::on_depa_ar_rejected() {
    this->ui->t_depa_id->clear();
    this->ui->t_depa_name->clear();
}

void MainWindow::on_per_ar_accepted() {
    Student stu(&mysql);
    stu.id = this->ui->t_id->text().toStdString();
    stu.name = this->ui->t_name->text().toStdString();
    stu.stu_class = this->ui->t_class->text().toStdString();
    stu.sex = this->ui->t_sex->text().toStdString();
    stu.department = this->ui->t_department->text().toStdString();
    stu.native_place = this->ui->t_nactive_place->text().toStdString();
    stu.birthday = this->ui->t_birthday->text().toStdString();
    stu.insert();
}

void MainWindow::on_per_ar_rejected() { // 学籍变更输入

    this->ui->t_name->clear();
    this->ui->t_class->clear();
    this->ui->t_sex->clear();
    this->ui->t_department->clear();
    this->ui->t_nactive_place->clear();
    this->ui->t_birthday->clear();
    this->ui->t_id->clear();
}

void MainWindow::on_chg_accepted() {
    Change change(&mysql);
    change.id = this->ui->t_ch_id->text().toStdString();
    change.change_code = this->ui->t_ch_stuid->text().toStdString();
    change.rec_time = this->ui->t_ch_tm->text().toStdString();
    change.studentid = this->ui->t_ch_stuid->text().toStdString();
    change.description = this->ui->t_ch_des->text().toStdString();
    change.insert();
}

void MainWindow::on_chg_rejected() {
    this->ui->t_ch_id->clear();
    this->ui->t_ch_stuid->clear();
    this->ui->t_ch_tm->clear();
    this->ui->t_ch_stuid->clear();
    this->ui->t_ch_des->clear();
}

void MainWindow::on_rw_rejected() {
    this->ui->t_rw_id->clear();
    this->ui->t_rw_lv->clear();
    this->ui->t_rw_tm->clear();
    this->ui->t_rw_des->clear();
    this->ui->t_rw_stuid->clear();
}

void MainWindow::on_rw_accepted() {
    Reward rw(&mysql);
    rw.id = this->ui->t_rw_id->text().toStdString();
    rw.reward_code = this->ui->t_rw_lv->text().toStdString();
    rw.rec_time = this->ui->t_rw_tm->text().toStdString();
    rw.description = this->ui->t_rw_des->text().toStdString();
    rw.studentid = this->ui->t_rw_stuid->text().toStdString();
    rw.insert();
}

void MainWindow::on_pns_rejected() {
    this->ui->t_pns_id->clear();
    this->ui->t_pns_des->clear();
    this->ui->t_pns_ea->clear();
    this->ui->t_pns_tm->clear();
    this->ui->t_pns_stuid->clear();
}

void MainWindow::on_pns_accepted() {
    Punishment pns(&mysql);
    pns.id = this->ui->t_pns_id->text().toStdString();
    pns.punishment_code = this->ui->t_pns_lv->text().toStdString();
    pns.description = this->ui->t_pns_des->text().toStdString();
    pns.enable = this->ui->t_pns_ea->text().toStdString();
    pns.rec_time = this->ui->t_pns_tm->text().toStdString();
    pns.studentid = this->ui->t_pns_stuid->text().toStdString();
    pns.insert();
}

void MainWindow::on_stu_query_Button_clicked() {
    tb_select = 0;
    on_stu_clapushButton_clicked();
    Student stu(&mysql);
    string tg = "student";
    auto res = mysql.select(tg);
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

void MainWindow::on_tabWidget_tabBarClicked(int index) {
    int a;
    // on_stu_query_Button_clicked();
}

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

void MainWindow::on_tableWidget_itemChanged(QTableWidgetItem *item) {
    int row = item->row();       // 获取行号
    int column = item->column(); // 获取列号
    QTableWidgetItem *pri_key = ui->tableWidget->item(row, 0);
    string set_src;
    string set_dst = item->text().toStdString(); // 获取更新后的内容
    switch (tb_select) {
    case 0: {
        Student stu(&mysql);
        switch (column) {
        case 0:
            set_src = "studentid";
            break;
        case 1:
            set_src = "name";
            set_dst = "'" + set_dst + "'";
            break;
        case 2:
            set_src = "sex";
            set_dst = "'" + set_dst + "'";
            break;
        case 3:
            set_src = "class";
            break;
        case 4:
            set_src = "deparment";
            break;
        case 5:
            set_src = "birthday";
            break;
        case 6:
            set_src = "native_place";
            set_dst = "'" + set_dst + "'";
            break;
        }
        string whe_src = "studentid";
        string whe_dst = pri_key->text().toStdString();
        stu.update(set_src, set_dst, whe_src,
                   whe_dst); // update [table] set tg=text where uptg=uu;
        break;
    }
    case 1: {
        Change chg(&mysql);
        switch (column) {
        case 0:
            set_src = "id";
            break;
        case 1:
            set_src = "studentid";
            break;
        case 2:
            set_src = "`change`";
            break;
        case 3:
            set_src = "rec_time";
            break;
        case 4:
            set_src = "description";
            set_dst = "'" + set_dst + "'";
            break;
        }
        string whe_src = "id";
        string whe_dst = pri_key->text().toStdString();
        chg.update(set_src, set_dst, whe_src,
                   whe_dst); // update [table] set tg=text where uptg=uu;
        break;
    }
    case 2: {
        Reward rw(&mysql);
        switch (column) {
        case 0:
            set_src = "id";
            break;
        case 1:
            set_src = "studentid";
            break;
        case 2:
            set_src = "levels";
            break;
        case 3:
            set_src = "rec_time";
            break;
        case 4:
            set_src = "description";
            set_dst = "'" + set_dst + "'";
            break;
        }
        string whe_src = "id";
        string whe_dst = pri_key->text().toStdString();
        rw.update(set_src, set_dst, whe_src,
                  whe_dst); // update [table] set tg=text where uptg=uu;
        break;
    }
    case 3: {
        Punishment pns(&mysql);
        switch (column) {
        case 0:
            set_src = "id";
            break;
        case 1:
            set_src = "studentid";
            break;
        case 2:
            set_src = "levels";
            break;
        case 3:
            set_src = "rec_time";
            break;
        case 4:
            set_src = "enable";
            set_dst = "'" + set_dst + "'";
            break;
        case 5:
            set_src = "description";
            set_dst = "'" + set_dst + "'";
            break;
        }
        string whe_src = "id";
        string whe_dst = pri_key->text().toStdString();
        pns.update(set_src, set_dst, whe_src,
                   whe_dst); // update [table] set tg=text where uptg=uu;
        break;
    }
    case 4: {
        Department depa(&mysql);
        switch (column) {
        case 0:
            set_src = "id";
            break;
        case 1:
            set_src = "name";
            set_dst = "'" + set_dst + "'";
            break;
        }
        string whe_src = "id";
        string whe_dst = pri_key->text().toStdString();
        depa.update(set_src, set_dst, whe_src,
                    whe_dst); // update [table] set tg=text where uptg=uu;
        break;
    }
    case 5: {
        C_class cls(&mysql);
        switch (column) {
        case 0:
            set_src = "id";
            break;
        case 1:
            set_src = "name";
            set_dst = "'" + set_dst + "'";
            break;
        }
        string whe_src = "id";
        string whe_dst = pri_key->text().toStdString();
        cls.update(set_src, set_dst, whe_src,
                   whe_dst); // update [table] set tg=text where uptg=uu;
        break;
    }
    }
}

void MainWindow::on_chg_query_p_clicked() {
    tb_select = 1;
    string tg = "`change`";
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    auto res = mysql.select(tg);
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
    tb_select = 2;
    string tg = "reward";
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    auto res = mysql.select(tg);
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
    tb_select = 3;
    string tg = "punishment";
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    auto res = mysql.select(tg);
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
    tb_select = 4;
    string tg = "department";
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    auto res = mysql.select(tg);
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
    tb_select = 5;
    string tg = "class";
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    auto res = mysql.select(tg);
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
