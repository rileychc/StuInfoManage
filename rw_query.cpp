#include "rw_query.h"
#include "sql.h"
#include "ui_rw_query.h"
rw_query::rw_query(QWidget *parent) : QWidget(parent), ui(new Ui::rw_query) {
    ui->setupUi(this);
}

rw_query::~rw_query() { delete ui; }
extern C_mysql mysql;
void rw_query::on_tableWidget_entered(const QModelIndex &index) {
    string tg = "reward";
    auto res = mysql.select(tg);
    // rows/fields  行/列
    // int rows = mysql_num_rows(res);
    int fields = mysql_num_fields(res);
    // fetch
    MYSQL_ROW row; // 定义一行的数据
    int j = 0;
    while ((row = mysql_fetch_row(res)) != NULL) {
        for (int i = 0; i < fields; i++) {

            // printf("%s\t", row[i]);
            ui->tableWidget->setItem(j, i, new QTableWidgetItem(row[i]));
        }
        // printf("\n");
        j++;
    }
    mysql_free_result(res);
}
