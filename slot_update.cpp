#include "mainwindow.h"

void MainWindow::on_tableWidget_cellChanged(int row, int column) {
    QTableWidgetItem *pri_key = ui->tableWidget->item(row, 0);
    string set_src;
    string set_dst = ui->tableWidget->item(row, column)
                         ->text()
                         .toStdString(); // 获取更新后的内容
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
        string whe_src = "studentid";
        string whe_dst = pri_key->text().toStdString();
        stu.update(set_src, set_dst, whe_src,
                   whe_dst); // update [table] set tg=text where uptg=uu;
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
        string whe_src = "id";
        string whe_dst = pri_key->text().toStdString();
        chg.update(set_src, set_dst, whe_src,
                   whe_dst); // update [table] set tg=text where uptg=uu;
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
        string whe_src = "id";
        string whe_dst = pri_key->text().toStdString();
        rw.update(set_src, set_dst, whe_src,
                  whe_dst); // update [table] set tg=text where uptg=uu;
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
        string whe_src = "id";
        string whe_dst = pri_key->text().toStdString();
        pns.update(set_src, set_dst, whe_src,
                   whe_dst); // update [table] set tg=text where uptg=uu;
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
        string whe_src = "id";
        string whe_dst = pri_key->text().toStdString();
        depa.update(set_src, set_dst, whe_src,
                    whe_dst); // update [table] set tg=text where uptg=uu;
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
        }
        string whe_src = "id";
        string whe_dst = pri_key->text().toStdString();
        cls.update(set_src, set_dst, whe_src,
                   whe_dst); // update [table] set tg=text where uptg=uu;
        break;
    }
    }
}
