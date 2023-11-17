/* ************************************************************************
> File Name:     student.h
> Author:        rileychc
> mail:          rileychc8@gmail.com
> Created Time:  Mon Nov 13 18:47:36 2023
> Copyright:
> Description:
 ************************************************************************/
#ifndef _STUDENT_H_
#define _STUDENT_H_
#include "BaseCtl.h"
class Student : public BaseCtl {
  public:
    string name;       // 姓名
    string sex;        // 性别
    string stu_class;  // 班级
    string department; // 院系
    string birthday;
    string native_place;      // 籍贯
    string change_code;       // 学籍变动编号
    string reward_levels;     // 奖励编号
    string punishment_levels; // 惩罚编号
    Student(MYSQL *sql) : BaseCtl(sql) {
        tb_name = "student";
        pri_key = "studentid";
    }
    bool insert();
};

#endif // _STUDENT_H_
