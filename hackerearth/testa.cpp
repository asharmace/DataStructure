#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <map>
#include <deque>
#include <set>
#include <queue>
//#include <multiset>
//#include <multimap>

using namespace std;

int main()
{

	list<int> a;
	vector<int>b;
	deque<int>c;

	set<int> d;
	map <int, int> e;

	stack<int> f;
	queue<int> g;
	priority_queue<int> h;

	multiset<int> i;
	multimap <int, int> j;

	cout << sizeof(a) << endl;
	cout << sizeof(b) << endl;
	cout << sizeof(c) << endl;
	cout << sizeof(d) << endl;
	cout << sizeof(e) << endl;
	cout << sizeof(f) << endl;
	cout << sizeof(g) << endl;
	cout << sizeof(h) << endl;
	cout << sizeof(i) << endl;
	cout << sizeof(j) << endl;

}
