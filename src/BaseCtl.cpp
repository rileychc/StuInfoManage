/* ************************************************************************
> File Name:     sql.cpp
> Author:        rileychc
> mail:          rileychc8@gmail.com
> Created Time:  Mon Nov 13 15:59:11 2023
> Copyright:
> Description:
 ************************************************************************/
#include "BaseCtl.h"
#include <QMessageBox>

void BaseCtl::date_erase_char(string &str) {
    std::string target = "-";
    std::string::size_type pos = 0;
    while ((pos = str.find(target, pos)) != std::string::npos) {
        str.erase(pos, target.length());
    }
}

bool BaseCtl::insert() {
    if (mysql_real_query(mysql, ctl.c_str(),
                         ctl.length())) { //(返回0为成功)
        cout << mysql_error(mysql) << endl;

        return false;
    }
    cout << "插入成功!" << endl;
    return true;
}

MYSQL_RES *BaseCtl::select(string &slc_dst, string &key_dst) {
    ctl = "select " + slc_dst + " from " + tb_name + " where " + pri_key +
          " = " + key_dst + ";";
    cout << "执行的操作是" << ctl << endl;

    if (mysql_real_query(mysql, ctl.c_str(), ctl.length())) {
        cout << mysql_error(mysql) << endl;
        return nullptr;
    }
    // store
    MYSQL_RES *res = mysql_store_result(mysql);
    if (res == nullptr) {
        cout << mysql_error(mysql) << endl;
        return nullptr;
    }
    return res;
}
MYSQL_RES *BaseCtl::select() {

    ctl = "select * from " + tb_name + ";";
    cout << "执行的操作是" << ctl << endl;
    if (mysql_real_query(mysql, ctl.c_str(), ctl.length())) {
        cout << mysql_error(mysql) << endl;
        return nullptr;
    }
    // store
    MYSQL_RES *res = mysql_store_result(mysql);
    if (res == nullptr) {
        cout << mysql_error(mysql) << endl;
        return nullptr;
    }
    return res;
}

bool BaseCtl::update(string &upd, string &updtg, string &tg) {

    ctl = "update " + tb_name + " set " + upd + "=" + updtg + "  where " +
          pri_key + "=" + tg + ";";
    cout << "执行的操作是" << ctl << endl;

    if (0 == mysql_real_query(mysql, ctl.c_str(), ctl.length())) {
        cout << mysql_error(mysql) << endl;
        return false;
    }
    return true;
}

bool BaseCtl::mdelete(string &aco, string &tg, string &keytg) {

    ctl = "delete from " + tb_name + "  where " + aco + "=" + tg + " and " +
          pri_key + "= " + keytg + ";";

    cout << "执行的操作是" << ctl << endl;
    if (0 == mysql_real_query(mysql, ctl.c_str(), ctl.length())) {
        cout << mysql_error(mysql) << endl;
        return false;
    }
    return true;
}
