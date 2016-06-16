#include <iostream>
using namespace std;

int fibonaci3by5()
{
    int currentValue = 0;
    int sum = 0;
    while (currentValue < 1000)
    {
        if(currentValue % 3 == 0 || currentValue % 5 == 0)
        {
            sum += currentValue;
            currentValue++;
        }
        return sum;
    }
}

int main()
{
    int sum = fibonaci3by5();
    cout << "The sum is: " << sum;
    return 0;
}
