#include<iostream>
#include<string>
#include<iterator>
#include<bits/stdc++.h>

using namespace std;

/* 
    It’s doesn’t allow duplicate elements i.e. it only contains unique elements.
*/

// Unordered Set is implemented using Hash Table where keys are hashed into indices of hash table.

// TC: O(1)

int main() {

    unordered_set <string> stringSet;

    stringSet.insert("code");
    stringSet.insert("in");
    stringSet.insert("cpp");
    stringSet.insert("is");
    stringSet.insert("fast");

    string key1 = "slow";
    if(stringSet.find(key1) == stringSet.end())
        cout << "Key not found: " << key1 <<endl;

    string key2 = "fast";
    if(stringSet.find(key2) == stringSet.end())
        cout << "Key not found: " << key2 <<endl;
    else
        cout << "Found Key: " << key2 <<endl;


    for(auto i = stringSet.begin(); i != stringSet.end(); ++i)
        cout << *i << endl;
    return 0;
}
