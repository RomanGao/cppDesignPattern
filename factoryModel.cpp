/*
工厂模式,生产类与工厂类为一对一关系
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



//定义工厂类的父类
class AbstractFactory
{
public:
    virtual AbstractProduct* createProduct() = 0;
    virtual ~AbstractFactory()
    {
        cout<<"AbstractFactory  destructor"<<endl;
    };
};

//工厂类的子类
class SheepFactory:public AbstractFactory
{
public:
    AbstractProduct* createProduct() override
    {
        return  new SheepProduct;
    }
    ~SheepFactory()
    {
        cout<<"sheep factory  destructor"<<endl;
    }
};

class LionFactory:public AbstractFactory
{
public:
    AbstractProduct* createProduct() override
    {
        return  new LionProduct;
    }
    ~LionFactory()
    {
        cout<<"LionFactory  destructor"<<endl;
    }
};

class BatFactory:public AbstractFactory
{
public:
    AbstractProduct* createProduct() override
    {
        return  new SheepProduct;
    }
    ~BatFactory()
    {
        cout<<"BatFactory  destructor"<<endl;
    }
};


int main()
{
    AbstractFactory *sheepFacory = new SheepFactory;
    AbstractProduct* sheepObject =sheepFacory->createProduct();
    sheepObject->transform();
    sheepObject->ability();
    delete sheepObject;
    delete sheepFacory;

    return 0;
}