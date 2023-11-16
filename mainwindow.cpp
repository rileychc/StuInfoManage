#include "mainwindow.h"
#include "./ui_mainwindow.h"
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
// #include
// "/Users/riley/Project/build-StuInfoManage-Desktop-Debug/StuInfoManage_autogen/include/ui_mainwindow.h"
#include "chg_query.h"
#include "cls_query.h"
#include "depar_wd.h"
#include "pns_query.h"
#include "rw_query.h"
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
// void MainWindow::on_pushButton_clicked() {

// }

// void MainWindow::on_pushButton_3_clicked() {

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

void MainWindow::on_stu_query_Button_clicked() {
    on_stu_clapushButton_clicked();
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

void MainWindow::on_demo_query_clicked() {
    chg_query *w = new chg_query();
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(w);
    setLayout(layout);
    w->show();
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

void MainWindow::on_rw_query_p_clicked() {
    rw_query *w = new rw_query();
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(w);
    setLayout(layout);
    w->show();
}

void MainWindow::on_pns_query_p_clicked() {
    pns_query *w = new pns_query();
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(w);
    setLayout(layout);
    w->show();
}

void MainWindow::on_depa_query_p_clicked() {
    depar_wd *w = new depar_wd();
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(w);
    setLayout(layout);
    w->show();
}

void MainWindow::on_cls_query_p_clicked() {
    cls_query *w = new cls_query();
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(w);
    setLayout(layout);
    w->show();
}

void MainWindow::on_tableWidget_itemChanged(QTableWidgetItem *item) {
    Student stu(&mysql);
    int row = item->row();       // 获取行号
    int column = item->column(); // 获取列号
    QTableWidgetItem *stuid = ui->tableWidget->item(row, 0);
    string tg;
    string text = item->text().toStdString(); // 获取更新后的内容
    switch (column) {
    case 0:
        tg = "studentid";
        break;
    case 1:
        tg = "name";
        text = "'" + text + "'";
        break;
    case 2:
        tg = "sex";
        text = "'" + text + "'";
        break;
    case 3:
        tg = "class";
        break;
    case 4:
        tg = "deparment";
        break;
    case 5:
        tg = "birthday";
        break;
    case 6:
        tg = "native_place";
        text = "'" + text + "'";
        break;
    }
    string uptg = "studentid";
    string uu = stuid->text().toStdString();

    stu.update(tg, text, uptg, uu);

    //     qDebug()
    // << "Item at (" << row << "," << column << ") has been changed to"
    // << text;
}
