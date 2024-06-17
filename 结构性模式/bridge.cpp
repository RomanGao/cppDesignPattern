/*
桥连接模式
需求：对海贼世界中的 海贼团 和 海军 通过桥连接模式进行管理
                   人       船
*/

#include<iostream>
#include<map>
using namespace std;

//定义一个人的类
struct Person
{
    Person(string name, string job, string ability, string reward, string beizhu)
    {
        this->name = name;
        this->job = job;
        this->ability = ability;
        this->reward = reward;
        this->beizhu = beizhu;
    }
    ~Person()
    {
        cout<<"deconstruct: "<<name<<endl;
    }
    string name;
    string job;
    string ability;
    string reward;
    string beizhu;
};

//定一个实现部分- 团体
class AbstractTream
{
public:
    AbstractTream(string name):m_name(name){};
    string getTeamName()
    {
        return m_name;
    }
    void addMember(Person *p)
    {
        m_members.insert(make_pair(p->name, p));
    }

    void show()
    {
        cout<<m_name<<": "<<endl;
        for(const auto& item: m_members)
            cout<<"[name:"<<item.second->name
            <<", job:"<<item.second->job
            <<", ability:"<<item.second->ability
            <<", reward:"<<item.second->reward
            <<", beizhu:"<<item.second->beizhu
            <<"]"<<endl;
    }
    virtual void excuteTask()=0; //每种类型船的所执行的任务不同
    virtual ~AbstractTream()
    {
        for(const auto& item:m_members)
        {
            delete item.second;
        }
    }
protected:
    string m_name; //团的名字
    map<string, Person*> m_members; //团的成员
};
//草帽团
class CaoMaoTeam:public AbstractTream
{
public:
    //using 父类类名::父类构造函数名
    using AbstractTream::AbstractTream;
    void excuteTask()
    {
        cout<<"Cao Mao excute task"<<endl;
    }
};
class SmokerTeam:public AbstractTream
{
public:
    using AbstractTream::AbstractTream;
    /*
    c++11之前的版本需要通过初始化列表添加构造函数
     // 子类构造函数通过初始化列表调用父类构造函数
    Child(int parentValue， int childValue) : Parent(parentValue) {
        std::cout << "Child constructor called with child value: " << childValue << std::endl;
        // 子类的初始化代码...
    }
    */
    void excuteTask()
    {
        cout<<"Smoker excute task"<<endl;
    }
};
//定义抽象部分 -  船
class AbstractShip
{
public:
    AbstractShip(AbstractTream* team):m_team(team){} //实现team多态
    void show()
    {
        m_team->show();
        m_team->excuteTask();
    }
    virtual string getName() = 0;
    virtual void feature() = 0;   //属性函数
    virtual ~AbstractShip(){}
protected:
    AbstractTream* m_team; //船的团
};
class Merry: public AbstractShip
{
public:
    using AbstractShip::AbstractShip;
    string getName()
    {
        return "Merry";
    }
    void feature()
    {
        cout<<getName()<<": feature!"<<endl;
    }
};
class HaiJunShip:public AbstractShip
{
public:
    using AbstractShip::AbstractShip;
    string getName()
    {
        return "Haijun";
    }
    void feature()
    {
        cout<<getName()<<": feature!"<<endl;
    }
};

int main()
{
    AbstractTream* team = new CaoMaoTeam("CaoMao");
    Person* luffy = new Person("lufei", "chuangzhang", "xiaojiang", "30yi", "chirou");
    Person* zoro = new Person("suolong", "jianshi", "sandao", "11yi", "luchi");
    Person* sanji = new Person("shanzhi", "chushi", "yinxing", "10yi", "haose");
    Person* nami = new Person("namei", "hanghaishi", "tianbanghou", "3yi", "xihuanqian");

    team->addMember(luffy);
    team->addMember(zoro);
    team->addMember(sanji);
    team->addMember(nami);

    AbstractShip* ship = new Merry(team);
    ship->show();
    ship->feature();
    delete team;
    delete ship;
    cout<<"============================"<<endl;
    team = new SmokerTeam("Smoker");
    Person* hulk = new Person("hulk", "shenlong", "shenlong", "100yi", "shenlong");
    Person* thor = new Person("thor", "wangzhe", "wangzhe", "1000yi", "wangzhe");
    team->addMember(hulk);
    team->addMember(thor);

    ship = new HaiJunShip(team);
    ship->show();
    ship->feature();
    delete team;
    delete ship;
    return 0;
}