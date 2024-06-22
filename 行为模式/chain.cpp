/*
责任链模式：
定义：使多个对象都有机会处理请求，从而避免请求的发送者和接收者之间的耦合关系。
将这些对象连成一条链，并沿着这条链传递该请求，直到有一个对象处理它为止。
*/

#include<iostream>
using namespace std;

//强类型枚举，加class或者struct，名字后边加上：类型，声明枚举类型
enum class RequestType:char{QingJia, ZhangXin, CiZhi};
//抽象的管理结点
class AbstractManager
{
public:
    //使用多态实现
    void setNext(AbstractManager* next)
    {
        m_next = next;
    }
    virtual void handleRequest(RequestType type) = 0;
    virtual ~AbstractManager(){}
protected:
    AbstractManager* m_next;
};

//底层管理者
class Manager:public AbstractManager
{
public:
    void handleRequest(RequestType type) override
    {
        switch (type)
        {
        case RequestType::QingJia:
            cout<<"[manger]qingjia: acceped! "<<endl;
            break;
        case RequestType::ZhangXin:
            cout<<"[manger]zhangxin: neeed to request CEO ==> ";
            m_next->handleRequest(type);
            break;
        case RequestType::CiZhi:
            cout<<"[manger]cizhi: need to request supervisor ==> ";
            m_next->handleRequest(type);
            break;
        default:
            break;
        }
    }
    ~Manager(){}
};

//中层管理者
class CEO:public AbstractManager
{
public:
    void handleRequest(RequestType type) override
    {
        switch (type)
        {
        case RequestType::QingJia:
            cout<<"[CEO]qingjia: acceped! "<<endl;
            break;
        case RequestType::ZhangXin:
            cout<<"[CEO]zhangxin: no!"<<endl;
            break;
        case RequestType::CiZhi:
            cout<<"[CEO]cizhi: need to request boss ==> ";
            m_next->handleRequest(type);
            break;
        default:
            break;
        }
    }
    ~CEO(){}
};

//上层管理者
class Boss:public AbstractManager
{
public:
    void handleRequest(RequestType type) override
    {
        switch (type)
        {
        case RequestType::QingJia:
            cout<<"[boss]qingjia: no no! "<<endl;
            break;
        case RequestType::ZhangXin:
            cout<<"[boss]zhangxin: no no no!"<<endl;
            break;
        case RequestType::CiZhi:
            cout<<"[boss]cizhi: no no no!"<<endl;
            break;
        default:
            break;
        }
    }
    ~Boss(){}
};

//打工人
class DaCongMing
{
public:
    void requst(RequestType type, AbstractManager* head)
    {
        head->handleRequest(type);
    }
};

/*
int main()
{
    //测试
    Manager* m1 = new Manager();
    CEO* m2 = new CEO();
    Boss* m3 = new Boss();
    m1->setNext(m2);
    m2->setNext(m3);

    DaCongMing *dcm = new DaCongMing;
    cout<<"all up to manager"<<endl;
    dcm->requst(RequestType::QingJia, m1);
    dcm->requst(RequestType::ZhangXin, m1);
    dcm->requst(RequestType::CiZhi, m1);
    
    cout<<"all up to CEO"<<endl;
    dcm->requst(RequestType::QingJia, m2);
    dcm->requst(RequestType::ZhangXin, m2);
    dcm->requst(RequestType::CiZhi, m2);

    cout<<"all up to boss"<<endl;
    dcm->requst(RequestType::QingJia, m3);
    dcm->requst(RequestType::ZhangXin, m3);
    dcm->requst(RequestType::CiZhi, m3);

    delete dcm;
    delete m3;
    delete m2;
    delete m1;

    return 0;
}*/