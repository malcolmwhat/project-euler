//THE QUESTION being answered is the following:
	//If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
	//Find the sum of all the multiples of 3 or 5 below 1000.

//FUNCTION
//This code successfully finds the answer and prints it to the screen

#include <iostream>
using namespace std;

	int fibonaci3by5(){													//method with no input params and return type int
		int currentValue = 0;											//Creates a counter variable of type int with value 0
		int sum = 0;													//Initializes a sum variable at 0
		while (currentValue < 1000){									//Will execute untill counter is 1000 or larger
			if((currentValue % 3) == 0 || (currentValue % 5) ==0)		//checks if currentvalue is a multiple of 3 or 5
				sum += currentValue;									//If the above statement is true, the current value is added to the sum
			currentValue++;												//Increments the current value
		}					
		return sum;														//Returns the sum value to the function call in the main method
	}
	
	int main() 								//Main Method
	{	
		int sum = fibonaci3by5();			//Calls the fibonaci3by5 method sends no input params, assigns the return value to sum
		cout << "The sum is: " << sum;		//Prints "The sum is: (value of the sum inserted here)"
		return 0;							//Explicitly exit the program
	}