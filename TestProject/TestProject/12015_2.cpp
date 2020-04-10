#include <bits/stdc++.h>
using namespace std;
int v[1000001];
vector<int> lis;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	lis.push_back(v[0]);
	
	for (int i = 1; i < n; i++) {
		if (lis.back() < v[i]) {
			lis.push_back(v[i]);
			
		}
		else {
			int idx = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
			lis[idx] = v[i];
		}
	}

	cout << lis.size();
	return 0;
}