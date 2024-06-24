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