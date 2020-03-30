#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int check[100001];
int main() {
	int n;
	cin >> n;
	int MAX = 0;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
		MAX = max(a, MAX);
	}

	for (int i = 0; i < v.size(); i++) {
		check[v[i]]++;
	}
	int res = 0;
	for (int i = 1; i <= MAX; i++) {
		if (check[i] == i) {
			res = i;
		}
	}
	
	if (res == 0) {
		cout << 0;
	}
	else {
		cout << res;
	}

	return 0;
}