#pragma once
#include<string>
#include<iostream>
#include"newsAgency.h"
using namespace std;

//抽象的观察者类
class Observer
{
public:
    //和发布者构件关联 --- 可通过构造函数实现
    Observer(NewsAgency *news, string name):m_news(news), m_name(name) //参数写在这里是初始化操作
    {
        /*参数写到这个位置就是赋值操作*/
        
        m_news->attach(this);
    };
    //和发布者解除关联  -- 取消订阅
    void unsubscribe()
    {
        m_news->detach(this);
    }
    //更新消息
    virtual void update(string msg)=0;

    virtual ~Observer(){}
protected:
    NewsAgency* m_news;
    string m_name;
};


//观察者类子类1
class Dragon:public Observer
{
public:
    using Observer::Observer;
    void update(string msg) override
    {
        cout<<"Dragon recv: "<<msg<<endl;
    }
};

//观察者类子类2
class Shanks:public Observer
{
public:
    using Observer::Observer;
    void update(string msg) override
    {
        cout<<"Shanks recv: "<<msg<<endl;
    }
};

//观察者类子类3
class Battery:public Observer
{
public:
    using Observer::Observer;
    void update(string msg) override
    {
        cout<<"Battery recv: "<<msg<<endl;
    }
};