#include<iostream>
#include<vector>
#include<iterator>
#include<string>
#include<bits/stdc++.h>
#include<map>

using namespace std;

class CheckAnagram {

    public:
        int size;

        /*
            bool checkAnagram1(vector <string> &Strings) {
                if ( string.size() != string2.size())
                    return false;
           
            return false;
        }
        
        void display(vector <string> &Strings) {

            for(auto i = Strings.begin(); i != Strings.end(); ++i)
                cout << *i << endl;
        }

        */
    
/*
    Sort Both Strings and compare each Character
        TC : nlogn + nlogn (sort) + n (scan) -> O(nlogn)
        SC: O(1)
*/
        bool checkAnagram1(string first, string second) {
            unsigned int i =0;

            if ( first.size() != second.size())
                return false;

            sort(first.begin(), first.end());
            sort(second.begin(), second.end());

            //this->display(first);
            //this->display(second);

            for(i = 0; i < first.size(); ++i) {
                if ( first[i] != second[i] )
                    return false;
            }
            return true;
        }

/*
    Storing all characters of first string in Map with count
    decrement the counter with second string
    TC: n * 2 * O(1) + n * 2 * O(1) -> O(n)
    SC: O(n)
*/

        bool checkAnagram2(string one, string two) {
            
            unordered_map<char, int> hashMap;

            if(one.size() != two.size())
                return false;

            for(const char c : one) // Range Based For-loops
                hashMap[c]++;

            for(const char c: two) { // Need to add logic ( If characters are different in same size strings )
                if(hashMap[c] < 1)
                    return false;
                hashMap[c]--;
            }
            return true;
        }

/*
    Create an Array of 26 characters/int, travese first string and found (ascii val - 'A') of each char then increment the integer val at that location in this array and then traverse second loop and decrement the int val at same location. If everything goes smooth return true;
TC: n + n = O(n), SC: O(1) // Only 26 chars are initialized
*/

        bool checkAnagram3(string one, string two) {
      
           int lookupArr[26]; // Will store as char - 'A' -> to store in this range ( char array not working ?? 
           unsigned int i = 0, index = 0;

           if(one.size() != two.size())
              return false;

           for(i = 0; i < one.size(); i++) {
               index = one[i] - 'A';
               lookupArr[index]++;
           }
           
           for(i = 0; i < two.size(); i++) {
               index = two[i] - 'A';  
               if( lookupArr[index] == 0 ) // One Extra Char OR New Char came here
                   return false; 

              lookupArr[index]--;
           }

           return true;
       }

        void display(string str) {
            cout << str << endl;
        }
};

int main() {
    
    string first, second;
    CheckAnagram obj;

    /* To store Both Strings inside Vector
        vector <string> Strings;
        cout << "Enter First String" << endl; 

        getline(cin, arr);
        Strings.push_back(arr);

        cout << "Enter Second String" << endl; 
        getline(cin, arr);
        Strings.push_back(arr);
    */

    cout << "Enter First String" << endl;
    getline(cin, first);

    cout << "Enter Second String" << endl;
    getline(cin, second);

//    obj.display(first);
//    obj.display(second);

    //cout << "Is Anagram: " << boolalpha << obj.checkAnagram1(first, second) << endl; 
    //cout << "Is Anagram: " << boolalpha << obj.checkAnagram2(first, second) << endl; 
    cout << "Is Anagram: " << boolalpha << obj.checkAnagram3(first, second) << endl; 

    return 0;
}
