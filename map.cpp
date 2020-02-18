#include<iostream>
#include<iterator>
#include<string>
#include<map>

/*
    Map store elements in Key Value Pairs:
    No two Values have same Key
*/

using namespace std;

int main() {

    map<string, int> mapOfWords; 

    mapOfWords.insert(make_pair("Earth", 1));
    mapOfWords.insert(make_pair("Moon", 2));

    cout << "size of Map is : " << mapOfWords.size() << endl;

    mapOfWords["Earth"] = 4;

    if ( mapOfWords.insert(make_pair("Earth" , 6)).second == false) {
        cout << "Element with Key 'Earth' not inserted because already existed in Map" << endl;
    }

    for(auto i = mapOfWords.begin(); i != mapOfWords.end(); ++i)
        cout << "Key : " << i->first << ", Value: " << i->second << endl;

    return 0;

}
