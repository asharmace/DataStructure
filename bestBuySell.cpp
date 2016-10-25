#include <iostream>

using namespace std;

double prices[] = {10.50, 55.39, 109.23, 48.29, 81.59, 105.53, 94.45, 12.24, 152.0, 2, 170.0};
int sizeOfPrices = sizeof(prices)/ sizeof(prices[0]);

int main()
{
    double min = prices[0];
    double max = prices[0];
    double profit = 0.0;
    double maxProfit = 0.0;
    double bestBuy = prices[0];
    double bestSell = prices[0];
    
    for(int i =1; i <sizeOfPrices -1; i++)
    {
        if (prices[i] < min)
        {
           min = prices[i];
           max = min;
        }  
        if (prices[i] < max)
        {
            max = prices[i];
            profit = max - min;
        }
        if (maxProfit < profit)
        {
            maxProfit = profit;
            bestBuy = min;
            bestSell = max;
        }
            
    }
    
    cout << "Best buy = " << bestBuy <<endl;
    cout << "Best sell = " << bestSell <<endl;
}