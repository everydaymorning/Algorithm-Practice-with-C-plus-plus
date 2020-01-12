#include <bits/stdc++.h>
using namespace std;
long long arr[1000001];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int n;
	cin >> n;
	vector<long long> v;
	vector<long long> cnt;
	for (int i = 0; i < n; i++) {
		long long t;
		cin >> t;
		v.push_back(t);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		if (binary_search(v.begin(), v.end(), v.at(i))) {
			arr[v.at(i)]++;
		}
	}

	for (int i = 0; i < n; i++) {
		cnt.push_back(arr[i]);
	}

	cout << max_element(cnt.begin(), cnt.end()) - cnt.begin();

	return 0;
}