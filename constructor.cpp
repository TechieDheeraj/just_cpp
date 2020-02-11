#include<iostream>

using namespace std;

class Geeks {

    public:
        int id;

        // Default Constructor
        Geeks() {
            cout << "Default Constructor is Called" << endl;
            id = -3;
        }

        void print_id(); // This Member function is defined outside class

        // Parametrized Constructor
        Geeks(int x) {
            cout << "Parametrized Constructor Called" << endl;
            id = x;
        }
        
        // Destructor is Called
        ~Geeks() {
            cout << "Destructor is called for id: " << id << endl;
        }
};

// Defintion of print_id using scope resolution operator ::
void Geeks::print_id() {
    cout << "id is " << id << endl;
}

int main() {

    Geeks obj1; // Default Contructor is called

    int i = 0;

    cout << "ID: " << obj1.id << endl; 
    obj1.print_id();

    Geeks obj2(30); // Parametrized Constructor is Called

    cout << "ID: " << obj2.id << endl; 
    obj2.print_id();

    while(i<5) {
        Geeks obj3;
        obj3.id = i;
        i++;
    } // Scope for obj3 ends here

    cout << __cplusplus / 100 % 100 << '\n'; // Two Check C++ Version

    return 0;
}
