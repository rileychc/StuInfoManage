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
    string ctl;
    BaseCtl(MYSQL *sql) : mysql(sql) {}
    ~BaseCtl() {}
    bool insert();
    MYSQL_RES *select();
    MYSQL_RES *select(string &tbl, string &slc_dst, string &key_src,
                      string &key_dst);
    bool update(string &upd, string &updtg, string &aco, string &tg);
    bool mdelete(string &aco, string &tg, string &key, string &keytg);
};

#endif // _SQL_H_
