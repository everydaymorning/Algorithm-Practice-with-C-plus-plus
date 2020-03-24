#include <bits/stdc++.h>
using namespace std;

int len;
int r;

vector<int> a, b;
vector<vector<int>> v;
bool check[1001];
vector<int> m;
int MIN = 987654321;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i][1]; j++) {
			m.push_back(v[i][0]);
			r += v[i][0];
		}
	}
	r /= 2;
	bool flag = true;
	int sum = 0;
	for (int i = 0; i < m.size(); i++) {
		sum += m[i];

	}

	cout << MIN;
	return 0;
}