#include"country.h"
#include<string>
using namespace std;

void Alabasta::declare(string msg, string country)
{
    cout<<"Alabasta declare: "<<endl;
    //让中介去发送消息
    m_org->declare(msg, this, country);
}

void Alabasta::recvMessage(string msg)
{
    cout<<"Alabasta received message: "<<msg<<endl;
}

//Dressrosa
void Dressrosa::declare(string msg, string country)
{
    cout<<"Dressrosa declare: "<<endl;
    //让中介去发送消息
    m_org->declare(msg, this, country);
}

void Dressrosa::recvMessage(string msg)
{
    cout<<"Dressrosa received message: "<<msg<<endl;
}

//Lulusia
void Lulusia::declare(string msg, string country)
{
    cout<<"Lulusia declare: "<<endl;
    //让中介去发送消息
    m_org->declare(msg, this, country);
}

void Lulusia::recvMessage(string msg)
{
    cout<<"Lulusia received message: "<<msg<<endl;
}
//Kambaka
void Kambaka::declare(string msg, string country)
{
    cout<<"Kambaka declare: "<<endl;
    //让中介去发送消息
    m_org->declare(msg, this, country);
}

void Kambaka::recvMessage(string msg)
{
    cout<<"Kambaka received message: "<<msg<<endl;
}