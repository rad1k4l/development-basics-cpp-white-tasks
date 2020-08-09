#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a;
    cin >> a;

    vector<int> binary = {};

    while (a != 0)
    {
        if (a % 2 == 0)
        {
            binary.push_back(0);
        }
        else
        {
            binary.push_back(1);
        }

        a = a / 2;
    }

    for (auto it = binary.rbegin(); it != binary.rend(); ++it)
    {
        cout << *it;

    }

    return 0;
}
