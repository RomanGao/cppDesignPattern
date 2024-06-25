/*
状态模式：
当一个对象的内在状态改变时允许改变其行为，这个对象看起来像是改变了其类。
状态模式主要解决的是当控制一个对象状态转换的条件表达式过于复杂时的情况。
*/

#include "state.h"
#include "sanJi.h"
#include"vector"
using namespace std;


int main()
{
    SanJi* sanji = new SanJi();
    vector<int> data{7,12,14,16,18,22};
    for(auto item : data)
    {
        sanji->setTime(item);
        sanji->working();
    }
    delete sanji;
    return 0;
}