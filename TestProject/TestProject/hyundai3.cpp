#include <bits/stdc++.h>
using namespace std;
vector<string> register_id;
string id;
string check(int idx, vector<string> registered_list, string new_id) {
	if (idx >= registered_list.size()) {
		return new_id;
	}
	string S, N;
	for (int i = idx; i < registered_list.size(); i++) {
		if (registered_list[i] == new_id) {
			for (int j = 0; j < registered_list[i].size(); j++) {
				if (registered_list[i][j] >= 'a' && registered_list[i][j] <= 'z') {
					S += registered_list[i][j];
				}
				else if (registered_list[i][j] >= '0' && registered_list[i][j] <= '9') {
					N += registered_list[i][j];
				}
			}
			if (N.size() == 0) {
				N = '0';
			}

			int tmp_num = stoi(N);
			tmp_num += 1;
			string num = to_string(tmp_num);
			string tmp = S + num;
			string a = check(idx + 1, registered_list, tmp);
			return a;
		}
		
	}
	return new_id;
}
string solution(vector<string> registered_list, string new_id) {
	string answer = "";
	sort(registered_list.begin(), registered_list.end());
	answer = check(0, registered_list, new_id);
	
	return answer;
}

int main() {
	
	register_id = { "bird99", "bird98", "bird101", "gotoxy" };
	id = "bird98";
	string a = solution(register_id, id);
	cout << a;
	return 0;
}