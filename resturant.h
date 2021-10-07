#ifndef RESTURANT_H
#define RESTURANT_H

#include <iostream>
#include <vector>
using namespace std;

class Resturant {
    public:
    bool open;
    bool arrived;
    int diners;
    int chickens;
    Resturant()
    {
        cout<<"Clinton Dining Hall is Open!\n";
        diners = 0;
        chickens = 0;
        arrived = false;
        open = true;
    }
    bool hasChickens();
    int serveChicken();
    void makeChickens();
    void arrive();
    void leave();
    void waiter();
};

bool Resturant::hasChickens()
{
    if (chickens >0)
     return true;

    return false;
}

int Resturant::serveChicken()
{
    if (hasChickens())
    {
        cout<<"waiter: Here you go, there is "<<chickens<<" chickens left.";
        chickens--;
        return 1;
    } else {
        cout<<"waiter: So sorry monsieur, there is no more chicken. But the cook is preparing more!."<<endl;
        return 0;
    }
}
void Resturant::makeChickens()
{
    while (open) {
    while (diners > 0) 
    {
      if (chickens < 1)
      {
        cout<<"The chef is preparing many good chickens\n";
        chickens = 4;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout<<"Chef: <ding> Hey Yo! Chickens up!\n";
      }
    }
    if (arrived) open = false;
    }
}

void Resturant::arrive()
{
    cout<<"Waiter: Bonjour monsieur!, Welcome to the Chicken Spot\n";
    if (!arrived) arrived = true;
    diners++;
}

void Resturant::leave()
{
    cout<<"Waiter: Bon voyage, merci beaucoup por manger avec moi!"<<endl;
    diners--;
}
#endif