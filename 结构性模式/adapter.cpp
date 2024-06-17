/*
适配器模式
*/

#include<iostream>
using namespace std;

#if 0
//适配器类与外国人类、熊猫类均为关联关系
//外国人类
class Foreigner
{
public:
    virtual string confession()=0;
    void setResult(string res)
    {
        cout<<"Foreigner Recv: "<<res<<endl;
    }
    virtual ~Foreigner(){}
};
//两个子类
//1 美国人
class American:public Foreigner
{
public:
    string confession()
    {
        return "American has trush";
    }
};
//2 法国人
class French:public Foreigner
{
public:
    string confession()
    {
        return "French has trush";
    }
};
//熊猫类
class Pandas
{
public:
    void recvMsg(string msg)
    {
        cout<<"Pandas recv:"<<msg<<endl;
    }
    string sendMsg()
    {
        return string("can not forgive");
    }
};

//适配器类
class AbstractChopper
{
public:
    AbstractChopper(Foreigner* foreigner):m_foreigner(foreigner)
    {}
    virtual void translate2Panda()=0;
    virtual void translate2Human()=0;
    virtual ~AbstractChopper(){}
protected: //私有成员不能被子类继承
    //熊猫类和外国人类均为关联关系
    Foreigner *m_foreigner; 
    Pandas m_panda;
};
//根据关联关系，定义两个子类
class EnglishChopper:public AbstractChopper
{
public:
    //继承了父类中定义的所有构造函数
    using AbstractChopper::AbstractChopper;
    /*
    子类继承父类构造函数案例
    //子类的构造函数通过初始化列表调用父类的构造函数
    Child(int parentValue, int childValue) : Parent(parentValue), m_childValue(childValue) {
        std::cout << "Child constructor called with child value: " << m_childValue << std::endl;
    }
    */
    void translate2Panda()
    {
        string msg = m_foreigner->confession();
        //解析语言
        m_panda.recvMsg("English say:"+msg);
    }
    void translate2Human()
    {
       string msg = m_panda.sendMsg();
       m_foreigner->setResult("English recv: "+msg);
    }
};

class FrenchChopper:public AbstractChopper
{
public:
    //继承了父类中定义的所有构造函数
    using AbstractChopper::AbstractChopper;

    void translate2Panda()
    {
        string msg = m_foreigner->confession();
        //解析语言
        m_panda.recvMsg("French say:"+msg);
    }
    void translate2Human()
    {
       string msg = m_panda.sendMsg();
       m_foreigner->setResult("Fresh recv: "+msg);
    }
};
#endif

#if 1
//适配器类和熊猫类是继承关系，与外国人类是关联关系
//适配器类与外国人类、熊猫类均为关联关系
//外国人类
class Foreigner
{
public:
    virtual string confession()=0;
    void setResult(string res)
    {
        cout<<"Foreigner Recv: "<<res<<endl;
    }
    virtual ~Foreigner(){}
};
//两个子类
//1 美国人
class American:public Foreigner
{
public:
    string confession()
    {
        return "American has trush";
    }
};
//2 法国人
class French:public Foreigner
{
public:
    string confession()
    {
        return "French has trush";
    }
};
//熊猫类
class Pandas
{
public:
    void recvMsg(string msg)
    {
        cout<<"Pandas recv:"<<msg<<endl;
    }
    string sendMsg()
    {
        return string("can not forgive");
    }
};

//适配器类
class AbstractChopper:public Pandas
{
public:
    AbstractChopper(Foreigner* foreigner):m_foreigner(foreigner)
    {}
    virtual void translate2Panda()=0;
    virtual void translate2Human()=0;
    virtual ~AbstractChopper(){}
protected: //私有成员不能被子类继承
    //熊猫类和外国人类均为关联关系
    Foreigner *m_foreigner; 
};
//根据关联关系，定义两个子类
class EnglishChopper:public AbstractChopper
{
public:
    //继承了父类中定义的所有构造函数
    using AbstractChopper::AbstractChopper;
    /*
    子类继承父类构造函数案例
    //子类的构造函数通过初始化列表调用父类的构造函数
    Child(int parentValue, int childValue) : Parent(parentValue), m_childValue(childValue) {
        std::cout << "Child constructor called with child value: " << m_childValue << std::endl;
    }
    */
    void translate2Panda()
    {
        string msg = m_foreigner->confession();
        //解析语言
        recvMsg("English say:"+msg);
    }
    void translate2Human()
    {
       string msg = sendMsg();
       m_foreigner->setResult("English recv: "+msg);
    }
};

class FrenchChopper:public AbstractChopper
{
public:
    //继承了父类中定义的所有构造函数
    using AbstractChopper::AbstractChopper;

    void translate2Panda()
    {
        string msg = m_foreigner->confession();
        //解析语言
        recvMsg("French say:"+msg);
    }
    void translate2Human()
    {
       string msg = sendMsg();
       m_foreigner->setResult("Fresh recv: "+msg);
    }
};
#endif
int main()
{
    Foreigner* foreigner = new American();
    AbstractChopper* chopper = new EnglishChopper(foreigner); //有子类的关联关系应用
    chopper->translate2Panda();
    chopper->translate2Human();
    delete foreigner;
    delete chopper;

    foreigner = new French;
    chopper = new FrenchChopper(foreigner); //有子类的关联关系
    chopper->translate2Panda();
    chopper->translate2Human();
    delete foreigner;
    delete chopper;

    return 0;
}
