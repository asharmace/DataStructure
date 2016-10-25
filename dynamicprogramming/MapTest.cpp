#include <iostream>
#include <chrono>
#include <ctime>
#include <ratio>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstdlib>
#include <cmath>

using namespace std;
using namespace std::chrono;


int main()
{
    int  n = 50;
    time_t t;
    srand((unsigned) time(&t));
    std::unordered_set<int> myUs;
    std::map<double, double> myRBMap;
    std::unordered_map<double, double> myHashMap;
    double temp;
    high_resolution_clock::time_point t1, t2;
    duration<double> time_span;

    t1 = high_resolution_clock::now();
    
    while(myUs.size() < 100000)
    {
        temp = rand();
        temp = fmod((temp * temp), 1000000000007);
        myUs.insert(temp);
    }
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double>>(t2 - t1);
    std::cout << "It took  " << time_span.count() << " seconds for " << myUs.size() 
              << " Elements in unordered Set" << endl;


              t1 = high_resolution_clock::now();
    for (auto a: myUs)
    {
        myRBMap.insert(make_pair(a, a));
        auto it = myRBMap.find(a);
    }
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double>>(t2 - t1);
    std::cout << "It took  " << time_span.count() << " seconds for " << myRBMap.size() 
              << " Elements in Old Map" << endl;

    t1 = high_resolution_clock::now();
    for (auto a: myUs)
    {
        myHashMap.insert(make_pair(a, a));
        auto it = myHashMap.find(a);
    } 
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double>>(t2 - t1);
    std::cout << "It took  " << time_span.count() << " seconds for " << myRBMap.size() 
              << " Elements in unordered Map" << endl;

    return 0;

}

