/* ************************************************************************
> File Name:     sql.cpp
> Author:        rileychc
> mail:          rileychc8@gmail.com
> Created Time:  Mon Nov 13 15:59:11 2023
> Copyright:
> Description:
 ************************************************************************/
#include "BaseCtl.h"

int BaseCtl::insert(string &ctl) {

    if (mysql_real_query(mysql, ctl.c_str(),
                         ctl.length())) { //(返回0为成功)
        printf("mysql_real_query:%s\n", mysql_error(mysql));
        return 0;
    }
    return -1;
}

MYSQL_RES *BaseCtl::select(string &tbl) {

    string ctl = "select * from " + tbl + ";";
    if (mysql_real_query(mysql, ctl.c_str(),
                         ctl.length())) { //(返回0为成功)
        printf("mysql_real_query:%s\n", mysql_error(mysql));
        return nullptr;
    }
    // store
    // 当查询语句执行完之后，数据就已经接收到了管道的数据（mysql服务器发送的）,因此要存储起来

    MYSQL_RES *res = mysql_store_result(mysql);
    if (res == nullptr) {
        printf("mysql_store_result:%s\n", mysql_error(mysql));
        return nullptr;
    }
    return res;
}

void BaseCtl::update(string &upd, string &updtg, string &aco, string &tg) {

    string ctl = "update " + tb_name + " set " + upd + "=" + updtg +
                 "  where " + aco + "=" + tg + ";";
    cout << "执行的操作是" << ctl << endl;

    if (0 == mysql_real_query(mysql, ctl.c_str(),
                              ctl.length())) { //(返回0为成功)
        printf("mysql_real_query:%s\n", mysql_error(mysql));
    }
}

void BaseCtl::mdelete(string &aco, string &tg, string &key, string &keytg) {

    string ctl = "delete from" + tb_name + "  where " + aco + "=" + tg +
                 " and " + key + "= " + keytg + ";";

    cout << "执行的操作是" << ctl << endl;
    if (0 == mysql_real_query(mysql, ctl.c_str(),
                              ctl.length())) { //(返回0为成功)
        printf("mysql_real_query:%s\n", mysql_error(mysql));
    }
}

// void BaseCtl::select(string &aco, string &tg) { //
// 根据哪个字段查询,目标值是多少
//     string ctl = "select * from " + tb_name + " where " + aco + "=" + tg +
//     ";";

//     cout << "执行的操作是" << ctl << endl;
//     auto res = mysql_select(ctl);
//     if (res == nullptr) {
//         cout << "查询不存在" << endl;
//     } else {
//         // rows/fields  行/列
//         int rows = mysql_num_rows(res);
//         printf("rows:%d\n", rows);
//         int fields = mysql_num_fields(res);
//         printf("fields:%d\n", fields);
//         // fetch
//         MYSQL_ROW row = mysql_fetch_row(res); // 定义一行的数据
//                                               // 处理结果
//         while (row != nullptr) {
//             for (int i = 0; i < fields; i++) {
//                 printf("%s\t", row[i]);
//             }
//             printf("\n");
//             row = mysql_fetch_row(res);
//         }
//         mysql_free_result(res);
//     }
// }
// MYSQL_RES *BaseCtl::mysql_select(string &ctl) {
//     // mysql_real_query--->sql
//     if (mysql_real_query(mysql, ctl.c_str(),
//                          ctl.length())) { //(ËøîÂõû0‰∏∫ÊàêÂäü)
//         printf("mysql_real_query:%s\n", mysql_error(mysql));
//         return nullptr;
//     }
//     // store
//     //
//     ÂΩÊü•ËØ¢ËØ≠Âè•ÊâßË°åÂÆå‰πãÂêéÔºåÊï∞ÊçÆÂ∞±Â∑≤ÁªèÊé•Êî∂Âà∞‰∫ÜÁÆ°ÈÅìÁöÑÊï∞ÊçÆÔºàmysqlÊúçÂä°Âô®ÂèëÈÄÅÁöÑÔºâ,Âõ†Ê≠§Ë¶ÅÂ≠òÂÇ®Ëµ∑Êù•
//     MYSQL_RES *res = mysql_store_result(mysql);
//     if (res == nullptr) {
//         printf("mysql_store_result:%s\n", mysql_error(mysql));
//         return nullptr;
//     }
//     // rows/fields  Ë°å/Âàó
//     // int rows = mysql_num_rows(res);
//     // printf("rows:%d\n", rows);
//     // int fields = mysql_num_fields(res);
//     // printf("fields:%d\n", fields);
//     // fetch
//     // MYSQL_ROW row; // ÂÆö‰πâ‰∏ÄË°åÁöÑÊï∞ÊçÆ

//     // while ((row = mysql_fetch_row(res)) != NULL) {
//     //     for (int i = 0; i < fields; i++) {
//     //         printf("%s\t", row[i]);
//     //     }
//     //     printf("\n");
//     // }

//     // mysql_free_result(res);
//     return res;
// }
