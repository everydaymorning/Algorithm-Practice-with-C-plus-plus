#include <bits/stdc++.h>
using namespace std;
int n;
vector<long long> p, m;
long long res, one, zero;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long a;
		cin >> a;
		if (a == 1) one++;
		else if (a == 0) zero++;
		else if (a > 0) p.push_back(a);
		else m.push_back(a);
	}
	sort(p.begin(), p.end(), greater<long long>());
	for (int i = 0; i < p.size() - 1; i += 2) {
		res += p[i] * p[i + 1];
	}
	if (p.size()&1) res += p.back();
	res += one;

	sort(m.begin(), m.end());
	for (int i = 0; i < m.size() - 1; i += 2) {
		res += m[i] * m[i + 1];
	}
	if ((m.size()&1) && zero == 0) res += m.back();
	cout << res;

	return 0;
}