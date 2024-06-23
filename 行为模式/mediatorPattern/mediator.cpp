/*
中介者模式：

中介者模式定义一个中介对象，该对象通常处理不同类之间的通信，使得对象之间的通信更加容易，并减少系统的耦合度。
*/

#include"mediator.h"
#include"country.h"

void MediatorOrg::addMember(Country* county)
{
    //在添加成员的时候就成员就可以自动绑定终结者
    county->setMediators(this);
    //中介者绑定成员
    m_countryMap.insert(make_pair(county->getName(), county));
}

void WorldGovt::declare(string message, Country* country, string name)
{
    //查看有目的国家是否加入该组织
    if(m_countryMap.find(name)!=m_countryMap.end())
    {
        string str = message+" from [ "+country->getName()+"]";
        
        //将消息转发给目的国家
        m_countryMap[name]->recvMessage(str);
    }
}

void GeMingArmy::declare(string message, Country* country,string name)
{
    //发给处本国外的所有国家
     string str = message+" from [ "+country->getName()+"]";
     for (const auto &item : m_countryMap)
     {
        if(item.second == country)
        {
            continue;
        }
        //发送给所有国家
        item.second->recvMessage(str);
     }
}