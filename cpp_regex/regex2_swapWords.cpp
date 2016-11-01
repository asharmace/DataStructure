#include <iostream>
using namespace std;

std::string swapAdjacentWords(std::string s) {
  return std::regex_replace(s, std::regex("([A-Za-z]+) ([A-Za-z]+)"), "$2 $1");
}

int main()
{
	string s1("Hello world");
	string s2("Hi How are you?");
	string s3("sfdasd");

	cout << swapAdjacentWords(s1) << endl;
	cout << swapAdjacentWords(s2) << endl;
	cout << swapAdjacentWords(s3) << endl;
}