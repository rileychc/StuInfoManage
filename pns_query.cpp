#include "pns_query.h"
#include "sql.h"
#include "ui_pns_query.h"

pns_query::pns_query(QWidget *parent) : QWidget(parent), ui(new Ui::pns_query) {
    ui->setupUi(this);
}

pns_query::~pns_query() { delete ui; }
extern C_mysql mysql;
void pns_query::on_tableWidget_entered(const QModelIndex &index) {
    string tg = "punishment";
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
