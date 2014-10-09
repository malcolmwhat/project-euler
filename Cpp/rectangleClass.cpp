/**
 *This file contains a class with different properties and funtions within the rectangle Class.
 *For the most part this is simply for learning purposes
 */ 

/**
 * The following section is based of an example on the cpp tutorials online
 */

 #include <iostream>
 using namespace std;

/**
 * @brief Declaration of class rectangle
 * @details 
 * Class name : Rectangle
 * Object name(s): rect
 * Local Parameters : width, height. Note that if not explicitly stated, the parameters are PRIVATE
 * Local Functions: None
 * Public Params: None
 * Public functions: setValues (see bellow), area() returns the area of the rectangle. 
 */
 class Rectangle{
 	int width, height;				
 public:
 	void setValues(int,int);  			//References function bellow
 	int area() {return width*height;} 	//Simple analysis will show that this sends back the area of the current rectangle
 };


/**
 * @brief Sets the values of height and width of the rectangle
 * @details
 * 
 * @param x	sets width
 * @param y Sets height
 */
 void Rectangle::setValues(int x, int y){
 	width = x;
 	height = y;
 }

 int main () {
  Rectangle rect;
  rect.setValues (3,4);
  cout << "area: " << rect.area();
  return 0;
}