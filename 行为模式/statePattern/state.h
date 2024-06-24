#pragma once

class SanJi; //声明只局限于拥护头文件中
//状态类的基类
class AbstractState
{
public:
    virtual void working(SanJi* sanji)=0;
    virtual ~AbstractState(){}    
};

//上午状态
class ForennoonState:public AbstractState
{
public:
    void working(SanJi* sanji) override;   
};

//中午状态
class noonState:public AbstractState
{
public:
    void working(SanJi* sanji) override;   
};

//下午状态
class AfternoonState:public AbstractState
{
public:
    void working(SanJi* sanji) override;   
};

//晚上状态
class EveningState:public AbstractState
{
public:
    void working(SanJi* sanji) override;   
};