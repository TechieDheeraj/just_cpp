#include<iostream>
#include<vector>

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
       
        bool twoDSearch(vector < vector <int> > &matrix) { // TC: O(n^2), SC: O(1)
            int i, j;
            
            for(i = 0; i < row; i++) {
                for(j = 0; j < row; j++) {
                    if(matrix[i][j] == key_element) 
                        return true;
                }
            }
            return false;
        }

        void testcase1(vector < vector <int> > &matrix) {
            int i, j, count = 0;

            for(i = 0; i < row; i++) {
                for(j = 0; j < row; j++)
                   matrix[i][j] = ++count;
            }
        }

        void display(vector < vector <int> > &matrix) {
            int i, j;

            cout << "\n"; 
            for(i = 0; i < row; i++) {
                for(j = 0; j < row; j++)
                    cout << matrix[i][j] << " ";
                cout << "\n";    
            }
        }    
};

int main() {

    TwoDSearch obj; 

    cout << "Enter No. of Rows Of Matrix" << endl;
    cin >> obj.row; // Assuming ROW and COL are same

     //vector< vector <int> > matrix; // Creating a 2-D Array(vector) 
    vector< vector <int> > matrix(obj.row, vector <int> (obj.row)); // Creating a 2-D Array(vector) with obj.row rows and cols
    
    cout << "Enter Key element to Search" << endl;

    cin >> obj.key_element;

    obj.testcase1(matrix);

    obj.display(matrix);
    cout << "Element existence: " << boolalpha << obj.twoDSearch(matrix) << endl;

    return 0;
}
