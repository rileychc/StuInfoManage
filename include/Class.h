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
class C_class : public BaseCtl {
  public:
    string name;
    string monitor;

    C_class(MYSQL *sql) : BaseCtl(sql) { tb_name = "class"; }
    // void mdelete(string &aco, string &tg, string &key, string &keytg);
    void insert();
    // void select(string &aco, string &tg);
    // void update(string &upd, string &updtg, string &aco, string &tg);
};
#endif // _CLASS_H_
