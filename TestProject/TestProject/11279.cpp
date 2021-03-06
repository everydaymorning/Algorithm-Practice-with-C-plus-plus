#include <bits/stdc++.h>
using namespace std;

//최대 힙 BOJ 11279
priority_queue<int> pq; // 힙을 우선순위 큐로 구현
//우선순위 큐는 push하면 큰 값부터 저장
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 0) {
			if (pq.size() == 0) {
				cout << "0" << '\n';
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else {
			pq.push(x);
		}
	}

	return 0;
}