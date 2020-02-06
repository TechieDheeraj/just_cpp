#include<iostream>
#include<time.h>
#include<limits.h>

/* Problem Statement:
   Array of n terms ( Elements from 1 to n-1 ), return any duplicate no. present in array.
 */
using namespace std;

class FindDuplicate {

	public:
		int size;

		int findDuplicate1(int *arr, int size) {
			int i,j;

			for(i = 0; i < size-1; i++) { // Picked First Element and compared with all rest 
				for(j=i+1; j< size; j++) { // From Next to 0th element till end of array
					if( arr[i] == arr[j] )
						return arr[i];
				}
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
	clock_t time;

	cout << "Enter Size of Array" << endl;
	cin >> obj.size;

	int arr[obj.size];

	obj.testcase1(arr, obj.size);

	obj.display(arr, obj.size);

	time = clock();

	cout << "Duplicate Element is " << obj.findDuplicate1(arr, obj.size) << endl;
	time = clock() - time;

	cout << "Time in Secs:" << ((double)time) / (double)CLOCKS_PER_SEC << endl;

	return 0;
}
