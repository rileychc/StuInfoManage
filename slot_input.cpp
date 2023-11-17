#include "mainwindow.h"

void MainWindow::on_cls_ar_accepted() {
    C_class cls(&sqlObj);
    cls.id = this->ui->t_cla_id->text().toStdString();
    cls.name = this->ui->t_cla_name->text().toStdString();
    cls.monitor = this->ui->t_cla_monitor->text().toStdString();
    if (cls.insert())
        ui->statusbar->showMessage("添加成功!");
    else
        ui->statusbar->showMessage("添加失败!");
}

void MainWindow::on_cla_ar_rejected() {
    this->ui->t_cla_id->clear();
    this->ui->t_cla_name->clear();
    this->ui->t_cla_monitor->clear();
}

void MainWindow::on_depa_ar_accepted() {
    Department dep(&sqlObj);
    dep.id = this->ui->t_depa_id->text().toStdString();
    dep.name = this->ui->t_depa_name->text().toStdString();
    if (dep.insert())
        ui->statusbar->showMessage("添加成功!");
    else
        ui->statusbar->showMessage("添加失败!");
}

void MainWindow::on_depa_ar_rejected() {
    this->ui->t_depa_id->clear();
    this->ui->t_depa_name->clear();
}

void MainWindow::on_per_ar_accepted() {
    Student stu(&sqlObj);
    stu.id = this->ui->t_id->text().toStdString();
    stu.name = this->ui->t_name->text().toStdString();
    stu.stu_class = this->ui->t_class->text().toStdString();
    stu.sex = this->ui->t_sex->text().toStdString();
    if (stu.sex == "男") {
        stu.sex = "M";
    } else if (stu.sex == "女") {
        stu.sex = "F";
    } else {
        ui->statusbar->showMessage("性别输入错误！");
        return;
    }
    stu.department = this->ui->t_department->text().toStdString();
    stu.native_place = this->ui->t_nactive_place->text().toStdString();
    stu.birthday = this->ui->t_birthday->text().toStdString();
    if (stu.insert())
        ui->statusbar->showMessage("添加成功!");
    else
        ui->statusbar->showMessage("添加失败!");
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
    Change change(&sqlObj);
    change.id = this->ui->t_ch_id->text().toStdString();
    change.change_code = this->ui->t_ch_stuid->text().toStdString();
    change.rec_time = this->ui->t_ch_tm->text().toStdString();
    change.studentid = this->ui->t_ch_stuid->text().toStdString();
    change.description = this->ui->t_ch_des->text().toStdString();
    if (change.insert())
        ui->statusbar->showMessage("添加成功!");
    else
        ui->statusbar->showMessage("添加失败!");
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
    Reward rw(&sqlObj);
    rw.id = this->ui->t_rw_id->text().toStdString();
    rw.reward_code = this->ui->t_rw_lv->text().toStdString();
    rw.rec_time = this->ui->t_rw_tm->text().toStdString();
    rw.description = this->ui->t_rw_des->text().toStdString();
    rw.studentid = this->ui->t_rw_stuid->text().toStdString();
    if (rw.insert())
        ui->statusbar->showMessage("添加成功!");
    else
        ui->statusbar->showMessage("添加失败!");
}

void MainWindow::on_pns_rejected() {
    this->ui->t_pns_id->clear();
    this->ui->t_pns_des->clear();
    this->ui->t_pns_ea->clear();
    this->ui->t_pns_tm->clear();
    this->ui->t_pns_stuid->clear();
}

void MainWindow::on_pns_accepted() {
    Punishment pns(&sqlObj);
    pns.id = this->ui->t_pns_id->text().toStdString();
    pns.punishment_code = this->ui->t_pns_lv->text().toStdString();
    pns.description = this->ui->t_pns_des->text().toStdString();
    pns.enable = this->ui->t_pns_ea->text().toStdString();
    if (pns.enable == "是")
        pns.enable = "T";
    else if (pns.enable == "否")
        pns.enable = "F";
    else {
        ui->statusbar->showMessage("输入有误!");
        return;
    }
    pns.rec_time = this->ui->t_pns_tm->text().toStdString();
    pns.studentid = this->ui->t_pns_stuid->text().toStdString();
    if (pns.insert())
        ui->statusbar->showMessage("添加成功!");
    else
        ui->statusbar->showMessage("添加失败!");
}
