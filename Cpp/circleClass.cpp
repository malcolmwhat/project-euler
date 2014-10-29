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
 	double getAreaCircle();
 public:
 	void setRadius(int);
 	void printAreaCircle();
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
 void Circle::printAreaCircle(){
	cout << "The area of the circle of radius " << radius <<" is: " << getAreaCircle() << '\n';
}

/**
 * @brief Main
 * @details All front end interaction done here
 * Circle circle declares a circle object of type Circle
 * @return ends the program
 */
int main(){
	Circle circle;
	int r, x, y;
	cout << "Radius of a circle: \n";
	cin >> r;
	cout << "Center coordinates: \n X: " ;
	cin >> x;
	cout << "Y: ";
	cin >> y;
	circle.setRadius(r);
	circle.printAreaCircle();
	return 0;
}


//Some interesting geometry calculations can be done once you've picked up the math library.