//This takes an input and returns the modulus of eleven

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int x = 1;
	while (x != 0){
		cout << "Enter a number, 0 to exit \n";
		cin >> x;
		cout << x << " mod 11 = " << (x % 11) << '\n';
	}
	return 0;
}