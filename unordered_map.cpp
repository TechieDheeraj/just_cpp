#include<iostream>
#include<string>
#include<bits/stdc++.h>

using namespace std;

// Internally unordered_map is implemented using Hash Table
// TC:O(1)

int main() {
    
    unordered_map <string, int> umap;

    umap["Dheeraj"] = 21;
    umap["Kakkar"] = 4;
    umap.insert(make_pair("Techie", 95));
    umap["helllo"] = 7;

    for(auto i = umap.begin(); i != umap.end(); ++i) {
        cout << "Key " << i->first << ", Value " << i->second << endl;
    }

    return 0;
}
