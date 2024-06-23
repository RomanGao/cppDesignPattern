/*
备忘录模式:

备忘录模式（Memento Pattern）是一种行为型设计模式，它在不破坏封装的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态。
这样以后就可以恢复到原先保存的状态。

*/

#include <iostream>
#include<vector>
#include<map>
using namespace std;

//数据类，保存事件的内容
class History
{
public:
    History(string content):m_content(content) {}
    string getContent() { return m_content; }
private:
    string m_content;
};
//事件的亲历者，事件的主题
//脚盆鸡---他做了某些罪行
class JiaoPenJI
{
public:
   //脚盆鸡做的事情
   void setState(string msg)
   {
        m_msg = msg;
   }
   //记录历史--对数据进行封装
   //至于这么记录，要交给记录者类
   History* saveHistory()
   {
        return new History(m_msg);
   }
   //恢复历史--从数据中恢复状态，
   //至于这么加载历史信息，记录者类来负责
   void restoreHistory(History* history)
   {
        m_msg = history->getContent();
   }
   string getState() { return m_msg; }
    //被打
    void bing()
    {
        cout << "bing" << endl;
    }
private:
    string m_msg;
};

//数据的记录者
class Recorder
{
public:
    //保存数据的函数
    //负责记录数据的具体操作
    void addHistory(int index, History* history)
    {
        m_historyMap.insert(make_pair(index, history));
    }

    History* getHistory(int index)
    {
        if(m_historyMap.find(index)!= m_historyMap.end())
        {
            return m_historyMap[index];
        }
        return nullptr;
    }
private:
    map<int, History*> m_historyMap;
};
int main()
{  
    //测试程序
    vector<string> msg{
        "buchengren a",
        "buchengren bb",
        "buchengren cc",
        "buchengren dd",
        "buchengren eee",
        "buchengren ffff",
        "buchengren hhhhhh",
    };

    JiaoPenJI* jiaoPenJI = new JiaoPenJI();
    Recorder* recorder = new Recorder();
    for(int i = 0; i < msg.size(); i++)
    {
        jiaoPenJI->setState(msg[i]);
        recorder->addHistory(i, jiaoPenJI->saveHistory());
        cout << "No." << i+1 << " recorder: " << jiaoPenJI->getState() << endl;
    }

    jiaoPenJI->bing();
    for(int i = 0; i < msg.size(); i++)
    {
        jiaoPenJI->restoreHistory(recorder->getHistory(i));
        cout << "No." << i+1 << " jiaoPenJI Done: " << jiaoPenJI->getState() << endl;
    }

    return 0;
}