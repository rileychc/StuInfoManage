#include "mainwindow.h"
#include "sql.h"
#include <QApplication>

MYSQL sqlObj;

int connect() {
    if (!mysql_init(&sqlObj)) { // sqlObj初始化并判断是否出错(返回0为失败)
        printf("mysql_init:%s\n",
               mysql_error(&sqlObj)); // mysql_error() 函数返回上一个sqlObj
                                      // 操作产生的文本错误信息
        return -1;
    }
    if (!mysql_real_connect(
            &sqlObj, KING_DB_SERVER_IP, KING_DB_USERNAME, KING_DB_PASSWORD,
            KING_DB_DEFAULTDB, KING_DB_SERVER_PORT, NULL,
            0)) { // 连接sqlObj数据库，并判断是否出错(返回0为失败)
        printf("mysql_real_connect:%s\n", mysql_error(&sqlObj));
        return -2;
    }
    return 0;
}
// mysql_close(&sqlObj);
int main(int argc, char *argv[]) {
    if (connect() != 0) {
        cout << "数据库连接失败" << endl;
        return -1;
    };
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
