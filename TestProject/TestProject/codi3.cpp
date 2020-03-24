#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n;
	vector<int> v;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	deque<int> dq;
	for (int i = 0; i < v.size(); i++) {
		dq.push_back(v[i]);
	}

	cin >> k;
	for (int i = 0; i < k; i++) {
		int tmp = dq.back();
		dq.pop_back();
		dq.push_front(tmp);
	}

	for (int i = 0; i < dq.size(); i++) {
		cout << dq[i] << " ";
	}
	return 0;

}