#include <iostream>
#include <string>
#include <vector>


using namespace std;


bool IsPalindrom(string s)
{
	int n = s.size();
	for (int i = 0; i < (n / 2); ++i) {
		if (s[i] != s[n - i - 1]) {
			return false;
		}
	}

	return true;
}


vector<string> PalindromFilter(vector<string> words, int minLength) {
	vector<string> res = { };

	for (string word : words)
	{
		if (word.size() >= minLength && IsPalindrom(word) == true)
		{
			res.push_back(word);
		}
	}

	return res;
}

int main()
{
	vector<string > filtered = PalindromFilter({ "code", "bro", "weew" }, 4);
	for (string word : filtered)
	{
		cout << word << endl; 
	}
}
