/**
 * The scope of this cpp file is to create a circle class and allow return of it's area and other interesting stuff
 */

#include <iostream>
using namespace std;

/**
 * @brief Circle Class
 * @details Contains the parameters and functions that can be done on a Circle
 * 
 * @param  
 * Local Params: 
 * radius: the radius of a circle
 * public Fns:
 * setRadius: Allows you to input a radius
 * getAreaCircle: Returns the area of the given circle
 */
 class Circle{
 	double radius;
 public:
 	void setRadius(int);
 	double getAreaCircle();
 };

/**
 * @brief A function for setting the radius
 * @param x : input from user once prompted for the radius, sets the radius of the circle
 */
 void Circle::setRadius(int x){	
 	radius = x;
 }
 double Circle::getAreaCircle(){
 	return ((radius)*(radius)*3.14);
 }

/**
 * @brief Main
 * @details All front end interaction done here
 * Circle circle declares a circle object of type Circle
 * @return ends the program
 */
int main(){
	Circle circle, circleTwo;
	int i, j;
	cout << "Enter the radius of a circle: \n";
	cin >> i;
	cout << "Enter the radius of another circle: \n";
	cin >> j;
	circle.setRadius(i);
	cout << "The area of the circle of radius " << i <<" is: " << circle.getAreaCircle() << '\n';
	circleTwo.setRadius(j);
	cout << "The area of the circle of radius " << j <<" is: " << circleTwo.getAreaCircle();
	return 0;
}


//Some interesting geometry calculations can be done once you've picked up the math library.