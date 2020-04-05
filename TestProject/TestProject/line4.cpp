#include <bits/stdc++.h>
using namespace std;
bool check[100001];

int main() {
	vector<vector<string>> snapshots, transactions, answer;
	snapshots.push_back({ "ACCOUNT1", "100" });
	snapshots.push_back({ "ACCOUNT2", "150" });

	transactions.push_back({ "1", "SAVE", "ACCOUNT2", "100" });
	transactions.push_back({ "2", "WITHDRAW", "ACCOUNT1", "50" });
	transactions.push_back({ "1", "SAVE", "ACCOUNT2", "100" });
	transactions.push_back({ "4", "SAVE", "ACCOUNT3", "500" });
	transactions.push_back({ "3", "WITHDRAW", "ACCOUNT2", "30" });

	unordered_map<string, string> MAP;
	for (int i = 0; i < snapshots.size(); i++) {
		MAP[snapshots[i][0]] = snapshots[i][1];
	}

	for (int i = 0; i < transactions.size(); i++) {
			int num = stoi(transactions[i][0]);
			cout << "num: " << num << '\n';
			if (check[num]) continue;	
			check[num] = true;
			if (MAP.end() != MAP.find(transactions[i][2])) {
				if (transactions[i][1] == "SAVE") {
					int num1 = stoi(MAP[transactions[i][2]]);
					int num2 = stoi(transactions[i][3]);
					int sum = num1 + num2;
					MAP[transactions[i][2]] = to_string(sum);
				}
				else if (transactions[i][1] == "WITHDRAW") {
					cout << transactions[i][0] << '\n';
					int num1 = stoi(MAP[transactions[i][2]]);
					int num2 = stoi(transactions[i][3]);
					int sum = num1 - num2;
					MAP[transactions[i][2]] = to_string(sum);
					cout << "sum : " << sum << '\n';
				}
			}
			else {
				MAP[transactions[i][2]] = transactions[i][3];
			}
	}
	unordered_map<string, string>::iterator it;
	for (it = MAP.begin(); it != MAP.end(); it++) {
		cout << it->first << " " << it->second << '\n';
	}
	return 0;

}