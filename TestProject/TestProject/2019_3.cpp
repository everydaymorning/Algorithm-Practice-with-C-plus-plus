#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
vector<vector<string>> tmp;
vector<string> t;
bool check[10];
void dfs(int cnt, int row, int depth, vector<vector<string>> v) {
	if (cnt == depth) {
		string s;
		for (int i = 0; i < t.size(); i++) {
			cout << t[i] << " ";
		}
		cout << '\n';
		tmp.push_back(t);
		return;
	}

	for (int i = cnt; i < v[i].size(); i++) {
		if (i < cnt) continue;
		if (check[i]) continue;
		check[i] = true;
		cout << "i: " << i << "  str: " << v[row][i] << '\n';
		t.push_back(v[row][i]);
		dfs(cnt + 1, row, depth, v);
		t.pop_back();
		check[i] = false;
	}
	
	cout << "dfs end" << '\n';

}
int solution(vector<vector<string>> relation) {
	int answer = 0;
	for (int i = 0; i < relation.size(); i++) {
		for (int j = 1; j <= relation[i].size(); j++) {
			dfs(0, i, j, relation);
		}
	}
	return answer;
}

int main() {
	vector<vector<string>> relation = { {"100", "ryan", "music", "2"}, {"200", "apeach", "math", "2"}, {"300", "tube", "computer", "3"}, {"400", "con", "computer", "4"}, {"500", "muzi", "music", "3"}, {"600", "apeach", "music", "2"} };

	int ans = solution(relation);
	cout << ans;
	return 0;
}