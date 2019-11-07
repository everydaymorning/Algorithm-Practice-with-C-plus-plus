#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	
	cin >> n >> k;

	queue<int> q;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	cout << "<";
	while (q.size()) {
		if (q.size() == 1) {
			cout << q.front() << ">";
			q.pop();
			break;
		}

		for (int i = 1; i < k; i++) {
			q.push(q.front());
			q.pop();
		}

		cout << q.front() << ", ";
		q.pop();
	}

	return 0;
}