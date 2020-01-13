#include <bits/stdc++.h>
using namespace std;
bool check[300000];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int a, p;
	cin >> a >> p;
	vector<int> v;
	v.push_back(a);
	check[a] = true;
	int i = 0;
	int s = 0;
	bool flag = false;
	while (1) {
		string tmp = to_string(v.at(i));
		int tmp_size = tmp.size();
		int sum = 0;
		for (int q = 0; q < tmp_size; q++) {
			int t = tmp[q] - '0';
			int tt = (int)pow(t, p);
			sum += tt;
		}
		if (check[sum]) {
			for (int j = 0; j <= i; j++) {
				if (v.at(j) == sum) {
					s = j;
					flag = true;
					break;
				}
			}
		}
		if (flag) break;
		check[sum] = true;
		v.push_back(sum);
		i++;
	}

	cout << s;

	return 0;
}