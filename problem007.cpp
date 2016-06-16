#include <iostream>
#include <cmath>
using namespace std;

int theXthPrime(int desiredPrime)
{
	int value = 3, counter = 1, result0, divisor;
	while (counter != desiredPrime)
	{
		result0 = 0;
		int limit = sqrt(value);
		//Determine whether a value is prime or not
		for (divisor = 1; divisor <= limit; divisor++)
		{
			if(value % divisor == 0)
			{
				result0++;
			}
			if(result0 == 2)
			{
				break;
			}
		}
		if(result0 != 2)
		{
			counter++;
		}
		if(counter != desiredPrime)
		{
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
