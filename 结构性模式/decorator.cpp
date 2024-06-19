/*
装饰模式（Decorator Pattern）是一种结构型设计模式，
它允许向一个现有的对象添加新的功能，同时又不改变其结构。
这种模式创建了一个装饰类，用来包装原有的类，并在保持类方法签名完整性的前提下，提供了额外的功能。
*/

#include <iostream>
using namespace std;

//战士基类
class Soldier
{
public:
    Soldier(){}
    Soldier(string name):m_name(name){}
    string getName()  {return m_name;}
    //对fight方法进行功能拓展
    virtual void fight() = 0;
    virtual ~Soldier(){}
protected:
    string m_name="";
};
//基类函数有两条分支：1、实例化战士 2、派生出恶魔果实，为战士提供装饰，加强
//黑胡子类
class Teach:public Soldier
{
public:
    using Soldier::Soldier;
    void fight()  
    {cout << "Teach: " << getName() << " to fight!" << endl;}
};
//恶魔果实基类，是一个装饰类，而不是一个战士类
class SoldierDecorator : public Soldier
{
public:
    //为战士添加修饰
    //通过方法传入实体参数
    void enchantment(Soldier* soldier)
    {
        m_soldier = soldier;
        m_name = soldier->getName();
    }
protected:
    Soldier *m_soldier=nullptr;
};
//暗暗果实
class DarknessFruit : public SoldierDecorator
{
public:
    void fight() override
    {
        cout<< getName() << "take Darkness "<< " to fight!" << endl;
        m_soldier->fight();
        warning();
    }
private:
    void warning()
    {
        cout<<getName()<<" Dark stand";
    }
};
//真真果实
class ZhenFruit : public SoldierDecorator
{
public:
    void fight() override
    {
        cout<< getName() << "take zhenzhen "<< " to fight!" << endl;
        m_soldier->fight();
      
    } 
private:
};
//爱爱果实
class AiFruit : public SoldierDecorator
{
public:
    void fight() override
    {
        cout<< getName() << "take aiai "<< " to fight!" << endl;
        m_soldier->fight();
        ability();
    }
    void ability()
    {
        cout<<"can add Ability"<<endl;
    }
};
int main()
{
    //案例，战士在战斗，吃了恶魔果实，提供了新的性能
    Soldier* soldier = new Teach("Tom");
    SoldierDecorator *dark = new DarknessFruit();
    SoldierDecorator* zhen = new ZhenFruit;
    SoldierDecorator* ai = new AiFruit;
    dark->enchantment(soldier);
    zhen->enchantment(dark);  //dark表示吃了暗暗果实的solder
    ai->enchantment(zhen);
    ai->fight();
    delete soldier;
    delete dark;
    delete zhen;
    delete ai;
    return 0;
}
