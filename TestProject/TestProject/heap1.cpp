#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		pq.push(a);
	}
	int res = 0;
	int idx = 0;
	int len = pq.size();
	while (1) {
		if (idx == len - 1) break;
		if (pq.top() >= k) {
			idx++;
			continue;
		}
		
		int tmp = pq.top();
		cout << "tmp: " << tmp << '\n';
		pq.pop();
		int sum = tmp + (2 * pq.top());
		cout << "sum: " << sum << '\n';
		pq.pop();
		pq.push(sum);
		res++;
		idx++;
		
	}
	cout << res;
	return 0;
}