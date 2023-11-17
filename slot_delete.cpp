#include "mainwindow.h"

void MainWindow::on_del_p_clicked() {
    QTableWidgetItem *item = ui->tableWidget->currentItem();
    if (nullptr == item) {
        return;
    }
    int row = item->row();       // 获取行号
    int column = item->column(); // 获取列号
    QTableWidgetItem *pri_key = ui->tableWidget->item(row, 0);
    string set_src;
    string set_dst = item->text().toStdString(); // 获取更新后的内容
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
        string whe_dst = pri_key->text().toStdString();
        stu.mdelete(set_src, set_dst,
                    whe_dst); // update [table] set tg=text where uptg=uu;
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
            break;
        case 4:
            set_src = "description";
            set_dst = "'" + set_dst + "'";
            break;
        }
        string whe_dst = pri_key->text().toStdString();
        chg.mdelete(set_src, set_dst,
                    whe_dst); // mdelete [table] set tg=text where uptg=uu;
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
            break;
        case 4:
            set_src = "description";
            set_dst = "'" + set_dst + "'";
            break;
        }
        string whe_dst = pri_key->text().toStdString();
        rw.mdelete(set_src, set_dst,
                   whe_dst); // mdelete [table] set tg=text where uptg=uu;
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
        string whe_dst = pri_key->text().toStdString();
        pns.mdelete(set_src, set_dst,
                    whe_dst); // mdelete [table] set tg=text where uptg=uu;
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
        string whe_dst = pri_key->text().toStdString();
        depa.mdelete(set_src, set_dst,
                     whe_dst); // mdelete [table] set tg=text where uptg=uu;
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
        string whe_dst = pri_key->text().toStdString();
        cls.mdelete(set_src, set_dst,
                    whe_dst); // mdelete [table] set tg=text where uptg=uu;
        on_cls__query_p_clicked();
        break;
    }
    }
}
