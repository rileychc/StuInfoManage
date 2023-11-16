#include "depar_wd.h"
#include "Department.h"
#include "ui_depar_wd.h"

// #include
// "/Users/riley/Project/build-StuInfoManage-Desktop-Debug/StuInfoManage_autogen/include/ui_depar_wd.h"

extern C_mysql mysql;

depar_wd::depar_wd(QWidget *parent) : QWidget(parent), ui(new Ui::depar_wd) {
    ui->setupUi(this);
}

depar_wd::~depar_wd() { delete ui; }

void depar_wd::on_tableWidget_entered(const QModelIndex &index) {
    Department c(&mysql);
    string tg = "department";
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
