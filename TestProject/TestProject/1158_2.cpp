#include <bits/stdc++.h>
using namespace std;
int n, k;
list<int> li;
queue<int> q;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		li.push_back(i);
	}
	list<int>::iterator cur = li.begin();
	int tmp = n;
	while (tmp > 0) {
		for (int i = 0; i < k - 1; i++) {
			if (cur == li.end()) {
				cur = li.begin();
			}
			cur++;
			if (cur == li.end()) {
				cur = li.begin();
			}
		}
		q.push(*cur);
		cur = li.erase(cur);
		tmp--;
	}
	cout << "<";
	while (!q.empty()) {
		if (q.size() == 1) cout << q.front();
		else cout << q.front() << ", ";
		q.pop();
	}
	cout << ">";
	return 0;
	

}