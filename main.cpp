#include "BaseCtl.h"
#include "mainwindow.h"
#include <QApplication>

MYSQL sqlObj; // 声明全局mysqlAPI，方便被调用

int connect() {                 // 执行数据库链接操作
    if (!mysql_init(&sqlObj)) { // 初始化sqlObj
        return -1;
    }
    if (!mysql_real_connect(
            &sqlObj, KING_DB_SERVER_IP, KING_DB_USERNAME, KING_DB_PASSWORD,
            KING_DB_DEFAULTDB, KING_DB_SERVER_PORT, NULL,
            0)) { // 连接sqlObj数据库，并判断是否出错(返回0为失败)
        return -2;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (connect() != 0) {
        cout << mysql_error(&sqlObj) << endl;
        return -1;
    }

    // 创建消息框
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("学生信息管理系统");
    w.show();
    return a.exec();
}
