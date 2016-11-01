#include <iostream>
#include <regex>
#include <string>
using namespace std;

bool verifyPassWord(string inputString)
{
	regex e1("[a-z]");
	regex e2("[A-Z]");
	regex e3("[0-9]");

	return (inputString.size() >=5 &&
			regex_search(inputString, e1) &&
			regex_search(inputString, e2) &&
			regex_search(inputString, e3)
			);
}

int main()
{

	cout << verifyPassWord("my.password1") <<endl; 
	cout << verifyPassWord("my.Password1") <<endl; 
	return 0;
}
