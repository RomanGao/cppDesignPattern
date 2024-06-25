/*
访问者模式（Visitor Pattern）是一种行为设计模式，
它使得我们可以在不改变对象结构的前提下定义作用于这些对象上的操作。

主体与行为分离：成员类和动作类，组合关系，通过成员函数参数相互访问。
*/
#include<iostream>
//注意：此处引用的一定是。h文件，而不是.cpp文件
#include"visitor.h"
#include"member.h"
#include<list> //增删效率高
#include<vector> //访问效率高
using namespace std;

//测试类
class CaoMaoTeam
{
public:
    CaoMaoTeam()
    {
        //行为对象不会增删，直接初始化出来
        m_actions.push_back(new Anger);
        m_actions.push_back(new Horror);
    }
    void add(AbstractMember* member)
    {
        m_members.push_back(member);
    }
    void remove(AbstractMember* member)
    {
        m_members.remove(member);
    }
    void display()
    {
        for(const auto &item : m_members)
        {
            int index= rand() % m_actions.size(); //随机选择一个行为
            item->accept(m_actions[index]); //调用行为的visit方法
        }
    }
    ~CaoMaoTeam()
    {
        for(const auto &item : m_members)
        {
            delete item;
        }
        for(const auto &item : m_actions)
        { 
            delete item;
        }
    }
private:
    list<AbstractMember*> m_members; //存储成员
    vector<AbstractAction*> m_actions; //存储行为
};


int main()
{
    srand(time(NULL));
    vector<string> names{"a","b","c","d","e","f","g"};
    CaoMaoTeam* team = new CaoMaoTeam;
    for(const auto& item:names)
    {
        team->add(new MaleMember(item));
    }
    team->add(new FemaleMember("h"));
    team->add(new FemaleMember("k"));
    team->display();
    delete team;
    return 0;
}

