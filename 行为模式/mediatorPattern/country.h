#pragma once
#include<iostream>
#include"mediator.h"
using namespace std;

//客户类，每个国家都有自己的需求
//基类
class Country 
{
public:
    Country() =default; //添加setMediators方法后，直接可以通过无参构造
    //构造函数就声明，自己的国家加入哪个中介组织
    Country(MediatorOrg *org):m_org(org){}
    //这只终结者对象的函数
    void setMediators(MediatorOrg* org) { m_org = org; }
    //指定声明内容msg和要发布给哪个国家country
    virtual void declare(string msg, string country)=0;
    //接收消息函数
    virtual void recvMessage(string msg) = 0;
    virtual string getName() = 0; //获取国家的名字
    virtual ~Country() {}
protected:
    MediatorOrg* m_org;
};

//国家1
class Alabasta:public Country
{
public:
    using Country::Country;
    Alabasta()=default;
    void declare(string msg, string country) override;
    void recvMessage(string msg) override; //接收中介者发送过来的消息
    string getName() override { return "Alabasta"; }
};

//国家2
class Dressrosa:public Country
{
public:
    using Country::Country;
    Dressrosa()=default;
    void declare(string msg, string country=string()) override;
    void recvMessage(string msg) override; //接收中介者发送过来的消息
    string getName() override { return "Dressrosa"; }
};

//国家3
class Lulusia:public Country
{
public:
    using Country::Country;
    Lulusia()=default;
    void declare(string msg, string country=string()) override;
    void recvMessage(string msg) override; //接收中介者发送过来的消息
    string getName() override { return "Lulusia"; }
};


//国家3
class Kambaka:public Country
{
public:
    using Country::Country;
    Kambaka()=default;
    void declare(string msg, string country=string()) override;
    void recvMessage(string msg) override; //接收中介者发送过来的消息
    string getName() override { return "Kambaka"; }
};

