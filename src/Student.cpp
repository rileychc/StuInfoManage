/* ************************************************************************
> File Name:     Student.cpp
> Author:        rileychc
> mail:          rileychc8@gmail.com
> Created Time:  Tue Nov 14 00:43:44 2023
> Copyright:
> Description:
 ************************************************************************/
#include "Student.h"

void Student::insert() {
    string ctl = "insert into student values (" + id + ",'" + name + "','" +
                 sex + "'," + stu_class + "," + department + "," + birthday +
                 ",'" + native_place + "');";
    if (mysql_insert(ctl) != 0) {
        cout << "插入成功" << endl;
    } else {
        cout << "插入失败,请确保班级和院校存在或日期正确或性别" << endl;
    }
}
