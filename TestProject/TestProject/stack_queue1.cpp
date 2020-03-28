#include <bits/stdc++.h>
using namespace std;
queue<pair<int, int>> wq;
queue<pair<int, int>> iq;
queue<int> lq;
int main() {
	int n;
	cin >> n;
	int len, w;
	cin >> len >> w;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		wq.push({ a,0 });
	}
	int res_size = wq.size();
	int curWeight = 0;
	int res = 0;
	while (1) {
		int iq_size = iq.size();
		while (iq_size--) {
			int cur_x = iq.front().first;
			int cur_y = iq.front().second;
			iq.pop();
			if (cur_y == len - 1) {
				curWeight -= cur_x;
				continue;
			}
			iq.push({ cur_x, cur_y + 1 });
		}

		if (!wq.empty() && curWeight + wq.front().first <= w) {
			iq.push(wq.front());
			curWeight += wq.front().first;
			wq.pop();
		}
		res++;

		if (wq.size() == 0 && iq.size() == 0) break;
	}
	cout << res;
	return 0;
}