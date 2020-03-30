#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int MAX = 0;
	vector<int> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	for (int i = 0; i < v.size(); i++) {
		string s = to_string(v[i]);
		int tmp = v[i];
		int a1 = v[i];
		int tmp_sum = 0;
		while (tmp) {
			int a = tmp % 10;
			tmp_sum += a;
			tmp /= 10;
		}
		cout << "tmp: " << tmp << "  tmp_sum: " << tmp_sum << '\n';
		for (int j = i+1; j < v.size(); j++) {
			string s2 = to_string(v[j]);
			int b1 = v[j];
			int tmp2 = v[j];
			int tmp_sum2 = 0;
			while (tmp2) {
				int a = tmp2 % 10;
				tmp_sum2 += a;
				tmp2 /= 10;
			}
			cout << "tmp2: " << tmp2 << "  tmp_sum2: " << tmp_sum2 << '\n';
			if (tmp_sum == tmp_sum2) {
				MAX = max(MAX, a1 + b1);
			}
		}
	}
	if (MAX == 0) {
		cout << -1;
	}
	else cout << MAX;
	return 0;
}