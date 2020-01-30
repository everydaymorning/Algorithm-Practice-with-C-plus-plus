#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
//우선순위 큐 -> priority_queue<int, 컨테이너(vector<int>), 비교함수 클래스(less<int>) > pq; 기본형, 최대 힙

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