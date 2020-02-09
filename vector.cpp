#include<iostream>
#include<vector>

using namespace std;

int main() {

    vector<int> g1;

    for(int i=0; i <5; i++)
        g1.push_back(i);

    for(auto i = g1.begin(); i != g1.end(); i++)
        cout << *i << endl;

    return 0;
}
