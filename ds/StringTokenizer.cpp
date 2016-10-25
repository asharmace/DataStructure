#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cctype>

using namespace std;

bool charIsSpace(char c)
{
    return c == ' '? true:false;
}

vector<string> tokenize(const string& input, char delim)
{
    vector<string> result;
    stringstream ss(input);
    string s;
    while(getline(ss, s, delim))
    {
        s.erase(std::remove_if(s.begin(), s.end(), charIsSpace), s.end());
        result.push_back(s);
    }
    return result;
}

int main()
{
    string input1="employee_id, employee_name,employee_salary,department_id";
    string input2="employee_id,employee_name where employee_id > 1 and employee_salary = 1000";
    string input3="employeeId,employee_name where employee_id = 1";
    string input4="employee_id,employee_name where (employee_id > 1 and employee_salary = 1000) or(department_id = 5 and employee_salary = 5000 ) or department_id = 5";
    
    vector<string> strVec = tokenize(input1,',');
    
    int count = 1;
    
    copy(strVec.begin(), strVec.end() - 1, ostream_iterator<string>(cout<<"[",  "]\n["));
    cout << *( strVec.end() - 1 )<< "]"<< endl;
}