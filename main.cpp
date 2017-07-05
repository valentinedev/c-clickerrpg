#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <limits>

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
}

Character::~Character()
{
    points = 0;
}

void Character::setpoints(int s)
{
    points+=s;
}

int Character::printstats()
{
    cout<<points;
    return 0;
}

int rebirth();

int cost;
int goal;
int currency;
int rebirthprice;

int main()
{
    char pinput[20];
    char playername[20];
    int pointadd;
    pointadd = 1;
    cost = 10;
    goal = 100;
    currency = 0;
    rebirthprice = 5;
    while(1)
    {
        cout<<"Enter Name: ";
        cin.getline(playername, 20, '\n');
        if(cin.fail())
        {
            system("CLS");
            cout<<"Invalid Input\n";
            cin.clear();
            cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
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
    player.points = 0;
    while(1)
    {
        while(1)
        {
            cout<<playername<<"'s Points:\n";
            player.printstats();
            cout<<"\nGoal: "<<goal<<"\nCurrency: "<<currency;
            cout<<"\n\nBlank. Click\n\n1. Points Per Click X2: Points Per Click: "<<pointadd*2<<" Cost: "<<cost<<"\n\n2. Rebirth. Currency Required: "<<rebirthprice<<"\n\nInput: ";
            cin.getline(pinput,20,'\n');
            if(cin.fail())
            {
                system("CLS");
                cout<<"Invalid Input\n";
                cin.clear();
                cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
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
        else if(strcmp(pinput,"2")==0)
        {

            if(rebirthprice<=currency)
            {
                system("CLS");
                currency -= rebirthprice;
                rebirth();
                player.points = 0;
                continue;
            }
            else
            {
                system("CLS");
                cout<<"Invalid Input. Not Enough Currency.\n";
            }
        }
        else{}
        if(player.points>=goal)
        {
            currency += 1;
            goal *= 5;
        }
    }
}

int rebirth()
{
    cost = 10;
    goal = 100;
    currency = 0;
    rebirthprice *= 3;
    return 0;
}
