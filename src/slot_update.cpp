#include "mainwindow.h"

void MainWindow::on_tableWidget_cellChanged(int row, int column) {
    update_slot();
}
void MainWindow::update_slot() {
    int row = ui->tableWidget->currentRow(); // 这两行是防止死循环的关键
    int column = ui->tableWidget->currentColumn();
    if (column == 0) { // 主键不能直接修改
        ui->statusbar->showMessage("主键单元格无法被修改!");
        return;
    }
    QTableWidgetItem *pri_key_dst = ui->tableWidget->item(row, 0);
    string set_src; // 需要更新的字段名
    string whe_dst; // 主键的值

    if (nullptr == pri_key_dst ||
        nullptr == ui->tableWidget->item(row, column)) {
        return;
    }
    string set_dst = ui->tableWidget->item(row, column)
                         ->text()
                         .toStdString(); // 获取更新后的内容

    bool update_flag = false; // 用于输出更新消息
    switch (tb_select) {
    case 0: {

        Student stu(&sqlObj);
        switch (column) {
        case 0:
            set_src = "studentid";
            break;
        case 1:
            set_src = "name";
            set_dst = "'" + set_dst + "'";
            break;
        case 2:
            if (set_dst == "男") {
                set_dst = "M";
            } else if (set_dst == "女") {
                set_dst = "F";
            } else {
                if (set_src == "sex") {
                    ui->statusbar->showMessage("性别输入错误！");
                    return;
                }
            }
            set_src = "sex";
            set_dst = "'" + set_dst + "'";
            break;
        case 3:
            set_dst = single_query(string("id"), new C_class(&sqlObj),
                                   (ui->tableWidget->item(row, column)), false);
            set_src = "class";
            break;
        case 4:
            set_dst = single_query(string("id"), new Department(&sqlObj),
                                   ui->tableWidget->item(row, column), false);
            set_src = "department";
            break;
        case 5:
            set_src = "birthday";
            stu.date_erase_char(set_dst);
            break;
        case 6:
            set_src = "native_place";
            set_dst = "'" + set_dst + "'";
            break;
        }
        whe_dst = pri_key_dst->text().toStdString();
        if (stu.update(set_src, set_dst, whe_dst))
            update_flag = true;
        on_stu_query_Button_clicked();
        break;
    }
    case 1: {
        Change chg(&sqlObj);
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
            chg.date_erase_char(set_dst);

            break;
        case 4:
            set_src = "description";
            set_dst = "'" + set_dst + "'";
            break;
        default:
            ui->statusbar->showMessage("该单元格不可被修改!");
            return;
        }
        whe_dst = pri_key_dst->text().toStdString();
        if (chg.update(set_src, set_dst, whe_dst))
            update_flag = true; // update [table] set tg=text where uptg=uu;
        on_chg_query_p_clicked();
        break;
    }
    case 2: {

        Reward rw(&sqlObj);
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
            rw.date_erase_char(set_dst);
            break;
        case 4:
            set_src = "description";
            set_dst = "'" + set_dst + "'";
            break;
        default:
            ui->statusbar->showMessage("该单元格不可被修改!");
            return;
        }
        whe_dst = pri_key_dst->text().toStdString();
        if (rw.update(set_src, set_dst, whe_dst))
            update_flag = true; // update [table] set tg=text where uptg=uu;
        on_rw_query_p_clicked();
        break;
    }
    case 3: {
        Punishment pns(&sqlObj);
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
            pns.date_erase_char(set_dst);
            break;
        case 4:
            if (tb_select == 2 && set_dst == "是") {
                set_dst = "T";
            } else if (tb_select == 2 && set_dst == "否") {
                set_dst = "F";
            } else {
                if (tb_select == 2 && set_src == "enable") {
                    ui->statusbar->showMessage("输入错误！");
                    return;
                }
            }
            set_src = "enable";
            set_dst = "'" + set_dst + "'";
            break;
        case 5:
            set_src = "description";
            set_dst = "'" + set_dst + "'";
            break;
        default:
            ui->statusbar->showMessage("该单元格不可被修改!");
            return;
        }
        whe_dst = pri_key_dst->text().toStdString();
        if (pns.update(set_src, set_dst, whe_dst))
            update_flag = true; // update [table] set tg=text where uptg=uu;
        on_pns__query_p_clicked();
        break;
    }
    case 4: {
        Department depa(&sqlObj);
        switch (column) {
        case 0:
            set_src = "id";
            break;
        case 1:
            set_src = "name";
            set_dst = "'" + set_dst + "'";
            break;
        }
        whe_dst = pri_key_dst->text().toStdString();
        if (depa.update(set_src, set_dst, whe_dst))
            update_flag = true; // update [table] set tg=text where uptg=uu;
        on_depa__query_p_clicked();
        break;
    }
    case 5: {
        C_class cls(&sqlObj);
        switch (column) {
        case 0:
            set_src = "id";
            break;
        case 1:
            set_src = "name";
            set_dst = "'" + set_dst + "'";
            break;
        case 2:
            set_src = "monitor";
            break;
        }
        whe_dst = pri_key_dst->text().toStdString();
        if (cls.update(set_src, set_dst, whe_dst))
            update_flag = true; // update [table] set tg=text where uptg=uu;
        on_cls__query_p_clicked();
        break;
    }
    }
    if (!update_flag) {
        ui->statusbar->showMessage("更新成功!", 2000);
    } else {
        ui->statusbar->showMessage("更新失败!", 2000);
    }
}
