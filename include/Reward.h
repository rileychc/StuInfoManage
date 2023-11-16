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
#include "BaseCtl.h"
class Reward : public BaseCtl {
  public:
    string studentid;
    string reward_code;
    string rec_time;
    string description;
    Reward(MYSQL *sql) : BaseCtl(sql) { tb_name = "reward"; }
    void insert();
};
#endif // _REWARD_H_
