#include <iostream>
#include <stdio.h>
#include <limits>
#include <conio.h>

using namespace std;

class Character
{
    public:
        Character();
        ~Character();
        void setpoints(long double s);
        long double points;
};

Character::Character()
{
}

Character::~Character()
{
    points = 0;
}

void Character::setpoints(long double s)
{
    points+=s;
}

void rebirth();

long double cost;
long double goal;
long double currency;
long double rebirthprice;

int main()
{
    char pinput[20];
    char playername[20];
    long double pointadd;
    char quitval[2];
    pointadd = .1;
    cost = 10;
    goal = 100;
    currency = 0;
    rebirthprice = 4;
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
            while(1)
            {
                system("CLS");
                player.setpoints(pointadd);
                cout<<playername<<"'s Points:\n";
                cout<<player.points;
                cout<<"\nGoal: "<<goal<<"\nCurrency: "<<currency;
                cout<<"\n\nBlank. Click\n\n1. Points Per Click X1.1: Points Per Click: "<<pointadd*1.1<<" Cost: "<<cost<<"\n\n2. Rebirth. Currency Required: "<<rebirthprice<<"\n\n3. Quit."<<"\n\nInput: ";
                if(kbhit())
                {
                    break;
                }
            }
            cin.getline(pinput,20,'\n');
            if(cin.fail())
            {
                system("CLS");
                cout<<"Invalid Input\n";
                cin.get();
                cin.clear();
                cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
                continue;
            }
            system("CLS");
            break;
        }
        if(strcmp(pinput,"1")==0)
        {
            if(cost<=player.points)
            {
                system("CLS");
                player.points = player.points - cost;
                pointadd*=1.1;
                cost*=1.2;
            }
            else
            {
                system("CLS");
                cout<<"Invalid Input. Not Enough Points. Press Enter To Resume.\n";
                cin.get();
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
                cout<<"Invalid Input. Not Enough Currency. Press Enter To Resume.\n";
                cin.get();
            }
        }
        else if(strcmp(pinput,"3")==0)
        {
            break;
        }
        else{}
        if(player.points>=goal)
        {
            currency += .1;
            goal *= 1.5;
        }
    }
}

void rebirth()
{
    cost = 10;
    goal = 100;
    currency = 0;
    rebirthprice *= 2;
}
