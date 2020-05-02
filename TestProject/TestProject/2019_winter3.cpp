#include <bits/stdc++.h>
using namespace std;
int answer;
vector<string> user_id, banned_id, tmp;
bool check[9];
bool check1[9];
map<string, int> mp;
void dfs(int cnt) {
	if (banned_id.size() == cnt) {
		string s;
		vector<string> tmp2;
		tmp2 = tmp;
		sort(tmp2.begin(), tmp2.end());
		for (int i = 0; i < tmp2.size(); i++) {
			s += tmp2[i];
			//cout << tmp2[i] << "  ";
		}
		//cout << "s: " << s << '\n';
		if (mp[s] == 0) answer++;
		mp[s]++;
		//cout << "answer: " << answer << '\n';
		return;
	}
	for (int i = cnt; i < banned_id.size(); i++) {
		int ban_num = 0;
		//mp.clear();
		for (int j = 0; j < banned_id[i].size(); j++) {
			if (banned_id[i][j] != '*') {
				ban_num++;
			}
		}
		//cout << "ban_num: " << ban_num << '\n';
		for (int j = 0; j < user_id.size(); j++) {
			int user_num = 0;
			if (check[i]) continue;
			if (check1[j]) continue;
			if (banned_id[i].size() != user_id[j].size()) continue;
			//cout << "ban_id: " << i << " " << banned_id[i] << "   user_id: " << user_id[j] << '\n';
			for (int k = 0; k < user_id[j].size(); k++) {
				if (banned_id[i][k] == user_id[j][k]) user_num++;
			}
			//cout << "user_num: " << user_num << '\n';
			if (ban_num == user_num) {
				check[i] = true;
				check1[j] = true;
				tmp.push_back(user_id[j]);
				//cout << "check j : " << j << '\n';
				dfs(cnt + 1);
				tmp.pop_back();
				check[i] = false;
				check1[j] = false;
			}
		}
	}
	
}
int solution(vector<string> user_id, vector<string> banned_id) {
	dfs(0);
	return answer;
}

int main() {
	user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
	banned_id = { "fr*d*", "abc1**" };
	int ans = solution(user_id, banned_id);
	cout << ans;
	return 0;

}