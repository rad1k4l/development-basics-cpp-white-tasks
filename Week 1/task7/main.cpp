
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string text;

    cin >> text;

    int count = 0;

    for (int i = 0; i < text.size(); i++)
    {
        char sym = text[i];

        if (sym == 'f')
        {
            count++;
        }

        if (count == 2)
        {
            cout << i;
            return 0;
        }
    }

    if (count == 1)
    {
        cout << -1;
    }

    if (count == 0)
    {
        cout << -2;
    }

    return 0;
}
