#include <vector>
#include <iostream>
using namespace std;
typedef std::vector<int> SET;
typedef std::vector<SET> POWERSET;

void RelationshipOfProblemAndSubproblem(POWERSET& result, int Mn)
{
    size_t len = result.size();

    // copy f(n-1) and append Mn to each element of f(n-1)
    // to generate {{C0, Mn}, {C1, Mn}, ..., {Cx, Mn}}
    // All together in "result" will be f(n)
    // { C0, C1, ..., Cx, {C0, Mn}, {C1, Mn}, ..., {Cx, Mn}, {Mn}}
    for (size_t i = 0; i < len; ++i) {
        result.push_back(result[i]);
    }
    for (size_t i = len; i < result.size(); ++i) {
        SET& curSet = result[i];
        curSet.push_back(Mn);
    }

    // Append {Mn} to the result
    result.push_back(SET(1, Mn));
}


// Recursive implementation
void PowerSetR(const SET& s, size_t pos, POWERSET& result)
{
    if (pos == s.size()) {
        return;
    }

    PowerSetR(s, pos + 1, result);
    RelationshipOfProblemAndSubproblem(result, s[pos]);
}

// Non-recursive implementation
POWERSET PowerSetNR(const SET& s)
{
    POWERSET result;
  
    for (size_t i = 0; i < s.size(); ++i) {
        RelationshipOfProblemAndSubproblem(result, s[i]);
    }

    return result;
}

int main(int argc, char* argv[])
{
    SET s;
    s.push_back(1);
    s.push_back(4);
    s.push_back(6);

    
    auto resultNR = PowerSetNR(s);
    
    for(auto && a: resultNR)
    {
        for (auto && b: a)
        {
            cout << b << " ";
        }
        cout << endl;
    }

    return 0;
}