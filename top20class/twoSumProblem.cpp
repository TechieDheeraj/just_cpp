#include<iostream>
#include<vector>

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

        bool twoSumProb(vector <int> &arr) {

            int tmp = 0;

            for(auto i=arr.begin(); i != arr.end(); i++) {
                tmp = sum-*i;
                for(auto j=arr.begin()+1; j != arr.end(); j++)
                    if (*j == tmp) return true; 
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

    obj.testcase1(arr);

    obj.display(arr);

    cout << "Pair existence: " << boolalpha << obj.twoSumProb(arr) << endl;

    return 0; 
}
