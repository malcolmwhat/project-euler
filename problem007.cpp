/**
 * @brief DISCLAIMER
 * @details NOT COMMMENTED PROPERLY, & not optimized completely, however it is functional
 * @return [description]
 */


/**
 * I need to get the 10 001st prime number.
 * What do I need to identify, 
 * 		value = The value of the current number
 * 		counter = The value corresponding to which prime this number is 
 * 		isPrime() or if statement - An algorithm that tests is a number is prime, when it evaluates to true it increments the counter
 * 		ALGORITHM WITHIN THE WHILE LOOP
 * 			Test For Prime
 * 				need a loop that goes from divisor = 1 to divisor = sqrt(value)
 * 			if it's prime increment both the value and the prime counter, if not only increment the value
 * 		
 * 		A loop that uses the isPrime algoritm untill the value corresponding the which prime number i'm at = 10001
 * 			This loop will increment the value of the current number
 * 		Print the value
 */

#include <iostream>
#include <cmath>
using namespace std;

int theXthPrime(int dsrd){
	int value = 3, counter = 1, result0, divisor;
	while (counter != dsrd){
		result0 = 0; 
		int limit = sqrt(value);
		//Determine whether a value is prime or not
		for (divisor = 1; divisor <= limit; divisor++){
			if(value % divisor == 0)
				result0++;
			if(result0 == 2)
				break;
		}
		if(result0 != 2)
			counter++;
		if(counter != dsrd){
			value++;
		}
	}
	return (value);
}

int main()	{
 	int x, value;
 	cout << "Which prime do you want? " << '\n';
 	cin >> x;
 	value = theXthPrime(x);
 	cout << "The " << x << "th prime number is: " << value;
 	return 0;
 }