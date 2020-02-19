#include<iostream>
#include<set>
#include<iterator>

using namespace std;

/* 
    It’s doesn’t allow duplicate elements i.e. it only contains unique elements.
*/

int main() {

    // Set is Implemented as Balanced binary tree. TC: O(logn)

    // Empty Set Container
    set <int> setOfNumbers; // Instead of int Template type could be anything (String, Class, char .. etc)

    setOfNumbers.insert(1);
    setOfNumbers.insert(2);
    setOfNumbers.insert(3);
    setOfNumbers.insert(4);

    cout << "Size of SetOfNumbers is : " << setOfNumbers.size() << endl;

    for( auto i = setOfNumbers.begin(); i != setOfNumbers.end(); ++i)
        cout << *i << endl;

    return 0;
}
