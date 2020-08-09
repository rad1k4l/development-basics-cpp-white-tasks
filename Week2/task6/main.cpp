#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Reverse(vector<int> &items)
{
    for (int i = 0; i < items.size() / 2; i++)
    {
        int temp = items[i];
        items[i] = items[items.size() - 1 - i];
        items[items.size() - 1 - i] = temp;
    }
}

int main()
{
    // Test

    vector<int> data = {1, 2, 3};

    Reverse(data);

    cout << "data contains: {" << endl;
    for (int num : data)
    {
        cout << "\t" << num << endl;
    }
    cout << "}";

    return 0;
}
