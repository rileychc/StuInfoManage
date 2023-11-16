/* ************************************************************************
> File Name:     Change.cpp
> Author:        rileychc
> mail:          rileychc8@gmail.com
> Created Time:  Tue Nov 14 00:48:55 2023
> Copyright:
> Description:
 ************************************************************************/
#include "Change.h"

void Change::insert() {
    string ctl = "insert into `change` values (" + id + "," + studentid + "," +
                 change_code + "," + rec_time + ",'" + description + "');";
    if (BaseCtl::insert(ctl) != 0) {
        cout << "插入成功" << endl;
    } else {
        cout << "插入失败,请确保学生存在或日期正确" << endl;
    }
}
