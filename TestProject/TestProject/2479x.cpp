#include <bits/stdc++.h> // 20200316 ½ÇÆÐ
using namespace std;
int n, k, A, B;
bool check[1001];
vector<string> v;
vector<int> res;
int convert(int num) {
	int result = 0;
	int mul = 1;

	while (num) {
		if (num % 2) result += mul;
		mul *= 2;
		num /= 10;
	}
	return result;
}


void bfs() {
	queue<pair<string, int>> q;
	q.push({ v[A - 1], A });
	res.push_back(A);
	int con = stoi(v[A - 1]);
	int tmp = convert(con);
	check[tmp] = true;

	while (!q.empty()) {
		string cur = q.front().first;
		int idx = q.front().second;
		q.pop();

		if (cur == v[B - 1]) return;

		for (int i = 0; i < v.size(); i++) {
			int con1 = stoi(v[i]);
			int tmp1 = convert(con1);
			if (check[tmp1]) continue;
			int dist = 0;
			for (int j = 0; j < cur.size(); j++) {
				if (cur[j] != v[i][j]) dist++;
			}
			if (dist == 1) {
				q.push({ v[i], i + 1 });
				res.push_back(i+1);
				check[tmp1] = true;
			}
		}
	}
	cout << "-1";
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}
	cin >> A >> B;

	bfs();
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	return 0;
}