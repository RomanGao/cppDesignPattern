#pragma once
#include <string>
#include<list>
using namespace std;

class Observer; //只使用类名，声明就够了
//发布者基类
class NewsAgency 
{
public:
    //添加订阅者
    void attach(Observer* obs);
    //删除订阅者
    void detach(Observer* obs);
    //通知订阅者，给订阅者发送消息
    virtual void notify(string name)=0; //用于多态，纯虚函数，派生类必须重写
    virtual ~NewsAgency() {}
protected:
    list<Observer*> m_observers; //订阅者列表
};


//发布者子类1
class Morgans:public NewsAgency 
{
public:
    //override为了检测与父类书写是否正确
    void notify(string name) override; //用于多态，纯虚函数，派生类必须重写
};

//发布者子类2
class Gossip:public NewsAgency 
{
public:
    //override为了检测与父类书写是否正确
    void notify(string name) override; //用于多态，纯虚函数，派生类必须重写
};