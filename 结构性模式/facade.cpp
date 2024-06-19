/*
外观模式：
复杂的问题分离，再整合在一起，将底层逻辑封装，
简单操作上层接口即可完成整个流程
*/
#include<iostream>
using namespace std;

//可乐系统
class CokeSystem
{
public:
    void imCoke()
    {
        cout<<"finish polling in Coke"<<endl;
    }
};
//能量转换系统
class EnergySystem
{
public:
    void energyConvert()
    {
        cout<<"coke has converted to energy"<<endl;
    }
};
//目标锁定系统
class AimLockSystem
{
public:
    void aimLock()
    {
        cout<<"aim and Lock the target"<<endl;
    }
};
//加农炮发射系统
class Cannon
{
public:
    void cannonFire()
    {
        cout<<"Lion Cannon has been fired"<<endl;
    }
};
//风来跑稳定系统
class WindCannon
{
public:
    void windCannoFire()
    {
        cout<<"wind Cannon has been fired"<<endl;
    }
};

//上层接口
//狮口炮类
class LionCannon
{
public:
//系统之间具有包含和被包含的关系，所以确定的关系是关联关系
    LionCannon()
    {
        m_coke= new CokeSystem();
        m_energy= new EnergySystem();
        m_aimLock= new AimLockSystem();
        m_cannon= new Cannon();
        m_windCannon= new WindCannon();
    }
    ~LionCannon()
    {
        //成员函数对象与次类共存亡
        delete m_coke;
        delete m_energy;
        delete m_aimLock;
        delete m_cannon;
        delete m_windCannon;
    }
    void aimAndLock()
    {
        m_coke->imCoke();
        m_energy->energyConvert();
        m_aimLock->aimLock();
    }
    void fire()
    {
        m_cannon->cannonFire();
        m_windCannon->windCannoFire();
    }
private:
    CokeSystem* m_coke= nullptr;
    EnergySystem* m_energy= nullptr;
    AimLockSystem* m_aimLock= nullptr;
    Cannon* m_cannon= nullptr;
    WindCannon* m_windCannon= nullptr;
};
int main()
{
    LionCannon* lion = new LionCannon();
    lion->aimAndLock();
    lion->fire();
    delete lion;
    return 0;
}