/* ************************************************************************
> File Name:     Class.cpp
> Author:        rileychc
> mail:          rileychc8@gmail.com
> Created Time:  Tue Nov 14 00:46:23 2023
> Copyright:
> Description:
 ************************************************************************/

#include "Class.h"

void C_class::insert() {
    string ctl =
        "insert into class values (" + id + ",'" + name + "'," + monitor + ");";
    cout << "ctl为:" << ctl << endl;
    if (my->mysql_insert(ctl) != 0) {
        cout << "插入成功" << endl;
    } else {
        cout << "插入失败,班级已存在" << endl;
    }
}
void C_class::select(string &aco, string &tg) { // 根据哪个字段查询,目标值是多少
    string ctl = "select * from class where " + aco + "=" + tg + ";";
    auto res = my->mysql_select(ctl);
    if (res == nullptr) {
        cout << "查询不存在" << endl;
    } else {
        // rows/fields  行/列
        int rows = mysql_num_rows(res);
        printf("rows:%d\n", rows);
        int fields = mysql_num_fields(res);
        printf("fields:%d\n", fields);
        // fetch
        MYSQL_ROW row = mysql_fetch_row(res); // 定义一行的数据
                                              // 处理结果
        while (row != nullptr) {
            for (int i = 0; i < fields; i++) {
                printf("%s\t", row[i]);
            }
            printf("\n");
            row = mysql_fetch_row(res);
        }
        mysql_free_result(res);
    }
}
void C_class::mdelete(string &aco, string &tg) {
    string ctl = "delete from class where " + aco + "=" + tg + ";";
    if (my->mysql_select(ctl) == 0) {
        cout << "删除成功" << endl;
    } else {
        cout << "删除失败" << endl;
    }
}

void C_class::update(string &upd, string &updtg, string &aco, string &tg) {

    string ctl = "update class set " + upd + "=" + updtg + "  where " + aco +
                 "=" + tg + ";";
    if (my->mysql_update(ctl) == 0)
        cout << "数据更新成功！" << endl;
    else {
        cout << "数据更新失败！" << endl;
    };
}
