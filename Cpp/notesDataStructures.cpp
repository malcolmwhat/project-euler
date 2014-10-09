//This program prints the month is february

#include <iostream>

using namespace std;

struct product_t{
	int weight;
}apple;
																							//The enum assigns interger values from 0 to 1 to the array of variables, this is C++ protocol
enum months_t {jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec}y2k; 			//Enums create their own variables of type months_t
void printWeight(product_t product);
void printMonth(months_t month);
int main()
{
	apple.weight = 5;
	printWeight(apple);
	y2k = feb;
	printMonth(y2k);	 
	return 0;
}

/**
 * @brief Prints the weight of the apple
 * @details [long description]
 * 
 * @param product takes as input a struct of type product]
 */
void printWeight(product_t product){
	cout << "The apple's weight is: ";
	cout << apple.weight;
}

void printMonth(months_t month){
	cout << "We are in the month of ";
	switch(month){ 								//Case switch, this checks the passes value of month against different int values and prints based on the input
		case 1:
		cout << "January";
		break;
		case 2:
		cout << "February ";
		break;
		case 3:
		cout << "March";
		break;
		case 4:
		cout << "April";
		break;
		case 5:
		cout << "May";
		break;
		case 6:
		cout << "June";
		break;
		case 7:
		cout << "July";
		break;
		case 8:
		cout << "August";
		break;
		case 9:
		cout << "September";
		break;
		case 10:
		cout << "October";
		break;
		case 11:
		cout << "November";
		break;
		case 12:
		cout << "December";
		break;
	}
}