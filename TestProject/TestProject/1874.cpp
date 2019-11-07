#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> v;
	stack<int> s;
	deque<char> dq;
	int n;
	cin >> n;


	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	int j = 0;
	int k = 1;
	while (1) {
		int tmp = v.at(j);
		if (k <= tmp) {
			s.push(k++);
			dq.push_back('+');
			//cout << "+" << '\n';
		}
		else {
			//cout << dq.front() << '\n';
			if (tmp == s.top()) {
				s.pop();
				dq.push_back('-');
				//cout << "n: " << n << '\n';
				//cout << "j: " << j << '\n';

				j++;
			}
			else {
				dq.push_front('n');
				//cout << "NO" << '\n';
				break;
			}
		}
		
		if (s.size() == 0 && j==n) break;
	}
	if (dq.front() == 'n') {
		cout << "NO" << '\n';
	}
	else {
		int t = dq.size();
		for (int i = 0; i < t; i++) {
			cout << dq.front() << '\n';
			dq.pop_front();
		}
	}
	
	return 0;
}