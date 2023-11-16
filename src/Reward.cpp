/* ************************************************************************
> File Name:     Reward.cpp
> Author:        rileychc
> mail:          rileychc8@gmail.com
> Created Time:  Tue Nov 14 00:51:44 2023
> Copyright:
> Description:
 ************************************************************************/
#include "Reward.h"

void Reward::insert() {
    string ctl = "insert into reward values (" + id + "," + studentid + "," +
                 reward_code + "," + rec_time + ",'" + description + "');";
    if (mysql_insert(ctl) != 0) {
        cout << "插入成功" << endl;
    } else {
        cout << "插入失败,请确保学生存在或日期正确" << endl;
    }
}
