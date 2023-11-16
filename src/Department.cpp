/* ************************************************************************
> File Name:     Department.cpp
> Author:        rileychc
> mail:          rileychc8@gmail.com
> Created Time:  Tue Nov 14 00:50:21 2023
> Copyright:
> Description:
 ************************************************************************/
#include "Department.h"
void Department::insert() {
    string ctl = "insert into department values (" + id + ",'" + name + "');";
    if (mysql_insert(ctl) != 0) {
        cout << "插入成功" << endl;
    } else {
        cout << "插入失败,院校已存在" << endl;
    }
}
