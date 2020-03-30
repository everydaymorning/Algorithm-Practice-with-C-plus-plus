#include <bits/stdc++.h>
using namespace std;
vector<int> v;
vector<int> re;
string str;
bool check[8];
bool visit[10000001];
int MAX;
bool isPrime(int a) {
	if (a < 2) return false;
	for (int i = 2; i <= sqrt(a); i++) {
		if (a % i == 0) return false;
	}
	return true;
}

void dfs(int len, int cnt) {
	if (len == cnt) {
		
		string s;
		for (int i = 0; i < v.size(); i++) {
			s += to_string(v[i]);
		}
		int tmp = stoi(s);
		if (visit[tmp]) return;
		visit[tmp] = true;
		cout << tmp << '\n';
		re.push_back(tmp);
		MAX = max(MAX, tmp);
		return;
	}

	for (int i = 0; i < str.size(); i++) {
		if (check[i]) continue;
		check[i] = true;
		v.push_back(str[i] - '0');
		dfs(len, cnt + 1);
		v.pop_back();
		check[i] = false;
	}
	
}
int main() {

	cin >> str;

	int res = 0;

	for (int i = 1; i <= str.size(); i++) {
		dfs(i, 0);
	}

	for (int i = 0; i < re.size(); i++) {
		if (isPrime(re[i])) {
			res++;
		}
	}
	cout << res;
	return 0;
}