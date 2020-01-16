#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n;
	m = n;
	vector<int> v;
	int tmp = 1;
	int i = 2;
	while (1) {
		if (n % i == 0) {
			v.push_back(i);
			tmp *= i;
			n /= i;
		}
		else {
			i++;
		}
		
		if (tmp == m) break;
	}

	int v_size = v.size();
	for (int i = 0; i < v_size; i++) {
		cout << v.at(i) << '\n';
	}

	return 0;
}