#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Class.h"
#include "Punishment.h"
#include "Reward.h"
#include "Student.h"
#include "Student.h"

// #include
// "/Users/riley/Project/build-StuInfoManage-Desktop-Debug/StuInfoManage_autogen/include/ui_mainwindow.h"
#include "Change.h"
#include "Class.h"
#include "Department.h"
#include "Punishment.h"
#include "Reward.h"
#include "Student.h"
#include "chg_query.h"
#include "cls_query.h"
#include "depar_wd.h"
#include "pns_query.h"

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
    stu.id = this->ui->t_name->text().toStdString();
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
    this->ui->t_name->clear();
}
// void MainWindow::on_pushButton_clicked() {
//     Student stu(&mysql);
//     string tg = "student";
//     auto res = mysql.select(tg);
//     // rows/fields  行/列
//     // printf("rows:%d\n", rows);
//     int fields = mysql_num_fields(res);
//     // printf("fields:%d\n", fields);
//     // fetch
//     MYSQL_ROW row; // 定义一行的数据
//     int j = 0;
//     while ((row = mysql_fetch_row(res)) != NULL) {
//         for (int i = 0; i < fields; i++) {
//             // printf("%s\t", row[i]);

//             // ui->tableWidget->setItem(j, i, new QTableWidgetItem(row[i]));
//         }
//         // printf("\n");
//         j++;
//     }
//     mysql_free_result(res);
// }

// void MainWindow::on_pushButton_3_clicked() {
//     chg_query w;
//     w.show();
// }

// void MainWindow::on_pushButton_4_clicked() {
//     rw_query w;
//     w.show();
// }

// void MainWindow::on_pushButton_5_clicked() {
//     pns_query w;
//     w.show();
// }

// void MainWindow::on_pushButton_6_clicked() {

//    depar_wd w;
//    w.show();
//}

// void MainWindow::on_pushButton_7_clicked() {
//     cls_query w;
//     w.show();
// }

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
