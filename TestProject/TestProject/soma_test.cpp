#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	int idx = 0;
	int MIN = 100001;
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		MIN = min(MIN, v[i]);
	}
	bool flag = false;
	for (int i = 0; i < v.size(); i++) {
		int num = k;
		cnt++;
		while (num--) {

			v[idx] = MIN;
			idx++;
			if (idx >= v.size()) {
				flag = true;
				break;
			}
			
		}
		idx--;
		if (flag) break;
		
	}

	cout << cnt;
	return 0;
}