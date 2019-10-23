//#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	//string str("radar");
	//string str("hello");
	string str("");
	cout << "Enter input string for checking if it is a palindrome: ";
	cin >> str;
	cout << str << endl;
	//string rev_str = reverse(str.begin(), str.end());
	string rev_str(str); // initialize with copy constructor 
    reverse(rev_str.begin(), rev_str.end());
	cout << rev_str << endl;
	//if(str == rev_str)
	//{
	//	cout << "It's a palindrome" << endl;
	//}
	//else
	//{
	//	cout << "It's not a palindrome" << endl;
	//}
	string result("It's");
	(str == rev_str)? result+="" : result += " not";
	result += " a palindrome";
	cout << result << endl;
}

