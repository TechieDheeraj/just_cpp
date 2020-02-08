#include<iostream>
#include<unistd.h> // For sleep()
#include<sys/time.h> // For gettimeoftheday()
#include<limits.h> // For INT_MIN and INT_MAX
#include<bits/stdc++.h>

/* Problem Statement:
   Array of n terms ( Elements from 1 to n-1 ), return any duplicate no. present in array.
 */
using namespace std;

class FindDuplicate {

    public:
        int size;

        int findDuplicate1(int *arr, int size) { // TC: O(n^2) ; SC: O(1)
            int i,j;

            for(i = 0; i < size-1; i++) { // Picked First Element and compared with all rest 
                for(j=i+1; j< size; j++) { // From Next to 0th element till end of array
                    if( arr[i] == arr[j] )
                        return arr[i];
                }
            }
            return INT_MIN;
        }
        // Other Operations + SORT + Comparisons with (n-1) 
        int findDuplicate2(int *arr, int size) { // TC: C * n log(n) + (n-1) --> O(nlog(n))
            int i;

            sort(arr, arr+size);				// Sort + Scan Approach, Sorted Array First.
            for( i = 0 ; i < size-1; i++) {		// Checking the adjacent elements to find duplicate.
                if (arr[i] == arr[i+1])
                    return arr[i];
            }
            return INT_MIN;
        }
        int findDuplicate3(int *arr, int size) { // TC: c * n --> O(n)
            int i;
            int aux[size] = {0}; // SC: O(n) units because apart from input allocating n bytes.

            for(i = 0;i < size; i++) {
                if(aux[arr[i]] != 0) {
                    return arr[i];
                }
                aux[arr[i]] = 1; // This will only work in case of range of elements (1 to n-1) 
            }                     // Otherwise it may go beyond aux array
            return INT_MIN;
        }
        int findDuplicate4(int *arr, int size) { // TC: c * n --> O(n) , SC: O(1) units 
            int i, tmp;

            for(i = 0; i < size; i++) {
                tmp = abs(arr[i]);
                if(arr[tmp] < 0) 
                    return tmp;
                arr[tmp] *= -1; // Setting MSB of same array to check duplicate number 
            }
            return INT_MIN;

        }
        void testcase1(int *arr, int size) {
            int i;

            for(i=0; i < size-1; i++) {
                arr[i] = i+1;
            }
            arr[i] = i;
        }

        void testcase2(int *arr, int size) {
            int i;
            struct timeval curtime;

            gettimeofday(&curtime, NULL);

            srand(curtime.tv_sec % 20 );

            for(i=0; i < size-1; i++) {
                arr[i] = (rand() % size); 
            }
            arr[i] = i;
        }

        void display(int *arr, int size) {
            int i;
            cout << "arr[";
            for(i =0; i < size-1; i++)
                cout << arr[i] << ", ";
            cout << arr[i];

            cout << "]" << endl;
        }
}; 

int main() {

    FindDuplicate obj;
    double elapse_time;
    struct timeval start_time, end_time;

    cout << "Enter Size of Array" << endl;
    cin >> obj.size;

    int arr[obj.size];

    obj.testcase2(arr, obj.size);

    //obj.display(arr, obj.size);

    gettimeofday(&start_time, NULL);

    //cout << "Duplicate Element is " << obj.findDuplicate1(arr, obj.size) << endl;
    //cout << "Duplicate Element is " << obj.findDuplicate2(arr, obj.size) << endl;
    //cout << "Duplicate Element is " << obj.findDuplicate3(arr, obj.size) << endl;
    cout << "Duplicate Element is " << obj.findDuplicate4(arr, obj.size) << endl;

    //obj.display(arr, obj.size);

    gettimeofday(&end_time, NULL);

    elapse_time = (end_time.tv_sec - start_time.tv_sec) * 1000.0;
    elapse_time += (end_time.tv_usec - start_time.tv_usec) / 1000.0;
    cout << "Time taken: " << elapse_time << " ms" << endl;
    //cout << "Time taken is " << time << "." << end_time.tv_usec + start_time.tv_usec << " seconds" << setprecision(5) << endl;

    return 0;
}
