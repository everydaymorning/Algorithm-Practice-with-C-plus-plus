#include <bits/stdc++.h>
using namespace std;
int check[31];
int main() {
	int n;
	cin >> n;
	vector<int> lost, reserve;
	lost.push_back(2);
	lost.push_back(3);
	lost.push_back(4);

	reserve.push_back(1);
	reserve.push_back(2);
	reserve.push_back(3);
	reserve.push_back(6);
	int res = 0;

	for (int i = 1; i <= n; i++) {
		check[i] = 1;
	}

	for (int i = 0; i < reserve.size(); i++) {
		check[reserve[i]]++;
	}
	for (int i = 0; i < lost.size(); i++) {
		check[lost[i]]--;
	}
	for (int i = 0; i < reserve.size(); i++) {
		
		if (check[reserve[i] - 1] == 0 && reserve[i] - 1 > 0 && check[reserve[i]] > 1) {
			check[reserve[i] - 1]++;
			continue;
		}

		if(check[reserve[i] + 1] == 0 && reserve[i] + 1 <= n && check[reserve[i]] > 1) {
			check[reserve[i] + 1]++;
			continue;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (check[i] > 0) res++;
	}
	cout << res;
	return 0;
}