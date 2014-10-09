#include <iostream>
#include <cmath>
#include <ctgmath>
 using namespace std;

/**
 * @brief Declaration of a sphere
 * You input a vector and it outputs the cartesian and spherical cords of the vector
 */
class Sphere{
	double radius, theta, phi, xComponent, yComponent, zComponent;
	void determineSphericalCords();
public:
	Sphere (double x, double y , double z): xComponent(x), yComponent(y), zComponent(z) {determineSphericalCords();};
	void printCartesianCoordinates();
};

void Sphere::printCartesianCoordinates(){
	cout << "The cartesian co-ordinates of your surface point are: (" << xComponent << ", " << yComponent << ", " << zComponent << ")\n";  
}

/**
 * @details this method determines the spherical coordinates of said sphere using the cartesian transformations
 * note, theta is the angle from the z axis and phi is angle in the x, y plane
 */
void Sphere::determineSphericalCords(){
	radius = sqrt (pow (xComponent, 2) + pow (yComponent, 2) + pow (zComponent, 2));
	theta = atan (sqrt (pow (xComponent, 2) + pow(yComponent, 2)) / zComponent);
	phi = atan (yComponent / xComponent);
}

/**
 * @brief User Prompt
 * @details The user is asked for three vector components
 */
int main(){
	double x, y, z;	//Vector components
	cout << "Enter the components of a vector pointing to the surface of a sphere: x: ";
	cin >> x;
	cout << "y: ";
	cin >> y;
	cout << "z: ";
	cin >> z;
	//if all entries are zero end program
	if(!(x == 0 && y == 0 && z == 0)){
		Sphere userDetSphere(x, y, z);
		userDetSphere.printCartesianCoordinates();
	}
	else
		cout << "Only entered zero, not a sphere vector but a point";
	return 0;
}