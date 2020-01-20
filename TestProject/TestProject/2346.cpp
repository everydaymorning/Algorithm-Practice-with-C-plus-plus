#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int N;
	cin >> N;
	vector<pair<int, int>> v;

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		v.push_back(make_pair(i+1, t));
	}

	int idx = 0;
	int tmp = N;

	for (int i = 0; i < tmp; i++) {

		cout << v[idx].first << " ";

		int move = v[idx].second;

		if (move > 0) {
			move--;
		}

		v.erase(v.begin() + idx);

		idx += move;
		if (--N == 0) {
			break;
		}

		idx = (idx >= 0 ? idx : N + idx % N);
		idx %= N;

	}
	return 0;
}