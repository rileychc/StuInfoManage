/* ************************************************************************
> File Name:     sql.h
> Author:        rileychc
> mail:          rileychc8@gmail.com
> Created Time:  Mon Nov 13 19:55:55 2023
> Copyright:
> Description:
 ************************************************************************/
#ifndef _SQL_H_
#define _SQL_H_
#include "mysql.h"
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

#define KING_DB_SERVER_IP "221.7.223.67"        // ip
#define KING_DB_SERVER_PORT 8003                // 端口号
#define KING_DB_USERNAME "root"                 // 用户名
#define KING_DB_PASSWORD "rijwiC-3kirnu-porpyx" // 密码
#define KING_DB_DEFAULTDB "stu_info_manage"     // 数据库名

class BaseCtl {

  public:
    MYSQL *mysql;
    string id;
    string tb_name;
    BaseCtl(MYSQL *sql) : mysql(sql) {}
    ~BaseCtl() {}
    // int connect();
    int mysql_insert(string &ctl);
    // int mysql_update(string &ctl);
    // int mysql_delete(string &ctl);
    // MYSQL_RES *mysql_select(string &ctl);
    MYSQL_RES *select(string &tbl);
    void update(string &upd, string &updtg, string &aco, string &tg);
    void mdelete(string &aco, string &tg, string &key, string &keytg);
    void select(string &aco, string &tg);
};

#endif // _SQL_H_
