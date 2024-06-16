/*
生成器/建造者模式
*/ 

//案例：制造两艘不同规格的船，每艘船都分高配、中配和低配

#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

/*
代码逻辑：
    1、定义船相关的类:这两个类都不负责创建零部件，零部件由生成器类完成
    2、定义生成器相关的类
    3、管理者类：用于建造不同规格的船
    4、编写测试程序
*/

//定义桑尼号
//用于存储已经建造好的零部件
class SunnyShip
{
public:
    void addPart(string part)
    {
        m_parts.push_back(part);
    }

    void showParts()
    {
        for(auto part : m_parts)  //基于范围的for循环
            cout << part << ", ";
        cout<<endl;
    }
private:
    vector<string> m_parts;  //存储零部件
};
//定义美丽号
class MerryShip
{
public:
    void assemble(string name, string parts)  //两个参数对应的：使用位置，材料
    {
        m_parts.emplace(name, parts);  //emplace()函数，用于在map中插入元素
       // m_parts.insert(make_pair(name, parts));
    }

    void showParts()
    {
        for(auto item : m_parts)  //基于范围的for循环
            cout << item.first<<": "<<item.second << ",  ";
        cout<<endl;
    }
private:
    map<string, string> m_parts;  //存储零部件
};

//定义相关船的生成器类
//先定义一个基类
class ShipBuilder
{
public:
    virtual void reset()=0;
    virtual void buildEngine()=0;
    virtual void buildBody()=0;
    virtual void buildWeapon()=0;
    virtual void buildInterior()=0;
    virtual ~ShipBuilder() {}
};

//为每类型船体构件一个相关子类
class SunnyBuilder:public ShipBuilder
{
public:
    SunnyBuilder()
    {
        reset();
    }
    void reset()  //用于对数据的重制,用于建造新的船
    {
        m_sunny = new SunnyShip();
    }
    void buildBody()
    {
        m_sunny->addPart("SunnyBody");
    }
    void buildEngine()
    {
        m_sunny->addPart("SunnyEngine");
    }
    void buildWeapon()
    {
        m_sunny->addPart("SunnyWeapon");
    }
    void buildInterior()
    {
        m_sunny->addPart("SunnyInterior");
    }
    SunnyShip* getSunny()
    {
        //获取指针
        SunnyShip* ship = m_sunny;
        //拿走船后，将指针置空
        m_sunny = nullptr;
        return ship;
    }
    ~SunnyBuilder() 
    {
        if(m_sunny)
        {
            delete m_sunny;
        }
    }

private:
    SunnyShip* m_sunny;
}; 


class MerryBuilder:public ShipBuilder
{
public:
    MerryBuilder()
    {
        reset();
    }
    void reset()  //用于对数据的重制,用于建造新的船
    {
        m_merry = new MerryShip();
    }
    void buildBody()
    {
        m_merry->assemble("EarthBody", "Body");
    }
    void buildEngine()
    {
        m_merry->assemble("EarthEngine", "Engine");
    }
    void buildWeapon()
    {
        m_merry->assemble("EarthWeapon", "Weapon");
    }
    void buildInterior()
    {
        m_merry->assemble("EarthInterior","Interior");
    }  

    MerryShip* getSunny()
    {
        //获取指针
        MerryShip* ship = m_merry;
        //拿走船后，将指针置空
        m_merry = nullptr;
        return ship;
    }
    ~MerryBuilder() 
    {
        if(m_merry)
        {
            delete m_merry;
        }
    }

private:
    MerryShip* m_merry;
}; 

//定义管理者，管理者管理的是建造者类
class Director
{
public:
    void setBuilder(ShipBuilder* builder)
    {
        m_builder = builder;
    }

    //简约型
    void buildSimpleShip()
    {
        m_builder->buildBody();
        m_builder->buildEngine();
    }
    //标准型
    void buildStandardShip()
    {
        buildSimpleShip();
        m_builder->buildWeapon();
    }
    //豪华型
    void buildLuxuryShip()
    {
        buildStandardShip();
        m_builder->buildInterior();
    }

private:
    ShipBuilder* m_builder = nullptr; //使用父类
};


//测试程序
//建造桑尼号
void buildSunnyShip()
{
    cout<<"build Sunny Ship:"<<endl;
    Director* director = new Director;
    SunnyBuilder* builder = new SunnyBuilder;
    //简约型
    director->setBuilder(builder);
    director->buildSimpleShip();
    SunnyShip* ship = builder->getSunny();
    ship->showParts();
    //标准型
    builder->reset();
    director->buildStandardShip();
    ship = builder->getSunny();
    ship->showParts();
    //豪华型
    builder->reset();
    director->buildLuxuryShip();
    ship = builder->getSunny();
    ship->showParts();
    delete ship;
    delete builder;
    delete director;
}

//建造美丽号
void buildMerryShip()
{
    cout<<"build Merry Ship:"<<endl;
    Director* director = new Director;
    MerryBuilder* builder = new MerryBuilder;
    //简约型
    director->setBuilder(builder);
    director->buildSimpleShip();
    MerryShip* ship = builder->getSunny();
    ship->showParts();
    //标准型
    builder->reset();
    director->buildStandardShip();
    ship = builder->getSunny();
    ship->showParts();
    //豪华型
    builder->reset();
    director->buildLuxuryShip();
    ship = builder->getSunny();
    ship->showParts();
    delete ship;
    delete builder;
    delete director;
}
int main()
{
    buildSunnyShip();
    buildMerryShip();
    return 0;
}

