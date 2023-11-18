#include "Change.h"
#include "Class.h"
#include "Department.h"
#include "Punishment.h"
#include "Reward.h"
#include "Student.h"

bool C_class::insert() {
    ctl =
        "insert into class values (" + id + ",'" + name + "'," + monitor + ");";

    cout << "ctl为:" << ctl << endl;
    return BaseCtl::insert(); // 调用父类insert个性化
}

bool Change::insert() {
    this->date_erase_char(rec_time);
    ctl = "insert into `change` values (" + id + "," + studentid + "," +
          change_code + "," + rec_time + ",'" + description + "');";
    return BaseCtl::insert();
}

bool Department::insert() {
    ctl = "insert into department values (" + id + ",'" + name + "');";
    return BaseCtl::insert();
}

bool Punishment::insert() {

    this->date_erase_char(rec_time);
    ctl = "insert into punishment values (" + id + "," + studentid + "," +
          punishment_code + "," + rec_time + ",'" + enable + "','" +
          description + "');";

    return BaseCtl::insert();
}

bool Reward::insert() {
    this->date_erase_char(rec_time);

    ctl = "insert into reward values (" + id + "," + studentid + "," +
          reward_code + "," + rec_time + ",'" + description + "');";

    return BaseCtl::insert();
}

bool Student::insert() {
    this->date_erase_char(birthday);
    ctl = "insert into student values (" + id + ",'" + name + "','" + sex +
          "'," + stu_class + "," + department + "," + birthday + ",'" +
          native_place + "');";
    return BaseCtl::insert();
}
