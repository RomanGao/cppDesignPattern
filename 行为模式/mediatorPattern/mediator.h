#pragma once
#include<string>
#include<map>
using namespace std;

class Country;
//中介者类的基类
class MediatorOrg
{
public:
    void addMember(Country *country);
    //发布声明，参数分别为：消息，发送过对象，接收国名字
    virtual void declare(string msg, Country* country, string name)=0;
    virtual ~MediatorOrg(){}
protected:
    //国家名字，国家实例对象
    map<string, Country*> m_countryMap; 
};

//世界政府
class WorldGovt:public MediatorOrg
{
public:
    void declare(string message, Country* country,string name) override;

};

//革命军
class GeMingArmy:public MediatorOrg
{
public:
    void declare(string message, Country* country,string name) override;

};
