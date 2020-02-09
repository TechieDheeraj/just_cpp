#include<iostream>
//#include<bool.h>

using namespace std;

/* Problem Statement: Grid Search
    Search a element in 2-D Matrix, Matrix is Row Wise Sorted:
                [1, 2, 5]    // Sorted
                [7, 10, 12]  // Next Row is Continuous Sort of First Row
                [14, 16, 17]
*/

class TwoDSearch {

    public:
        int row, key_element;

        bool twoDSearch(int **arr, int row, int key_element) {
            int i, j;
            
            for(i = 0; i < row; i++) {
                for(j = 0; j < row; j++) {
                    if(arr[i][j] == key_element) 
                        return true;
                }
            }
            return false;
        }

        void testcase1(int **arr, int row) {
            int i, j, count = 0;

            for(i = 0; i < row; i++) {
                for(j = 0; j < row; j++)
                    arr[i][j] = ++count;
            }
        }

        void display(int **arr, int size) {
            int i, j;
            cout << "arr";

            for(i = 0; i < row; i++) {
                for(j = 0; j < row; j++)
                    cout << arr[i][j] << ", ";
            }
        }    
};

int main() {

    TwoDSearch obj; 

    cout << "Enter No. of Rows Of Matrix";
    cin >> obj.row; // Assuming ROW and COL are same

    int arr[obj.row][obj.row];
    
    cout << "Enter Key element to Search" << endl;

    cin >> obj.key_element;

    obj.testcase1(arr, obj.row);

    cout << obj.twoDSearch(arr, obj.row, obj.key_element) < endl;

    return 0;
}
