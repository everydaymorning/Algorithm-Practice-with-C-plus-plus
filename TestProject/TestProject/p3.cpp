#include <bits/stdc++.h>
using namespace std;
vector<int> n;
vector<string> v;
bool check[100001];
int MAX = 0;
bool cmp(string a, string b) {
	return a + b > b + a;
}
int main() {
	n.push_back(3);
	n.push_back(30);
	n.push_back(34);
	n.push_back(5);
	n.push_back(9);

	for (int i = 0; i < n.size(); i++) {
		v.push_back(to_string(n[i]));
	}
	sort(v.begin(), v.end(), cmp);
	string ans;
	for (int i = 0; i < v.size(); i++) {
		ans += v[i];
	}
	cout << ans;
	return 0;
}