#include<iostream>

using namespace std;

class A {

    private:
        int a = 30;

    public:
        void display() {
           cout << "In Parent " << a << endl;
        }
    
    A() {
        cout << "A Constructor " <<  endl;
    }
    

    A(int c) {
        cout << "Parameterized Constructor Called " <<  endl;
        a = c;
    }

};

class B : public A {

    private:
        int b = 10;

    public:
        void display();

    B() {
        cout << "B Constructor " <<  endl;
    }
};

class C {

    private:
        int c = 33;

    public:
        void display() {
            cout << " C is " << c << endl;
        }
};

class copyConstr {

    private:
        int hello = 10;

    public:
        void display() {
            cout << "hello : " << hello << endl;
        }

        void setHello(int val) {
            hello = val;
        }

        int getHello() {
            return hello;
        }

     copyConstr() { } // Default Constructor

     copyConstr(copyConstr &r) { // Copy Constructor
        hello = r.hello;
     }

};

void B::display() {
    cout << "Inside Child " << b << endl;
}

/*
    NOTE: 

       empty array of 5 elements:
			int * arr = new int[5]; 
	
	   pointer to single integer with value 5
			int * arr = new int(5);

As for the vector syntax: This syntax is not specific to vectors. It's a "direct initialization" where the stuff between the parentheses are the constructor's arguments. vector<int> is a type that offers a couple of overloaded constructors. In this case, it'll create a vector of size 5 with default-initialized ints (all zeros).

		std::vector<int> vec(5);
*/

int main() {
    
 //   B *obj = new B();
    A *obja = new A(22);
    A *objb = new B; // 
    
    copyConstr test;

    test.setHello(33);

    copyConstr test1(test);

    cout << "test1 " << test1.getHello() << endl;


//    B *objd = new A();
//    A *objc = new C(); // new keyword will Allocate and Inilialize the memory So Expecting same Typr in Left Side.

 //   objd->display();
    //cout << " b is " << obj->b << endl;

    return 0;
}
