#include <iostream>

using namespace std;

int Factorial(int number)
{
    if (number <= 1)
        return 1;
    int res = 1;

    for (int i = 1; i <= number; i++)
    {
        res *= i;
    }

    return res;
}

int main()
{
    int num;

    cin >> num;

    cout << Factorial(num);
}
