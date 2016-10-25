/*
    Counting number of employee under each employee
    @author: MasterJEET
    @email : jitendramarndi@gmail.com
*/

#include <iostream>
#include <map>
#include <list>

//declaring typedef maps and list
typedef std::list < std::string > List;
typedef std::map < std::string, std::string > Map;
typedef std::map < std::string, List > revMap;
typedef std::map < std::string, int > Ans;

//create reverse map <string,list<string>>
revMap reverseMap(Map &m)
{
    revMap rm;
    Map::iterator it;
    for(it = m.begin(); it!=m.end(); it++)
        if(it->first != it->second)
            rm[it->second].push_back(it->first);
    return rm;
}

//get root element (i.e. CEO)
std::string getRoot(Map &m)
{
    Map::iterator it;
    it = m.begin();
    while(it!=m.end())
    {
        if(it->first == it->second)
            return it->first;
        it++;
    }
}

//count number of employees using stack
Ans countEmployeeStack(Map &m)
{
    int n;                        //integer to keep track of # of employees under employee just removed from stack
    Ans ans;                      //Map to store answers
    revMap rm = reverseMap(m);    //getting reverse map
    std::string top = getRoot(m); //getting root element
    List S;                       //Creating stack

    //Initialization
    Map::iterator it = m.begin();
    while(it!=m.end())
        ans[(it++)->first] = 0;
    n = 0;
    S.push_back(top);

    //counting number of employees
    while(S.size())
    {
        top = S.back();
        ans[top] += n;
        if(rm[top].size())
        {
            ans[top] += 1;
            S.push_back( rm[top].back() );
            rm[top].pop_back();
            n = 0;
        }
        else
        {
            n = ans[top];
            S.pop_back();
        }
    }
    return ans;
}

//Driver function to test the program
int main()
{
    Ans ans;
    Map m;
    m["F"] = "F";
    m["B"] = "C";
    m["C"] = "F";
    m["D"] = "E";
    m["E"] = "F";
    m["A"] = "C";
    ans = countEmployeeStack(m);
    Ans::iterator it;
    for(it=ans.begin(); it!=ans.end(); it++)
        std::cout << it->first << " - " << it->second << std::endl;
    return 0;
}
