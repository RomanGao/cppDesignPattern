/*
命令模式：
*/

#include <iostream>
#include<map>
#include<list>
using namespace std;

//厨师 ==> 命令执行者,收到命令才开始工作
//如果有个厨师，可以定义一个抽象类
//本案例假设就一位厨师
class CookerZeff
{
public:
    void makeDSX()
    {
        cout<<"make di san xian ...";
    }
    void makeYXRS()
    {
        cout<<"make yu xiang rou si";
    }
    void makeGBJD()
    {
        cout<<"make gong bao ji ding ...";
    }
    void makeHSPG()
    {
        cout<<"make hong shao pai gu...";
    }
};
//命令 
//===》 对应炒什么菜
//先定一个命令的一个抽象类
class AbtractComand
{
public:
    //命令需要有一个执行者
    AbtractComand(CookerZeff *cooker):m_cooker(cooker){}
    virtual void excute()=0;  //对应一个执行的虚函数，对应是炒菜
    virtual string name()=0 ;    //返回对应炒菜的什么菜
    virtual ~AbtractComand(){}
protected:
    CookerZeff *m_cooker;
};
//具体命令     将执行者（厨师）与命令分离，哪个对象炒什么菜，调用其对象即可
class DSXCommand:public AbtractComand
{
public:
    using AbtractComand::AbtractComand;
    void excute() override
    {
        m_cooker->makeDSX();
    }
    string name() override
    {
        return "di san xian";
    }
};
class GBJDCommand:public AbtractComand
{
public:
    using AbtractComand::AbtractComand;
    void excute() override
    {
        m_cooker->makeGBJD();
    }
    string name() override
    {
        return "gong bao ji ding";
    }
};

class YXRSCommand:public AbtractComand
{
public:
    using AbtractComand::AbtractComand;
    void excute() override
    {
        m_cooker->makeYXRS();
    }
    string name() override
    {
        return "yu xiang rou si";
    }
};
class HSPGCommand:public AbtractComand
{
public:
    using AbtractComand::AbtractComand;
    void excute() override
    {
        m_cooker->makeHSPG();
    }
    string name() override
    {
        return "hong shao pai gu";
    }
};

//服务员 -> 命令的接收者
class Waiter
{
public:
    //下单
    //参数对应 哪个桌， 下了什么菜
    void setOder(int index, AbtractComand* command)
    {
        cout<<" No."<<index<<"Desk, order: "<<command->name()<<endl;
        if(command->name() == "yu xiang rou si")
        {
            cout<<"no fish ,can't cook!"<<endl;
            return;
        }
        if(m_orders.find(index) == m_orders.end())
        {
            //如果这桌点的是第一道菜
            list<AbtractComand*> mylist{command};
            m_orders.insert(make_pair(index, mylist));
        }
        else
        {
            //否者直接添加进去即可
             m_orders[index].push_back(command);
        }
    }
    //取消订单
    void cancelOder(int index, AbtractComand* command)
    {
        if(m_orders.find(index) != m_orders.end())
        {
            //找到这桌，如果这个桌点了这个菜，就删除这道菜
            m_orders[index].remove_if([command](AbtractComand* p){return p->name() == command->name();});
            cout<<index<<"Desk, cancel order: "<<command->name()<<endl;
        }
    }
    //结账
    void checkOut(int index)
    {
        cout<<"No."<<index<<"Desk, check out! Order: [";
        for(const auto& item : m_orders[index])
        { 
            cout<<item->name();
            if(item!=m_orders[index].back())
            {
                cout<<", ";
            }
        }
        cout<<"]"<<endl;

        //需要删掉第index桌的订单
        m_orders.at(index).clear();
    }
    //发送通知 -》 要求厨师执行命令
    void notify(int index)
    {
        //给定桌好，就知道有哪些菜
        for(const auto &item: m_orders[index])
        {
            item->excute();
            cout<<"N0."<<index<<"Desk, "<<item->name()<<" is done!"<<endl;
        }
    }
private:
    map<int, list<AbtractComand*>> m_orders; //服务员需要维护一个订单列表
};
int main()
{
    //测试
    CookerZeff* zeff = new CookerZeff();
    Waiter *wait = new Waiter();

    YXRSCommand *yxrs = new YXRSCommand(zeff);
    GBJDCommand *gbjd = new GBJDCommand(zeff);
    DSXCommand *dsx = new DSXCommand(zeff);
    HSPGCommand *hspg = new HSPGCommand(zeff);

    cout<<"gu le kai shi dian can: "<<endl;
    wait->setOder(1, yxrs);
    wait->setOder(1, gbjd);
    wait->setOder(1, dsx);
    wait->setOder(1, hspg);

    wait->setOder(2, gbjd);
    wait->setOder(2, dsx);
    wait->setOder(2, hspg);

    cout<<"cancel order ======== "<<endl;
    wait->cancelOder(1, hspg);

    cout<<"start order ========"<<endl;
    wait->notify(1);
    wait->notify(2);

    cout<<"check out ========="<<endl;
    wait->checkOut(1);
    wait->checkOut(2);

    cout<<"xin de yi zhuo: "<<endl;
    wait->setOder(1, hspg);
    wait->notify(1);
    wait->checkOut(1);

    delete wait;
    delete zeff;
    delete yxrs;
    delete gbjd;
    delete dsx;
    delete hspg;

    return 0;
}