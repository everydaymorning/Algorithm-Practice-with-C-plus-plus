#include <bits/stdc++.h>
using namespace std;
int MIN;
int sum;
vector<int> v;
void prime(int a, int b) {
	
	for (int i = a; i <= b; i++) {
		int t = 0;
		for (int j = 1; j <= i; j++) {
			if (i % j == 0) {
				t++;
			}
		}
		if (t == 2) {
			v.push_back(i);
			sum += v.back();
		}
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;

	
	prime(n, m);
	
	int v_size = v.size();
	if (v_size == 0) {
		printf("-1");
		return 0;
	}
	MIN = v.at(0);
	cout << sum << '\n';
	cout << MIN;
	
	return 0;
}