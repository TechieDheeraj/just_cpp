#include<iostream>
#include<sys/time.h>
#include<limits.h>
#include<unistd.h> // for sleep

/* Problem Statement:
   Array Consists of Zeroes followed by non-zeroes return No. of Zeroes available in the array.
 */

using namespace std;

class CountZeroes
{
    public:
        int size; // Size of array

        int countZeroes1(int *arr, int size) {
            int i;

            for(i=0; i < size; i++) { // TC: O(n), SC: O(1)
                if (arr[i] != 0) 
                    break;
            }
            return i;
        }
        
        int countZeroes2(int *arr, int size) {
            int m = 0, l, r;

            l = 0;
            r = size-1;

            while( (r - l) > 1) { // TC: O(logn), SC: O(1)
                m = (l+r)/2;
                if (arr[m] == 0) 
                    l = m;
                else
                    r = m-1;
            }
            if(arr[r] == 0)
                return r+1;
            return l+1;
        }

// NOTE: We can also solve this by taking two index variables and eleminating the 2/3 array with every two comparisons 
//       and found the 1/3 of array that would take: TC: 2 * log3(n) which is not better than log2(n) 

        int testcase1(int *arr, int size) { // All Zeroes in an array but last element is 1.
            int i;
            
            for(i = 0; i < size-1; i++)
                arr[i] = 0;  
            arr[i] = 1;
        }
        
        void display(int *arr, int size) {
            int i = 0;
            
            cout << "[";
            for( i = 0; i < size-1; i++) 
                cout << arr[i] << ",";
            cout << arr[i] << "]" << endl;
        }
};

int main() {

    CountZeroes obj;
    double elapse_time;
    struct timeval start_time, end_time;

    cout << "Enter size of Array" << endl;

    cin >> obj.size;
    int arr[obj.size];

    obj.testcase1(arr, obj.size);

    //obj.display(arr, obj.size);

    gettimeofday(&start_time, NULL);

    cout << "No. of Zeros are " << obj.countZeroes1(arr, obj.size) << endl;

    gettimeofday(&end_time, NULL);

    elapse_time = (end_time.tv_sec - start_time.tv_sec) * 1000.0;
    elapse_time += (end_time.tv_usec - start_time.tv_usec) / 1000.0;
    cout << "Time taken: " << elapse_time << " ms" << endl;

    return 0;
}
