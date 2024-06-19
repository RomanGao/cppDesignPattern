/*
组合模式
定一个基类，派生出两个子类，管理结点存储器其子节点，如果是叶子结点，需要添加其父结点
*/
#include<iostream>
#include<list>
#include<vector>
using namespace std;

class AbtractTeam
{
public:
    AbtractTeam(string name):m_name(name){}
    string getName()
    {
        return m_name;
    }
    void setParent(AbtractTeam* parent)
    {
        m_parent = parent;
    }
    AbtractTeam* getParent()
    {
        return m_parent;
    }
    //虚函数
    //这三个不是纯虚函数，可以不用重写直接调用
    virtual bool hasChild() {return false;} //叶子结点不重新写，管理结点中需要重新写
    //这两个函数可以不重写直接调用，只不过不会有任何响应
    virtual void addChild(AbtractTeam* node) {}
    virtual void removeChild(AbtractTeam* node) {}
    //这两个为纯虚函数，子类必须重写
    virtual void display()=0;
    virtual void fight() = 0;
    virtual ~AbtractTeam(){}
protected:
    string m_name;
    AbtractTeam* m_parent=nullptr;
};

//叶子结点
class LeafTeam:public AbtractTeam
{
public:
    using AbtractTeam::AbtractTeam;
    //重写纯虚函数
    void display() override
    {
        cout<<m_name<<" is "<<m_parent->getName()<<"'s leaf node."<<endl;
    }

    void fight() override
    {
        cout<<m_parent->getName()<<" and "<<m_name<<" fight!"<<endl;
    }
    ~LeafTeam()
    {
        cout<<"LeafTeam: "<<m_name<<" is destroyed."<<endl;
    }
};

//管理结点
class MangerTeam: public AbtractTeam
{
public:
    using AbtractTeam::AbtractTeam;

    //纯虚函数
    bool hasChild() override
    {
        return true;
    }
    void addChild(AbtractTeam* node) override
    {
        node->setParent(this);
        m_childs.push_back(node);
    }
    void removeChild(AbtractTeam* node) override
    {   
        node->setParent(nullptr);
        m_childs.remove(node);
    }
    void display() override
    {
        cout<<m_name<<" is manger node, has "<<m_childs.size()<<" childs:"<<endl;
        for(auto child:m_childs)
        {
            if(child == m_childs.back())
            {
                cout<<child->getName();
            }
            else
            {
                cout<<child->getName()<<", ";
            }
        }
    }

    void fight() override
    {
        cout<<m_name<<" is manger node, can't fight!"<<endl;
    }

    list<AbtractTeam*> getChilds()
    {
        return m_childs;
    }
    ~MangerTeam()
    {
        cout<<"MangerTeam: "<<m_name<<" is destroyed."<<endl;
    }
private:
    list<AbtractTeam*> m_childs;
};

//测试用例
void gameOver(AbtractTeam* root)
{
    if(root== nullptr)
    {
        return;
    }
    if(root->hasChild())
    {
        MangerTeam* team = dynamic_cast<MangerTeam*>(root);
        for(auto& child: team->getChilds())
        {
            gameOver(child);
        }
    }
    delete root;
}
void fighting()
{
    //根结点
    MangerTeam* root = new MangerTeam("caomao");
    vector<string> namev = {"xiaohei","xiaobei","xiaozhou","caidan","caitan","caiman"};
    for(int i = 0; i< namev.size(); i++)
    {
        MangerTeam* child = new MangerTeam(namev[i]);
        root->addChild(child);

        if (i== namev.size()-1)
        {
            for(int j = 0; j<3; j++)
            {
                LeafTeam* leaf = new LeafTeam(namev[i]+"_"+to_string(j));
                child->addChild(leaf);
                leaf->setParent(child);
                leaf->fight();
                leaf->display();
            }
        }
        child->fight();
        child->display();
    }
    root->fight();
    root->display();
    cout<<"==============================="<<endl;
    gameOver(root);
}
int main()
{
    fighting();
    return 0;
}