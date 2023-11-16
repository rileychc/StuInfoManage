#include "chg_query.h"
#include "sql.h"
#include "ui_chg_query.h"

chg_query::chg_query(QWidget *parent) : QWidget(parent), ui(new Ui::chg_query) {
    ui->setupUi(this);
}

chg_query::~chg_query() { delete ui; }
extern C_mysql mysql;
void chg_query::on_tableWidget_entered(const QModelIndex &index) {

    string tg = "`change`";
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
