/*
观察者模式：
定义对象间一对多依赖，当一个对象改变状态时，依赖它的对象都会收到通知并自动更新。
*/

#include"newsAgency.h"
#include"observer.h"
using namespace std;

int main()
{
    //发布者
    NewsAgency* new1 = new Morgans;
    NewsAgency* new2 = new Gossip;

    //观察者
    Dragon* dragon = new Dragon(new1, "dragon");
    Shanks* shanke = new Shanks(new1, "shanke");
    Battery* battery = new Battery(new2, "battery");

    new1->notify("11111111111111");
    cout<<"============="<<endl;
    new2->notify("qqqqqqqqqqqq");

    delete battery;
    delete shanke;
    delete dragon;
    delete new2;
    delete new1;

    return 0;
}