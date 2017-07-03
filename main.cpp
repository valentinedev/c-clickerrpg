#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

using namespace std;

class Character
{
    public:
        Character();
        ~Character();
        void setpoints(int s);
        int printstats();
        int points;
};

Character::Character()
{
    points = 1;
}

Character::~Character()
{
}

void Character::setpoints(int s)
{
    points+=s;
}

int Character::printstats()
{
    cout<<points;
}

int main()
{
    char pinput[20];
    char playername[20];
    int pointadd;
    int cost;
    pointadd = 1;
    cost = 10;
    while(1)
    {
        cout<<"Enter Name: ";
        cin.getline(playername, 20, '\n');
        if(cin.fail())
        {
            system("CLS");
            cout<<"Invalid Input\n";
            cin.clear();
            cin.ignore(10000,'\n');
            continue;
        }
        if(strcmp(playername,"")==0)
        {
            system("CLS");
            cout<<"Invalid Input\n";
            continue;
        }
        break;
    }
    system("CLS");
    Character player;
    while(1)
    {
        while(1)
        {
            cout<<playername<<"'s Points:\n";
            player.printstats();
            cout<<"\n\nBlank. Click\n\n1. Points Per Click X2: Points Per Click: "<<pointadd*2<<" Cost: "<<cost<<"\n\nInput: ";
            cin.getline(pinput,20,'\n');
            if(cin.fail())
            {
                system("CLS");
                cout<<"Invalid Input\n";
                cin.clear();
                cin.ignore(10000,'\n');
                continue;
            }
            system("CLS");
            break;
        }
        if(strcmp(pinput,"")==0)
        {
            system("CLS");
            player.setpoints(pointadd);
        }
        else if(strcmp(pinput,"1")==0)
        {
            if(cost<=player.points)
            {
                system("CLS");
                player.points = player.points - cost;
                pointadd*=2;
                cost*=4;
            }
            else
            {
                system("CLS");
                cout<<"Invalid Input. Not Enough Points.\n";
            }
        }
    }
}
