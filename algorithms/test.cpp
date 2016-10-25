#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort
#include <set>
#include <sstream>
#include <cmath>
using namespace std;

int main () {
  int myints[] = {1,2,1,1,1,3,3};

  int start = 3; 
  int end =  6;
  int count = 0;
  
  int j =0;
  for (int i = start; i <= end; )
  {
    int continuous = 1;
    j = i + 1;
    while (myints[j++] == myints[i])
        continuous++;
    
    count+= (continuous) * (continuous+ 1) / 2; 
    i += continuous;
    cout << i << " " << j << " " << count << " " << continuous << endl;
  }
  
  std::cout << "After loop: " << count << '\n';

  return 0;
}