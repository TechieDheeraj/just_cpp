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
				arr[i] = (rand() % 100) + 5; 
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
	long time;
	struct timeval start_time, end_time;

	cout << "Enter Size of Array" << endl;
	cin >> obj.size;

	int arr[obj.size];

	obj.testcase2(arr, obj.size);

	//obj.display(arr, obj.size);

	gettimeofday(&start_time, NULL);

	//cout << "Duplicate Element is " << obj.findDuplicate1(arr, obj.size) << endl;
	cout << "Duplicate Element is " << obj.findDuplicate2(arr, obj.size) << endl;

	//obj.display(arr, obj.size);

	gettimeofday(&end_time, NULL);

	time = end_time.tv_sec - start_time.tv_sec;

	cout << "Time taken is " << time << "." << end_time.tv_usec + start_time.tv_usec << " seconds" << setprecision(5) << endl;

	return 0;
}
