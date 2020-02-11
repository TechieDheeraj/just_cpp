#include<iostream>

using namespace std;

template <typename T>
T myMax(T x, T y) {
    return (x > y) ? x : y;
}

int main() {
    
    cout << "Val is " << myMax<int>(2,3) << endl;
    cout << "char is " << myMax<char>('a','b') << endl;
    cout << "Val is " << myMax<double>(2.0,3.0) << endl;

    return 0;
}
