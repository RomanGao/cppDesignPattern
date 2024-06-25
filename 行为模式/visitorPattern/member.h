#pragma once
#include<string>
using namespace std;
//成员类
class AbstractAction;

//成员类的基类
class AbstractMember {
public:
    AbstractMember(string name):m_name(name) {}
    string getName()
    { 
        return m_name;
    }
    //访问接口函数
    virtual void accept(AbstractAction* action) = 0;
    virtual ~AbstractMember() {}
protected:
    string m_name;  //成员的名字
};

//成员函数分类出两个大类：男性，女性
//男性子类
class MaleMember : public AbstractMember {
public:
    using AbstractMember::AbstractMember;
    
    //访问接口函数
    void accept(AbstractAction* action);
};

//女性子类
class FemaleMember: public AbstractMember {
public:
    using AbstractMember::AbstractMember;
    
    //访问接口函数
    void accept(AbstractAction* action);
};