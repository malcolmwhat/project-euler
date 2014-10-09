//This contains notes on classes, check out rectangleClass and circleClass for applications of general classes
/**
 * The following will introduce constructors.
 * Constructors are basically setting all required fields upon declaration of variables
 * Constructors do not have a return type in their set methods
 * COnstructors can only be called once, you could have a modify function set values that could change the originally constructed object
 * Constructors can react to the input
 */

 #include <iostream>
 using namespace std;
//////Clases//////////////////////////////////////////////////////////////////////////////////////////////
 class Circle{
 	double radius;
 public:
 	Circle(double x) : radius(x) {}
 	double getAreaCircle();
 };

 class Cylinder{
 	Circle base;
 	double height;
 public:
 	Cylinder(double r, double h) : base (r), height(h) {}
 	double getVolumeCyl() {return base.getAreaCircle() * height;}
 };

/////Class methods///////////////////////////////////////////////////////////////////////////////////////////////
 double Circle::getAreaCircle(){
 	return ((radius)*(radius)*3.14);
 }

int main(){
	Cylinder pole (1, 2);
	Cylinder * spam, * eggs, * monty;
	spam = &pole;
	eggs = new Cylinder (2, 1);
	monty = new Cylinder[3] { {1, 1}, {1, 1}, {1, 1}};
	cout << pole.getVolumeCyl() << '\n';
	cout << (*spam).getVolumeCyl() << '\n';
	cout << eggs->getVolumeCyl() << '\n';
	cout << monty[0].getVolumeCyl() << '\n';
	cout << monty[1].getVolumeCyl() << '\n';
	cout << monty[2].getVolumeCyl() << '\n';
	return 0;
}
