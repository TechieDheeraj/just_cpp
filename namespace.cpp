#include<iostream>

using namespace std;

// Can Declare same name variable with namespace
namespace first {
    int value = 500;
}

// Global Variable
int value = 100;

int main() {

/*
    int value;
    value = 0;
    double value; // There Can't be two variables with the same name.
    value = 0.0;
*/

    // Local variable
    int value = 300;
    cout << "Addr at local:" << &value << endl;
    cout << "Value in Namspace: " << first::value << endl;
        
    return 0;
}
