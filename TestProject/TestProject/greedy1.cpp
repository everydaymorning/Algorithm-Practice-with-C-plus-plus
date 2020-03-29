#include <bits/stdc++.h>
using namespace std;
int check[31];
int main() {
	int n;
	cin >> n;
	vector<int> lost, reverse;
	lost.push_back(2);
	lost.push_back(3);
	lost.push_back(4);

	reverse.push_back(1);
	reverse.push_back(2);
	reverse.push_back(3);
	reverse.push_back(6);
	int res = 0;

	for (int i = 1; i <= n; i++) {
		check[i] = 1;
	}

	for (int i = 0; i < reverse.size(); i++) {
		check[reverse[i]]++;
	}
	for (int i = 0; i < lost.size(); i++) {
		check[lost[i]]--;
	}
	for (int i = 0; i < reverse.size(); i++) {
		
		if (check[reverse[i] - 1] == 0 && reverse[i] - 1 > 0 && check[reverse[i]] > 1) {
			check[reverse[i] - 1]++;
			continue;
		}

		if(check[reverse[i] + 1] == 0 && reverse[i] + 1 <= n && check[reverse[i]] > 1) {
			check[reverse[i] + 1]++;
			continue;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (check[i] > 0) res++;
	}
	cout << res;
	return 0;
}