/* ************************************************************************
> File Name:     sql.cpp
> Author:        rileychc
> mail:          rileychc8@gmail.com
> Created Time:  Mon Nov 13 15:59:11 2023
> Copyright:
> Description:
 ************************************************************************/
#include "sql.h"

int C_mysql::connect() {
    if (!mysql_init(&mysql)) { // mysql初始化并判断是否出错(返回0为失败)
        printf("mysql_init:%s\n",
               mysql_error(&mysql)); // mysql_error() 函数返回上一个 MySQL
                                     // 操作产生的文本错误信息
        return -1;
    }
    if (!mysql_real_connect(
            &mysql, KING_DB_SERVER_IP, KING_DB_USERNAME, KING_DB_PASSWORD,
            KING_DB_DEFAULTDB, KING_DB_SERVER_PORT, NULL,
            0)) { // 连接mysql数据库，并判断是否出错(返回0为失败)
        printf("mysql_real_connect:%s\n", mysql_error(&mysql));
        return -2;
    }
    return 0;
}
int C_mysql::mysql_insert(string &ctl) {

    if (mysql_real_query(&mysql, ctl.c_str(),
                         ctl.length())) { //(返回0为成功)
        printf("mysql_real_query:%s\n", mysql_error(&mysql));
        return 0;
    }
    return -1;
}
MYSQL_RES *C_mysql::mysql_select(string &ctl) {
    // mysql_real_query--->sql
    if (mysql_real_query(&mysql, ctl.c_str(),
                         ctl.length())) { //(返回0为成功)
        printf("mysql_real_query:%s\n", mysql_error(&mysql));
        return nullptr;
    }
    // store
    // 当查询语句执行完之后，数据就已经接收到了管道的数据（mysql服务器发送的）,因此要存储起来
    MYSQL_RES *res = mysql_store_result(&mysql);
    if (res == nullptr) {
        printf("mysql_store_result:%s\n", mysql_error(&mysql));
        return nullptr;
    }
    // rows/fields  行/列
    // int rows = mysql_num_rows(res);
    // printf("rows:%d\n", rows);
    // int fields = mysql_num_fields(res);
    // printf("fields:%d\n", fields);
    // fetch
    // MYSQL_ROW row; // 定义一行的数据

    // while ((row = mysql_fetch_row(res)) != NULL) {
    //     for (int i = 0; i < fields; i++) {
    //         printf("%s\t", row[i]);
    //     }
    //     printf("\n");
    // }

    // mysql_free_result(res);
    return res;
}
MYSQL_RES *C_mysql::select(string &tbl) {

    string ctl = "select * from " + tbl + ";";
    if (mysql_real_query(&mysql, ctl.c_str(),
                         ctl.length())) { //(返回0为成功)
        printf("mysql_real_query:%s\n", mysql_error(&mysql));
        return nullptr;
    }
    // store
    // 当查询语句执行完之后，数据就已经接收到了管道的数据（mysql服务器发送的）,因此要存储起来
    MYSQL_RES *res = mysql_store_result(&mysql);
    if (res == nullptr) {
        printf("mysql_store_result:%s\n", mysql_error(&mysql));
        return nullptr;
    }
    return res;
}

int C_mysql::mysql_delete(string &ctl) {
    if (mysql_real_query(&mysql, ctl.c_str(),
                         ctl.length())) { //(返回0为成功)
        printf("mysql_real_query:%s\n", mysql_error(&mysql));
        return 0;
    }
    return -1;
}
int C_mysql::mysql_update(string &ctl) {
    if (mysql_real_query(&mysql, ctl.c_str(),
                         ctl.length())) { //(返回0为成功)
        printf("mysql_real_query:%s\n", mysql_error(&mysql));
        return 0;
    }
    return -1;
}
