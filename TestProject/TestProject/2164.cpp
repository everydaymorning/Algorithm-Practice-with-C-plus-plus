#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	deque<int> dq;

	for (int i = 0; i < n; i++) {
		dq.push_back(i + 1);
	}

	while (dq.size() != 1) {
		dq.pop_front();
		int tmp = dq.front();
		dq.pop_front();
		dq.push_back(tmp);
	}

	printf("%d", dq.front());

	return 0;
}