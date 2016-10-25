#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    int option;
    map<string, int> productCount;
    map<string, vector<string> > userBought;
    
    while(T--)
    {
        cin >> option;
        string user, product;
        switch(option)
        {
            case 1:
            {
                    cin >> product;
                    productCount.insert(make_pair(product, 0));
                break;
            }
            case 2:
            {
                    cin >> user >> product;
                    productCount[product]++;
                    cout << "Added " << product << " " << productCount[product] << " by " << user <<endl;
                    auto mapIt = userBought.find(user);
                    if (mapIt == userBought.end())
                    {
                        vector<string> temp; 
                        temp.push_back(product);
                        userBought[user] = temp;
                    }
                    else
                    {
                        mapIt->second.push_back(product);
                        userBought[user] = mapIt->second;
                    }
                break;
            }
            case 3:
            {
                    cin >> user >> product;
                    productCount[product]--;
                    cout << "Returned " << product << " " << productCount[product] << " by " << user <<endl;
                    auto mapIt = userBought.find(user);
                    if (mapIt == userBought.end())
                    {
                        //NOTHING TO BE DONE.
                    }
                    else
                    {
                        mapIt->second.erase(remove(mapIt->second.begin(), mapIt->second.end(),product), mapIt->second.end());
                        userBought[user] = mapIt->second;
                    }
                break;
            }
            case 4:
            {
                    cin >> user;
                    auto mapIt = userBought.find(user);
                    cout << "BlackListing " << user <<endl;

                    if (mapIt == userBought.end())
                    {
                        //NOTHING TO BE DONE.
                    }
                    else
                    {
                        for (auto a: mapIt->second)
                        {
                            cout << "Deleting " << a << " " << productCount[a] << " by " << user <<endl;

                            productCount[a]--;
                        }
                        mapIt->second.clear();
                        userBought[user] =  mapIt->second;
                    }
                    
                break;
            }
            case 5:
            {
                string bestSelling;
                int maxCount = 0;
                for(auto a: productCount)
                {
                    if (maxCount < a.second)
                    {
                        bestSelling = a.first;
                        maxCount = a.second;
                    }
                }
                
                cout << bestSelling << " " << maxCount <<endl;
                break;
            }
        }
    }
}