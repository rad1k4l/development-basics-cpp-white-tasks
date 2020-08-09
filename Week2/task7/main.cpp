#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> Reversed(vector<int> items)
{
    vector<int> result = {};
    for (int i = items.size() - 1; i >= 0; i--)
    {
        result.push_back(items[i]);
    }
    return result;
}

int main()
{
    // Test

    vector<int> data = {1, 2, 3};

    data = Reversed(data);

    cout << "data contains: {" << endl;
    for (int num : data)
    {
        cout << "\t" << num << endl;
    }
    cout << "}";

    return 0;
}