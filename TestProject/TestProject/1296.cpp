#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, string> p1, pair<int, string> p2) {
	if (p1.first == p2.first) return p1.second < p2.second;
	return p1.first > p2.first;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	string oh;
	cin >> oh;

	int L, O, V, E;
	int n;
	cin >> n;
	vector<string> v;
	vector<pair<int, string>> result;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}
	for (int i = 0; i < v.size(); i++) {
		L = 0;
		O = 0;
		V = 0;
		E = 0;
		for (int j = 0; j < oh.size(); j++) {
			if (oh[j] == 'L') L++;
			else if (oh[j] == 'O') O++;
			else if (oh[j] == 'V') V++;
			else if (oh[j] == 'E') E++;
		}
		string tmp = v[i];
		for (int j = 0; j < tmp.size(); j++) {
			if (tmp[j] == 'L') L++;
			else if (tmp[j] == 'O') O++;
			else if (tmp[j] == 'V') V++;
			else if (tmp[j] == 'E') E++;
		}

		int sum = ((L + O) * (L + V) * (L + E) * (O + V) * (O + E) * (V + E)) % 100;
		result.push_back({ sum, v[i] });
		
	}
	sort(result.begin(), result.end(), cmp);
	cout << result[0].second;
	return 0;

}