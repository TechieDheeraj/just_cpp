#include<iostream>
#include<vector>
#include<iterator>
#include<bits/stdc++.h>
#include<unordered_set>
#include<sys/time.h>

using namespace std;


/* Problem Statement: Two Sum Problem

    Given an Array of n integers, find an efficient algo that determines there exists
    a pair of elements whose sum is S ( Passed into Function )
*/

class TwoSumProb {

    public:
        int size, sum;

        void testcase1(vector <int> &arr) {

           int i;
           /* int count = 0;

            for(auto i = arr.begin(); i != arr.end(); i++) {
                *i = (count+4)*(count+1);
                ++count;
            }
            */

            for(i =0; i<size; i++)
               arr.push_back((i+4)*(i+1));
               //arr.push_back(i);
        }

        void testcase2(vector <int> &arr) {

            int i =0;
            struct timeval cur_time;

            gettimeofday(&cur_time, NULL);
            srand(cur_time.tv_sec);

            for( i =0; i < size; ++i)
                arr.push_back((rand() % sum) + i);
            /*for( auto i = arr.begin(); i != arr.end(); ++i)
                *i = rand() % sum;
            arr.push_back(rand() % sum);
            */
        }


        bool twoSumProb1(vector <int> &arr) { // TC: O(^n2), SC: O1)

            int tmp = 0;

            for(auto i = arr.begin(); i != arr.end(); i++) {
                tmp = sum-*i;
                for(auto j=arr.begin()+1; j != arr.end(); j++)
                    if (*j == tmp) return true; 
            }
            return false;
        }
        
        bool searchElement(vector <int> &arr, int element) {

            int l = 0, m = 0;
            int r = arr.size() - 1;
            
            m = (l+r)/2;
            
            while(r-l > 1) {
                if( arr[m] == element)
                    return true;
                else if( arr[m] > element)
                    r = m-1;
                else
                    l = m+1;

                 m = (l+r)/2 ;
             }       
             
             if ( arr[l] == element || arr[r] == element )
                return true;
             else
                return false;
        }

/* 
    This is sort and search approach. First Sort the Vector and then search using Divide & Prune Approach
*/
        bool twoSumProb2(vector <int> &arr) { // TC: nlogn + log(n-1)! -> nlogn + nlogn -> O(nlogn), SC : O(1)

            int element = 0;
            sort(arr.begin(), arr.end());

            for(auto i = arr.begin(); i != arr.end(); ++i) {
                element = sum - *i;
                return searchElement(arr, element);
            }
            return false;
        }

        bool twoSumProb3(vector <int> &arr) { // TC: 2 * O(1) * n ( Two Operations ( insert, find ) for each Element -> O(n) , SC: O(n) -> Extra Space tradeoff to improve Time Complexity
            
            int element = 0;
            unordered_set <int> hashSet;

            for(auto i = arr.begin(); i != arr.end(); ++i) {
                element = sum-*i;

                if(hashSet.find(element) == hashSet.end()) {
                   // cout << "bucket Nuumber of this element is : " << hashSet.bucket() << ", TBS: " << hashSet.bucket_count() << ", LF: " << hashSet.loadfactor() << endl;
                    hashSet.insert(*i);
                }
                else
                    return true;
            }
            return false;
        }

        void display(vector<int> &arr) {
        
            cout << "vec: [";
            for(auto i = arr.begin(); i != arr.end(); i++)
                cout << *i << " ";
            cout << "]" << endl;
        }
};

int main() {
    
    TwoSumProb obj;

    cout << "Enter size of Array" << endl;

    cin >> obj.size;

    cout << "Enter Value of Sum" << endl;

    cin >> obj.sum;
    //vector< int > arr(obj.size); // Can't do push_back after this because that will allocate more memory
    vector< int > arr;

    //obj.testcase1(arr);

    obj.testcase2(arr);

    obj.display(arr);

    //cout << "Pair existence: " << boolalpha << obj.twoSumProb1(arr) << endl;
    // cout << "Pair existence: " << boolalpha << obj.twoSumProb2(arr) << endl;
    cout << "Pair existence: " << boolalpha << obj.twoSumProb3(arr) << endl;

    //obj.display(arr);

    return 0; 
}
