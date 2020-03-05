#include <bits/stdc++.h>
using namespace std;
int n, res;
bool check[1001];
vector<pair<int, pair<int, int>>> v;
void setting() {
	memset(check, true, sizeof(check));
	for (int i = 123; i < 1000; i++) {
		string tmp = to_string(i);

		if (tmp[0] == tmp[1] || tmp[0] == tmp[2] || tmp[1] == tmp[2]) check[i] = false;
		if (tmp[0] == '0' || tmp[1] == '0' || tmp[2] == '0') check[i] = false;
	}
}

void play() {
	for (int i = 0; i < v.size(); i++) {
		int num = v[i].first;
		int s = v[i].second.first;
		int b = v[i].second.second;
		string str_num = to_string(num);

		for (int j = 123; j < 1000; j++) {
			int tmp_s = 0;
			int tmp_b = 0;
			
			if (check[j] == false) continue;

			string tmp_j = to_string(j);
			for (int k = 0; k < 3; k++) {
				for (int p = 0; p < 3; p++) {
					if (k == p && str_num[k] == tmp_j[p]) tmp_s++;
					if (k != p && str_num[k] == tmp_j[p]) tmp_b++;
				}
			}
			if (s != tmp_s || b != tmp_b) check[j] = false;
		}
	}
	
	for (int i = 123; i < 1000; i++) {
		if (check[i]) res++;
	}
	cout << res;

}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ {a},{b,c} });
	}

	setting();
	play();

	return 0;
}