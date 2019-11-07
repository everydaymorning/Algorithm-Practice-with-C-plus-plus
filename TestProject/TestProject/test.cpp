#include <bits/stdc++.h>

using namespace std;

int main() {
	
	deque<int> d;
	d.push_back(10);
	d.push_back(20);

	d.pop_front();
	cout << d.at(0);

	return 0;
}