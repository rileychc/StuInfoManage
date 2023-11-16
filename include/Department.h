/* ************************************************************************
> File Name:     Department.h
> Author:        rileychc
> mail:          rileychc8@gmail.com
> Created Time:  Tue Nov 14 00:38:20 2023
> Copyright:
> Description:
 ************************************************************************/
#ifndef _DEPARTMENT_H_
#define _DEPARTMENT_H_

#include "sql.h"

class Department : public BaseCtl {
  public:
    string name;
    Department(MYSQL *sql) : BaseCtl(sql) { tb_name = "department"; }
    // void mdelete(string &aco, string &tg, string &key, string &keytg);
    void insert();
    // void select(string &aco, string &tg);
    // void update(string &upd, string &updtg, string &aco, string &tg);
};

#endif // _DEPARTMENT_H_
