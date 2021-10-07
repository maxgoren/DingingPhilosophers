/* the dining philosophers problem, rewritten starring
   the greats of programming language design and 
   algorithm design and analysis */
#include <iostream>
#include <fstream>
#include <ctime>
#include <thread>
#include <queue>
#include "programer.h"
using namespace std;

void dinnerTime(vector<Programmer*> diners)
{
  //Without the use of semaphores or mutexes, Dijkstra's original solution to the problem
  //The code falls into deadlock scenario of Resource starvation.
  Resturant *diningHall;                    //Pointer to a resturant object
  diningHall = new Resturant;               //create a resutrant on the heap
  std::thread chef(&Resturant::makeChickens, diningHall);  //spawn it as a thread
  
  std::thread *diner;               //For creating threads for each diner
  std::vector<thread*> threadPool; //for managing each diner thread
  for (auto pgr : diners)
  {
    diner = new thread(&Programmer::goeat, pgr, diningHall);  //create a thread for each hungry programmer
    threadPool.push_back(diner);                              //add it to the thread pool
    std::this_thread::sleep_for(std::chrono::seconds(1));     //sleep for one second
  }
  chef.join();                                          //when the diners have all left, join the dining hall thread
  for (auto d : threadPool)                             //and then join each programmers thread back to the main.
    d->join();
}


void Just_One_Diner()
{
  //This function is here to show, that when we have just One Programmer
  //There is, as should be obvious, no competition for Resources
  Programmer rob("Sedgewick");
  Resturant *diningHall;
  diningHall = new Resturant;
  std::thread canteen(&Resturant::makeChickens, diningHall);
  std::thread sedge(&Programmer::goeat, rob, diningHall);
  canteen.join();
  sedge.join();
}


int main(int argc,char *argv[])
{  
    vector<string> programmers = { "Donald Knuth", "Edsgar Dijkstra", "Tony Hoare", "Robert Sedgewick", "Nick Wirth"}; //name our programmers
    vector<Programmer*> theGreats;           //vector of our programmers
    for (int i = 0; i < 5; i++)
    {
      theGreats.push_back(new Programmer(programmers[i]));  //bring our programmers to life, and name them
    }
    for (auto pgr : theGreats)              //put those programmers to work! 
    {                                       //this part is not pertenant to
        pgr->writeCode();                   //the issue, its just fun :-P
    }
    //Just_One_Diner(); //Sedgewick needed an early snack.
    /* Note:  */
    cout<<"...some time later..."<<endl<<" After discussing between themselves what programming language to implement there program in, the Programmers are Hungry"<<endl;
    cout<<"Its Dinner Time!\n";
    dinnerTime(theGreats);
    
   //alt();
    return 0;
}