#include <bits/stdc++.h>
using namespace std;
bool check[10001];
vector<string> answer, tmp;
vector<vector<string>> tickets;
bool flag;

void dfs(string next) {
	if (tmp.size() == tickets.size()) {
		tmp.push_back(next);
		flag = true;
		answer = tmp;
		return;
	}

	for (int i = 0; i < tickets.size(); i++) {
		if (check[i] || tickets[i][0] != next) continue;
		check[i] = true;
		tmp.push_back(tickets[i][0]);
		dfs(tickets[i][1]);
		tmp.pop_back();
		check[i] = false;
	}
}

void solution() {
	sort(tickets.begin(), tickets.end());

	for (int i = 0; i < tickets.size(); i++) {
		if (tickets[i][0] == "ICN") {
			check[i] = true;
			tmp.push_back(tickets[i][0]);
			dfs(tickets[i][0]);
			if (flag) return;
			tmp.pop_back();
			check[i] = false;
		}
	}

}
int main() {
}