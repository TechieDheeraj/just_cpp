#include<iostream>
#include<string>

using namespace std;

struct playerInfo
{
  int skill_level;
  string name;
};

int main()
{

  int i = 0;
  struct playerInfo players[5];

  for( i =0; i< 5; i++ )
  {
    cout << "Please Enter name of Players\n";
    cin >> players[i].name;
    cout << "Enter Player Skills\n";
    cin >> players[i].skill_level;
  }

  for ( i =0 ; i< 5; i++)
  {
    cout << players[i].name << " is at skill:" << players[i].skill_level << endl;
   }

  return 0;
 }

