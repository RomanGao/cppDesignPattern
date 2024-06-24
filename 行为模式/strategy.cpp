/*
策略模式
*/
#include<iostream>
using namespace std;

//抽象类
class AbstractStrategy
{
public:
    //战斗
    virtual void fight(bool isfar=false) =0;
    virtual ~AbstractStrategy(){}
};

//子类--一档
class YiDang:public AbstractStrategy
{
public:
    //战斗
    void fight(bool isfar) override
    {
        cout<<"use yi dang: ";
        if(isfar)
        {
            cout<<"fight far"<<endl;
        }
        else
        {
            cout<<"fight near"<<endl;
        }
    }
};

//子类--二档
class ErDang:public AbstractStrategy
{
public:
    //战斗
    void fight(bool isfar) override
    {
        cout<<"use er dang: ";
        if(isfar)
        {
            cout<<"fight far"<<endl;
        }
        else
        {
            cout<<"fight near"<<endl;
        }
    }
};

//子类--san档
class SanDang:public AbstractStrategy
{
public:
    //战斗
    void fight(bool isfar) override
    {
        cout<<"use san  dang: ";
        if(isfar)
        {
            cout<<"fight far"<<endl;
        }
        else
        {
            cout<<"fight near"<<endl;
        }
    }
};

//子类--si档
class SiDang:public AbstractStrategy
{
public:
    //战斗
    void fight(bool isfar) override
    {
        cout<<"use Si dang: ";
        if(isfar)
        {
            cout<<"fight far"<<endl;
        }
        else
        {
            cout<<"fight near"<<endl;
        }
    }
};

//子类--wu档
class WuDang:public AbstractStrategy
{
public:
    //战斗
    void fight(bool isfar) override
    {
        cout<<"use Wu dang: go go go!"<<endl;
    }
};

//实体类，将策略类使用起来
enum class Level:char{EASY, NORMAL, HARD,EXPERT,PROFESSIONAL};
class Luffy
{
public:
    void fight(Level level, bool isfar = false)
    {
        if(m_strategy != nullptr)
        {
            delete m_strategy;
            m_strategy=nullptr;
        }
        switch (level)
        {
        case Level::EASY:
            m_strategy=new YiDang();
            break;
        case Level::NORMAL:
            m_strategy=new ErDang();
            break;
        case Level::HARD:
            m_strategy=new SanDang();
            break;
        case Level::EXPERT:
            m_strategy=new SiDang();
            break;
        case Level::PROFESSIONAL:
            m_strategy=new WuDang();
            break; 
        default:
            break;
        }
        if(m_strategy)
            m_strategy->fight(isfar);
    }
    ~Luffy()
    {
        if(m_strategy != nullptr)
            delete m_strategy;
    }
private:
    AbstractStrategy* m_strategy=nullptr;
};

int main()
{   
    Luffy* luff = new Luffy;
    luff->fight(Level::EASY, true);
    luff->fight(Level::NORMAL, false);
    luff->fight(Level::HARD, true);
    luff->fight(Level::PROFESSIONAL);
    luff->fight(Level::EXPERT, false);
    delete luff;
    return 0;
}