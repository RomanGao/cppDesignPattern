#include<iostream>
#include "visitor.h"
#include"member.h"
using namespace std;


void Anger::fight()
{
    cout<<"keep fighting!!!"<<endl;
}

void Anger::warning()
{
    cout<<"I'm warning...."<<endl;
}
void Anger::maleDoing(MaleMember *male)
{
    cout<<male->getName()<<" is angry!"<<endl;
    cout << "Anger::maleDoing" << endl;
    fight();
}

void Anger::femaleDoing(FemaleMember *female)
{
    cout<<female->getName()<<" is angry!"<<endl;
    cout << "Anger::femaleDoing" << endl;
    warning();
}



void Horror::help()
{
    cout<<"I need help!!!"<<endl;
}

void Horror::thinking()
{
    cout<<"I think about it...."<<endl;
}


void Horror::maleDoing(MaleMember *male)
{
    cout<<male->getName()<<" is horrified!"<<endl;
    cout << "Horror::maleDoing" << endl;
    thinking();
}

void Horror::femaleDoing(FemaleMember *female)
{
    cout<<female->getName()<<" is horrified!"<<endl;
    cout << "Horror::femaleDoing" << endl;
    help();
}
