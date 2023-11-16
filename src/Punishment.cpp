/* ************************************************************************
> File Name:     Punishment.cpp
> Author:        rileychc
> mail:          rileychc8@gmail.com
> Created Time:  Tue Nov 14 00:51:12 2023
> Copyright:
> Description:
 ************************************************************************/
#include "Punishment.h"

void Punishment::insert() {
    string ctl = "insert into punishment values (" + id + "," + studentid +
                 "," + punishment_code + "," + rec_time + ",'" + enable +
                 "','" + description + "');";
    if (BaseCtl::insert(ctl) != 0) {
        cout << "插入成功" << endl;
    } else {
        cout << "插入失败,请确保学生存在或日期正确或生效是否为TF" << endl;
    }
}
