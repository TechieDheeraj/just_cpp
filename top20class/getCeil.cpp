#include<iostream>
#include<unistd.h> // For sleep()
#include<stdlib.h>
#include<sys/time.h>
#include<bits/stdc++.h> // This also internally including sort
//#include<algorithm> //  For SORT function

using namespace std;

/* Problem Statement:
   Given an Sorted array Return Ceil(X) -> next higher value in array
 */

// Divide and Prune thinking problem
class GetCeil {

    public:
        int size, key_element;

        void display(int *arr, int size) {
            int i;

            cout << "[";
            for(i =0 ;i < size-1; i++)
                cout << arr[i] << ",";
            cout << arr[i] <<"]" << endl;
        }

        int getCeil1(int *arr, int size, int in) {
            int i = 0;

            for(i=0; i <size; i++) {
                if(arr[i] >= in)
                    return arr[i];
            }
            return INT_MIN;
        }

        int getCeil2(int *arr, int size, int in) {
            int l = 0, r;
            int m = 0;

            r = size-1;
            while(r-l > 1) {
                m = (l+r)/2;
                if(arr[m] >= in) 
                    r = m;  
                else
                    l = m+1;
            }
            if ( arr[l] >= in )
                return arr[l];
            else
                return arr[r];
        }

        int testcase1(int *arr, int size, int key_element) {
            int i=0;
            struct timeval cur_time;

            gettimeofday(&cur_time, NULL);
            srand(cur_time.tv_sec);

            for(i = 0; i < size; i++) {
                arr[i] = ( rand() % (key_element+1))+4; // Taking Modulus of Key Element because If I take Size here in modulus, What if key_element entered by user is large                    
            }

            sort(arr, arr+size);
        }
};

int main() {

    GetCeil obj;

    cout << "Enter the size of array" << endl;

    cin >> obj.size;

    int arr[obj.size];

    cout << "Enter element" << endl;

    cin >> obj.key_element;

    obj.testcase1(arr, obj.size, obj.key_element);

    obj.display(arr, obj.size);

    //cout << "Ceil of Entered Element is :" << obj.getCeil1(arr, obj.size, obj.key_element) << endl;;
    cout << "Ceil of Entered Element is :" << obj.getCeil2(arr, obj.size, obj.key_element) << endl;;

    return 0;
}
