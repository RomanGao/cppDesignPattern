#pragma once
#include"MyList.h"


class Iterator {
public:
    Iterator(MyList* list):m_list(list){}
    //当前结点地址
    Node* current()  //当前指针
    { 
        return m_current; 
    }
    virtual Node* first() = 0; //头结点
    virtual Node* next() = 0; //下一个结点
    virtual bool isEnd() = 0; //是否到头了
    virtual ~Iterator(){}
protected:
    MyList* m_list = nullptr;
    Node* m_current = nullptr;
};

//正向遍历
class ForwardIterator : public Iterator 
{
    using Iterator::Iterator;
    Node*  first() override
    {
        m_current = m_list->head();
        return m_current;
    }
    Node* next() override
    {
        m_current = m_current->next;
        return m_current;
    }
    bool isEnd() override
    {
        return m_current == m_list->tail()->next;
    }
};

//逆向遍历
class ReverseIterator : public Iterator 
{
    using Iterator::Iterator;
    Node*  first() override
    {
        m_current = m_list->tail();
        return m_current;
    }
    Node* next() override
    {
        m_current = m_current->pre;
        return m_current;
    }
    bool isEnd() override
    {
        return m_current == m_list->head()->pre;
    }
};