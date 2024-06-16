/*
原型模式案例
*/

#include <iostream>
#include <string>
using namespace std;

//父类
class GernaSoldier
{
public:
    virtual GernaSoldier* clone() =0;
    virtual string whoAmI() =0;
    virtual ~GernaSoldier() {}
};

//派生出两个子类
class Soldier66:public GernaSoldier
{
public:
    GernaSoldier* clone()
    {
        //在此函数中调用构造函数，并返回一个新的实例
        //this是一个指针，指向当前实例，我们需要解引用
        //因为拷贝构造函数中传递的是某个实例的引用
        //所以我们需要在this前加*转化成一个实例
        return new Soldier66(*this);
    }
    string whoAmI()
    {
        cout<<"I am Soldier66"<<endl;
        return "Soldier66";
    }
};
//派生出两个子类
class Soldier67:public GernaSoldier
{
public:
    GernaSoldier* clone()
    {
        //在此函数中调用构造函数，并返回一个新的实例
        //this是一个指针，指向当前类的实例，我们需要解引用
        //因为拷贝构造函数中传递的是某个实例的引用
        //所以我们需要在this前加*转化成一个实例
        return new Soldier67(*this); //默认构造函数的是浅拷贝，两个对象指向同一块内存
    }
    string whoAmI()
    {
        cout<<"I am Soldier67"<<endl;
        return "Soldier67";
    }
};

int main()
{
    GernaSoldier* soldier66 = new Soldier66;
    GernaSoldier* soldier67 = soldier66->clone();
    cout<<soldier66->whoAmI()<<endl;
    cout<<soldier67->whoAmI()<<endl;

    soldier66 = new Soldier67;
    soldier67 = soldier66->clone();
    cout<<soldier66->whoAmI()<<endl;
    cout<<soldier67->whoAmI()<<endl;
    delete soldier66;
    delete soldier67;
    return 0;
}