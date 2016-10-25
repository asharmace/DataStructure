#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort
#include <set>
#include <sstream>
#include <cmath>
using namespace std;

int main () {
  int A[] = {1,2,1,1,1,3,3};

  int start = 0; 
  int end =  6;
  int count = 0;
  
  int j, k , cont;
  for (j = start; j <= end; )
  {
    int cont = 1;
    k = j + 1;
    while (A[k++] == A[j])
        cont++;
    
    count+= ((cont) * (cont+ 1)) / 2; 
    j += cont;
    cout << j << " " << k << " " << count << " " << cont << endl;
  }
  
  std::cout << "After loop: " << count << '\n';

  return 0;
}