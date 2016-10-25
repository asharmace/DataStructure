#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>

int main ()
{
  using namespace std::chrono;

  high_resolution_clock::time_point t1 = high_resolution_clock::now();
  int x = 2000;
  int y;
  for (int i=0; i<2340000000; ++i)
    {
        y = x/1;
    }
  std::cout << std::endl;

  high_resolution_clock::time_point t2 = high_resolution_clock::now();

  duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

  std::cout << "It took  " << time_span.count() << " seconds.";
  
  high_resolution_clock::time_point t3 = high_resolution_clock::now();
  x = 20;
  for (int i=0; i<2340000000; ++i)
    {
        y = x;
    }
  std::cout << std::endl;

  high_resolution_clock::time_point t4 = high_resolution_clock::now();

  duration<double> time_span2 = duration_cast<duration<double>>(t4 - t3);

  std::cout << "It took  " << time_span2.count() << " seconds.";
  std::cout << std::endl;
  
  }