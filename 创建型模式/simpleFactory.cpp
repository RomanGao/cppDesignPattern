/*
简单工厂模式，生产类与工厂类对多对一的关系
*/

#include<iostream>
using namespace std;

//产品类的父类

class AbstractProduct
{
public:
    virtual void transform() = 0;
    virtual void ability() = 0;
    virtual ~AbstractProduct(){};
};

//产品类1
class SheepProduct:public AbstractProduct
{
public:
    void transform() override
    {
        cout<<"sheep transform"<<endl;
    }
    void ability() override
    {
        cout<<"sheep ability"<<endl;
    }
};

class LionProduct:public AbstractProduct
{
public:
    void transform() override
    {
        cout<<"lion transform"<<endl;
    }
    void ability() override
    {
        cout<<"lion ability"<<endl;
    }
};

class BatProduct:public AbstractProduct
{
public:

    void transform() override
    {
        cout<<"Bat transform"<<endl;
    }
    void ability() override
    {
        cout<<"bat ability"<<endl;
    }
};



//定义工厂类
//简单工厂模式中的工厂类只有一个
enum class Type:char{Sheep, Lion, Bat};//枚举类型有错误检查
//c++中，带class或者struct属于强类型枚举，并且可以指定枚举类型
class Factory
{
public:
    AbstractProduct* createProduct(Type type)
    {
        AbstractProduct *ptr = nullptr;
        switch (type)
        {
        case Type::Sheep:
            ptr = new SheepProduct();
            break;
        case Type::Lion:
            ptr = new LionProduct();
            break;
        case Type::Bat:
            ptr = new BatProduct();
            break;
        default:
            break;
        }
        return ptr;
    }
};

int main()
{
    Factory factory;
    AbstractProduct* product = factory.createProduct(Type::Sheep);
    product->transform();
    product->ability();
    delete product;
    return 0;
}