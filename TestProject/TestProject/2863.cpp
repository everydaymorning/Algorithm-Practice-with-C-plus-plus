#include <bits/stdc++.h>
using namespace std;
vector<pair<double, double>> v;
double MAP[2][2];

bool cmp(pair<double, double> p1, pair<double, double> p2) {
	if (p1.second == p2.second) return p1.first < p2.first;
	return p1.second > p2.second;
}
int main() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> MAP[i][j];
		}
	}
	for (int i = 0; i < 4; i++) {
		double sum = (MAP[0][0] / MAP[1][0]) + (MAP[0][1] / MAP[1][1]);
		v.push_back({ i,sum });
		double tmp = MAP[0][0];
		MAP[0][0] = MAP[1][0];
		MAP[1][0] = MAP[1][1];
		MAP[1][1] = MAP[0][1];
		MAP[0][1] = tmp;
	}
	sort(v.begin(), v.end(), cmp);

	cout << v[0].first;

	return 0;
}