#ifndef PROGRAMER_H
#define PROGRAMER_H

#include <iostream>
#include <fstream>
#include <thread>
#include "resturant.h"
using namespace std;

class Programmer {
   public:
   string name;     //Whats in a name?
   int chickensAte; //The only thing our programmers care about more than data 
                    //structures, algorithms, and compiler design? Chicken of course!
   Programmer(string _name) 
   { 
       this->name = _name;
       cout<<name<<" is on campus.\n"; //anounce our arrival on campus
       chickensAte = 0;
   }
   ~Programmer()
   {
     cout<<name<<": Yawn, i'm outta here!\n"; //its only polite to say goodbye
   }
   void goeat(Resturant* chickenspot);
   void writeCode();
   void eat(Resturant* chickenspot);
};

void Programmer::writeCode()   //Our programmers must do something on campus besides gorge on chicken
{                              //Arent they supposed to be writing code or curriculums or something?
  vector<string> source = {"algolcode.algol", "java_code.java", "tony.bas", "camelCase.pl", "hello.pas"};
  string fname = "secret_project/" + source[(rand()%(source.size() - 1)) - 1];
  char loc[257];
  fstream code;              
  code.open(fname);
  if (code.is_open()) {
    cout<<name<<": "<<endl;
    while (!code.eof())
    {
      code.getline(loc, 256);
      cout<<loc<<endl;
    }
    code.close();
  }
}

void Programmer::goeat(Resturant* chickenspot)
{
  chickenspot->arrive();   //Tell the chicken spot that theyre here
  eat(chickenspot);        //and they hungry!
}

void Programmer::eat(Resturant* chickenspot)
{
   if (chickensAte == 10) //wouldnt want to be greedy and eat ELEVEN chickens, right?
   {
      cout<<name<<": Wooh, ten chickens is my limit! im out of here!\n";
      chickenspot->leave();
      return;
   }

    cout<<name<<": I'm Hungry! garcon, one chicken please!"<<endl;
       
    if (chickenspot->serveChicken() > 0) //Request chicken from the waiter
    {
      cout<<name<<": mmm, yummy!\n";      //if theres chicken, eat it
      chickensAte++;
      std::this_thread::sleep_for(std::chrono::seconds(4)); //wait some time
      eat(chickenspot);                                    //ask for more
    } else {
        cout<<"What!? no chickens!? Fine. I'll write some code while i wait.\n";     //no chicken?
        writeCode();
        std::this_thread::sleep_for(std::chrono::seconds(2)); //wait
        eat(chickenspot);                                     //try again
    }
}

#endif