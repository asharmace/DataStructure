#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>
using namespace std;
class Palindrome
{
public:
	static bool isPalindrome(std::string str)
	{
        bool result = true;
		const char* c = str.c_str();
        int start = 0, end = str.size() -2;
        
        while (start < end)
        {
            cout << toupper(c[start]) << " " << toupper(c[end]) << endl;
        	if (toupper(c[start++]) != toupper(c[end--]))
            {
                result = false;
                break;
            }
        }
        
        return result;
	}
};

int main(int argc, const char* argv[])
{
	std::cout << Palindrome::isPalindrome("Noel sees Leon.");
}