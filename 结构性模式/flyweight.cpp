/*
享元模式（Flyweight Pattern）主要用于减少创建对象的数量，以减少内存占用和提高性能。
这种模式主要应用于有大量重复对象的场景，比如字体的渲染，图形的渲染。
这种模式的主要思想是共享对象，即多个对象共用一个相同的状态，这样可以节省内存，提高性能。
*/
#include <iostream>
#include<map>
#include<vector>
using namespace std;

//享元类为炮弹的蛋体，享元的静态数据
//享元类的基类
class FlyweightBody
{
public:
    FlyweightBody(string sprite):m_sprite(sprite){}
    virtual void move(int x, int y, int speed)=0; //移动
    virtual void draw(int x, int y)=0; //重绘
    virtual ~FlyweightBody(){}
protected:
    //静态属性 
    string m_sprite;//精灵图
    string m_color;//颜色
};
//享元类的子类
//共享的-炮弹类
class SharedBombBody:public FlyweightBody
{
public:
    using FlyweightBody::FlyweightBody;

    void move(int x, int y, int speed) override
    {
        cout<<"paodan moving -> speed:"<<speed
        <<" x:"<<x<<" y:"<<y<<endl;
    }
    void draw(int x, int y) override
    {
        cout<<"paodan draw in "<<x<<", "<<y<<endl;
    }
};

//独享的-彩蛋类
class UnqiueBombBody:public FlyweightBody
{
public:
    using FlyweightBody::FlyweightBody;
    void move(int x, int y, int speed) override
    {
        cout<<"caidan -> speed:"<<speed
        <<" x:"<<x<<" y:"<<y<<endl;
    }
    void draw(int x, int y) override
    {
        cout<<"caidan draw in "<<x<<", "<<y<<endl;
    }
};

//发射炮弹类，享元的动态数据，享元的动态类，需要用到享元对象是共享对象
class LaunchBomb
{
public:
    LaunchBomb(FlyweightBody* body):m_body(body){}
    void setSpeed(int speed)
    {
        m_speed = speed;
    }
    void move(int x, int y)
    {
        m_x = x;
        m_y = y;
        m_body->move(m_x,m_y,m_speed); 
        draw(); 
    }
    void draw()
    {
        m_body->draw(m_x,m_y);
    }
    void setColor(string color)
    {

    }

private:
    FlyweightBody* m_body;
    int m_speed=100;
    int m_x=0;
    int m_y=0;
};
//享元工厂类
//为了创建和维护多个享元静态对象，需要创建一个享元工厂类
class BombBodyFactory
{
public:
    //参数是炸弹的型号
    FlyweightBody* getFlyweightBody(string name)
    {
        //即返回一个炮弹类，有维护炮弹对象
        FlyweightBody* data = nullptr;
        if(m_flyweightBodyMap.find(name)==m_flyweightBodyMap.end())
        {
            data = new SharedBombBody(name);
            cout<<"create shared bomb body:"<<name<<endl;
            m_flyweightBodyMap.emplace(name, data);
            return data;
        }
        else
        {
            cout<<"repeat use:"<<name<<endl;
            return m_flyweightBodyMap[name];
        }
    }
    ~BombBodyFactory()
    {
        for(auto item:m_flyweightBodyMap)
        {
            delete item.second;
        }
    }
private:
    map<string, FlyweightBody*> m_flyweightBodyMap;
};
int main()
{
    //关于投掷炸弹可能也对应一个类在，我们在main()函数中实现了。

    //创建和维护享元类的工厂函数
    BombBodyFactory* factory = new BombBodyFactory();
    //创建动态类
    vector<LaunchBomb*> bombs;
    //创建共享的炮弹
    vector<string> nameList={"X1","X1","Y1","Y1","Y1","Z1","Z1"};
    for(auto name: nameList)
    {   //动态获得享元资源
        LaunchBomb* launch = new LaunchBomb(factory->getFlyweightBody(name));
        int x=0,y=0;
        for(int i=0;i<5;i++)
        {
            x += rand()%100;;
            y += rand()%50;
            launch->move(x,y);
        }
        bombs.push_back(launch);
    }
    //彩蛋--独享类，不是共享类
    UnqiueBombBody* uniqueBomb = new UnqiueBombBody("caidan");
    LaunchBomb* bomb = new LaunchBomb(uniqueBomb);
    int x=0,y=0;
    for(int i = 0; i<5; i++)
    {
        x += rand()%100;
        y += rand()%50;
        bomb->move(100,100);
    }
    //bomb与uniqueBomb为聚合关系，析构bomb，uniqueBomb不会随之析构，如果会析构那么对组合关系
    //因此，两个对象均需要手动析构
    delete bomb;
    delete uniqueBomb;

    for(auto bom: bombs)
    {
        delete bom;
    }
    delete factory;
    return 0;
}
