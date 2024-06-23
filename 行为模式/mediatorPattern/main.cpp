/*
中介者模式

测试程序
*/
#include"country.h"
#include"mediator.h"
using namespace std;

int main()
{
    //世界政府
    WorldGovt* world = new WorldGovt();
    //加盟过对象
    //Alabasta* alaba = new Alabasta(world);
    //Dressrosa* dress = new Dressrosa(world);
   
    //加入setMediators 后，可以使用无参构造
    Alabasta* alaba = new Alabasta;
    Dressrosa* dress = new Dressrosa();
    
    //世界政府把加盟国添加
    world->addMember(alaba);
    world->addMember(dress);

    alaba->declare(" Dressrosa'girls is beautiful", "Dressrosa");
    dress->declare(" Alabasta'boy is handsome", "Alabasta");

    //革命军
    GeMingArmy* army = new GeMingArmy();
    //加盟国家
    Lulusia* lulusia = new Lulusia();
    Kambaka* kama = new Kambaka();

    army->addMember(lulusia);
    army->addMember(kama);
    lulusia->declare(" Is Kambaka's girl OK?");
  //  kama->declare(" Is Lulusia's boy OK?", "Lulusia");
    delete world;
    delete alaba;
    delete dress;
    delete army;
    delete lulusia;
    delete kama;
    
    return 0;
}