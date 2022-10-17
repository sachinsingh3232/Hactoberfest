// C++ Program to reverse words in a String

#include <bits/stdc++.h>
using namespace std;

// Function to reverse the given string
string reverseString(string str)
{
	reverse(str.begin(), str.end());
	str.insert(str.end(), ' ');
	int n = str.length();

	int j = 0;
	for (int i = 0; i < n; i++) {
		if (str[i] == ' ') {
			reverse(str.begin() + j,
					str.begin() + i);
			j = i + 1;
		}
	}
	str.pop_back();

	// Return the reversed string
	return str;
}

// Driver code
int main()
{
	string str = "this is an amazing program";

	// Function call
	string rev = reverseString(str);

	// Print the reversed string
	cout << rev;
	return 0;
}
