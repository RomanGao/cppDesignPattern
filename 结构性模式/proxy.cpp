/*
代理模式：
主要解决：在直接访问对象时带来的问题，
比如说：要访问的对象在远程的机器上，需要花费大量的时间。
代理模式：给这个对象提供一个代理，

一个父类，派生出两个子类，一个是代理类（工具人），一个是幕后类（手中有权利，本质行使职责的类）。
*/
#include<iostream>
using namespace std;
//代理类的基类
class Communication
{
public:
    virtual void communication() = 0;
    virtual ~Communication(){}
};
//子类
//讲话者的类
class Speaker : public Communication
{
public:
    void communication() override
    {
        cout<<"start speaking"<<endl;
        cout<<"make action"<<endl;
    }
};
//代理类
//由于讲话类与代理类形式同一个职责，所以继承同一个父类
class DenDenProxy:public Communication
{
public:
    DenDenProxy()
    {
        m_isStart = true;
        m_speaker = new Speaker; //直接创建，而不是传入
    }
    void setStart(bool flag)
    {
        m_isStart = flag;
    }
    bool isStart()
    {
        return m_isStart;
    }
    
    void communication() override
    {
        if(isStart())
        {
            cout<<"proxy start translate: "<<endl;
            m_speaker->communication();
        }
    }
    ~DenDenProxy()
    {
        if(m_speaker != nullptr)
        {
            delete m_speaker;
        }
    }
private:
    bool m_isStart = false;
    //代理对象
    Speaker* m_speaker = nullptr;
};

int main()
{
    //直接交流
    Communication* speak = new Speaker;
    speak->communication();
    delete speak;
    cout<<"========================"<<endl;
    //通过代理类交流
    speak = new DenDenProxy;
    speak->communication();
    delete speak;
    return 0;
}