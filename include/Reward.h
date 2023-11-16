/* ************************************************************************
> File Name:     Reward.h
> Author:        rileychc
> mail:          rileychc8@gmail.com
> Created Time:  Tue Nov 14 00:41:52 2023
> Copyright:
> Description:
 ************************************************************************/
#ifndef _REWARD_H_
#define _REWARD_H_
#include "sql.h"

class Reward {
  public:
    string id;
    string studentid;
    string reward_code;
    string rec_time;
    string description;
    C_mysql *my;
    Reward(C_mysql *m) { my = m; }
    void mdelete(string &aco, string &tg);
    void insert();
    void select(string &aco, string &tg);
    void update(string &upd, string &updtg, string &aco, string &tg);
};
#endif // _REWARD_H_
