/*
抽象工厂模式，工厂类与生产类时n对n的关系
*/

#include<iostream>
#include<string>
using namespace std;

//船体基类
class ShipBody
{
public:
    virtual string getBody() = 0;
    virtual ~ShipBody() {}
};
//船体基类对应是三个子类
class WoodenShipBody : public ShipBody
{
public:
    string getBody() override
    { 
        return "[Wooden] ship body"; 
    }
};

class IronShipBody : public ShipBody
{
public:
    string getBody() override
    { 
        return "[Iron] ship body"; 
    }
};

class MetalShipBody : public ShipBody
{
public:
    string getBody() override
    { 
        return "[Metal] ship body"; 
    }
};

//引擎基类
class Engine
{
public:
    virtual string getEngine() = 0;
    virtual ~Engine() {}
};
//引擎基类对应三个子类
class HumanEngine : public Engine
{
public:
    string getEngine() override
    {
        return "[Human] engine"; 
    }
};

class DieselEngine : public Engine
{
public:
    string getEngine() override
    {
        return "[Diesel] engine"; 
    }
};

class NuclearEngine : public Engine
{
public:
    string getEngine() override
    {
        return "[Nuclear] engine"; 
    }
};

//武器基类
class Weapon
{
public:
    virtual string getWeapon() = 0;
    virtual ~Weapon() {}
};

class Gun : public Weapon
{
public:
    string getWeapon() override
    {
        return "[Gun] weapon"; 
    }
};

class Cannon : public Weapon
{
public:
    string getWeapon() override
    {
        return "[Cannon] weapon"; 
    }
};

class Laser : public Weapon
{
public:
    string getWeapon() override
    {
        return "[Laser] weapon"; 
    }
};

//船
class Ship
{
public:
    Ship(ShipBody* body, Engine* engine, Weapon* weapon)
    {
        this->body = body;
        this->engine = engine;
        this->weapon = weapon;
    } 
    //组合关系，需要释放三个类内存，聚合关系则不需要
     ~Ship()
    {
        delete body;
        delete engine;
        delete weapon;
    }
    string getpriority()
    {
        return body->getBody() + " and " + engine->getEngine() + " and " + weapon->getWeapon();
    }
private:
    ShipBody* body;
    Engine* engine;
    Weapon* weapon;
};

//以上属于生产类
//下面定义工厂类
//抽象工厂类
class Factory
{
public:
    virtual Ship* createShip()=0;
    virtual ~Factory() {}
};

//具体工厂类-基础类型的船，标准类型的船，旗舰类型的船
class BaseFactory : public Factory  
{
public:
    Ship* createShip() override
    {
        Ship* ship = new Ship(new WoodenShipBody(), new HumanEngine(), new Gun());
        cout<<"Create a base ship"<<endl;
        return ship;
    }
    ~BaseFactory() 
    {
        cout<<"Delete a base ship"<<endl;
    }
};

class StandardFactory : public Factory
{
public:
    Ship* createShip() override
    {
        Ship* ship = new Ship(new IronShipBody(), new DieselEngine(), new Cannon());
        cout<<"Create a standard ship"<<endl;
        return ship;
    }
};

class FlagshipFactory : public Factory
{
public:
    Ship* createShip() override
    {
        Ship* ship = new Ship(new MetalShipBody(), new NuclearEngine(), new Laser());
        cout<<"Create a flagship ship"<<endl;
        return ship;
    }
};

//客户端代码
int main()
{
    Factory* factory = new BaseFactory();
    Ship* ship = factory->createShip();
    cout<<ship->getpriority()<<endl;
    //生产类定义一个基类，通过借口实现相应的子类
    
    factory = new StandardFactory();
    ship = factory->createShip();
    cout<<ship->getpriority()<<endl;

    delete factory;
    delete ship;
    return 0;
}