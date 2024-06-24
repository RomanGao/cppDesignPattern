#include<iostream>
#include "state.h"
#include"sanJi.h"
using namespace std;

void ForennoonState::working(SanJi *sanji)
{
    //得到当前的时间
    int time = sanji->getTime();
    //判断时间点
    if(time < 8)
    {
        cout<<"now "<<time<<" clock, do forennoon"<<endl;
    }
    //切换状态
    else if(time >=8 && time <11)
    {
        cout<<"now "<<time<<" clock, prepare to cook"<<endl;
    }
    else
    {
        sanji->setState(new noonState);
        sanji->working();
    }
}

void noonState::working(SanJi *sanji)
{
      //得到当前的时间
    int time = sanji->getTime();
    //判断时间点
    if(time <13)
    {
        cout<<"now "<<time<<" clock, do noot"<<endl;
    }
    else
    {
        sanji->setState(new AfternoonState);
        sanji->working();
    }
}

void AfternoonState::working(SanJi *sanji)
{
      //得到当前的时间
    int time = sanji->getTime();
    //判断时间点
    if(time <15)
    {
        cout<<"now "<<time<<" clock, dring"<<endl;
    }
    else if (time >=15 && time<18)
    {
        cout<<"now "<<time<<" clock, prepare to evening"<<endl;
    }
    else
    {
        sanji->setState(new EveningState);
        sanji->working();
    }
}

void EveningState::working(SanJi *sanji)
{
    //得到当前的时间
    int time = sanji->getTime();
    //判断时间点
    if(time <19)
    {
        cout<<"now "<<time<<" clock, evening"<<endl;
    }
    else
    {
        cout<<"sleeping"<<endl;
    }
}
