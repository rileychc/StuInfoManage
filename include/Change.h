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

#include "BaseCtl.h"
class Change : public BaseCtl {
  public:
    string studentid;
    string change_code;
    string rec_time;
    string description;
    Change(MYSQL *sql) : BaseCtl(sql) { tb_name = "`change`"; }
    bool insert();
};

#endif // _CHANGE_H_
