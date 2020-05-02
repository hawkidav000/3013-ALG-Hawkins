#include <iostream>
#include <queue>

using namespace std;

#define endl "\n"


int main() {
  int numCases;         //number of cases in input file
  int maxCars;          //number of cars the ferry can carry
  int travTime;         //how long it takes the ferry to travel
  int numCars;          //number of cars that will be carried across
  int arrTime;          //time that the car arrives at the bank
  int ferryPos;         //side of the river that the ferry is on
  int currentTime;      //keeps track of the current time
  bool travelled = false;  //checks to see if the boat loaded any cars
  bool firstTrip;        //Keeps track of whether or not the first partial trip was checked for
  int numLoaded;        //Keeps track of number loaded on boat
  int numTrips;
  int largestGap;       //largest time gap between the arrival of the cars
  int numOnPartial;     //Number of cars loaded onto ferry for the first partial trip

  queue<int> cars;

  cin >> numCases;

  for(int i = 0; i < numCases; i++)
  {
    currentTime = 0;
    firstTrip = false;
    numTrips = 0;
  
    cin >> maxCars >> travTime >> numCars;

    // cout << maxCars << endl;
    // cout << travTime << endl;
    // cout << numCars << endl;

    for(int n = 0; n < numCars; n++)
    {
      cin >> arrTime;
      cars.push(arrTime);
    }


    // //Checking to make sure the cars are read in correctly
    // for (int m = 0; m < size; m++)
    // {
    //   cout << cars.front() << endl;
    //   cars.pop();
    // }

    numOnPartial = numCars % maxCars;
    firstTrip = false;

    while(!cars.empty())
    {
      //cout << cars.front() << endl;

      if (!firstTrip && numOnPartial != 0)
      {
        for (int j = 0; j < numOnPartial && !cars.empty(); j++)
        {
          currentTime = cars.front();
          cars.pop();
        }
        currentTime = currentTime + (2*travTime);
        numTrips++;
      }
      if (firstTrip && !cars.empty())
      {
        for (int j = 0; j < maxCars && !cars.empty(); j++)
        {
          if(cars.front() > currentTime)
          {
            currentTime = cars.front();
          }
          cars.pop();
        }
      }
      if (!cars.empty() && firstTrip)
      {
        currentTime = currentTime + (2*travTime);
        numTrips++;
      }
      if(cars.empty())
      {
        currentTime = currentTime + travTime;
        numTrips++;
      }
      firstTrip = true;
    }
    cout << currentTime << " " << numTrips << endl;
  }
}
