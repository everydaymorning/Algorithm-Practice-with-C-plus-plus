#include <bits/stdc++.h>
using namespace std;
bool check[100001];
bool cmp(vector<int> v1, vector<int> v2) {
	return v1.size() < v2.size();
}
vector<int> solution(string s) {
	vector<int> answer;
	vector<vector<int>> v;
	vector<int> tmp;
	stack<char> stk;
	string str;
	for (int i = 1; i < s.size() - 1; i++) {
		if (stk.empty() && s[i] == ',') {
			v.push_back(tmp);
			tmp.clear();
		}
		else if (s[i] == ',') {
			int num = stoi(str);
			tmp.push_back(num);
			str = "";
		}
		else if (s[i] == '{') {
			stk.push(s[i]);
		}
		else if (s[i] == '}') {
			int num = stoi(str);
			tmp.push_back(num);
			str = "";
			if (i == s.size() - 2) {
				v.push_back(tmp);
			}
			stk.pop();
		}
		else if (s[i] >= '0' && s[i] <= '9') {
			str += s[i];
		}
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			if (check[v[i][j]])continue;
			check[v[i][j]] = true;
			answer.push_back(v[i][j]);
		}
	}
	return answer;
}
int main() {
	string str = "{{4,2,3},{3},{2,3,4,1},{2,3}}";
	vector<int> ans = solution(str);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}