/* ************************************************************************
> File Name:     Change.h
> Author:        rileychc
> mail:          rileychc8@gmail.com
> Created Time:  Tue Nov 14 00:41:09 2023
> Copyright:
> Description:
 ************************************************************************/
#ifndef _CHANGE_H_
#define _CHANGE_H_

#include "sql.h"

class Change {
  public:
    string id;
    string studentid;
    string change_code;
    string rec_time;
    string description;

    C_mysql *my;
    Change(C_mysql *m) { my = m; }

    void mdelete(string &aco, string &tg, string &key, string &keytg);
    void insert();
    void select(string &aco, string &tg);
    void update(string &upd, string &updtg, string &aco, string &tg);
};

#endif // _CHANGE_H_
