#include<iostream>
#include<string.h>

using namespace std;

class car
{
  public:      // By Default Class Members are Private
    char brand[10];
    int speedLimit;
    int mileage;
};

int main()
{
  cout << "This Sample Code is introduction to Classes in CPP \n";

  car newCar; // Declaring Objects to access Class (car) Members. 

  strcpy(newCar.brand, "Toyota"); // Setting up class name
  newCar.speedLimit = 80;
  newCar.mileage = 8;

  cout << "Car brand is " << newCar.brand << endl << "Speed limit " << newCar.speedLimit  << endl << "Mileage" << newCar.mileage << endl;

  return 0;
}
