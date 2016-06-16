#include <iostream>
using namespace std;

// Finds the sum of all even fibonacci numbers between 2 and 4 million
int fibonacciEven()
{
	int sumOfEvenFibonacci = 0;
	int currentTerm = 2;
	int previousTerm = 1;
	int nextTerm = 0;
	while (currentTerm < 4000000)
	{
		if (currentTerm % 2 == 0)
		{
			sumOfEvenFibonacci += currentTerm;
		}
		nextTerm = currentTerm + previousTerm;
		previousTerm = currentTerm;
		currentTerm = nextTerm;
	}
	return sumOfEvenFibonacci;
}

int main()
{
	int sum = fibonacciEven();
	cout << "Sum of even fibonacci numbers < 4 million is: " << sum;
	return 0;
}
