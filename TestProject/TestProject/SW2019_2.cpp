#include <bits/stdc++.h>
using namespace std;

int main() {
	string skill = "CBD";
	vector<string> skill_trees;
	skill_trees.push_back("BACED");
	skill_trees.push_back("CBADE");
	skill_trees.push_back("AECB");
	skill_trees.push_back("BDA");
	int cnt = 0;
	for (int i = 0; i < skill_trees.size(); i++) {
		queue<char> q;
		for (int j = 0; j < skill_trees[i].size(); j++) {
			for (int k = 0; k < skill.size(); k++) {
				if (skill_trees[i][j] == skill[k]) {
					q.push(skill_trees[i][j]);
				}
			}
		}
		bool flag = true;
		int q_size = q.size();
		for (int j = 0; j < q_size; j++) {
			if (q.front() != skill[j]) {
				flag = false;
				break;
			}
			q.pop();
		}

		if (flag) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}