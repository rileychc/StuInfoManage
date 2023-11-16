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
    if (BaseCtl::insert(ctl) != 0) {
        cout << "插入成功" << endl;
    } else {
        cout << "插入失败,班级已存在" << endl;
    }
}
