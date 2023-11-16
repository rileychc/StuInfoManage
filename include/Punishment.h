/* ************************************************************************
> File Name:     Punishment.h
> Author:        rileychc
> mail:          rileychc8@gmail.com
> Created Time:  Tue Nov 14 00:42:13 2023
> Copyright:
> Description:
 ************************************************************************/
#ifndef _PUNISHMENT_H_
#define _PUNISHMENT_H_

#include "sql.h"

class Punishment : public BaseCtl {
  public:
    string punishment_code;
    string studentid;
    string rec_time;
    string description;
    string enable;
    Punishment(MYSQL *sql) : BaseCtl(sql) { tb_name = "punishment"; }
    // void mdelete(string &aco, string &tg, string &key, string &keytg);
    void insert();
    // void select(string &aco, string &tg);
    // void update(string &upd, string &updtg, string &aco, string &tg);
};

#endif // _PUNISHMENT_H_
