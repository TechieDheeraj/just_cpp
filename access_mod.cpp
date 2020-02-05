#include<iostream>

using namespace std;

/* Demo of Public Class Access Modifier:
	- All the Class members and functions of Public class can be accessed by everyone.
	- Other classes can access them by creating object of the class.
*/
class CircleOne
{
	public:
		int radius;
		
		double compute_area()
		{
			return 3.14*radius*radius;
		} 
};

/* Demo of Private Class Access Modifier:
	- The class members declared as private can be accessed only by the functions inside the class. 
	- Only the member functions or the friend functions are allowed.
*/

class CircleTwo
{
	private:
		int radius;
	
	public:
		double compute_area(int r)
		{
			radius = r;
			return 3.14 * radius * radius;
		}
};

/* Demo of Protected Class Access Modifier:
	- class member declared as Protected are inaccessible outside the class but they can be accessed by any subclass(derived class) of that class
*/


/* Note:
	1. private and protected   

*/
class CircleThree
{
	protected:
		int radius;

	public:	
		double compute_area(int r)
		{
			radius = r;
			return 3.14 * radius * radius;
		}
};

class test_protected : public CircleThree
{
	public:
		void print_radius() 
		{
			cout << "In Child Class, Radius from parent class:"<< radius;
		}
};
	
int main()
{

// Public Access modifier demo
	CircleOne obj_one;
	
	cout << "Enter Radius of CircleOne" << endl ;
	
	cin >> obj_one.radius;

	cout << "Area of circle is: " << obj_one.compute_area() << endl;

// Private Access modifier demo
	CircleTwo obj_two;
	int radius = 0;

	cout << "Enter Radius of CircleTwo" << endl ;

	cin >> radius;	
	
	cout << "Area of circle is: " << obj_two.compute_area(radius) << endl;

// Protected Access modifier demo
	CircleThree obj_three;
	int radius_three = 0;

	cout << "Enter Radius of CircleThree" << endl ;

	cin >> radius_three;	

// Protected class Members access from Inheritence

	test_protected obj;
	obj.print_radius();
	
	cout << "Area of circle is: " << obj_three.compute_area(radius_three) << endl;
}
