#pragma once
#include <iostream>
//#include"iterator.h" //不建议这么操作，因为会导致循环依赖，而且不利于维护
using namespace std;
//声明类
class Iterator; //不使用里边的方法，声明即可
//定一个结点
struct Node 
{
    Node(string n):name(n){}
    string name = string();
    Node* pre = nullptr;
    Node* next = nullptr;
};
//定义双向链表类
class MyList
{
public:
    //内联函数不能太复杂，否则会影响效率，里边没有循环，没有判断
    inline int getCount()
    {
        return m_count; 
        //内敛函数不会压栈的，直接进行内存替换，提高内存效率，通过牺牲空间来实现
    }
    inline Node* head()
    {
        return m_head;
    }
    inline Node* tail()
    {
        return m_tail;
    }
    //插入结点
    Node* insert(Node* node, string name);
    Node* pushFront(string name);
    Node* pushBack(string name);
    Iterator* getIterator(bool reverse = true); 
private:
    Node* m_head = nullptr;  //头结点指针
    Node* m_tail = nullptr;  //尾结点指针
    int m_count = 0;  //结点数量
};