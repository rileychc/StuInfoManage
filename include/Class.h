/* ************************************************************************
> File Name:     Class.h
> Author:        rileychc
> mail:          rileychc8@gmail.com
> Created Time:  Tue Nov 14 00:40:43 2023
> Copyright:
> Description:
 ************************************************************************/
#ifndef _CLASS_H_
#define _CLASS_H_
#include "sql.h"
class C_class {
  public:
    string id;
    string name;
    string monitor;

    C_mysql *my;
    C_class(C_mysql *m) { my = m; }
    void mdelete(string &aco, string &tg);
    void insert();
    void select(string &aco, string &tg);
    void update(string &upd, string &updtg, string &aco, string &tg);
};
#endif // _CLASS_H_
