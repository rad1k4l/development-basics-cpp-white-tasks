
#include <iostream>

using namespace std;

double percent(int total, int percent)
{

    return total * (percent / 100);
}

int main()
{
    int a, b;

    cin >> a >> b;

    for (int i = a; i < b + 1; i++)
    {
        if (i % 2 == 0)
        {
            cout << i << " ";
        }
    }

    return 0;
}