#include "sanJi.h"
#include <iostream>
using namespace std;

//成员函数赋值优先级
//1、class private在声明时赋值，先被复制
//2、构造函数中的的参数列表
//3、构造函数内
SanJi::SanJi()
{
    m_state = new ForennoonState;
}

void SanJi::working()
{
    cout<<"SanJi is working!"<<endl;
    m_state->working(this);
}

void SanJi::setState(AbstractState *state)
{
    if(m_state!=nullptr)
    {
        delete m_state;
        m_state = nullptr;
    }
    m_state = state;
}

int SanJi::getTime()
{
    return m_time;
}

void SanJi::setTime(int time)
{
    m_time = time;
}
