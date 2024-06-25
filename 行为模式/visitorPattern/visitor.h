#pragma once
//行为类

class MaleMember;
class FemaleMember;
//行为基类
class AbstractAction
{
public:
    //两个大类的行为方法区分定义
    //男人访问
    virtual void maleDoing(MaleMember* male)=0;
    //女人访问
    virtual void femaleDoing(FemaleMember* female)=0;
    virtual ~AbstractAction() {}
};

//派生出的行为子类
//愤怒子类
class Anger:public AbstractAction
{
public:
    void maleDoing(MaleMember* male);
    void femaleDoing(FemaleMember* female);
    void fight();
    void warning();
};
//恐惧子类
class Horror:public AbstractAction
{
public:
    void maleDoing(MaleMember* male);
    void femaleDoing(FemaleMember* female);
    void help();
    void thinking();
};