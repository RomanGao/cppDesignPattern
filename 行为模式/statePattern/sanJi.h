#pragma once
#include"state.h"

class SanJi
{
public:
    SanJi();
    //工作函数
    void working();
    //切换状态函数
    void setState(AbstractState* state);
    int getTime();
    void setTime(int time);
private:
    AbstractState* m_state=nullptr;
    int m_time=0;
};