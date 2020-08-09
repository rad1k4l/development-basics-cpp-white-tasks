
#include <iostream>
#include <string>

using namespace std;

int main() {
    string x, y, z;

    cin >> x >> y >> z;


    string minimum = x;


    if (minimum > y) {
        minimum = y;
    }

    if (minimum > z )
    {
        minimum = z;
    }
    
    cout << minimum;

    return 0;
}