#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
	int re = 0;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			re++;
		}
	}
	if (re == 2) return 1;
	else return 0;
}
int main() {
	int n, k;
	cin >> n >> k;
	queue<int> q;
	for (int i = 2; i <= n; i++) {
		q.push(i);
	}
	int cnt = 0;
	int num = 0;
	while (!q.empty()) {
		int tmp = q.front();
		if (isPrime(tmp)) {
			int q_size = q.size();
			for (int i = 1; i < q_size + 1; i++) {
				int front = q.front();
				if (front % tmp == 0) {
					q.pop();
					cnt++;
				}
				else {
					q.pop();
					q.push(front);
				}
				if (cnt == k) {
					num = front;
					cnt++;
				}
			}
		}
	}

	printf("%d", num);

	return 0;
}