#include<iostream>
#include<vector>
#include<iterator>
#include<string>
#include<sys/time.h>
#include<unordered_map>

#define ALPHABETS 26 
using namespace std;

/* 
    Problem Statement:
        Given an array of Strings, find algorithm that returns no. of distinct Anagram classes available in Array
*/

class GroupAnagram {
    
    public:
        int size, len;

        bool checkAnagram(string one, string two) {
           
            unordered_map<char, int> hashMap;

            if( one.size() != two.size() )  
                return false;
           
            for(char c: one) 
                hashMap[c]++;

            for(char c: two) {

                if(hashMap[c] < 1)
                    return false;

                hashMap[c]--;
            }

            return true;
        }

/*
    Iterating through each string in a Vector of Strings and comparing if anagram or not.
    Maintaining Counter to check the Distinct Anagram classes
    TC:  n^2 * m  + n -> O(n^2 * m), SC: O(n)
*/
        int groupAnagram1(vector <string> &array) {
            
            vector <bool> count(size);
            int distinctAnagram = 0;

            for(auto i = array.begin(); i != array.end(); ++i) {
                cout << "String is " << *i << endl; 

                for(auto j = i+1; j!= array.end(); ++j) {

                    if(count[i-array.begin()])
                        continue;

                    if(checkAnagram(*i,*j)) {
                        cout << "At Index: " << j-array.begin() <<  " Group: [i,j] " << *i << ", " << *j << endl;
                        count[j-array.begin()] = true;
                    }
                }
            }
            for (bool k: count) {
                if(k)
                    distinctAnagram++;
            }

            return distinctAnagram;
        }

        void testCase1(vector <string> &array) {
            
            struct timeval cur_time;
            string tmp = "";

            gettimeofday(&cur_time, NULL);
            srand(cur_time.tv_sec);

            for(int i = 0; i <size; i++) {
                for (int j=0; j < len; j++)
                    tmp += (char)('a'+ (rand() % ALPHABETS));
                    //tmp.push_back((char)('a'+ (rand() % ALPHABETS)));

                array.push_back(tmp);
                tmp = "";
            }
        }
};

int main() {
   
    GroupAnagram obj;

    cout << "Enter Length of Each String" << endl;

    cin >> obj.len;

    cout << "Size of Array of Strings" << endl;

    cin >> obj.size;
    
    vector <string> array;

    obj.testCase1(array);

    cout << "Distinct Anagram: " << obj.groupAnagram1(array) << endl;

    return 0;
}

