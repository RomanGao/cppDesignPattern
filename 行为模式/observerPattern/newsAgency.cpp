#include "newsAgency.h"
#include"observer.h"
#include<iostream>
using namespace std;

void NewsAgency::attach(Observer *obs)
{
    m_observers.push_back(obs);
}

void NewsAgency::detach(Observer *obs)
{

    m_observers.remove(obs);
}

void Morgans::notify(string msg)
{
    //把信息发给所有订阅者
    cout<<"Morgans has "<<m_observers.size()<<" subscribers"<<endl;
    for(const auto& item : m_observers)
    {
        //通过观察者更新数据
        item->update(msg);
    }
}

void Gossip::notify(string msg)
{
     //把信息发给所有订阅者
    cout<<"Gossip has "<<m_observers.size()<<" subscribers"<<endl;
    for(const auto& item : m_observers)
    {
        //通过观察者更新数据
        item->update(msg);
    }
}
