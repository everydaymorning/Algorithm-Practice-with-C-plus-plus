#include <bits/stdc++.h>
using namespace std;
bool cmp(string v1, string v2) {
	if (v1.size() == v2.size()) return v1 < v2;
	return v1.size() < v2.size();
}
bool cmp1(pair<int, string> p1, pair<int, string> p2) {
	return p1.first > p2.first;
}
int main() {
	int n;
	cin >> n;
	vector<vector<string>> dataSource;
	vector<string> tags;
	dataSource.push_back({ "docs1", "t1", "t2", "t3" });
	dataSource.push_back({ "docs2", "t0", "t2", "t3" });
	dataSource.push_back({ "docs3", "t1", "t6", "t7" });
	dataSource.push_back({ "docs4", "t1", "t2", "t4" });
	dataSource.push_back({ "docs5", "t6", "t100", "t8" });
	tags.push_back("t1");
	tags.push_back("t2");
	tags.push_back("t3");

	vector<pair<int, string>> answer;
	for (int i = 0; i < dataSource.size(); i++) {
		sort(dataSource[i].begin() + 1, dataSource[i].end(), cmp);
	}
	
	for (int i = 0; i < dataSource.size(); i++) {
		int cnt = 0;
		for (int j = 1; j < dataSource[i].size(); j++) {
			for (int k = 0; k < tags.size(); k++) {
				if (dataSource[i][j] == tags[k]) {
					cnt++;
					break;
				}
			}
			
		}
		if (cnt > 0) {
			answer.push_back({ cnt, dataSource[i][0] });
		}
	}

	sort(answer.begin(), answer.end(), cmp1);
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i].second << '\n';
	}
	return 0;
}