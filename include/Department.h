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

class Department {
  public:
    string id;
    string name;
    C_mysql *my;
    Department(C_mysql *m) { my = m; }
    void mdelete(string &aco, string &tg);
    void insert();
    void select(string &aco, string &tg);
    void update(string &upd, string &updtg, string &aco, string &tg);
};

#endif // _DEPARTMENT_H_
