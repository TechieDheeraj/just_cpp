#include<iostream>
#include<bits/time.h>
#include<limits.h>

/* Problem Statement:
   Array Consists of Zeroes followed by non-zeroes return No. of Zeroes available in the array.
 */

using namespace std;

class CountZeroes
{
    public:
        int size; // Size of array
        int countZeroes1(int *arr, size) {
            int i;

            for(i=0; i < size; i++) {


                return INT_MIN;
            }
        }

        int testcase1(int arr, int size) {
            int i;
            
            for(i = 0; i < size; i++) {
                arr[i] = 0;  
            }   
        }


};

int main()
{
    CountZeroes obj;

    cout << "Enter size of Array" << endl;

    cin >> obj.size;
    int arr[obj.size];

    obj.testCase(arr, obj,size);




    return 0;
}
