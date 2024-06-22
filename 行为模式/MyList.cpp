
#include"iterator.h" //在这里引用头文件

Node* MyList::insert(Node* node, string name)
{
    Node* newNode = nullptr;
    if(node == m_head)
    {
        newNode = pushFront(name);
    }
    else
    {
        newNode = new Node(name);
        //1 将newNode和链表连接
        newNode->next = node;
        newNode->pre = node->pre;
        //2 将原来的链表断开，重新连接
        node->pre->next = newNode;
        node->pre = newNode;
    }
    m_count++;
    return newNode;
}
Node* MyList::pushFront(string name)
{
    Node* newNode = new Node(name);
    if(m_head == nullptr)
    {
        m_head = m_tail = newNode;
    }
    else
    {
        newNode->next = m_head;
        m_head->pre = newNode;
        m_head = newNode;
    }
    m_count++;
    return newNode;
}
Node* MyList::pushBack(string name)
{
     Node* newNode = new Node(name);
    if(m_head == nullptr)
    {
        m_head = m_tail = newNode;
    }
    else
    {
        m_tail->next = newNode;
        newNode->pre = m_tail;
        m_tail = newNode;
    }
    m_count++;
    return newNode;
}

Iterator* MyList::getIterator(bool isReverse)
{
    Iterator* iterat = nullptr;
    if(isReverse)
    {
        iterat = new ReverseIterator(this);
    }
    else
    {
        iterat = new ForwardIterator(this);
    }
    return iterat;
}