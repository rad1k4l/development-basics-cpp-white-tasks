#include <iostream>
#include <string>
#include <vector>


using namespace std;


void UpdateIfGreater(const int first, int& second) 
{

	if (first > second)
	{
		second = first;
	}
}
 

int main()
{
	// Test

	int a = 50, b = 10;

	UpdateIfGreater(a, b);

	cout << "a == " << a << endl;
	cout << "b === " << b << endl;

    return 0;
}