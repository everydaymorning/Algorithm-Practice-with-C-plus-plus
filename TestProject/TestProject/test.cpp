#include <bits/stdc++.h>

using namespace std;

int main() {
	
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(4);

	int idx = lower_bound(v.begin(), v.end(), 2) - v.begin() + 1;
	cout << idx;


	return 0;
}