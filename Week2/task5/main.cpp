#include <iostream>
#include <string>
#include <vector>


using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination)
{
	for (string s : source)
	{
		destination.push_back(s);
	}
	source.clear();
}


int main()
{
	// Test

	vector<string> item1 = { "data" , "data2" };

	vector<string> item2 = { "lorem" , "ipsum" };

	// move item1 elements to item2
	MoveStrings(item1, item2);


	cout << "item2 contains: { " << endl;
	for (string s : item2)
	{
		cout << "\t" << s << endl;
	}
	cout << "} " << endl;


	cout << "Item1 size(must be 0) => " << item1.size() << endl;


	return 0;
}