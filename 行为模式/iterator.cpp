/*
迭代器模式：
*/

//双向链表代码实例
#include<iostream>
#include<vector>
#include"MyList.h"
#include"iterator.h"

using namespace std;
//测试文件
int main()
{
    vector<string> nameList{"a","b","c","d","e","f","g","h"};
    MyList ls;
    for(int i =0 ;i <nameList.size(); i++)
    {
        ls.pushBack(nameList[i]);
    }
    cout<<"zheng xiang bianli" <<endl;
    Iterator* it = ls.getIterator(false);
    cout<<"bian li"<<endl;
    for(auto begain = it->first(); !it->isEnd();it->next())
    {
        cout<<" "<<it->current()->name<< ", ";
    }
    cout<<endl;
    cout<<"====================="<<endl;
    cout<<"ni xiang bianli " <<endl;
    it = ls.getIterator(true);
    cout<<"bian li"<<endl;
    for(auto begain = it->first(); !it->isEnd();it->next())
    {
        cout<<" "<<it->current()->name<< ", ";
    }
    cout<<endl;
    cout<<"====================="<<endl;
    return 0;
}