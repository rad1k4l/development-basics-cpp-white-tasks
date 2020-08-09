
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    double a, b, c;

    cin >> a >> b >> c;


    if (a==0 && b == 0)
    {
        cout << ' ';
        return 0;
    }
    
    if (a == 0)
    {
        double res = (-1 * c)/b;
        cout << res;
        return 0;
    }



    double d = (b * b) - (4 * a * c);

    if (d < 0)
    {
        cout << ' '; 
        return 0;
    }

    double x1 = ( (-1 * b) + sqrt(d)) / (2 * a);

    double x2 = ( (-1 * b) - sqrt(d) ) / (2 * a);    

    cout << x1 << " ";
    if (x1 != x2)
    {
        cout << x2;
    }
    

    return 0;
}