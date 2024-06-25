/*
模版方法模型

模版方法模式是一种行为型设计模式，它定义一个操作中的算法的骨架，而将一些步骤延迟到子类中，使得子类可以不改变一个算法的结构即可重定义该算法的某些特定步骤。
*/
#include<iostream>
using namespace std;

//抽象机器人类
class AbstractRobot
{
public:
    //武器
    virtual void weapon() = 0;
    //外观
    virtual void appearance() = 0;
    //战斗能力
    virtual void fightAbility() = 0;
    //名字
    virtual string getName() = 0;
    //自愈能力
    virtual void selfHealing(){} //子类中不是必须拥有的功能，就不用写成纯虚函数，这样子类中不需要必须重写
    //是否能飞
    virtual bool canFly() { return false; } //子类中可以选择性重写，也可以不重写，默认返回false
    //是否可以自动控制
    virtual bool isAutoControl() { return true; }
    //当前机器人属性
    virtual void getProperty()
    {
        cout<<"Robot "<<getName()<<" 's attrubte:"<<endl;
        if(canFly())
        {
            cout<<"It can fly. ";
        }
        else
        {
            cout<<"It cannot fly. ";
        }
        cout<<endl;
        if (isAutoControl())
        {
            cout<<"It can be controlled automatically. ";
        }
        else
        {
            cout<<"It needs human intervention. ";
        }
        cout<<endl;
        weapon();   
        appearance();   
        fightAbility();
        selfHealing();
    }
    virtual ~AbstractRobot(){}
};

//派生类1
class Pacifist: public AbstractRobot
{
public:
    //武器
     void weapon() override
     {
        cout<<"ji guang"<<endl;
     }
    //外观
    void appearance() override
    {
        cout<<"da er duo"<<endl;
    }
    //战斗能力
    void fightAbility() override
    {
        cout<<"kang zou"<<endl;
    }
    //名字
    string getName() override
    {
        return "Pacifist";
    }
};

//派生类2
class Angel: public AbstractRobot
{
public:
    //武器
     void weapon() override
     {
        cout<<"da jian "<<endl;
     }
    //外观
    void appearance() override
    {
        cout<<"you da zhi bang"<<endl;
    }
    //战斗能力
    void fightAbility()override
    {
        cout<<"fa she ji kuang ....."<<endl;
    }
    //名字
    string getName() override
    {
        return "Angel";
    }
    //自愈能力
   void selfHealing() override
   {
        cout<<"can self headling"<<endl;
   }
   bool canFly() override
   {
    return true;
   }
};


int main()
{
    AbstractRobot *robot = new Pacifist;
    robot->getProperty();
    delete robot;
    cout<<"================"<<endl;
    robot = new Angel;
    robot->getProperty();
    delete robot;
}